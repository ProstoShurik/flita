#include <stdio.h>
#include <stdlib.h>

int main(){
    int counter=0;
    int s=0;
    int dots=0;
    char c;
    FILE *file=fopen("list_of_edges70.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    c=fgetc(file);
    while(c!=EOF)
    {
        if(c=='\n')
        {
            counter++;
        }
        c=fgetc(file);
    }
    fclose(file);

    s=counter;
    int matrix[100][2];
    int i, j;
    FILE* file1 = fopen("list_of_edges70.txt", "r");
    if (!file1)
        exit(EXIT_FAILURE);
    for (i = 0; i < s && !feof(file1); i++)
    {
        for (j = 0; j < 2 && !feof(file1); j++)
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
