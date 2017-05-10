#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dados.h"
#include "functions.h"


int main(int argn, char *argv[])
{
    //char fname[100]="hubwaystations.cvs";
    if ( argn < 3)
    {
        fprintf(stderr, "usage : \n  hubway station-data-file  trip-data-file\n");
        exit(1);
    }

    readStationDataFile(argv[1]);

    return EXIT_SUCCESS;
}

/**
 * Lê os ficheiros para as listas já com os dados organizados de acordo com
 * as estruturas de dados.
 *
 * @param stationDataFileName Nome do ficheiro CSV onde se encontram os dados
 *         relativos à estação das bicicletas
 * @param tripDataFileName Nome do ficheiro em formato CSV onde existe a
        informação das viagens que os utilizadores realizaram
 */
void readStationDataFile (char *stationDataFileName)
{
    FILE *fp=NULL;
    char *line;
    int i=0;
    //char *status;
    int  stationStatus=0;

    // Station Data
    fp = fopen(stationDataFileName, "r");

    if (fp == NULL)
    {
        perror("Erro a abrir ficheiro \n");
        exit (1);
    }

    while ((line = readLine(fp)) != NULL)
    {
        char **columns = lineSplit(line);
        Station s;
        i = 0;
        while (columns[i] != NULL) {
            switch (i) {
            case 0:
                s.id = atoi(columns[i]);
                break;
            case 1:
                strcpy(s.terminal,columns[i]);
                break;
            case 2:
                s.name = (char *) malloc ((size_t)columns[i]);
                strcpy(s.name,columns[i]);
                break;
            case 3:
                strcpy(s.name,columns[i]);
                break;
            case 4:
                s.latitude =  atoi(columns[i]);
                break;
            case 5:
                s.longitude = atoi(columns[i]);
                break;
            case 6:
                {
                    //strcpy(status, columns[i]);

                    if ( strcmp(columns[i], "Removed") == 0)
                        stationStatus = 0;

                    else if (strcmp(columns[i], "Existing") == 0)
                        stationStatus = 1;

                    s.status = stationStatus;
                }
                break;

            }
            printf("%s\n", columns[i]);
            free(columns[i]);
            i++;
        }
    }

    fclose(fp);

    // Trip Data

}


/**
 * Lê as linhas do ficheiro e retorna o conteudo da linha
 *
 * @param fp ponteiro para o ficheiro
 */
char *readLine(FILE *fp)
{
    char  *line = NULL;
    size_t len = 0;

    if (getline (&line, &len, fp) <=0)
        return NULL;

    return line;
}


/**
 * Separa o conteudo da linha e retorna um array com os diferentes elementos
 *
 * @param line  contem o conteudo da linha
 *
 * @param i numero da linha
 */
char **lineSplit(char *line)
{
    char *stringBetweenTokens;
    char **columns = NULL;
    int currNumColumns=0;

    columns = (char **) malloc (sizeof(char *));

    char *copiedLine = strdup(line);

    while ((stringBetweenTokens = strsep(&copiedLine, ",")) != NULL)
    {

        char *columnData = strdup(stringBetweenTokens);

        // Copiar dados do campo, da linha, para a nova variavel coluna
        columns[currNumColumns] = columnData;

        currNumColumns++;
        // Arranjar espaço para mais uma linha
        columns = (char **) realloc(columns, currNumColumns*sizeof(char *));

    }

    //columns = (char **) realloc(columns, currNumColumns*sizeof(char *));
    columns[currNumColumns] = NULL;
    free(copiedLine);
    return columns;
}
