#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include "phplib.h"

int main()
{
    int nb_points = 0;

/*---------------
---------------*/

    {
        char str[100] = "HelloWorld";
        printf("%s \n",str);
        lcfirst(str);
        if(strcmp(str, "helloWorld") == 0)
        {
            printf(str);
            printf("\nlcfirst ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("lcfirst KO!\n");
    }

/*---------------
---------------*/

    {
        char str[100] = "HelloWorld";
        printf("%s : without rot13\n",str);
        strrot13(str);
        if(strcmp(str, "UryybJbeyq") == 0)
        {
            printf("%s : with rot13", str);
            printf("\nstrrot13 ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("strrot13 KO!\n");

    }

/*---------------
---------------*/

    {
        char str[100] = "HelloWorld";
        printf("%s : without strtoupper\n",str);
        strtoupper(str);
        if(strcmp(str, "HELLOWORLD") == 0)
        {
            printf("%s : with strtoupper\n",str);
            printf("strtoupper ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("strtoupper KO!\n");

    }

/*---------------
---------------*/

    {
        char str[100] = "HELLOWORLD";
        printf("%s : without strtolower\n",str);
        strtolower(str);
        if(strcmp(str, "helloworld") == 0)
        {
            printf("%s : with strtolower\n",str);
            printf("strtolower ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("strtolower KO!\n");

    }

/*---------------
---------------*/

    {
        char str[100] = "helloworld";
        printf("%s\n",str);
        ucfirst(str);

        if(strcmp(str, "Helloworld") == 0)
        {
            printf("%s\n",str);
            printf("ucfirst ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("ucfirst KO!\n");

    }

/*---------------
---------------*/

    {
        char *str1 = "hello world";
        char *str2 = "hello wooooooorld";
        int result;

        result = mystrcasecmp(str1, str2);

        if (result == 0)
            printf("\"%s\" = \"%s\".\n", str1, str2);
        else if (result < 0)
            printf("\"%s\" > \"%s\".\n", str1, str2);
        else
            printf("\"%s\" < \"%s\".\n", str1, str2);
        printf("strcasecmp ok!\n");
        nb_points++;
        printf("%d / 20\n\n", nb_points);
    }

/*---------------
---------------*/

    {
        char str[100] = "hello world";
        int nb = 0;
        int count = 2;
        nb = strwordcount(str,nb);
        if (nb==count)
        {
            printf("strwordcount ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
        {
            printf("strwordcount KO!\n");
        }
    }

/*---------------
---------------*/

    {
        int mysubstrcount (char string2, char *string1);
        int a ;
        {

            char* str = "hello world";
            a = mysubstrcount('o', str);
            if (a ==2)
            {
                printf("substrcount ok!\n");
                nb_points++;
                printf("%d / 20\n\n", nb_points);
            }
            else
            {
                printf("substrcount KO");
            }
        }
    }

/*---------------
---------------*/

   {
        char *str = "hello\nworld\nhello\nworld";
        char str2[100];
        nl2br(str,str2);
        printf(str2);
        if(strcmp(str2, "hello<br>\nworld<br>\nhello<br>\nworld") == 0)
        {
            printf("\nnl2br ok!\n");
                nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("nl2br KO!\n");
    }



/*---------------
---------------*/

    {
        char str[100] = "hello world what's up";
        printf("%s : without ucwords\n",str);
        ucwords(str);
        if (strcmp(str, "Hello World What's Up")==0)
        {
            printf("%s : with ucwords\n",str);
            printf("ucwords ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("ucwords KO!");
    }

/*---------------
---------------*/

    {
        char *str = "helloworld";
        wordwrap(str, 5);
        if (strcmp(str, "helloworld")==0)
        {
            printf("\nwordwrap ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);

        }
        else
            printf("wordwrap KO!\n");
    }

/*---------------
---------------*/

    {
        char str[]="                hello world";
        printf("%s  : without ltrim", str);
        printf("\n");
        ltrim(str);
        if (strcmp(str, "hello world")==0)
        {
            printf("%s  : with ltrim",str);
            printf("\nltrim ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);

        }
        else
            printf("ltrim KO!\n");
    }

/*---------------
---------------*/

    {
        char str[]="hello world             ";
        printf("%s  : without rtrim", str);
        printf("\n");
        rtrim(str);
        if (strcmp(str, "hello world")==0)
        {
            printf("%s: with rtrim",str);
            printf("\nrtrim and strrev ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);

        }
        else
            printf("rtrim KO!\n!");
    }

/*---------------
---------------*/

    {
        char str[]="        hello world             ";
        printf("      %s    : without trim", str);
        printf("\n");
        trim(str);
        if (strcmp(str, "hello world")==0)
        {
            printf("%s: with trim",str);
            printf("\ntrim ok!\n");
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
        else
            printf("trim KO!\n");
    }

/*---------------
---------------*/

    {
        char strr[100]="HelloWorld";
        srand(time(NULL));

        printf("%s : basic string",strr);
        strshuffle(strr);
        if(strcmp(strr, "HelloWorld")==0)
        {
            printf("strshuffle KO!");
        }
        else
        {
            printf("\n%s : shuffled string\n",strr);
            nb_points++;
            printf("%d / 20\n\n", nb_points);
        }
    }

/*---------------
---------------*/

{
        char str[] = "Hello World";


        printf("%s : without substr\n",str);
        char* dest = mysubstr(str, 4, 20);
        if (strcmp(str, "lo World"))
        {
            printf("%s : with substr\n", dest);
            printf("substr ok!");
            nb_points++;
            printf("\n%d / 20\n\n", nb_points);
        }
        else
        {
            printf("substr KO!");
        }
    }

/*---------------
---------------*/

{
        char str[100]= "helloworld";
        char str2[100]= "dlrowolleh";
        printf("%s : without strrev\n",str);
        strrev(str);
        if (strcmp(str, str2)==0)
        {
            printf("%s : with strrev", str);
            printf("\nstrrev ok!");
            nb_points++;
            printf("\n%d / 20\n\n",nb_points);
        }

        else
            printf("strrev KO!\n");
    }

    {
        char str[100]= "helloworld";
        printf("%s : without strtr\n",str);
        strtr(str,'l','Z');
        if (strcmp(str, "heZZoworZd")==0)
        {
            printf("%s : with strtr", str);
            printf("\nstrtr ok!");
            nb_points++;
            printf("\n%d / 20\n\n", nb_points);
        }

        else
            printf("strtr KO!\n");
    }

/*---------------
---------------*/

    {
        char str[100]= "helloworld";
        printf("%s : without strpad\n",str);
        str_pad(str,"d",20);
        if(strcmp(str, "helloworldddddddddd"))
        {
            printf("%s : with strpad\n",str);
            printf("strpad ok!");
            nb_points++;
            printf("\n%d / 20\n\n", nb_points);
        }
        else
        {
            printf("strpad KO!");
        }
    }

/*---------------
---------------*/

    {
        char *str = "helloworld";
        printf("%s : without str_repeat",str);
        char *result = strrepeat(str, 3);
        if(strcmp(str, "helloworldhelloworldhelloworld"))
        {
            printf("\n%s : with str_repeat", result);
            printf("\nstr_repeat ok!");
            nb_points++;
            printf("\n%d / 20\n\n", nb_points);
        }
        else
        {
            printf("str_repeat KO!");
        }
    }

/*---------------
---------------*/

    {
        char str[] = "hello world";
        stripos(str,"o");
        printf("\nstripos ok!\n");
        nb_points++;
        printf("%d / 20\n\n", nb_points);
    }

/*---------------
---------------*/

    {
        char str[] = "hello world";
        strripos(str,"o");
        printf("\nstrripos ok!\n");
        nb_points++;
        printf("%d / 20\n\n", nb_points);
    }

/*---------------
---------------*/

{
    char str[] = "Hello World";
    str_split(str);
    printf("str_split ok!\n");
    nb_points++;
    printf("%d / 20\n\n", nb_points);
}

return 0;
}
