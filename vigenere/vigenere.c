#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int getCypher(char, const char * const);
    if(argc != 2) {
        printf("Usage: ./vigenere k");
        return 1;
    }
    else {
        for(int i=0; i<strlen(argv[1]); i++) {
            if(!isalpha(argv[1][i])) {
                printf("Usage: ./vigenere k");
                return 1;
            }
        }
    }
    int keyIndex = 0;
    char * key = argv[1];
    printf("plaintext: ");
    char * message = get_string();
    char encryptedMessage[10];
    while(strlen(message) > 0) {
        int length = strlen(encryptedMessage);

        int n = -1;
        int a = -1;

        if (message[0] >= 'A' && message[0] <= 'Z') {
            static const char * const alphabet1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            n = getCypher(message[0], alphabet1);

            if (key[keyIndex%strlen(key)] >= 'A' && key[keyIndex%strlen(key)] <= 'Z') {
                a = getCypher(key[keyIndex%strlen(key)], alphabet1);
            }
            else if (key[keyIndex%strlen(key)] >= 'a' && key[keyIndex%strlen(key)] <= 'z') {
                static const char * const alphabet2 = "abcdefghijklmnopqrstuvwxyz";
                a = getCypher(key[keyIndex%strlen(key)], alphabet2);
            }

            if(a == -1) {
                return 1;
            }

            n = (n+a)%26;
            encryptedMessage[length] = alphabet1[n];
        }
        else if (message[0] >= 'a' && message[0] <= 'z') {
            static const char * const alphabet1 = "abcdefghijklmnopqrstuvwxyz";
            n = getCypher(message[0], alphabet1);

            if (key[keyIndex%strlen(key)] >= 'A' && key[keyIndex%strlen(key)] <= 'Z') {
                static const char * const alphabet2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                a = getCypher(key[keyIndex%strlen(key)], alphabet2);
            }
            else if (key[keyIndex%strlen(key)] >= 'a' && key[keyIndex%strlen(key)] <= 'z') {
                a = getCypher(key[keyIndex%strlen(key)], alphabet1);
            }

            if(a == -1) {
                return 1;
            }

            n = (n+a)%26;
            encryptedMessage[length] = alphabet1[n];
        }
        else {
            encryptedMessage[length] = message[0];
        }

        encryptedMessage[length+1] = '\0';
        keyIndex++;
        message = message+1;
    }
    printf("ciphertext: %s\n", encryptedMessage);
    return 0;
}

int getCypher(char c, const char * const alphabet) {
    char *p = strchr(alphabet, c);

    if (p)
    {
        return p - alphabet;
    }
    else {
        return -1;
    }

}