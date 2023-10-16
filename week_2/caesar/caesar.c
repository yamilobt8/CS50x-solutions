#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{

    // nchofo wach l user dkhl chi argument ola dkhl ktr mn whda
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // ghanh99o f kola char mn l argument bach nt2kdo bli kamlo digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            continue;
        }
    }

   // nhwlo l argument mn string l int
   int k = atoi(argv[1]);


   // Prompt user for plaintext
   string plain_text = get_string("plaintext: ");


   // ghadi nktbha mn drok hitach ila ktbtha wst loop btb9a t3awd
   printf("ciphertext: ");


   // ghadi nlopiw 3la ga3 les carachters bach nchofo no3 dylhoum
   for (int i = 0; i < strlen(plain_text); i++)
   {
        // ghadi n9ado wahd l array bnfs lenght dyal input bach nhto fiha les lettres apres changement
        int conv[strlen(plain_text)];

        // hna ghanchofo wach char lettre awla la bach n3arfo wach nbdloh ola la
        if (isalpha(plain_text[i]))
        {
            // hna upper case lihoum regle dyalhum bohdha 3la hsab number dylhm f l ASCII
            if (isupper(plain_text[i]))
            {
                // hna fin ghanhowlo lettre mn l ASCII l alphabet INDEX
                conv[i] = (int) plain_text[i] - (int) 'A';

                // hna ghadi nhsboh b lformula
                int c_i = (conv[i] + k) % 26;

                // hna ghadi nprintiwh (zdna 65 bach nrdoh ASCII, A = 65)
                printf("%c",c_i + 65);
            }

            // hna ta3 lower case
            else
            {
                // hna fin ghanhowlo lettre mn l ASCII l alphabet INDEX
                conv[i] = (int) plain_text[i] - (int) 'a';

                // hna ghadi nhsboh b lformula
                int c_i = (conv[i] + k) % 26;

                // hna ghadi nprintiwh (zdna 97 bach nrdoh ASCII, a = 97)
                printf("%c", c_i + 97);
            }
        }

        // ila makanch lettre makanbdlohch
        else
        {
            printf("%c", plain_text[i]);
        }
   }
   // hna new ligne bach thbd $ l tht
   printf("\n");
}
