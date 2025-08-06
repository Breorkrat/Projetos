#include <stdio.h>

void u32le(int input, unsigned char output[4]){
	// Convert integer input into 4 octets in output[];
	// Ex.: input  = 0x12345678
	//	output = {0x12, 0x34, 0x56, 0x78}
	output[0] = (input >> 24) & 0xFF;
	output[1] = (input >> 16) & 0xFF;
	output[2] = (input >> 8)  & 0xFF;
	output[3] = (input >> 0)  & 0xFF;
	return;
}

int main (){

	int width = 2;
	int height = 2;
	int bitsPerPixel = 24;
	int bytesPerPixel = bitsPerPixel/8;
	int rowSize = width*bytesPerPixel;
	int pixelDataSize = rowSize*height;
	int pixelDataOffset = 54;
	int fileSize = pixelDataSize + pixelDataOffset;
 	int padding = width % 4;

	char temp[4];
	u32le(65534, temp);
	/*FILE* file = fopen("out.bmp", "w");
	if (file == NULL) {
		printf("Erro ao criar imagem");
		return 1;
	}

	char header[54];
	createHeader(header, FILESIZE, WIDTH, HEIGHT);

	int a = fwrite(header, 54, 1, file);
	printf("Código: %d\n", a);
	char tempColor[3];
	char nullbyte[2] = {0};

	for (int i = 0; i <= HEIGHT; i++){
		for (int j = 0; j <= WIDTH; j++){
			createColor(255, 255, 255, tempColor);
			fwrite(tempColor, sizeof(tempColor), 1, file);
		}
		fwrite(nulchar, sizeof(nulchar), PADDING, file);
	}
	createColor(255, 255, 255, tempColor);
	fwrite(tempColor, sizeof(tempColor), 1, file);
	fwrite(tempColor, sizeof(tempColor), 1, file);
	fwrite(nullbyte, 2, 1, file);
	fwrite(tempColor, sizeof(tempColor), 1, file);
	fwrite(tempColor, sizeof(tempColor), 1, file);
	fwrite(nullbyte, 2, 1, file);


	fclose(file);*/

	return 0;
}

