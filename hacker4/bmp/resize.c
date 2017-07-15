/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

// function prototypes
int resizeLarger(FILE* inptr, FILE* outptr, float n);
int resizeSmaller(FILE* inptr, FILE* outptr, float n);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    float n = atof(argv[1]);
    
    if (!atof(argv[1]))
    {
        printf("The factor must be a float or integer.\n");
        return 5;
    }
    else if (atof(argv[1]) <= 0 || atof(argv[1]) >= 100)
    {
        printf("The factor must be of type float or integer and larger than zero and smaller or equal to 100. Aborting.\n");
        return 6;
    }
    
     // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
     
    if (n >= 1) resizeLarger(inptr, outptr, n);
    else resizeSmaller(inptr, outptr, n);
}

int resizeLarger(FILE* inptr, FILE* outptr, float n){

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    int originalBiHeight = bi.biHeight;
    int originalBiWidth = bi.biWidth;
    
    // overwrite the BITMAPINFOHEADER values for biWidth & biHeight   
    bi.biWidth = ceil(originalBiWidth * n); // new Width is original width of the infile times the input factor
    
    // if originalBiHeight is negative, ceil rounds (e.g.) -2.3 to -2, while we would expect -3, so we floor instead
    bi.biHeight = (originalBiHeight >= 0) ? ceil(originalBiHeight * n) : floor(originalBiHeight * n); // new Height is original height of the infile times the factor

    // determine padding for scanlines
    int originalPadding =  (4 - (originalBiWidth * sizeof(RGBTRIPLE)) % 4) % 4; // padding in the original file
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4; // padding in the to be resized file
    
    // calculate biSizeImage for to be resized image. biHeight can be negative so with abs() we make it positive.
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof(RGBTRIPLE)) + padding); // width times the size of each RGBTRIPLE plus the padding at the end of line
    
    // calculate bfSize for to be resized image. This is equal to the biSizeImage of the same file, plus the size of the two HEADERs
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, newBiHeight = ceil(abs(originalBiHeight) * n); i < newBiHeight; i++)
    {
        int originalLineSizeInBytes = originalBiWidth * sizeof(RGBTRIPLE) + originalPadding;
        
        for (int lines = 0; lines < ceil(n); lines++){
            // iterate over pixels in scanline
            for (int j = 0; j < originalBiWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile
                for (int k = 0; k < n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // skip over padding, if any
            fseek(inptr, originalPadding, SEEK_CUR);
            
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, -originalLineSizeInBytes, SEEK_CUR);
        }
        
        fseek(inptr, originalLineSizeInBytes, SEEK_CUR);    
    
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

int resizeSmaller(FILE* inptr, FILE* outptr, float n){
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    int originalBiHeight = bi.biHeight;
    int originalBiWidth = bi.biWidth;
    
    // overwrite the BITMAPINFOHEADER values for biWidth & biHeight   
    bi.biWidth = ceil(originalBiWidth * n); // new Width is original width of the infile times the input factor
    
    // if originalBiHeight is negative, ceil rounds (e.g.) -2.3 to -2, while we would expect -3, so we floor instead
    bi.biHeight = (originalBiHeight >= 0) ? ceil(originalBiHeight * n) : floor(originalBiHeight * n); // new Height is original height of the infile times the factor

    // determine padding for scanlines
    int originalPadding =  (4 - (originalBiWidth * sizeof(RGBTRIPLE)) % 4) % 4; // padding in the original file
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4; // padding in the to be resized file
    
    // calculate biSizeImage for to be resized image. biHeight can be negative so with abs() we make it positive.
    bi.biSizeImage = abs(bi.biHeight) * ((bi.biWidth * sizeof(RGBTRIPLE)) + padding); // width times the size of each RGBTRIPLE plus the padding at the end of line
    
    // calculate bfSize for to be resized image. This is equal to the biSizeImage of the same file, plus the size of the two HEADERs
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    return 0;
}