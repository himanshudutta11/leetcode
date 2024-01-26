/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
*/
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
bool valid_word_abbr(char *word, char *abbr)
{
    int word_len = strlen(word);
    int abbr_len = strlen(abbr);
    int i = 0;
    int j = 0;
//    printf("word_len: %d, abbr_len: %d", word_len, abbr_len);
    while(i < word_len && j < abbr_len)
    {
        if(abbr[j] >= 'a' && abbr[j] <= 'z')
        {
            if(word[i] != abbr[j])
            {
                return false;
            }
            i++;
            j++;
            continue;
        }
        int len = 0;
        while(j < abbr_len && abbr[j] >= '0' && abbr[j] <= '9')
        {
            len = len * 10 + abbr[j++] - '0';
            if(!len) return false;
        }
        i = i + len;
    }
    return i == word_len && j == abbr_len;
}
int main()
{

    if (valid_word_abbr("internationalization", "i12iz4n"))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}