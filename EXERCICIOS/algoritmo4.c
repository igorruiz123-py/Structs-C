#include <stdio.h>
#include <string.h>

/*
Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matr´ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.

    1- Permita ao usuario entrar com os dados de 5 alunos.
    2- Encontre o aluno com maior nota da primeira prova.
    3- Encontre o aluno com maior media geral.
    4- Encontre o aluno com menor media geral.
    5- Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
    aprovac¸ao
*/

void FlushBuffer(){
    int temp = 0;

    while((temp = getchar()) != '\n' && temp != EOF){};
}

typedef struct {

    char names[5][50];
    int grades1[5];
    int grades2[5];
    int grades3[5];

}math;

int DisplayData(math *p){

    // Entrada de dados dos nomes dos alunos
    for (int i = 0; i < 5; i++){
        printf("Enter name: ");
        fgets(p->names[i], sizeof(p->names[i]), stdin);
        p->names[i][strcspn(p->names[i], "\n")] = '\0';

        // Verificação para impedir de ser inserido digitos
        if (p->names[i][0] >= '0' && p->names[i][0] <= '9'){
            return 0;
        }
    }

    printf("\n");

    printf("1 TEST: \n");

    // Entrada de dados das notas da 1° prova
    for (int i = 0; i < 5; i++){
        printf("Enter value for grade from student %s: ", p->names[i]);
        // verificação para impedir de ser inserido chars
        if (scanf(" %d", &p->grades1[i]) == 0){
            FlushBuffer();
            return 0;
        }
    }

    // Limpar o buffer depois do 1° scanf
    FlushBuffer();

    printf("\n");

    printf("2 TEST: \n");

    // Entrada de dados da 2º prova
    for (int i = 0; i < 5; i++){
        printf("Enter value for grade from student %s: ", p->names[i]);
        // Verificação para impedir de ser inseridos chars
        if (scanf(" %d", &p->grades2[i]) == 0){
            FlushBuffer();
            return 0;
        }
    }

    // Limpar o buffer deoois do 2º scanf
    FlushBuffer();

    printf("\n");

    printf("3 TEST: \n");

    // Entrada de dados da 3º prova
    for (int i = 0; i < 5; i++){
        printf("Enter value for grade from student %s: ", p->names[i]);
        // Verificação para impedir de ser inserido chars
        if (scanf(" %d", &p->grades3[i]) == 0){
            FlushBuffer();
            return 0;
        }
    }

    // Limpar o buffer do 3° scanf
    FlushBuffer();

    printf("\n");

    // CALCTASKS

    // (TASK 1) Aluno com a maior nota da 1º prova

    int target1 = 0;
    int index1 = 0;
    for (int i = 0; i < 5; i++){
        // Encontrar a maior nota por comparação
        if (p->grades1[i] > target1){
            target1 = p->grades1[i];
            index1 = i;
        }
    }

    // Match da maior nota com o nome do aluno por indices
    printf("The student with the highest grade from 1 test is: %s \n", p->names[index1]);

    printf("\n");

    // (TASK 2) Encontrar o aluno com a maior média geral
    
    // Criar novo vetor para suportar as médias
    float means[5];

    printf("MEANS: \n");

    for (int i = 0; i < 5; i++){
        // Inserir os valores para o vetor das médias (novos valores serão a soma dos outros 3 vetores de notas)
        means[i] = p->grades1[i] + p->grades2[i] + p->grades3[i];
        means[i] = means[i] / 3;
        printf("means[%d] = %.2f \n", i, means[i]);
    }

    printf("\n");

    // Encontrar a maior média 
    int target2 = 0;
    int index2 = 0;

    for (int i = 0; i < 5; i++){
        // Encontrar a maior nota por comparação
        if (means[i] > target2){
            target2 = means[i];
            index2 = i;
        }
    }

    // Match da maior média com o nome do aluno por indices
    printf("The student with the highest means is: %s \n", p->names[index2]);

    printf("\n");

    // (TASK 3) Encontrar o aluno com a menor média geral

    // Encontrar a menor média
    int target3 = 100;
    int index3 = 0;

    for (int i = 0; i < 5; i++){
        // Encontrar a menor nota por comparação
        if (means[i] < target3){
            target3 = means[i];
            index3 = i;
        }
    }

    // Match da menor média com nome do aluno por indices
    printf("The student with the lowest mean is: %s \n", p->names[index3]);

    printf("\n");

    // (TASK 4) Verificar se aluno está aprovado >= 6 ou reprovado < 6

    // Display nos aprovados
    for (int i = 0; i < 5; i++){
        if (means[i] >= 6){
            printf("APROVED STUDENT: %s \n", p->names[i]);
        }
    }

    printf("\n");

    // Display nos reprovados
    for (int i = 0; i < 5; i++){
        if (means[i] < 6){
            printf("REPROVED STUDENT: %s \n", p->names[i]);
        }
    }

    printf("\n");

    return 1;
}

int main(){

    math var;

    if (DisplayData(&var)){

    }
    else {
        printf("Error! \n");
    }
}