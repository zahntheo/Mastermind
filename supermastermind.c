#include "header.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define BUFFER_ERROR -1
#define INVALID_INPUT -2
#define SMALL_SIZE_COLORCODE 4
#define BIG_SIZE_COLORCODE 5
#define MAX_TURN 12
#define WIN 0
#define LOSE -1
#define NAME_MAX 15

char created_code_big[BIG_SIZE_COLORCODE + 1];
extern int won_games1;
extern int won_games2;
int won_games1_super = 0;
int won_games2_super = 0;
extern int lost_games1;
extern int lost_games2;
int lost_games1_super = 0;
int lost_games2_super = 0;
extern int winning_moves1;
extern int winning_moves2;
int winning_moves1_super = 0;
int winning_moves2_super = 0;
extern char name1[NAME_MAX];
extern char name2[NAME_MAX];

void create_code_sm(void){
	int i, a;
	srand(time(NULL));

	i = 0;
	while (i < BIG_SIZE_COLORCODE) {
		a = rand() % 8;
		created_code_big[i] = a + '0';
		++i;
	}
}
int choose_code_sm(char player[]){
	int i;
	char b;
	i = 0;
	b = getchar();

	while (b != '\n' && i < BIG_SIZE_COLORCODE) {
		if (b == EOF) {
			return BUFFER_ERROR;
		} else if (!isdigit(b) || b > '7') {
			if (!flush_buff()) {
				return BUFFER_ERROR;
			}
			printf("Falsche Eingabe! Nur Zahlen von 0-7\n");
			return INVALID_INPUT;
		}
		player[i++] = b;
		b = getchar();

	}
	if (i < BIG_SIZE_COLORCODE) {
		printf("Falsche Eingabe! Bitte genau 5 Ziffern!\n");
		return INVALID_INPUT;
	} else if (i == BIG_SIZE_COLORCODE && b != '\n') {
		if (!flush_buff()) {
			return BUFFER_ERROR;
		}
		printf("Falsche Eingabe! Bitte genau 5 Ziffern!\n");
		return INVALID_INPUT;
	}

	player[i] = '\0';

	return 0;
}
int game_surface_sm(void){
	char temp[BIG_SIZE_COLORCODE + 1];
	int turns = 1;
	int moves1 = 0;

	while(turns <= MAX_TURN) {
		++turns;
        ++moves1;
		do {
			printf("Raten Sie den 5-stelligen Code\n");
		} while(choose_code_sm(temp) != 0);
		if (checking_sm(created_code_big, temp) == 0) {
			printf("\tSie haben gewonnen!\n");
			winning_moves1 += moves1;
			winning_moves1_super += moves1;
			++won_games1;
			return WIN;
		}
	}

	printf("\tSie haben verloren!\n");
	++lost_games1_super;
	printf("Der Code war: %s\n", created_code_big);
	return LOSE;
}
int game_surface_2_sm(char player1[], char player2[]){
	char temp[BIG_SIZE_COLORCODE + 1];
	int turns = 1;
	int moves1 = 0;
	int moves2 = 0;

	while(turns <= 2 * MAX_TURN) {
		if (turns % 2 == 1) {
			++turns;
            ++moves1;
			do {
				printf("%s ist am Zug: Raten Sie den 5-stelligen Code\n", name1);
			} while(choose_code_sm(temp) != 0);
			if (checking_sm(player2, temp) == 0) {
				printf("\tSie haben gewonnen!\n");
				printf("Der Code von %s war: %s\n", name1, player1);
                ++won_games1;
				++won_games1_super;
				winning_moves1 += moves1;
				winning_moves1_super += moves1;
				++lost_games2_super;
				++lost_games2;
				return WIN;
			}
		} else {
			++turns;
            ++moves2;
			do {
				printf("%s ist am Zug: Raten Sie den 5-stelligen Code\n", name2);
			} while(choose_code_sm(temp) != 0);
			if (checking_sm(player1, temp) == 0) {
				printf("\tSie haben gewonnen!\n");
				printf("Der Code von %s war: %s\n", name2, player2);
                ++won_games2;
				++won_games2_super;
				winning_moves2 += moves2;
				winning_moves2_super += moves2;
				++lost_games1_super;
				++lost_games1;
				return WIN;
			}
		}
	}

	printf("\tSie sind beide gescheitert!\n");
	printf("Der Code von %s war: %s\n", name1, player1);
	printf("Der Code von %s war: %s\n", name2, player2);
	++lost_games1_super;
	++lost_games2_super;
	++lost_games1;
	++lost_games2;
	return LOSE;
}
int checking_sm(char set_code[], char guess[]){
	int i = 0, j = 0, black = 0, white = 0;
	char guess_copy[BIG_SIZE_COLORCODE + 1];
	char set_code_copy[BIG_SIZE_COLORCODE + 1];

	strcpy(set_code_copy, set_code);
	strcpy(guess_copy, guess);

	i = 0, j = 0;
	while(i < BIG_SIZE_COLORCODE) {
		while(j < BIG_SIZE_COLORCODE) {
			if(guess_copy[i] == set_code_copy[j]) {
				if (i == j) {
					++black;
					guess_copy[i] = 'a';
					set_code_copy[j] = 'b';
					j = BIG_SIZE_COLORCODE;
				}
			}
		++j;
		}
	j = 0;
	++i;
	}

	i = 0, j = 0;
	while(i < BIG_SIZE_COLORCODE) {
		while(j < BIG_SIZE_COLORCODE) {
			if(guess_copy[i] == set_code_copy[j]) {
				++white;
				guess_copy[i] = 'a';
				set_code_copy[j] = 'b';
				j = BIG_SIZE_COLORCODE;
			}
		++j;
		}
	j = 0;
	++i;
	}


	printf("black: %i, white: %i\n", black, white);

	if(black == 5) {
		return WIN;
	}

	return LOSE;
}
