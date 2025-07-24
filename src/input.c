#include "twenty_squares.h"

int	get_yes_no_input(const char *question)
{
	int i;
	char input[5] = {0};

	printf("%s Yes/No\n\n", question);

	while (strcmp(input, "yes") && strcmp(input, "no") && strcmp(input, "quit"))
	{
		printf("> ");
		fflush(0);
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

int	get_number_input(int min_number, int max_number, const char *question)
{
	int number = 0;
	char input[8] = {0};

	printf("%s %d - %d.\n\n", question, min_number, max_number);

	while (number < min_number || number > max_number)
	{
		printf("> ");
		fflush(0);
		if (fgets(input, 8, stdin))
			number = atoi(input);
		flush_stdin();
		only_one_greaterthan_sign_is_printed();
	}

	printf("\n");
	return number;
}

int	get_number_input_amongst_array(const int *number_array, int array_count,
		const char *question)
{
	int i;
	int number = 0, is_number_valid = 0;
	char input[8] = {0};

	printf("%s\n", question);
	for (i = 0; i < array_count; ++i)
	{
		if (i == array_count - 1)
			printf("%d.\n\n", number_array[i]);
		else
			printf("%d - ", number_array[i]);
	}

	while (!is_number_valid)
	{
		printf("> ");
		fflush(0);
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

	printf("\n");
	return number;
}

void	flush_stdin(void)
{
	char c = 'A';
	if (!fseek(stdin, 0, SEEK_END))
	{
		while (c != '\n' && c != EOF)
			c = getchar();
	}
	return;
}

void	only_one_greaterthan_sign_is_printed(void)
{
	printf("\r");
	return;
}

void	press_enter_to_continue(void)
{
	char c = '\0';
	printf("Press ENTER to continue.");
	while (c != '\n')
	{
		c = getchar();
	}
	flush_stdin();
	return;
}
