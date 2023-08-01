/*  PROGRAM CALCULATES THE NUMBER OF YEARS TAKEN TO REACH A CERTAIN POPULATION COUNT.
    THE STARTING POPULATION SIZE MUST NOT BE LESS THAN 9.
    THE END POPULATION SIZE MUST BE NOT LESS THAN THE STARTING SIZE.
    EVERY YEAR 1/3 OF THE POPULATION INCREASES, WHILE 1/4 OF THE POPULATION DECREASES.
*/

#include <cs50.h>
#include <stdio.h>

int get_startSize(int limit);
int get_endSize(int limit);

int growth_time(int start_size, int end_size);

int main(void)
{
    int start_size, end_size;
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    }
    // RE-PROMPT UNLESS THE INPUT IS APPROPRIATE
    while (start_size < 9);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    // RE-PROMPT UNLESS THE INPUT IS APPROPRIATE
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = growth_time(start_size, end_size);
    // TODO: Print number of years
    printf("Years: %d\n", years);
}

// calculates the number of years taken to reach the end population
int growth_time(int start_size, int end_size)
{
    int size = start_size, years = 0;
    int birth_count, death_count;

    while (size < end_size)
    {
        // increase in population
        birth_count = size / 3;

        // decrease in population
        death_count = size / 4;

        // overall change in population
        size = size + birth_count - death_count;

        years++;
    }
    return years;
}
