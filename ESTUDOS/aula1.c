#include <stdio.h>
#include <string.h>

/*
Um registro é uma coleção de variáveis, possivelmente de tipos diferentes. Cada
uma dessas variáveis é um campo do registro. Na linguagem C, registros são
conhecidos como structs (abreviatura de structures).

O exemplo abaixo declara um registro x com três campos inteiros:
    struct {
        int dia, mês, ano;
    } x;

É uma boa ideia dar um nome dma, por exemplo ao tipo de registro:

    struct dma {
        int dia, mês, ano;
    };

struct dma x;
struct dma y;

Use o operador ponto (.) para atribuir valores aos campos do registro:
x.dia = 31; x.mês = 12; x.ano = 2008;

As structs surgem no contexto de suprir a necessidade de criar novos tipos de dados chamados dados complexos, que guardam dados de tipos diferentes,
como C não possui classes, structs vêm para agrupar dados diferentes mas relacionados, organizar melhor o código e criar tipos complexos, 
como modelos de objetos (“Aluno”, “Carro”, “Produto”)..
*/

// Criação de um tipo de dado "Student" que agrupa dados do tipo: char, int e float
struct Student {
    char name[50];
    int age;
    float grade;
};

int main(){

    // Declaração da struct
    struct Student student1;

    // Atribuição de valores aos tipos de dados da struct "Student"
    strcpy(student1.name, "Igor");
    student1.age = 19;
    student1.grade = 10.00;

    printf(
        "Name: %s / Age: %d / Grade: %.2f \n", student1.name, student1.age, student1.grade
    );

    printf("\n");

    // Declaração de valores vindo de inputs
    char name[50];
    int age;
    float grade;

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter age: ");
    scanf(" %d", &age);

    printf("Enter grade: ");
    scanf(" %f", &grade);

    strcpy(student1.name, name);
    student1.age = age;
    student1.grade = grade;

    printf("\n");

    printf(
        "Name: %s / Age: %d / Grade: %.2f \n", student1.name, student1.age, student1.grade
    );
}
