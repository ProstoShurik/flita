#include <stdio.h>
#include <stdlib.h>

int main(){
    int counter=0;
    int s=0;
    char c;
    FILE *file1=fopen("list_of_edges181.txt", "r");
    if (!file1)
    exit(EXIT_FAILURE);
    c=fgetc(file1);
    while(c!=EOF){
        if(c=='\n'){
            counter++;
            printf("N counter %d \n",counter);
        }
        c=fgetc(file1);
    }
    fclose(file1);
    //counter++;
    s=counter;
    
    //s=s/4;
    int matrix[100][2];
    int i, j, k;
    FILE* file = fopen("list_of_edges181.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file); i++)
    {
        for (j = 0; j < 2 && !feof(file); j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(file);
    FILE* out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");

    for (i = 0; i < (s); i++)
    {

        fprintf(out, "%d -- %d", matrix[i][0], matrix[i][1]);
        fprintf(out, "\n");

    }
    fprintf(out, "}\n");
    fclose(out);
    system("dot output.dot -Tpng -o image.png");
    return (EXIT_SUCCESS);
}