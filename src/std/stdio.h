#ifndef STDIO_H
#define STDIO_H

enum origin_t { SEEK_SET, SEEK_CUR, SEEK_END };

typedef struct file {
  char *location;
  char *name;
  unsigned char position;
  unsigned short size;
} FILE;

// Open file
FILE *fopen (char *filename, char *mode);
// Write methods
int fputc (int character, FILE *stream);
int fputs (char *c, FILE *stream);
// Read methods
int fgetc (FILE *stream);
char *fgets (char *str, int num, FILE *stream);
// Position methods
long int ftell (FILE *stream);
int fseek (FILE *stream, long int offset, int origin);


int getchar ();
char *gets (char *str);

#endif
