#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string alphabet = "abcdefghijklmnopqrstuvwxyz";

bool check_dup(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    if (tolower(argv[1][i]) < 'a' || tolower(argv[1][i]) > 'z')
    {
        printf("Key must contain only alphabetic characters\n");
        return 1;
    }

    if (!check_dup(argv[1]))
    {
        printf("Key must not contain duplicates.\n");
        return 1;
    }

    string input = get_string("plaintext: ");
    char output[strlen(input)];

    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = 0; j < strlen(alphabet); j++)
        {
            if (alphabet[j] == tolower(input[i]))
            {
                if (isupper(input[i]))
                {
                    output[i] = toupper(argv[1][j]);
                }
                else
                {
                    output[i] = tolower(argv[1][j]);
                }
                break;
            }
        output[i] = input[i];
        }
    }
    printf("ciphertext: %s\n", output);
    return 0;
}

// Handle uniqueness validation in key
bool check_dup(string str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for(int j = i + 1; j < strlen(str); j++)
        {
            if (tolower(str[i]) == tolower(str[j]))
            {
                return false;
            }
        }
    }
    return true;
}
