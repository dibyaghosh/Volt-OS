#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "../video.h"
#include "../timer.h"
#include "../keyboard.h"
FILE *fopen (char *filename, char *mode) {
  FILE file;
  file.name = filename;
  file.size = 256;
  file.location = (char *) malloc(file.size);
  file.position = 0;
  return &file;
}

// Write to file
int fputc (int character, FILE *stream) {
  char c = character;
  *(stream->location + (stream->position++)) = c;
  return character;
}
int fputs (char *c, FILE *stream) {
  open_memory_system();
  int j = 0;
  while (c[j] != '\0') {
    fputc(c[j], stream);
  }
  return 0;
}
// Read from file
int fgetc (FILE *stream) {
  return *(stream->location + (stream->position++));
}
char *fgets (char *str, int num, FILE *stream) {
  int a = 0;
  while (num > a) {
    str[a++] = fgetc(stream);
  }
  str[a]='\0';
  return str;
}
// Cursor methods
long int ftell (FILE *stream) {
  return stream->position;
}
int fseek (FILE *stream, long int offset, int origin) {
  if (origin == 0)
    stream->position = offset;
  if (origin == 1)
    stream->position += offset;
  if (origin == 2)
    stream->position = stream->size - offset;
  return 0;
}

//stdin
int getchar ()
{
  char character = '\0';
  while(character == '\0'){
    character = getfromstdin();
  }
  return character;
}

char *gets (char *str)
{
  int i = 0;
  char a[80];
  char inputChar = '\0';
  while(inputChar != '\n')
  {																	     inputChar = getchar();
    if (inputChar == 8)
    {
      i--;
      continue;
    }
    a[i++] = inputChar;
  }
  a[i-1]='\0';
  print("");
  strcpy(str, a);
  return str;
}
