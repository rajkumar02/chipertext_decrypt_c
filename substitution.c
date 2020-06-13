#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool is_valid_key(string s);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n"); // if not key found show this messge
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n"); // if not key contain 26 characters return value.
        return 1;
    }

    string s = get_string("plaintext: "); //get plaintext if all required conditions are met
    string diff = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i; //convert 'J' - 'A'
    }

    printf("ciphertext: "); //print cyphertext
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = s[i] + diff[s[i] - (isupper(s[i]) ? 'A' : 'a')]; //calculate ciphertext function
        }
        printf("%c", s[i]);
    }
    printf("\n");
}

//check valid key
bool is_valid_key(string s)
{
    int len = strlen(s);
    if (len != 26) //if not the string length is 26 return false
    {
        return false;
    }

    int freq[26] = { 0 }; //key containt 26

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }

        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }

    return true;
}