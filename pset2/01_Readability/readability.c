#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    string text = get_string("Text: ");
    long letters = 0;
    long words = 0;
    long sentences = 0;
    float grade;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words ++;
        }
        else if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
        {
            letters ++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    words++;
    grade = (5.88 * letters / words) - (29.6 * sentences / words) - 15.8;
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}
