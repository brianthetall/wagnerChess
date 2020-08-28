//strncpy, strncat, strncmp

#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *s){
  size_t i=0;

  while( *s++ != '\0' )
    i++;

  return i;
}

char* mystrncpy(char* s, const char* t, size_t n){
  char *start=s;
  for(int i=0; (*s++=*t++) != '\0' && i<n;i++);
  *s='\0';
  return start;
}

//I'm of the opinion Strings should be immutable.
char* mystrncat(char* s,const char* t,size_t n){
  char* retval = calloc(sizeof(char), strlen(s)+n);
  char* start = retval;
  for(;*s!='\0';)
    *retval++=*s++;
  for(int i=0; i<n; i++)
    *retval++=*t++;

  s=start;
  return s;
}


//I'm of the opinion Strings should be immutable.
char* mystrcat(char* s,const char* t){
  char* retval = calloc(sizeof(char), strlen(s)+strlen(t));
  char* start = retval;
  while(*s!='\0')
    *retval++=*s++;

  while(*t!='\0')
    *retval++=*t++;

  s=start;
  return s;
}
