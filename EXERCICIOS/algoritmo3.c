#include <stdio.h>
#include <string.h>

/*
Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
armazene os dados em uma estrutura.
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

typedef struct {

    char name[50];
    int age;
    char addrr[100];

}data;

int DisplayData(data *p){

    printf("Enter name: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    for (int i = 0; p->name[i] < 50; i++){
        if (p->name[i] >= '0' && p->name[i] <= '9'){
            return 0;
        }
    }

    printf("Enter value for age: ");
    if (scanf(" %d", &p->age) == 0){
        FlushBuffer();
        return 0;
    }

    FlushBuffer();

    printf("Enter address (ciy and country name): ");
    fgets(p->addrr, sizeof(p->addrr), stdin);
    p->addrr[strcspn(p->addrr, "\n")] = '\0';

    for (int j = 0; p->addrr[j] < 100; j++){
        if (p->addrr[j] >= '0' && p->addrr[j] <= '9'){
            return 0;
        }
    }

    printf("\n");

    return 1;
}

int main(){

    data PersonInfo;

    if (DisplayData(&PersonInfo)){

        printf("NAME: %s \n", PersonInfo.name);
        printf("AGE: %d \n", PersonInfo.age);
        printf("ADDRESS: %s \n", PersonInfo.addrr);
    }
    else{
        printf("error \n");
    }
}