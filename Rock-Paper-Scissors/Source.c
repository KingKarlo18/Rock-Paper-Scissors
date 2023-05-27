#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Funkcija koja vra�a pobjednika izme�u dva poteza
char* get_winner(char* move1, char* move2) {
    if (strcmp(move1, "papir") == 0) {
        if (strcmp(move2, "�kare") == 0) {
            return "Player 2";
        }
        else if (strcmp(move2, "dijamant") == 0) {
            return "Player 1";
        }
    }
    else if (strcmp(move1, "�kare") == 0) {
        if (strcmp(move2, "papir") == 0) {
            return "Player 1";
        }
        else if (strcmp(move2, "dijamant") == 0) {
            return "Player 2";
        }
    }
    else if (strcmp(move1, "dijamant") == 0) {
        if (strcmp(move2, "papir") == 0) {
            return "Player 2";
        }
        else if (strcmp(move2, "�kare") == 0) {
            return "Player 1";
        }
    }

    return "Tie";
}

int main() {
    char player1[20], player2[20], move1[10], move2[10];
    int score1 = 0, score2 = 0;

    printf("Unesite ime prvog igra�a: ");
    scanf("%s", player1);

    printf("Unesite ime drugog igra�a: ");
    scanf("%s", player2);

    while (score1 < 3 && score2 < 3) {
        while (1) {
            printf("%s, unesite svoj potez (papir, �kare ili dijamant): ", player1);
            scanf("%s", move1);
            while (getchar() != '\n'); // Ovaj redak bri�e sve znakove nakon prvog unosa rije�i

            if (strcmp(move1, "papir") == 0 || strcmp(move1, "�kare") == 0 || strcmp(move1, "dijamant") == 0) {
                break;
            }
            printf("Pogre�an unos. Molimo unesite ponovo.\n");
        }

        while (1) {
            printf("%s, unesite svoj potez (papir, �kare ili dijamant): ", player2);
            scanf("%s", move2);
            while (getchar() != '\n'); // Ovaj redak bri�e sve znakove nakon prvog unosa rije�i

            if (strcmp(move2, "papir") == 0 || strcmp(move2, "�kare") == 0 || strcmp(move2, "dijamant") == 0) {
                break;
            }
            printf("Pogre�an unos. Molimo unesite ponovo.\n");
        }

        char* winner = get_winner(move1, move2);


        if (strcmp(winner, "Player 1") == 0) {
            printf("%s pobje�uje ovu rundu!\n", player1);
            score1++;
        }
        else if (strcmp(winner, "Player 2") == 0) {
            printf("%s pobje�uje ovu rundu!\n", player2);
            score2++;
        }
        else {
            printf("Nerije�eno!\n");
        }

        printf("Trenutni rezultat: %s: %d, %s: %d\n", player1, score1, player2, score2);
    }

    if (score1 > score2) {
        printf("%s pobje�uje igru!\n", player1);
    }
    else {
        printf("%s pobje�uje igru!\n", player2);
    }

    return 0;
}