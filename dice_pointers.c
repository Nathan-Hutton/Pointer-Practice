#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rollDice(int *first, int *second, int *third);

int main()
{
    printf("Dice roll! I am rolling four dice and dropping the lowest\n\n");
    int first_die, second_die, third_die;
    int total = rollDice(&first_die, &second_die, &third_die);
    printf("%d!\n%d!\n%d!\n\n", first_die, second_die, third_die);
    printf("%d + %d + %d = %d", first_die, second_die, third_die, total);
    printf("\n");
    return 0;
}

int rollDice(int *first, int *second, int *third)
{
    srand(time(NULL));
    int rand_nums[4];
    for(int i = 0; i < 4; i = i + 1)
    {
      rand_nums[i] = rand() % 6 + 1;
    }
    int smallest_die = 0;
    for(int i = 0; i < 4; i = i + 1)
    {
        if(rand_nums[i] < rand_nums[smallest_die])
        {
            smallest_die = i;
        }
    }
    int temp = rand_nums[3];
    rand_nums[3] = rand_nums[smallest_die];
    rand_nums[smallest_die] = temp;
    *first = rand_nums[0];
    *second = rand_nums[1];
    *third = rand_nums[2];
    return  rand_nums[0] + rand_nums[1] + rand_nums[2];
}
