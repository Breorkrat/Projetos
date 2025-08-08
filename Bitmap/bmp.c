#include <stdio.h>
#include <math.h>

void u32le(char* output, int integer){
	output[0] = (char) (integer >> 24 & 0xff);
	output[1] = (char) (integer >> 16 & 0xff);
	output[2] = (char) (integer >> 8  & 0xff);
	output[3] = (char) (integer >> 0  & 0xff);
	return;
};

void createHeader(char* header, int filesize, int width, int height){
	sprintf(header, "BM");	// Signature
	char seReserve[4];	
	u32le(seReserve, filesize);	// File Size
	sprintf(header+2, "%c%c%c%c", seReserve[3], seReserve[2], seReserve[1], seReserve[0]);

	sprintf(header+6, "%c%c%c%c", '\0', '\0', '\0', '\0');	// Reserved
					
	u32le(seReserve, 54);		// Data offset
	sprintf(header+10, "%c%c%c%c", seReserve[3], seReserve[2], seReserve[1], seReserve[0]);

	u32le(seReserve, 40);		// Info Header size
	sprintf(header+14, "%c%c%c%c", seReserve[3], seReserve[2], seReserve[1], seReserve[0]);

	u32le(seReserve, width);	// Bitmap Width
	sprintf(header+18, "%c%c%c%c", seReserve[3], seReserve[2], seReserve[1], seReserve[0]);

	u32le(seReserve, height);	// Bitmap Height
	sprintf(header+22, "%c%c%c%c", seReserve[3], seReserve[2], seReserve[1], seReserve[0]);

	sprintf(header+26, "%c%c", 1, 0); // Planes

	sprintf(header+28, "%c%c", 24, 0); // Bits per pixel

	sprintf(header+30, "%c%c%c%c", '\0', '\0', '\0', '\0'); // Compression
	sprintf(header+34, "%c%c%c%c", '\0', '\0', '\0', '\0'); // Image size
	sprintf(header+38, "%c%c%c%c", '\0', '\0', '\0', '\0'); // XpixelsPerM
	sprintf(header+42, "%c%c%c%c", '\0', '\0', '\0', '\0'); // YpixelsPerM
	sprintf(header+46, "%c%c%c%c", '\0', '\0', '\0', '\0'); // Colors used
	sprintf(header+50, "%c%c%c%c", '\0', '\0', '\0', '\0'); // Important colors

	return;
};

void createColor(char r, char g, char b, char out[3]){
	out[0] = b;
	out[1] = g;
	out[2] = r;
	return;
}

int main (){

	int width = 500;
	int height = 500;
	int bytesPerRow = 3*width;
 	int padding = (4 - (bytesPerRow % 4)) % 4;
	int fileSize = 54 + 3*(width+padding)*height;

	char header[54];
	createHeader(header, fileSize, width, height);

	FILE* file = fopen("out.bmp", "w");
	if (file == NULL) {
		printf("Erro ao criar imagem");
		return 1;
	}


	fwrite(header, 54, 1, file);
	char tempColor[3];

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			createColor(i*255/width, 0, j*255/height, tempColor);
			fwrite(tempColor, sizeof(tempColor), 1, file);
		}
		fwrite("\0", 1, padding, file);
	}

	fclose(file);
	return 0;
}
