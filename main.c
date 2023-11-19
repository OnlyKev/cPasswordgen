/*
Create a password generator using structs
Created: Kevin Wahome
Date: 11/19/23
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// our password struct
typedef struct password{
    int numbers;
    int lowercaseCharacters;
    int uppercaseCharacters;
    int specialCharacters;
    const char* charset;
    int length;
} Password;

void initPassword(struct password *gen){
    gen->numbers = 0;
    gen->lowercaseCharacters = 0;
    gen->uppercaseCharacters = 0;
    gen->specialCharacters = 0;
    gen->charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
}

void generatePassword(struct password *gen, char* password, int num, int upper, int lower, int special){

   int totalLen = num + upper + lower + special;
   gen->length = totalLen;
   int i = 0, j;
   j = rand() % 3; // for more randomness

   switch (j)
   {
       case 0:
           while (totalLen > 0 )
           {
               if (num > 0)
               {
                   password[i] = gen->charset[rand() % 10 + 52];

                   num--;
                   i++;
                   totalLen--;
               }
               if (upper > 0)
               {
                   password[i] = gen->charset[rand() % 26 + 26];

                   upper--;
                   i++;
                   totalLen--;
               }
               if (lower > 0)
               {
                   password[i] = gen->charset[rand() % 26];

                   lower--;
                   i++;
                   totalLen--;
               }
               if (special > 0)
               {
                   password[i] = gen->charset[rand() %  8 + 60];
                   special--;
                   i++;
                   totalLen--;
               }
           }
           break;
       case 1:
           while (totalLen > 0 )
           {
               if (upper > 0)
               {
                   password[i] = gen->charset[rand() % 26 + 26];

                   upper--;
                   i++;
                   totalLen--;
               }
               if (num > 0) {
                   password[i] = gen->charset[rand() % 10 + 52];

                   num--;
                   i++;
                   totalLen--;
               }
               if (special > 0)
               {
                   password[i] = gen->charset[rand() %  8 + 60];
                   special--;
                   i++;
                   totalLen--;
               }
               if (lower > 0)
               {
                   password[i] = gen->charset[rand() % 26];

                   lower--;
                   i++;
                   totalLen--;
               }
           }
           break;
       case 2:
           while (totalLen > 0 )
           {
               if (lower > 0)
               {
                   password[i] = gen->charset[rand() % 26];

                   lower--;
                   i++;
                   totalLen--;
               }
               if (special > 0)
               {
                   password[i] = gen->charset[rand() %  8 + 60];
                   special--;
                   i++;
                   totalLen--;
               }
               if (num > 0)
               {
                   password[i] = gen->charset[rand() % 10 + 52];

                   num--;
                   i++;
                   totalLen--;
               }
               if (upper > 0)
               {
                   password[i] = gen->charset[rand() % 26 + 26];

                   upper--;
                   i++;
                   totalLen--;
               }
           }
           break;
       case 3:
           while (totalLen > 0 )
           {
               if (num > 0)
               {
                   password[i] = gen->charset[rand() % 10 + 52];

                   num--;
                   i++;
                   totalLen--;
               }
               if (special > 0)
               {
                   password[i] = gen->charset[rand() %  8 + 60];
                   special--;
                   i++;
                   totalLen--;
               }
               if (upper > 0)
               {
                   password[i] = gen->charset[rand() % 26 + 26];

                   upper--;
                   i++;
                   totalLen--;
               }
               if (lower > 0)
               {
                   password[i] = gen->charset[rand() % 26];

                   lower--;
                   i++;
                   totalLen--;
               }
           }
           break;
   }
    password[gen->length] = '\0';
}

void clearKeyboardBuffer(void)
{
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
}

int main(int argc, char** argv){

    int choice;
        Password fPassword; // casting to the known type
        srand((unsigned int) time(NULL)); // for seeding
        int noc = 0;
        int num, upper, lower, special;
        char password[fPassword.length + 1];

        printf("\t---------------------------------------------\n");
        printf("\t_______________GENERATE_PASSWORD_____________\n");
        printf("\t---------------------------------------------\n");

        printf("Hello user, You have been granted the ability to generate a password. Please enter a number in its corresponding order. \nex. number, uppercaseLetter, lowercaseLetter, SpecialCharacter | 5 6 3 4\n");
        printf("\n");
        initPassword(&fPassword);
        printf("\n");
        printf("enter now or have our 'AI' generate one for you. 1 = user, 0 = AI\n");
        scanf("%d", &choice);
        clearKeyboardBuffer();

        while (choice > 1 || choice < 0){
            printf("enter now or have our 'AI' generate one for you. 1 = user, 0 = AI\n");
            scanf("%d", &choice);
            clearKeyboardBuffer();
        }

        switch (choice){
            case 0:
                generatePassword(&fPassword, password, 4, 4, 4, 4);
                printf("Password: %s\n", password);
                break;
            case 1:
                printf("Enter Now\n");
                noc = scanf("%d%d%d%d", &num, &upper, &lower, &special);
                clearKeyboardBuffer();

                while (noc != 4) {
                    printf("ERROR_INVALID_VALUE\n");
                    printf("make sure you have entered numerical values and that all parameters have a value\n");
                    noc = scanf("%d%d%d%d", &num, &upper, &lower, &special);
                    clearKeyboardBuffer();
                }

                generatePassword(&fPassword, password, num, upper, lower, special);
                printf("Password: %s\n", password);
                break;
        }
    printf("\n");
        printf("Want to generate another one? 1 = yes, 0 no");
    printf("\n");
        scanf("%d", &choice);
        clearKeyboardBuffer();

        while (choice == 1){
            printf("\n");
            printf("enter now or have our 'AI' generate one for you. 1 = user, 0 = AI");
            printf("\n");
            scanf("%d", &choice);
            clearKeyboardBuffer();
            while (choice > 1 || choice < 0){
                printf("enter now or have our 'AI' generate one for you. 1 = user, 0 = AI\n");
                scanf("%d", &choice);
                clearKeyboardBuffer();
            }

            switch (choice){
                case 0:
                    generatePassword(&fPassword, password, 4, 4, 4, 4);
                    printf("Password: %s\n", password);
                    break;
                case 1:
                    printf("Enter Now\n");
                    noc = scanf("%d%d%d%d", &num, &upper, &lower, &special);
                    clearKeyboardBuffer();

                    while (noc != 4) {
                        printf("ERROR_INVALID_VALUE\n");
                        printf("make sure you have entered numerical values and that all parameters have a value\n");
                        noc = scanf("%d%d%d%d", &num, &upper, &lower, &special);
                        clearKeyboardBuffer();
                    }

                    generatePassword(&fPassword, password, num, upper, lower, special);
                    printf("Password: %s\n", password);
                    break;
            }
            printf("\n");
            printf("Want to generate another one? 1 = yes, 0 no");
            printf("\n");
            scanf("%d", &choice);
            clearKeyboardBuffer();
        }

    return 0;
}

