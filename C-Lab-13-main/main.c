#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **arr_malloc(unsigned long h, unsigned long w) {
int **ARR = (int **) malloc(h * sizeof(int *));
for (int i = 0; i < h; i++) {
ARR[i] = (int *) malloc(w * sizeof(int));
}
return ARR;
}
int neighborCounter(int **area, int x, int y) {

int sum = 0;
for (int i = x - 1; i <= x + 1; i++) {
for (int j = y - 1; j <= y + 1; j++) {
sum += area[i][j];
}
}
if (area[x][y] == 1) {
sum--;
}
return sum;
}
unsigned char *transl_to_str(int **matrix, unsigned long h, unsigned long w)
{
unsigned char *info_on_pix = (unsigned char *) malloc(h * w * 3);
int m = 0;
for (int i = h - 1; i >= 0; i--) {
for (int j = 0; j < w; j++) {
if (matrix[i][j] == 1) {
info_on_pix[m] = 0;
info_on_pix[m + 1] = 0;
info_on_pix[m + 2] = 0;
} else {
info_on_pix[m] = 255;
info_on_pix[m + 1] = 255;
info_on_pix[m + 2] = 255;
}
m += 3;
}
}
return info_on_pix;
}
struct info_file {
unsigned long height;
unsigned long width;
unsigned long size;
unsigned long image_offset;
unsigned char bmp_header[54];
};
int main(int argc, char *argv[]) {
struct info_file info;
FILE *image;
long dump_freq = 1;
long max_iter = 1;
char *dirName;
int **cur_gen;
int **next_gen;
for (int i = 1; i < argc; i += 2) {
if (strcmp(argv[i], "--input") == 0) {
image = fopen(argv[i + 1], "rb"); // открывю для считывания
информации
if (image == NULL) {
printf("Cant open :(");
return (0);
}
} else if (strcmp(argv[i], "--output") == 0) {
dirName = argv[i + 1];
} else if (strcmp(argv[i], "--max_iter") == 0) {
max_iter = strtol(argv[i + 1], NULL, 10);
} else if (strcmp(argv[i], "--dump_freq") == 0) {
dump_freq = strtol(argv[i + 1], NULL, 10);

}
}
fread(info.bmp_header, sizeof(unsigned char), 54, image);
info.image_offset = info.bmp_header[0xD] << 24 | info.bmp_header[0xC] << 16 | info.bmp_header[0xB] << 8 | info.bmp_header[0xA];
info.size = info.bmp_header[0x5] << 24 | info.bmp_header[0x4] << 16 | info.bmp_header[0x3] << 8 | info.bmp_header[0x2];
info.width = info.bmp_header[0x15] << 24 | info.bmp_header[0x14] << 16 | info.bmp_header[0x13] << 8 | info.bmp_header[0x12];
info.height = info.bmp_header[0x19] << 24 | info.bmp_header[0x18] << 16 | info.bmp_header[0x17] << 8 | info.bmp_header[0x16];
printf("offset - %lu\n", info.image_offset);
printf("size - %lu\n", info.size);
printf("height - %lu\n", info.height);
printf("width - %lu\n", info.width);
printf("\n");
cur_gen = arr_malloc(info.height, info.width * 3);
next_gen = arr_malloc(info.height, info.width * 3);
fseek(image, info.image_offset, SEEK_SET);
char buffer[3];
for (int i = info.height - 1; i >= 0; i--) {
for (int j = 0; j < info.width; j++) {
buffer[0] = fgetc(image);
buffer[1] = fgetc(image);
buffer[2] = fgetc(image);
if (buffer[0] != 0 || buffer[1] != 0 || buffer[2] != 0) {
cur_gen[i][j] = 1;
} else {
cur_gen[i][j] = 0;
}
}
}
char fileName[10];
char directory[256];
char *pixelInfo;
for (unsigned long i = 0; i < info.height; i++) {
for (unsigned long j = 0; j < info.width; j++) {
next_gen[i][j] = cur_gen[i][j];
}
}
int countOfNeighbors;
for (int gameIteration = 0; gameIteration < max_iter; gameIteration++) {
for (unsigned long i = 1; i < info.height - 1; i++) {
for (unsigned long j = 1; j < info.width - 1; j++) {
countOfNeighbors = neighborCounter(cur_gen, i, j);
if (cur_gen[i][j] == 0 && countOfNeighbors == 3) {
next_gen[i][j] = 1;
} else if (cur_gen[i][j] == 1) {
if (countOfNeighbors < 2 || countOfNeighbors > 3) {
next_gen[i][j] = 0;
}
}
}
}
for (unsigned long i = 0; i < info.height; i++) {
for (unsigned long j = 0; j < info.width; j++) {
cur_gen[i][j] = next_gen[i][j];
}
}

pixelInfo = transl_to_str(cur_gen, info.height, info.width);
if (gameIteration % dump_freq == 0) {
sprintf(fileName, "%d", gameIteration);
strcpy(directory, dirName);
strcat(directory, "/");
strcat(directory, fileName);
strcat(directory, ".bmp");
FILE *new_bmp = fopen(directory, "wb");
if (new_bmp != NULL) {
printf("File %d created\n", gameIteration);
}
else {
printf("File %4d can't be open\n", gameIteration);
}
fseek(new_bmp, 0, SEEK_SET);
fwrite(info.bmp_header, 1, 54, new_bmp);
fwrite(pixelInfo, 1, 3 * info.width * info.height, new_bmp);
}
}
free(cur_gen);
free(next_gen);
free(pixelInfo);
return 0;
}
