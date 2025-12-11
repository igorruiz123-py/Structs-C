#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ponteiros com Structs

/*
Ponteiros de structs guardam o endereço dessa struct.

Junta-se structs com ponteiros para:
    1- evitar cópias enormes de dados (quando uma struct é copiada para um função, milhares de bytes são duplicados. Com ponteiros apenas endereços são trabalhados)
    2- Modificar dados internos de structs, precisamos fazer por meio de funções, porém sem ponteiros, iriamos apenas modificar as cópias dos dados das structs
    3- Criar structs dinâmicamente. Quando não sabemos de antemão quantos dados precisamos ter em uma struct, fazemos alocação de memória com malloc
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

// defina o tipo de dado "Person"
typedef struct{
    char name[50];
    int age;

}Person;

// Passa como parâmetro o ponteiro da variável do tipo criado 
void DisplayNameAndAge(Person *person){

    // para acessar os atributos do ponteiro do "objeto" utiliza-se "->" em ivés de "." 
    printf("Enter name: ");
    fgets(person->name, sizeof(person->name), stdin);
    person->name[strcspn(person->name, "\n")] = '\0';

    printf("Enter age: ");
    scanf(" %d", &person->age);

    FlushBuffer();

    printf("\n");

    printf("Name: %s / Age: %d \n", person->name, person->age);

    printf("\n");
}

int main(){

    // declaração de variáveis do tipo de dado criado pela struct
    Person person1;
    Person person2;

    // Passa os endereços dessas variáeis
    DisplayNameAndAge(&person1);
    DisplayNameAndAge(&person2);

}