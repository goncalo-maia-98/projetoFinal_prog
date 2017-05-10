#include <string.h>
#include <math.h>
#include <ctype.h>


//data
typedef struct
{
    int day;
    int month;
    int year;
}ddate;

//horas
typedef struct
{
    int hours;
    int minutes;
}ttime;

//estaçao
typedef struct
{
    int id;
    char terminal[7];
    char *name;
    char municipal[20];
    float latitude;
    float longitude;
    int status; //ou foi removida (0) ou ainda exite (1)
}Station;

//lista das estaçoes



//dados do utilizador
typedef struct
{
    int type;       //tipo de utilizador casual (0) ou registado (1)
    int birth_year; //apenas tem informaçao se for registado
    int gender;     //apenas tem informaçao se for registado
}person;


//Estrutura com informaçao da viagem
typedef struct trip
{
    int trip_id;
    int duration;
    ddate d_start;
    ttime t_start;
    ddate d_end;
    ttime t_end;
    char bike_id[6];
    person user;
    Station *s_start;
    Station *s_end;
}cdas;


typedef struct node
{
    struct  trip trip_data;
    struct  trip *next;
    struct  trip *prev;
}tnode;
