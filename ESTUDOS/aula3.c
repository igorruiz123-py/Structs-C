#include <stdio.h>
#include <stdlib.h>

// Structs criadas dinamicamente

/*
Define a struct normalmente e depois cria um vetor dinâmico dessa struct usando malloc
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

typedef struct{

    char name[50];
    int age;

}Person;

int main(){

    int num;
    Person *people;

    printf("Enter number of people: ");
    scanf(" %d", &num);
    FlushBuffer();

    printf("\n");

    people = malloc(num * sizeof(Person));

    if (people == NULL){
        printf("Error to allocate memory! \n");
    }

    for (int i = 0; i < num; i++){
        printf("Enter name for person %d: ", i + 1);
        fgets(people[i].name, sizeof(people[i].name), stdin);

        printf("Enter age for person %d: ", i + 1);
        scanf(" %d", &people[i].age);
        FlushBuffer();

        printf("\n");

    }

    printf("\n");

    printf("=== People enrolled ===\n");
    for (int i = 0; i < num; i++) {
        printf("Nome: %s", people[i].name);
        printf("Idade: %d\n", people[i].age);
        printf("-------------------------\n");
    }

    free(people);

    return 0;
}