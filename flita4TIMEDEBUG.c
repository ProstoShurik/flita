#define _CRT_SECURE_NO_WARNINGS
#define MAX_BOARD 10000
#define MATRIX_LEN 100000
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    int max = 0;
    int counter = 0;
    int asoc_counter = 0;
    int s = 0;
    int dots = 0;
    int association[MAX_BOARD] = { 0 };
    char c;
    int EdgeCount = 0;
    int Graph = 0;
    int i;
    printf("How many edges will be?\n");
    scanf("%d", &EdgeCount);
    printf("How many connections will be?\n");
    scanf("%d", &Graph);
    printf("%d\n", EdgeCount);
    printf("%d\n", Graph);

    FILE* out1;
    out1 = fopen("list_of_edges98.txt", "w");
    for (i = 0; i < Graph; i++) {
        fprintf(out1, "%d %d\n", rand() %10000, rand()%10000 );
    }
    fclose(out1);

    FILE* file = fopen("list_of_edges98.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    c = fgetc(file);
    while (c != EOF)
    {
        if (c == '\n')
        {
            counter++;
        }
        c = fgetc(file);
    }
    fclose(file);

    s = counter;
    int matrix[MATRIX_LEN][2];
    int count_arr[MAX_BOARD] = { 0 };
    long  j;
    
    FILE* file1 = fopen("list_of_edges98.txt", "r"); 
    if (!file1)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file1); i++)
    {
        for (j = 0; j < 2&&!feof(file1); j++)
        {

            fscanf(file1, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
            if (dots < matrix[i][j])
            {
                dots = matrix[i][j];
            }
        }
        putchar('\n');
    }
    fclose(file1);
    FILE* out;
    out = fopen("output.dot", "w");
    clock_t start = clock();
    fprintf(out, "graph{\n");
    for (int out_bord = 0; out_bord < MAX_BOARD; out_bord++) {
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < 2; j++) {
                if (matrix[i][j] == out_bord) {
                    count_arr[out_bord] += 1;
                }
            }


        }
        if (count_arr[out_bord] == max) {
            association[asoc_counter++] = out_bord;
        }
        if (count_arr[out_bord] > max) {
            
            memset(association, 0, asoc_counter);
            asoc_counter = 0;

            max = count_arr[out_bord];
            association[asoc_counter++] = out_bord;
        }
        

    }
    clock_t end = clock();
    float clocks = end - start;
    clocks /= CLOCKS_PER_SEC;
    
    printf("CLOCKS %f \n", clocks);
    printf("%d Maximal degree of edge \n Edge ", max);
    for (i = 0; i < asoc_counter; i++) {
        printf("%d ,",association[i]);
    }
    for (i = 0; i < (s); i++)
    {

        fprintf(out, "%d -- %d", matrix[i][0], matrix[i][1]);
        fprintf(out, "\n");

    }
    fprintf(out, "}\n");
    fclose(out);
    //system("dot output.dot -Tpng -o image.png");
    for (i = 0; i < s; i++)
    {
        if (matrix[i][0] == matrix[i][1])
        {
            counter--;
        }
        if (i > 0 && matrix[i][0] == matrix[i - 1][0] && matrix[i][1] == matrix[i - 1][1])
        {
            counter--;
        }
    }

    dots++;
    printf("Number of dots = %d Number of connections = %d\n", dots, counter);
    if (counter > ((dots - 1) * (dots - 2) / 2))
    {
        printf("This is a connected graph\n");
    }
    else
    {
        printf("This is a disconnected graph\n");
    }

    return (EXIT_SUCCESS);
}
