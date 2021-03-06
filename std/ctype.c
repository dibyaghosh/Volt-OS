#include "ctype.h"

int isalpha (int c) {
  if ((c>=65 && c<=90) || (c>=97 && c<=122))
    return 1;
  return 0;
}
int isdigit (int c) {
  if (c>=48 && c<=57)
    return 1;
  return 0;
}
int isspace (int c) {
  if (c==32 || (c>=9 && c<=13))
    return 1;
  return 0;
}
int isprint (int c) {
  if (c>=32 && c<=126)
    return 1;
  return 0;
}
int iscntrl (int c) {
  return !isprint(c);
}
int isalnum (int c) {
  return (isalpha(c) || isdigit(c));
}
int isgraph (int c) {
  return (isprint(c) && (c!=32));
}
int isupper (int c) {
  return (c>=65 && c<=90);
}
int islower (int c) {
  return (isalpha(c) && !isupper(c));
}
int ispunct (int c) {
  return (isgraph(c) && !isalnum(c));
}
int isxdigit (int c){
  if (isdigit(c) || (toupper(c)>=65 && toupper(c)<=70))
    return 1;
}

int tolower (int c) {
  if (isupper(c))
    c += 32;
  return c;
}
int toupper (int c) {
  if (islower(c))
    c -= 32;
  return c;
}
