#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Escreva um trecho de codigo para fazer a criac¸ ´ ao dos novos tipos de dados conforme ˜
solicitado abaixo:
    1- Horario: composto de hora, minutos e segundos.
    2- Data: composto de dia, mes e ano.
    3- Compromisso: composto de uma data, horario e texto que descreve o compromisso.
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

typedef struct {

    int hour;
    int minute;
    int second;

}Time;

typedef struct{

    int day;
    int month;
    int year;

}Date;

typedef struct {
    
    Time time;
    Date date;
    char note[100];

}Schedule;


int DisplayTime(Time *tme){

    printf("Enter value for hour: ");
    if (scanf(" %d", &tme->hour) == 0){
        FlushBuffer();
        return 0;
    }

    if (tme->hour < 0 || tme->hour > 24){
        return 0;
    }

    printf("Enter value for minute: ");
    if (scanf(" %d", &tme->minute) == 0){
        FlushBuffer();
        return 0;
    }

    if (tme->minute < 0 || tme->minute > 59){
        return 0;
    }

    printf("Enter value for second: ");
    if (scanf(" %d", &tme->second) == 0){
        FlushBuffer();
        return 0;
    }

    if (tme->second < 0 || tme->second > 59){
        return 0;
    }

    printf("TIME: %.2d:%.2d:%.2d \n", tme->hour, tme->minute, tme->second);

    printf("\n");

    return 1;
}


int DisplayDate(Date *dte){

    printf("Enter value for day: ");
    if (scanf(" %d", &dte->day) == 0){
        FlushBuffer();
        return 0;
    }

    if (dte->day > 31 || dte->day < 1){
        return 0;
    }

    printf("Enter value for month: ");
    if (scanf(" %d", &dte->month) == 0){
        FlushBuffer();
        return 0;
    }

    if (dte->month > 12 || dte->month < 1){
        return 0;
    }

    printf("Enter value for year (2020 - 2025): ");
    if (scanf(" %d", &dte->year) == 0){
        FlushBuffer();
        return 0;
    }

    if (dte->year > 2025 || dte->year < 2020){
        return 0;
    }

    printf("DATE: %.2d/%.2d/%.4d \n", dte->day, dte->month, dte->year);

    printf("\n");

    return 1;
}

int DisplaySchedule(Schedule *sch){

    FlushBuffer();

    printf("Enter short text for schedule note: ");
    fgets(sch->note, sizeof(sch->note), stdin);
    sch->note[strcspn(sch->note, "\n")] = '\0';
    
    DisplayTime(&sch->time);

    DisplayDate(&sch->date);

    printf("NOTE: %s \n", sch->note);

    return 1;
}

int main(){

    Time tme;
    Date dte;
    Schedule sch;

    DisplayTime(&tme);
    DisplayDate(&dte);
    DisplaySchedule(&sch);
}