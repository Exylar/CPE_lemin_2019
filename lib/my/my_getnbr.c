/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get number
*/

int get_start_number(char const *str)
{
    int current_case = 0;

    int start_of_number = -1;
    while (start_of_number == -1 && str[current_case] != '\0') {
        if (str[current_case] >= '1' && str[current_case] <= '9')
            start_of_number = current_case;
        else
            current_case++;
    }
    return (start_of_number);
}

int get_val(char const *str, int current_case)
{
    int number = 0;
    int last_n = 0;
    int signe = 1;
    int start_of_number;

    start_of_number = get_start_number(str);
    if (start_of_number > 0)
        if (str[start_of_number - 1] == '-')
            signe = -1;
    while (str[current_case] >= '0' && str[current_case] <= '9') {
        number = number * 10 + (str[current_case] - '0') * signe;
        if ((last_n < number && signe == 1) ||
            (last_n > number && signe == -1))
            last_n = number;
        else
            return (0);
        current_case++;
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int current_case = 0;
    int start_of_number = -1;
    int number = 0;

    start_of_number = get_start_number(str);
    current_case = start_of_number;
    if (start_of_number == -1)
        return (0);
    number = get_val(str, current_case);
    return (number);
}
