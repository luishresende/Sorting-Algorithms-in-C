#include <stdio.h>
#include <stdlib.h>
#include "Auxiliar.h"
#include <time.h>
#include <string.h>

double bubble_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }

    fclose(file);

    clock_t start_time = clock();

    int aux;
    for(int x = count-1; x >= 1; x--){
        for(int y = 0; y <= x-1; y++){
            if(numbers[y] > numbers[y+1]){
                aux = numbers[y];
                numbers[y] = numbers[y+1];
                numbers[y+1] = aux;
            }
        }
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");
    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

double insertion_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);

    clock_t start_time = clock();

    int aux, atual, index;
    for(int i = 1; i < count; i++){
        atual = numbers[i];
        index = i-1;

        while(index >= 0 && atual < numbers[index]){
            numbers[index + 1] = numbers[index];
            index--;
        }
        numbers[index+1] = atual;
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

double selection_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);


    clock_t start_time = clock();

    int i, j, menor, troca;
    for (i = 0; i < count; i++){
        menor = i;
        for (j = i+1; j < count; j++){
            if(numbers[j] < numbers[menor]){
                menor = j;
            }
        }
        troca = numbers[i];
        numbers[i] = numbers[menor];
        numbers[menor] = troca;
    }

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

double shell_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);



    clock_t start_time = clock();

    int h;
    for(h = 1; h < count; h = 3*h+1);

    while(h > 0){
        h = (h - 1) / 3;
        for(int i = h; i < count; i++){
            int aux = numbers[i];
            int j = i;

            while(numbers[j-h] > aux){
                numbers[j] = numbers[j-h];
                j -= h;
                if(j < h){
                    break;
                }
            }
            numbers[j] = aux;
        }
    }

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

double quick_sort(char file_path[100], int replace){
      FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);

    clock_t start_time = clock();

    // Função a ser executada

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

double merge_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);

    clock_t start_time = clock();

    merge_sort_execute(numbers, 0, count-1);

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;


    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

//https://www.scaler.com/topics/heap-sort-program-in-c/
double heap_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);

    clock_t start_time = clock();

    for(int i = count / 2 - 1; i >= 0; i--){
        heap_sort_execute(numbers, count, i);
    }

    for (int i = count - 1; i >= 0; i--) {
      trocar(&numbers[0], &numbers[i]);

      heap_sort_execute(numbers, i, 0);
    }

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

//https://www.programiz.com/dsa/radix-sort
double radix_sort(char file_path[100], int replace){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int *numbers = NULL; // Ponteiro para o array de n�meros
    int count = 0; // Contador de n�meros
    int num;

    // L� os n�meros do arquivo e conta quantos n�meros existem
    while (fscanf(file, "%d", &num) == 1) {
        count++;
        // Realoca o array para acomodar o novo n�mero
        numbers = (int *)realloc(numbers, count * sizeof(int));
        numbers[count - 1] = num;
    }
    fclose(file);

    clock_t start_time = clock();

    int max = getMax(numbers, count);

    for (int place = 1; max / place > 0; place *= 10)
        radix_sort_execute(numbers, count, place);

    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    char new_file_name[50] = "finished_";
    strcat(new_file_name, file_path);
    file = fopen(new_file_name, "w");

    for(int i = 0; i < count; i++){
        fprintf(file, "%d\n", numbers[i]);
    }

    free(numbers);
    fclose(file);
    return elapsed_time;
}

void executar_ordenacao(int metodo, char arquivo[]){
    printf("Ordenando arquivo: '%s', aguarde...\n", arquivo);
    switch(metodo){
    case 1:
        printf("Tempo de execucao: %lf\n", bubble_sort(arquivo, 0));
        break;

    case 2:
        printf("Tempo de execucao: %lf\n", insertion_sort(arquivo, 0));
        break;

    case 3:
        printf("Tempo de execucao: %lf\n", selection_sort(arquivo, 0));
        break;

    case 4:
        printf("Tempo de execucao: %lf\n", shell_sort(arquivo, 0));
        break;

    case 5:
        printf("Tempo de execucao: %lf\n", quick_sort(arquivo, 0));
        break;

    case 6:
        printf("Tempo de execucao: %lf\n", merge_sort(arquivo, 0));
        break;

    case 7:
        printf("Tempo de execu��o: %lf\n", heap_sort(arquivo, 0));
        break;

    case 8:
        printf("Tempo de execu��o: %lf\n", heap_sort(arquivo, 0));
        break;
    }
    printf("Resultado salvo em: 'finished_%s'!\n", arquivo);
}

int main(){
    printf("Programa de Ordena��o de Dados!\n\n");
    int metodo, tipo_arquivo, arquivo_escolhido, continuar, quant_arquivos = 15;
    char arquivos_padroes[15][30] = {
        "odernate100k.txt",
        "odernate200k.txt",
        "odernate300k.txt",
        "odernate500k.txt",
        "odernate1kk.txt",
        "unodernate100k.txt",
        "unodernate200k.txt",
        "unodernate300k.txt",
        "unodernate500k.txt",
        "unodernate1kk.txt",
        "rand100k.txt",
        "rand200k.txt",
        "rand300k.txt",
        "rand500k.txt",
        "rand1kk.txt"
    };
    char nome_arquivo[100];
    while(1){
        do{
            printf("Escolha um m�todo de ordena��o:\n"
                   "1 - Bubble Sort\n"
                    "2 - Insertion Sort\n"
                    "3 - Selection Sort\n"
                    "4 - Shell Sort\n"
                    "5 - Quick Sort\n"
                    "6 - Merge Sort\n"
                    "7 - Heap Sort\n"
                    "8 - Radix Sort\n"
                    "Alternativa: ");
            scanf("%d", &metodo);
            if(metodo < 1 || metodo > 8){
                printf("Metodo invalido! Tente novamente.\n");
                system("pause");
                system("cls");
            }
        } while(metodo < 1 || metodo > 8);

        do{
            printf("Voce deseja informar um novo arquivo ou utilizar um dos arquivos padroes?\n"
                   "1 - Arquivo padrao\n"
                   "2 - Novo arquivo\n"
                   "Alternativa: ");
            scanf("%d", &tipo_arquivo);
            if(tipo_arquivo < 1 || tipo_arquivo > 2){
                printf("Tipo invalido! Tente novamente.\n");
                system("pause");
                system("cls");
            }
        }while(tipo_arquivo < 1 || tipo_arquivo > 2);

        if(tipo_arquivo == 2){
            printf("Informe o caminho do arquivo: ");
            scanf(" %[^\n]", nome_arquivo);
        }else{
            do{
                printf("Escolha um arquivo:\n");
                for(int i = 0; i < quant_arquivos; i++){
                    printf("%d - %s\n", i+1, arquivos_padroes[i]);
                }
                printf("Alternativa: ");
                scanf("%d", &arquivo_escolhido);
                if(arquivo_escolhido < 1 || arquivo_escolhido > quant_arquivos){
                    printf("Alternativa invalida! Tente novamente.\n");
                    system("pause");
                    system("cls");
                }
            } while(arquivo_escolhido < 1 || arquivo_escolhido > quant_arquivos);
            strcpy(nome_arquivo, arquivos_padroes[arquivo_escolhido-1]);
        }
        system("cls");
        executar_ordenacao(metodo, nome_arquivo);
        printf("Entre com '1' para continuar: ");
        scanf("%d", &continuar);
        if(continuar != 1){
            break;
        }else {
            system("cls");
        }
    }

    return 0;
}

