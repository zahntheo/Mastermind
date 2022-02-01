#include "header.h"
#include <stdio.h>

#define SMALL_SIZE_COLORCODE 4
#define BIG_SIZE_COLORCODE 5
#define NAME_MAX 15 

extern int number_players;
extern int game_mode;
extern char name1[NAME_MAX];
extern char name2[NAME_MAX];
int games = 0;


int main(void){
	char player1[SMALL_SIZE_COLORCODE + 1];
	char player2[SMALL_SIZE_COLORCODE + 1];
	char super_player1[BIG_SIZE_COLORCODE + 1];
	char super_player2[BIG_SIZE_COLORCODE + 1];
	
	printf("\t\t/// MASTERMIND /// SUPERMASTERMIND /// \n\n");

	headcount_players();
	rules();
	do{
		gamemode();
		printf("\n\t///SPIEL-OBERFLÄCHE\n");
		if (games == 0){
			names_player();
			read_statistics();
		}
		if (game_mode == 1){
			if (number_players == 2) {
				do {
					printf("Es ist %s dran. Erstellen Sie einen 4-stelligen Code ein, welcher nur Ziffern von 0-5 enthaelt\n", name1);
				} while(choose_code(player1) != 0);
				do {
					printf("Es ist %s dran. Erstellen Sie einen 4-stelligen Code ein, welcher nur Ziffern von 0-5 enthaelt\n", name2);
				} while(choose_code(player2) != 0);
				game_surface_2(player1, player2);
			} else {
				create_code();
				game_surface();
			}

		}else {
			if (number_players == 2) {
				do {
					printf("Es ist %s dran. Erstellen Sie einen 5-stelligen Code ein, welcher nur Ziffern von 0-7 enthaelt\n", name1);
				} while(choose_code_sm(super_player1) != 0);
				do {
					printf("Es ist %s dran. Erstellen Sie einen 5-stelligen Code ein, welcher nur Ziffern von 0-7 enthaelt\n", name2);
				} while(choose_code_sm(super_player2) != 0);
				game_surface_2_sm(super_player1, super_player2);
			} else {
				create_code_sm();
				game_surface_sm();
			}
		}
		++games;
	} while (repeat_play() == 0);
	
	write_statistics();
	
	return 0;
}
