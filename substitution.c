#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int czy_lit(string x);

int main(int argc, string argv[])
{
    if ((argc != 2) || (czy_lit(argv[1]) == 1))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string tx = get_string("plaintext: ");  // wprowadzony text *** the text entered
    printf("ciphertext: ");                 // zaszyfrowany text *** encrypted text

    for (int i = 0, n = strlen(tx); i < n; i++)
    {
        if (tx[i] >= 'a' && tx[i] <= 'z')   // czy mała litera *** distance tx[i] from a
        {
            int j = tx[i] - 'a';            // odleglosc tx[i] od a ***
            printf("%c", tolower(argv[1][j]));      //zamiana na code char jesli zgodna litera *** converted to code char if a letter matches
        }
        else if (tx[i] >= 'A' && tx[i] <= 'Z')      // czy DUZA litera *** or a CAPITAL letter
        {
            int j = tx[i] - 'A';                    // odleglosc tx[i] od A *** distance tx[i] from A
            printf("%c", tolower(argv[1][j]) - 32);     //zamiana na code char jesli zgodna litera - 32 zeby z malej zrobic duza ***
        }                                               //change to code char if the letter - 32 matches to make the lower one large
        else
        {
            printf("%c", tx[i]);
        }
    }
    printf("\n");
    return 0;
}

// sprawdza czy to litery *** checks for letters
int czy_lit(string x)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        while ((x[i] < 'A') || ((x[i] > 'Z') && (x[i] < 'a')) || (x[i] > 'z'))
        {
            return 1;
        }
    }
    return 0;
}
