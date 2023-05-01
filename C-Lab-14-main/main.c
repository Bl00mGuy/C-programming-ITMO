#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_ID3 128

typedef struct ID3TAG {
char name[30];
char artist[30];
char album[30];
char year[4];
char description[30];
unsigned short genre;
} ID3TAG;
long file_offset(FILE* fp) {
fseek(fp, 0, SEEK_END);
return ftell(fp) - MAX_SIZE_ID3;
}

int main(int argc, char* argv[]) {
FILE* inf = NULL;
FILE* ouf = NULL;
char* mp3_name;
char* tag;
char* val;
ID3TAG* TAGS = NULL;

if (!strncmp(argv[1],"--filepath=",11)) {
mp3_name = strpbrk(argv[1], "=") + 1;
}
char* temp = (char*) malloc(sizeof(char) * MAX_SIZE_ID3);
memset(temp, 0, MAX_SIZE_ID3);
fseek(inf, file_offset(inf), SEEK_SET);
fread(temp, 1, MAX_SIZE_ID3, inf);
TAGS = (ID3TAG*)(temp);
if (!strcmp("--show", argv[2])) {
printf("\nSong name: %s\n",TAGS->name);
printf("Artist: %s\n",TAGS->artist);
printf("Album: %s\n",TAGS->album);
printf("Year: %s\n",TAGS->year);
printf("Description: %s\n",TAGS->description);
printf("Genre: %d\n\n",TAGS->genre);
}
else if (!strncmp("--get=", argv[2], 6)) {
tag = strpbrk(argv[2], "=") + 1;
if (!strcmp(tag, "name"))
printf("Song name:%s\n",TAGS->name);
else if (!strcmp(tag, "artist"))
printf("Artist:%s\n",TAGS->artist);
else if (!strcmp("album", tag))
printf("Album:%s\n",TAGS->album);
else if (!strcmp("year", tag))
printf("Year:%s\n",TAGS->year);
else if (!strcmp("description", tag))
printf("Description:%s\n",TAGS->description);
else if (!strcmp("genre", tag))
printf("Genre:%d\n\n",TAGS->genre);
}
else if (!strncmp("--set=", argv[2], 6)) {
tag = strpbrk(argv[2], "=") + 1;
if (!strncmp("--value=", argv[3], 8)) {
val = strpbrk(argv[3], "=") + 1;
if (!strcmp(tag, "name"))
memcpy(TAGS->name, val, 30);
else if (!strcmp(tag, "artist"))
memcpy(TAGS->artist, val, 30);
else if (!strcmp(tag, "album"))
memcpy(TAGS->album, val, 30);
else if (!strcmp(tag, "year"))
memcpy(TAGS->year, val, 4);
else if (!strcmp(tag, "description"))
memcpy(TAGS->description, val, 30);
}
}
fclose(inf);
char* temp2 =(char*) malloc(sizeof(char) * MAX_SIZE_ID3);
memset(temp2, 0, MAX_SIZE_ID3);
temp2 = (char*)TAGS;
fseek(ouf, file_offset(ouf), SEEK_SET);
fwrite(temp2, 1, MAX_SIZE_ID3, ouf);
free(temp2);
fclose(ouf);
return 0;
}
