#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Fac¸a um programa que armazene em um registro de dados (estrutura composta) os dados de um funcionario de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, ´
Data de Nascimento, Cargo que ocupa (string de ´ate 30 caracteres) e Sal ´ ario. Os dados devem ser digitados pelo usu ´ ario, armazenados ´
na estrutura e exibidos na tela.
*/

// Limpar o buffer
void flushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

// Estrutura de um funcionário
typedef struct {

    char name[50];
    int age;
    char sex;
    char CPF[15];
    char birthdate[11];
    char position[30];
    int salary;

}employee;

// Função para entrada dos nomes dos funcionários
int GetName(employee *var){

    // Entrada de nome
    printf("Enter name: ");
    fgets(var->name, sizeof(var->name), stdin);
    var->name[strcspn(var->name, "\n")] = '\0';

    // Verificação para não ter digito no nome
    for (int i = 0; var->name[i] != '\0'; i++){
        if (var->name[i] >= '0' && var->name[i] <= '9'){
            return 0;
        }
    }

    return 1;
}

// Função para entrada das idades dos funcionários
int GetAge(employee *var){

    // Entrada de idade
    printf("Enter age: ");
    // Verificação para saber se scanf receberá um dado tipo int
    if (scanf(" %d", &var->age) == 0){
        flushBuffer();
        return 0;
    }

    flushBuffer();

    // Verificação para prevenir entrada de números menores que 18 ou maiores que 65
    if (var->age < 18 || var->age > 65){
        return 0;
    }

    return 1;
}

// Entrada de dado referente ao sexo do funcionário
int GetEmpSex(employee *var){

    // vetor temporário usado na verificação para limitar a entrada de apenas um char
    char buffer[10];

    printf("Enter Emplyoee sex: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    // verificação para limitar a entrada de apenas um char
    if (strlen(buffer) != 1){
        return 0;
    }

    var->sex = buffer[0];

    return 1;
    
}

int GetCPF(employee *var){

    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 
    // x x x . x x x . x x x - x x

    printf("Enter CPF as (xxx.xxx.xxx-xx): ");
    fgets(var->CPF, sizeof(var->CPF), stdin);
    var->CPF[strcspn(var->CPF, "\n")] = '\0';

    if (var->CPF[3] != '.' || var->CPF[7] != '.' || var->CPF[11] != '-'){
        return 0;
    }

    int buffer[] = {0,1,2,4,5,6,8,9,10,12,13};

    for (int i = 0; i < 11; i++) {
        char c = var->CPF[buffer[i]];
        if (c < '0' || c > '9') {
            return 0;
        }
    }

    flushBuffer();

    return 1;

}

int GetBirthdayDate(employee *var){

    // 0 1 2 3 4 5 6 7 8 9
    // x x / x x / x x x x

    printf("Enter date of birth as (xx/xx/xxxx): ");
    fgets(var->birthdate, sizeof(var->birthdate), stdin);
    var->birthdate[strcspn(var->birthdate, "\n")] = '\0';

    if (var->birthdate[2] != '/' || var->birthdate[5] != '/'){
        return 0;
    }

    int buffer[] = {0, 1, 3, 4, 6, 7, 8, 9};

    for (int i = 0; i < 8; i++){
        char c = var->birthdate[buffer[i]];
        if (c < '0' || c > '9'){
            return 0;
        }
    }

    flushBuffer();

    return 1;
}

int GetPosition(employee *var){

    printf("Enter job title: ");
    fgets(var->position, sizeof(var->position), stdin);
    var->position[strcspn(var->position, "\n")] = '\0';

    for (int i = 0; var->position[i] != '\0'; i++){
        if (var->position[i] >= '0' && var->position[i] <= '9'){
            return 0;
        }
    }

    return 1;
}

int GetSalary(employee *var){

    printf("Enter salary: ");
    if (scanf(" %d", &var->salary) == 0){
        flushBuffer();
        return 0;
    }

    flushBuffer();

    return 1;
}

int main(){

    int empnum;
    employee *var;

    // Entrada do número de estruturas que irão ser criadas de forma dinamica
    printf("Enter number of employees: ");
    //Verificação para saber se scanf receberá um dado tipo int
    if (scanf(" %d", &empnum) == 0){flushBuffer(); printf("Error! \n");  return 0;}
    flushBuffer();
    
    printf("\n");

    // Alocação de structs na heap da memória 
    var = malloc(empnum * sizeof(employee));
    // tratamento de erro de alocação de memória
    if (var == NULL){printf("Error to allocate memory! \n"); return 0;}

    // Funções para entrada de dados em cada struct
    for (int i = 0; i < empnum; i++){

        printf("---- Data Entry for %d Emplyoee ---- \n", i + 1);

        if (!GetName(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetAge(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetEmpSex(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetCPF(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetBirthdayDate(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetPosition(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        if (!GetSalary(&var[i])){
            printf("Invalid Entry! \n");
            free(var);
            return 0;
        }

        printf("\n");
        
    }

    system("cls");

    // Display nos dados que foram entrados em cada struct
    printf("=== Emplyoees hired ===\n");
    for (int i = 0; i < empnum; i++){
        
        printf("EMPLOYEE NAME: %s \n", var[i].name);
        printf("EMPLYOYEE AGE: %d \n", var[i].age);
        printf("EMPLOYEE SEX: %c \n", var[i].sex);
        printf("EMPLOYEE CPF: %s \n", var[i].CPF);
        printf("EMPLOYEE BIRTHDAY: %s \n", var[i].birthdate);
        printf("EMPLOYEE POSITION: %s \n", var[i].position);
        printf("EMPLOYEE SALARY: %d \n", var[i].salary);
        printf("-------------------------\n");
    }

    free(var);
}
