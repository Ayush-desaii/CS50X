#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text : ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (letters*100)/words;
    float S = (sentences*100)/words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 16 && index >= 1)
    {
        printf("Grade %i\n",index);
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }




}


int count_letters(string text)
{
    int letters = 0,i;
    for(i=0;i<strlen(text);i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 1,i;
     for(i=0;i<strlen(text);i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}


int count_sentences(string text)
{
    int sentences = 0,i;
    for(i=0;i<strlen(text);i++)
    {
        if(text[i]=='.' || text[i]=='!' || text[i]=='?')
        {
            sentences++;
        }
    }
    return sentences;
}