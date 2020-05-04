#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char* lcfirst(char* str)
{
    *str = *str + ('a' - 'A');
    return str;
}

//----------------------------------

char* strrot13(char str[100])
{
    for ( ; *str != '\0'; str++ )
    {
        if ( ( *str >= 'A' && *str < 'N') || ( *str >= 'a' && *str < 'n') )
        {
            *str += 13;
        }
        else
        {
            *str -= 13;
        }
    }
    return str;
}

//-----------------------------------------

char *strtoupper(char* str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i]>= 'a' && str[i]<='z')
        {
            str[i] = str[i] - 32 ;
        }
        i++;
    }
    return str;
}

//-----------------------------------------

char *strtolower(char* str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i]>= 'A' && str[i]<='Z')
        {
            str[i] = str[i] + 32 ;
        }
        i ++;
    }
    return str;
}

//------------------------------------------

char *ucfirst(char* str)
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(i==0)
        {
            if((str[i]>='a' && str[i]<='z'))
                str[i]=str[i]-32;
            continue;
        }
        if(str[i]==' ')
        {
            ++i;

            if(str[i]>='a' && str[i]<='z')
            {
                str[i]=str[i]-32;
                continue;
            }
        }
        else
        {
            if(str[i]>='A' && str[i]<='Z')
                str[i]=str[i]+32;
        }
    }
    return str;
}

//----------------------------------------------

int mystrcasecmp ( char *s1, char *s2)
{

    char *p1 = (char *) s1;
    char *p2 = (char *) s2;
    int result;
    if (p1 == p2)
        return 0;
    while ((result = tolower (*p1) - tolower (*p2++)) == 0)
        if (*p1++ == '\0');
    return result;
}

//----------------------------------

int strwordcount(char* str, int nb)
{
    int i = 0;
    while (str[i]!=0)
    {
        if (str[i] == ' ' && str[i+1]>= 33 && str[i+1] <=126)
        {
            nb++;
        }
        else if (i==0 && str[i] != ' ')
        {
            nb++;
        }
        i++;
    }
    return  nb;
}

//--------------------------------------------

int mysubstrcount(char string2, char *string1)
{
    int  i;
    int  nb;

    for (i = 0, nb = 0; string1[i]; i++)
    {
        if (string1[i] == string2)
            nb++;
    }
    return nb;
}
//---------------------------------------------------


 char *nl2br (char* str, char *str2)
{
    int nb = 0;
    int nb2 = 0;

    while (str[nb] != '\0')
    {
        if (str[nb]== '\n') {
            str2[nb2] = '<';
            str2[nb2+1] = 'b';
            str2[nb2+2] = 'r';
            str2[nb2+3] = '>';
            nb2 = nb2 + 4;
        }
        str2[nb2] = str[nb];
        nb++;
        nb2++;
    }
    return(str2);
}


//----------------------------------------------------

char ucwords(char* str)
{
    int i;
    for(i=0; i<strlen(str); i++)
    {
        if (i==0 || (str[i-1]==' '&& str[i]>='a' && str[i]<='z'))
            str[i]=toupper(str[i]);
    }
    return 0;
}
//---------------------------------------------

char wordwrap(char *str, int n)
{
    int str_size = strlen(str);
    int i;
    int part_size;

    if (str_size % n != 0)
    {
        printf("not divisable");
        return 0;
    }

    part_size = str_size / n;
    for (i = 0; i< str_size; i++)
    {
        if (i % part_size == 0)
            printf("\n");
        printf("%c", str[i]);
    }
    return 0;
}

//----------------------------------------
char * ltrim(char* str)
{
    int i =0;
    while(str[0]== 32||str[0]==9||str[0]==10||str[0]==13||str[0]==0||str[0]==11)
    {
        i = 0;
        while(str[i])
        {
            str[i] = str[i+1];
            i++;
        }
    }
    return str;
}

//---------------------------------------------
char *rtrim(char * str)
{
    strrev(str);
    ltrim(str);
    strrev(str);
    return str;
}

//---------------------------------------------

char * trim(char * str)
{
    ltrim(str);
    rtrim(str);
    return str;
}

//---------------------------------------------

char * strrev(char * str)
{
    if(!str || !*str)
        return str;
    int i = strlen(str) - 1, j = 0;
    char ch;
    while(i>j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

//--------------------------------------------

char strshuffle(char *str)
{
    int i, random, length = strlen(str);
    char temp;

    for (i = length-1; i > 0; i--)
    {
        random = rand()%(i+1);
        temp = str[random];
        str[random] = str[i];
        str[i] = temp;
    }
    return 0;
}

//-------------------------------------------

char *mysubstr(char *str, int str_nb1, int str_nb2)
{
    char *strbis = str;
    int start = str_nb1;
    int end = str_nb2;
    int compteur = 0;

    if (strlen(str) < start) {
        exit (84);
    }
    if (start < 0) {
        start = strlen(str) + start;
    }
    if (end < 0) {
        end = strlen(str) + end;
    }

    while (start <= end || str[compteur] == '\0') {
        str[compteur] = strbis[start];
        compteur++;
        start++;
    }
    str[compteur] = '\0';
    return str;
}

//------------------------------------------

char strtr(char *buff, char str1, char str2)
{
    char *ptr;
    for(;;)
    {
        ptr =strchr(buff,str1);
        if (ptr == NULL)
            break;
        buff[(int)(ptr-buff)]=str2;
    }
    return 0;
}

//------------------------------------------------
char * str_pad(char * str, char * c, int n)
{
    int i;
    int len = strlen(str);
    if(strlen(str)>=n)
        return 0;
    for(i=0; i<n - len; i++)
    {
        strcat(str,c);
    }
    return str;
}
//-------------------------------------------------------

char *strrepeat(char *str, int x)
{
    char *result = malloc(sizeof(str) * x + 1);

    while (x > 0) {
        strcat(result, str);
        x --;
    }
    return result;
}

//--------------------------------------

char stripos(char * str, char * c)
{
    strtolower(str);
    int l = tolower(*c);

    int i=0;
    while(i<strlen(str))
    {
        if(str[i]==l)
        {
            printf("first char \"%c\" on position %d",l,i+1);
            return 0;
        }
        i++;
    }
    return 0;
}

//-------------------------------------------------

char strripos(char * str, char * c)
{
    strtolower(str);
    int l = tolower(*c);
    strrev(str);
    int i=0;

    while(i<strlen(str))
    {
        if(str[i]==l)
        {
            int n = strlen(str) - i;
            printf("last char \"%c\" on position %d",l,n);
            return 0;
        }
        i++;
    }
    return 0;
}

//--------------------------------------------

char str_split(char * str)
{
int str_size=strlen(str);
for(int i=0;i<str_size;i++)
{
printf("[%d] -> %c\n",i,str[i]);
}
return 0;
}


//-------------------------------------------

