#include <stdio.h>

/*
Escreva uma função que receba dois structs do tipo dma, cada um representando
uma data válida, e devolva o número de dias que decorreram entre as duas datas.
*/

struct Data1 {
    int day;
    int month;
    int year;
};

struct Data2 {
    int day;
    int month;
    int year;
};


int main(){

    // Declaração das structs
    struct Data1 dma1;
    struct Data2 dma2;

    // Atribução de valores a data 1
    printf("Enter day for date 1: ");
    scanf(" %d", &dma1.day);

    printf("Enter month for date 1: ");
    scanf(" %d", &dma1.month);

    printf("Enter year for date 1: ");
    scanf(" %d", &dma1.year);

    printf("\n");

    // Atribuição de valores a data 2
    printf("Enter day for date 2: ");
    scanf(" %d", &dma2.day);

    printf("Enter month for date 2: ");
    scanf(" %d", &dma2.month);

    printf("Enter year for date 2: ");
    scanf(" %d", &dma2.year);

    printf("\n");

    printf("DATE 1: %d/%d/%d \n", dma1.day, dma1.month, dma1.year);

    printf("\n");

    printf("DATE 2: %d/%d/%d \n", dma2.day, dma2.month, dma2.year);

    printf("\n");

    // Calculo dos anos 1 e 2
    int diffyear = dma1.year - dma2.year;

    diffyear = diffyear * 365; // resultado em dias

    // Calculo dos meses 1 e 2
    int diffmonth = (dma1.month - dma2.month) * 30;

    // Calculo de dias 
    int diffday = dma1.day - dma2.day;

    // soma total de dias
    int sum;

    sum = (diffday + diffmonth + diffyear);

    printf("Total sum of days between date 1 and date 2: %d \n", sum); 

}