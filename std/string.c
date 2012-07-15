#include "../common.h"
#include "string.h"

void memcpy (u8int *dest, const u8int *src, u32int len) {
  const u8int *sp = (const u8int *) src;
  u8int *dp = (u8int *) dest;
  for( ; len!=0; len--)
    *dp++ = *sp++;
}
void memset (u8int *dest, u8int val, u32int len) {
  u8int *temp = (u8int *) dest;
  for( ; len!=0; len--)
    *temp++ = val;
}
int strcmp(char *str1, char *str2)
{
  int i = 0;
  int failed = 0;
  while(str1[i]!='\0' && str2[i]!='\0') {
    if(str1[i] != str2[i]) {
      failed = 1;
      break;
    }
    i++;
  }
  if((str1[i]=='\0' && str2[i]!='\0') || (str1[i]!='\0' && str2[i]=='\0'))
    failed = 1;
  return failed;
}
char *strcpy(char *dest, const char *src) {
  do {
    *dest++ = *src++;
  } while (*src != 0);
}
char *strcat(char *dest, char *src) {
  while (*dest != 0)
    *dest = *dest++;
  do {
    *dest++ = *src++;
  } while (*src != 0);
  return dest;
}
void append(char* s, char c)
{
  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';
}
size_t strlen (const char *str){
	int i=0;
	while(str[i] != '\0'){
		i++;
	}
}
