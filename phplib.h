#ifndef PHPLIB_H
#define PHPLIB_H



char *lcfirst(char* str);
char *strrot13(char* str);
char *strtoupper(char* str);
char *strtolower(char* str);
char *ucfirst(char* str);
int mystrcasecmp ( char *s1,  char *s2);
int strwordcount(char* str, int nb);
int mysubstrcount(char string2, char *string1);
char *nl2br (char* str, char *str2);
char ucwords(char* str);
char wordwrap(char *str, int n);
char *ltrim(char * str);
char *rtrim(char * str);
char *trim(char * str);
char *strrev(char * str);
char strshuffle(char *str);
char *mysubstr(const char *src, int m, int n);
char strtr(char *buff, char str1, char str2);
char *substrreplace(const char *s, const char *str1, const char *str2);
char *str_pad(char * str, char * c, int n);
char *strrepeat(char *str, int x);
char stripos(char * str, char * c);
char strripos(char * str, char * c);
char str_split(char * str);

#endif // PHPLIB_H
