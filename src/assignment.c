#include <stdio.h>

#include <constants.h>
#include <domain.h>
#include <services.h>
#include <ui.h>

int main()
{
    printf("Menu\n");

    int user_option;

    while (1)
    {
        display_menu();
        printf("Options (1-5): ");
        scanf("%d", &user_option);

        switch (user_option)
        {
        case 1:
            printf("Reading a Vector of Numbers from Console\n");

            int vector_of_numbers[MAX_VECTOR_SIZE];
            int hit = read_num_vector_console(vector_of_numbers);
            display_num_vector_console(vector_of_numbers, hit);

            break;
        case 2:
            printf("Maxes of Sequences, Global Max\n");

            struct sequences_maxes maxes = maxes_of_sequences();
            display_maxes_of_sequences(maxes);

            int global_max = max_of_sequences_maxes(maxes);
            display_global_max(global_max);

            break;
        case 3:
            printf("Longest Subsequence with values in Interval\n");

            int numbers[MAX_VECTOR_SIZE];
            int hit_numbers = read_num_vector_console(numbers);

            struct pair interval;
            printf("interval: \n");
            scanf("%d %d", &interval.first, &interval.second);

            struct lsi lsi = longest_subsequence_interval(numbers, hit_numbers, interval);
            if (lsi.len == 0)
            {
                printf("No LSI found.\n");
                break;
            }
            display_num_vector_console(lsi.elems, lsi.len);

            break;
        case 4:
            exit_program();
            break;
        case 5:
            float x;
            int n;
            printf("x and n: \n");
            scanf("%f %d", &x, &n);
            float result = to_power_of_n(x, n);
            printf("%.2f to the power of %d is %.2f", x, n, result);
            break;
        default:
            break;
        }
    }

    return 0;
}