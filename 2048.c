#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define MAX_SCORES 5
#define username admin123
#define pass password123

struct Score {
    char playerName[20];
    int score;
};

int board[SIZE][SIZE];
struct Score highScores[MAX_SCORES];
int currentScore; 

int move(char direction);
int isGameOver();

void updateScore(int value);
void displayLeaderboard();
void writeHighScores();

void sortHighScores();
void initialize();
void printBoard();
void addTile();


void initialize() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    srand(time(NULL));
    int r1 = rand() % SIZE;
    int c1 = rand() % SIZE;
    int r2, c2;

    do {
        r2 = rand() % SIZE;
        c2 = rand() % SIZE;
    } while (r1 == r2 && c1 == c2);

    board[r1][c1] = (rand() % 2 + 1) * 2;
    board[r2][c2] = (rand() % 2 + 1) * 2;
}

void printBoard() {
    system("cls");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n\n");
    }

    printf("\033[1m================================================================\033[0m\n");
    printf("\033[1mScore: %d\nTo exit the game type 'X' 2 times (Do note it doesnt save the score!)\033[0m\n", currentScore);
    printf("\033[1m================================================================\033[0m\n\n");
}

void addTile() {
    int r, c;
    do {
        r = rand() % SIZE;
        c = rand() % SIZE;
    } while (board[r][c] != 0);

    board[r][c] = (rand() % 2 + 1) * 2;
}

int move(char direction) {
    int moved = 0;

    switch (direction) {
        case 'W':
            for (int j = 0; j < SIZE; j++) {
                for (int i = 1; i < SIZE; i++) {
                    for (int k = i; k > 0 && board[k][j] != 0; k--) {
                        if (board[k - 1][j] == 0 || board[k - 1][j] == board[k][j]) {
                            if (board[k - 1][j] == 0) {
                                board[k - 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k - 1][j] == board[k][j]) {
                                board[k - 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 'S':
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    for (int k = i; k < SIZE - 1 && board[k][j] != 0; k++) {
                        if (board[k + 1][j] == 0 || board[k + 1][j] == board[k][j]) {
                            if (board[k + 1][j] == 0) {
                                board[k + 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k + 1][j] == board[k][j]) {
                                board[k + 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
            break;
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    for (int k = i; k < SIZE - 1 && board[k][j] != 0; k++) {
                        if (board[k + 1][j] == 0 || board[k + 1][j] == board[k][j]) {
                            if (board[k + 1][j] == 0) {
                                board[k + 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k + 1][j] == board[k][j]) {
                                board[k + 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 'A':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 1; j < SIZE; j++) {
                    for (int k = j; k > 0 && board[i][k] != 0; k--) {
                        if (board[i][k - 1] == 0 || board[i][k - 1] == board[i][k]) {
                            if (board[i][k - 1] == 0) {
                                board[i][k - 1] = board[i][k];
                                board[i][k] = 0;
                            } else if (board[i][k - 1] == board[i][k]) {
                                board[i][k - 1] *= 2;
                                board[i][k] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
            break;

        case 'D':
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE - 2; j >= 0; j--) {
                    for (int k = j; k < SIZE - 1 && board[i][k] != 0; k++) {
                        if (board[i][k + 1] == 0 || board[i][k + 1] == board[i][k]) {
                            if (board[i][k + 1] == 0) {
                                board[i][k + 1] = board[i][k];
                                board[i][k] = 0;
                            } else if (board[i][k + 1] == board[i][k]) {
                                board[i][k + 1] *= 2;
                                board[i][k] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;

        case 'w':
            for (int j = 0; j < SIZE; j++) {
                for (int i = 1; i < SIZE; i++) {
                    for (int k = i; k > 0 && board[k][j] != 0; k--) {
                        if (board[k - 1][j] == 0 || board[k - 1][j] == board[k][j]) {
                            if (board[k - 1][j] == 0) {
                                board[k - 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k - 1][j] == board[k][j]) {
                                board[k - 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;

        case 's':
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    for (int k = i; k < SIZE - 1 && board[k][j] != 0; k++) {
                        if (board[k + 1][j] == 0 || board[k + 1][j] == board[k][j]) {
                            if (board[k + 1][j] == 0) {
                                board[k + 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k + 1][j] == board[k][j]) {
                                board[k + 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    for (int k = i; k < SIZE - 1 && board[k][j] != 0; k++) {
                        if (board[k + 1][j] == 0 || board[k + 1][j] == board[k][j]) {
                            if (board[k + 1][j] == 0) {
                                board[k + 1][j] = board[k][j];
                                board[k][j] = 0;
                            } else if (board[k + 1][j] == board[k][j]) {
                                board[k + 1][j] *= 2;
                                board[k][j] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;

        case 'a':
            for (int i = 0; i < SIZE; i++) {
                for (int j = 1; j < SIZE; j++) {
                    for (int k = j; k > 0 && board[i][k] != 0; k--) {
                        if (board[i][k - 1] == 0 || board[i][k - 1] == board[i][k]) {
                            if (board[i][k - 1] == 0) {
                                board[i][k - 1] = board[i][k];
                                board[i][k] = 0;
                            } else if (board[i][k - 1] == board[i][k]) {
                                board[i][k - 1] *= 2;
                                board[i][k] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;

        case 'd':
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE - 2; j >= 0; j--) {
                    for (int k = j; k < SIZE - 1 && board[i][k] != 0; k++) {
                        if (board[i][k + 1] == 0 || board[i][k + 1] == board[i][k]) {
                            if (board[i][k + 1] == 0) {
                                board[i][k + 1] = board[i][k];
                                board[i][k] = 0;
                            } else if (board[i][k + 1] == board[i][k]) {
                                board[i][k + 1] *= 2;
                                board[i][k] = 0;
                                for (int i = 0; i < SIZE; i++) {
                                    for (int j = 0; j < SIZE; j++) {
                                    currentScore += board[i][j];
                                    }
                                }
                            }
                            moved = 1;
                        }
                    }
                }
            }
        break;

        case 'X':
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mGoodbye! See you next time!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            exit(0);
        break;

        case 'x':
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mGoodbye! See you next time!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            exit(0);
        break;
    }
    return moved;
}

int isGameOver() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0; 
            }

            if (j + 1 < SIZE && board[i][j] == board[i][j + 1]) {
                return 0; 
            }

            if (i + 1 < SIZE && board[i][j] == board[i + 1][j]) {
                return 0; 
            }
        }
    }

    return 1; 
}

void updateScore(int value) {
    currentScore += value;
}

void writeHighScores(char *name, int score) {
    FILE *file = fopen("highscores.txt", "r");
    int count = 0;
    if (file != NULL) {
        while (fscanf(file, "%[^#]#%d\n", highScores[count].playerName, &highScores[count].score) != EOF && count < MAX_SCORES) {
            count++;
        }
        fclose(file);
    }

    if (count < MAX_SCORES || score > highScores[count - 1].score) {
        if (count == MAX_SCORES) {
            count--;
        }

        strcpy(highScores[count].playerName, name);
        highScores[count].score = score;
        count++;

        file = fopen("highscores.txt", "w");
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s#%d\n", highScores[i].playerName, highScores[i].score);
        }
        fclose(file);
    }
}

void sortHighScores() {
    FILE* file = fopen("highscores.txt", "r");
    struct Score highScores[MAX_SCORES];
    int count = 0;

    if (file != NULL) {
        while (fscanf(file, "%[^#]#%d\n", highScores[count].playerName, &highScores[count].score) != EOF && count < MAX_SCORES) {
            count++;
        }
        fclose(file);
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (highScores[j].score < highScores[j + 1].score) {
                struct Score temp = highScores[j];
                highScores[j] = highScores[j + 1];
                highScores[j + 1] = temp;
            }
        }
    }

    // Write the sorted scores back to the file
    file = fopen("highscores.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s#%d\n", highScores[i].playerName, highScores[i].score);
    }
    fclose(file);
}

void displayLeaderboard() {
    FILE *file = fopen("highscores.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char name[50];
    int score;
    int i = 1;
    while (fscanf(file, "%[^#]#%d\n", name, &score) != EOF) {
        printf("%d. %s: %d\n", i, name, score);
        i++;
    }
    fclose(file);
}

int main() {
    int n;
    char username[20];
    char pass[20];
    start:
    system("cls");
    printf("\033[1m===========================================================\033[0m\n");
    printf("\033[1mWelcome to 2048 Game! Please Login to proceed to the game!\033[0m\n");
    printf("\033[1m===========================================================\033[0m\n\n");
    printf("\033[1m1. Login\033[0m\n");
    printf("\033[1m2. Exit\033[0m\n");
    printf("\033[1mSelection : \033[0m");
    scanf("%d",&n);
    switch(n){
        case 1:
            login:
            system("cls");
            printf("\033[1m==================================================\033[0m\n");
            printf("\033[1mPlease enter your username and password to login!\033[0m\n");
            printf("\033[1m==================================================\033[0m\n\n");
            printf("\033[1mUsername : \033[0m");
            scanf("%s",username);
            printf("\033[1mPassword : \033[0m");
            scanf("%s",pass);
            if(strcmp(username,"admin123")==0 && strcmp(pass,"password123")==0){
                system("cls");
                printf("\033[1m=====================================\033[0m\n");
                printf("\033[1mLogin Successful! Welcome to 2048!\033[0m\n");
                printf("\033[1m=====================================\033[0m\n\n");
                sleep(3);
                goto game;
            }
            else{
                system("cls");
                printf("\033[1m=====================================\033[0m\n");
                printf("\033[1mLogin Failed! Please try again!\033[0m\n");
                printf("\033[1m=====================================\033[0m\n\n");
                sleep(3);
                goto login;
            }
        break;

        case 2:
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mGoodbye! See you next time!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            exit(0);
        break;

        case 999:
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mWelcome to the secret menu!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            goto game;
        break;
        case 998:
            system("cls");
            printf("\033[1m============\033[0m\n");
            printf("\033[1mLeaderboard!\033[0m\n");
            printf("\033[1m============\033[0m\n\n");
            displayLeaderboard();
            printf("\n\n\nClick enter to continue...");
            getch();
            goto start;
        break;
        case 997:
            system("cls");
            goto testing;
        break;
        
        default:
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mInvalid input! Please try again!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            goto start;
    }
    game:
        initialize();

        while (!isGameOver()) {
            printBoard();
            printf("Enter move (W/A/S/D): ");
            char moveDir = getchar();
            while (getchar() != '\n');

            if (move(moveDir)) {
                addTile();
            }
        }
    
        printBoard();
        testing:
        printf("Game Over!\n");
        printf("Enter your name: ");
        char playerName[20];
        char restart;
        scanf("%19s", playerName); 
        updateScore(currentScore);
        writeHighScores(playerName, currentScore);
        sortHighScores();
        displayLeaderboard();
        printf("Restart the game? (Y/N): ");
        while((getchar()) != '\n');
        scanf("%c", &restart);
        if (restart == 'Y' || restart == 'y') {
            goto game;
        }
        else {
            system("cls");
            printf("\033[1m=============================\033[0m\n");
            printf("\033[1mGoodbye! See you next time!\033[0m\n");
            printf("\033[1m=============================\033[0m\n\n");
            sleep(3);
            exit(0);
        }
    return 0;
}
