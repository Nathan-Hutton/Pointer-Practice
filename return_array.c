#include <stdio.h>
#include <stdlib.h>

double *inputDoubleArray(int *n);

int main()
{
    int num_numbers;
    double sum;
    double *pointer = inputDoubleArray(&num_numbers);
    //printf("%f", pointer[5]);
    for(int i = 0; i < num_numbers; i = i + 1)
    {
        sum = sum + pointer[i];
    }
    printf("\nThe sum is %f.", sum);
    printf("\nThe average is %f.\n", sum / num_numbers);
    free(pointer);
    return 0;
}

double *inputDoubleArray(int *n)
{
    //printf("How many numbers do you have? ");
    //scanf("%d", n);
    // double *ptr = (double*) malloc(*n * sizeof(double));
    *n = 5;
    double *ptr = (double*) malloc(*n * sizeof(double));
    printf("Enter numbers seperated by spaces. End with a zero followed by any value (like 1 2 3 4 0 a):\n    ");

    //for(int i = 0; i < *n; i = i + 1)
    int i = 0;
    double user_input;
    while(user_input != 0.0)
    {
        if(i % 5 == 0)
        {
            *n = *n + 5;
            ptr = realloc(ptr, *n *  sizeof(double));
        }
        // printf("%lf ", user_input);
        scanf("%lf ", &user_input);
        if(user_input == 0)
        {
            break;
        }
        //scanf("%lf ", &user_input);
        ptr[i] = user_input;
        i = i + 1;
    }
    *n = i;
    return ptr;
}
