#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Defining-inicializing variables.
    long long cc_number; //credit card number.
    long long temp_cc_number; //credit card number temporal value to get its lenght.
    unsigned int digit = 0;
    unsigned int temp_digit_value = 0; //temporal digit value.
    unsigned int simple_sum = 0;
    unsigned int mult_sum = 0;
    unsigned int cc_num_lenght = 0;

    //Prompt the user for the credit card number.
    do
    {
        cc_number = get_long_long("Number: ");
    }
    while (cc_number <= 0);

    //variable to store de credit card number for first digit validation.
    long long validation_number = cc_number;

    //Getting the lenght of the credit card number.
    temp_cc_number = cc_number;
    while (temp_cc_number != 0)
    {
        temp_cc_number /= 10;
        ++cc_num_lenght;
    }

    //Process de credit card number.
    if ((cc_num_lenght > 12) && (cc_num_lenght < 17))
    {
        for (int i = 0; i <= ((cc_num_lenght / 2) + 1); ++i)
        {
            //Simple digits addition process.
            digit = cc_number % 10;
            simple_sum += digit;
            cc_number /= 10;

            //Addition of digit's products
            digit = cc_number % 10;
            temp_digit_value = digit * 2;

            if (temp_digit_value > 9)
            {
                int last_digit = temp_digit_value % 10;
                int second_to_last_digit = temp_digit_value / 10;
                int internal_sum = last_digit + second_to_last_digit;
                mult_sum += internal_sum;
            }
            else
            {
                mult_sum += temp_digit_value;
            }
            cc_number /= 10;
        }

        int final_sum = simple_sum + mult_sum;

        //Check if the last digit in final_sum is a 0.
        if ((final_sum % 10) == 0)
        {
            if (cc_num_lenght == 15)
            {
                //Check if starts with 3, then is AMEX.
                if ((validation_number / (10000000000000) == 34) || (validation_number / (10000000000000) == 37))
                {
                    printf("AMEX\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }

            else if (cc_num_lenght == 13)
            {
                //Check if starts wiht 4, then is VISA.
                if (validation_number / (1000000000000) == 4)
                {
                    printf("VISA\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }

            else if (cc_num_lenght == 16)
            {
                //Check if starts with 4, then is VISA.
                if (validation_number / (1000000000000000) == 4)
                {
                    printf("VISA\n");
                }
                //Check if starts with 5, then is MASTERCARD.
                else if ((validation_number / (100000000000000) >= 51) && (validation_number / (100000000000000) <= 55))
                {
                    printf("MASTERCARD\n");
                }

                else
                {
                    printf("INVALID\n");
                }
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}