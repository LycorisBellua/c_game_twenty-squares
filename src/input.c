#include "input.h"
#include "output.h"

int get_yes_no_input(const char* question)
{
    int i;
    char input[5] = {0};

    write_line("%s Yes/No\n\n", question);

    while (strcmp(input, "yes") && strcmp(input, "no") && strcmp(input, "quit"))
    {
        write_line("> ");
        if (fgets(input, 5, stdin))
        {
            for (i = 0; i < 5; ++i)
            {
                if (input[i] == '\n')
                {
                    input[i] = '\0';
                    break;
                }
                input[i] = tolower(input[i]);
            }
        }
        flush_stdin();
        only_one_greaterthan_sign_is_printed();
    }

    if (!strcmp(input, "no"))
        return 0;
    else if (!strcmp(input, "yes"))
        return 1;
    else
        return -1;
}

int get_number_input(const int min_number, const int max_number, const char* question)
{
    int number = 0;
    char input[8] = {0};

    write_line("%s %d - %d.\n\n", question, min_number, max_number);

    while (number < min_number || number > max_number)
    {
        write_line("> ");
        if (fgets(input, 8, stdin))
            number = atoi(input);
        flush_stdin();
        only_one_greaterthan_sign_is_printed();
    }

    write_line("\n");
    return number;
}

/* When passed to a function, the array decays to a pointer to the first element, so you must compute array_count before it decays:
    array_count = sizeof(number_array)/sizeof(number_array[0]) */
int get_number_input_amongst_array(const int number_array[], const int array_count, const char* question)
{
    int i;
    int number = 0, is_number_valid = 0;
    char input[8] = {0};

    write_line("%s\n", question);
    for (i = 0; i < array_count; ++i)
    {
        if (i == array_count - 1)
            write_line("%d.\n\n", number_array[i]);
        else
            write_line("%d - ", number_array[i]);
    }

    while (!is_number_valid)
    {
        write_line("> ");
        if (fgets(input, 8, stdin))
        {
            number = atoi(input);
            for (i = 0; i < array_count; ++i)
            {
                if (number == number_array[i])
                {
                    is_number_valid = 1;
                    break;
                }
            }
        }
        flush_stdin();
        only_one_greaterthan_sign_is_printed();
    }

    write_line("\n");
    return number;
}

void flush_stdin(void)
{
    char c = 'A';
    if (!fseek(stdin, 0, SEEK_END))
    {
        while (c != '\n' && c != EOF)
            c = getchar();
    }
    return;
}

void only_one_greaterthan_sign_is_printed(void)
{
    write_line("\r");
    return;
}

void press_enter_to_continue(void)
{
    char c = '\0';
    write_line("Press ENTER to continue.");
    while (c != '\n')
    {
        c = getchar();
    }
    flush_stdin();
    return;
}

