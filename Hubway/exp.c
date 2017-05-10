
#include <stdio.h>
#include <string.h>

/*
int main()
{
    char *string,*found;

    string = strdup("Hello there, peasants!");
    printf("Original string: '%s'\n",string);

    while( (found = strsep(&string," ")) != NULL )
        printf("%s\n",found);

    return(0);
}
*/


void main(int argv, char **argc) {
  char *string,*found;
  string = strdup("id,terminal,station,municipal,lat,lng,status");
  while( (found = strsep(&string,",")) != NULL )
        printf("%s\n",found);

}
