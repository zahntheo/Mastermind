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
#define LOSE -2
#define NAME_MAX 15


char created_code_small[SMALL_SIZE_COLORCODE + 1];
int won_games1 = 0;
int won_games2 = 0;
int lost_games1 = 0;
int lost_games2 = 0;
int winning_moves1 = 0;
int winning_moves2 = 0;
int winning_moves1_classic = 0;
int winning_moves2_classic = 0;
extern char name1[NAME_MAX];
extern char name2[NAME_MAX];


void create_code(void){
	int i, a;
	srand(time(NULL));

	i = 0;
	while (i < SMALL_SIZE_COLORCODE) {
		a = rand() % 6;
		created_code_small[i] = a + '0';
		++i;
	}
}

int choose_code(char player[]){
	int i;
	char b;

	i = 0;
	b = getchar();
	while (b != '\n' && i < SMALL_SIZE_COLORCODE) {
		if (b == EOF) {
			return BUFFER_ERROR;
		} else if (!isdigit(b) || b > '5') {
			if (!flush_buff()) {
				return BUFFER_ERROR;
			}
			printf("Falsche Eingabe! Nur Zahlen von 0-5\n");
			return INVALID_INPUT;
		}
		player[i++] = b;
		b = getchar();

	}
	if (i < SMALL_SIZE_COLORCODE) {
		printf("Falsche Eingabe! Bitte genau 4 Ziffern!\n");
		return INVALID_INPUT;
	} else if (i == SMALL_SIZE_COLORCODE && b != '\n') {
		if (!flush_buff()) {
			return BUFFER_ERROR;
		}
		printf("Falsche Eingabe! Bitte genau 4 Ziffern!\n");
		return INVALID_INPUT;
	}

	player[i] = '\0';

	return 0;
}

	int game_surface(void){
		char temp[SMALL_SIZE_COLORCODE + 1];
		int turns = 1;
		int moves1 = 0;

		while(turns <= MAX_TURN) {
			do {
			++turns;
			++moves1;
				printf("Raten Sie den 4-stelligen Code\n");
			} while(choose_code(temp) != 0);

			if (checking(created_code_small, temp) == 0) {
				printf("\tSie haben gewonnen!\n");
				++won_games1;
				winning_moves1 += moves1;
				winning_moves1_classic += moves1;
				return WIN;
			}
		}

		printf("\tSie haben verloren!\n");
		printf("Der Code war: %s\n", created_code_small);
		++lost_games1;
		return LOSE;
	}

int game_surface_2(char player1[], char player2[]){
	char temp[SMALL_SIZE_COLORCODE + 1];
	int turns = 1;
	int moves1 = 0;
	int moves2 = 0;

	while(turns <= 2 * MAX_TURN) {
		if (turns % 2 == 1) {
			++turns;
			++moves1;
			do {
				printf("%s ist am Zug: Raten Sie den 4-stelligen Code\n", name1);
			} while(choose_code(temp) != 0);
			if (checking(player2, temp) == 0) {
				printf("\tSie haben gewonnen!\n");
				printf("Der Code von %s war: %s\n", name1, player1);
				++won_games1;
				winning_moves1 += moves1;
				winning_moves1_classic += moves1;
				++lost_games2;
				return WIN;
			}
		} else {
			++turns;
			++moves2;
			do {
				printf("%s ist am Zug: Raten Sie den 4-stelligen Code\n", name2);
			} while(choose_code(temp) != 0);
			if (checking(player1, temp) == 0) {
				printf("\tSie haben gewonnen!\n");
				printf("Der Code von %s war: %s\n", name2, player2);
				++won_games2;
				winning_moves2 += moves2;
				winning_moves2_classic += moves2;
				++lost_games1;
				return WIN;
			}
		}
	}

	printf("\tSie sind beide gescheitert!\n");
	printf("Der Code von %s war: %s\n", name1, player1);
	printf("Der Code von %s war: %s\n", name2, player2);
	++lost_games1;
	++lost_games2;
	return LOSE;
}

int checking(char set_code[], char guess[]){
	int i = 0, j = 0, black = 0, white = 0;
	char guess_copy[SMALL_SIZE_COLORCODE + 1];
	char set_code_copy[SMALL_SIZE_COLORCODE + 1];
	strcpy(set_code_copy, set_code);
	strcpy(guess_copy, guess);

	i = 0, j = 0;
	while(i < SMALL_SIZE_COLORCODE) {
		while(j < SMALL_SIZE_COLORCODE) {
			if(guess_copy[i] == set_code_copy[j]) {
				if (i == j) {
					++black;
					guess_copy[i] = 'a';
					set_code_copy[j] = 'b';
					j = SMALL_SIZE_COLORCODE;
				}
			}
		++j;
		}
	j = 0;
	++i;
	}

	i = 0, j = 0;
	while(i < SMALL_SIZE_COLORCODE) {
		while(j < SMALL_SIZE_COLORCODE) {
			if(guess_copy[i] == set_code_copy[j]) {
				++white;
				guess_copy[i] = 'a';
				set_code_copy[j] = 'b';
				j = SMALL_SIZE_COLORCODE;
			}
		++j;
		}
	j = 0;
	++i;
	}

	printf("black: %i, white: %i\n", black, white);

	if(black == 4) {
		return WIN;
	}

	return LOSE;
}

int flush_buff(void) {
	int c;
	while ((c = getchar ()) != '\n' && c != EOF )
		{}
	return c != EOF ;
}
