#include "header.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_MAX 8
#define STATISTICS_MAX 15

int number_players; /*Globale Variable für Anzahl Spieler*/
char name1[NAME_MAX];/*Globale Variable für Namen der Spieler (des Spielers*/
char name2[NAME_MAX];/*Globale Variable für Namen der Spieler (des Spielers*/
int game_mode;/*Spielmodi*/
extern int won_games1;
extern int won_games2;
extern int won_games1_super;
extern int won_games2_super;
extern int lost_games1;
extern int lost_games2;
extern int lost_games1_super;
extern int lost_games2_super;
extern int winning_moves1;
extern int winning_moves2;
extern int winning_moves1_classic;
extern int winning_moves2_classic;
extern int winning_moves1_super;
extern int winning_moves2_super;
extern int games;

void names_player(void){
        if (number_players == 1){
                printf("Bitte Name eingeben: ");
                scanf("%s", name1);
                flush_buff();

        }else{
                printf("Bitte Name für Spieler 1 eingeben: ");
                scanf("%s", name1);
                printf("Bitte Namen für Spieler 2 eingeben: ");
                scanf("%s", name2);
				printf("\n");
                flush_buff();
        }
}
void headcount_players(void){
        printf("Bitte Spieleranzahl eingeben (bis zu 2 Spielern moeglich): ");
        scanf("%i", &number_players);
		flush_buff();
        while (number_players > 2 || number_players < 1){
                printf("Falsche Eingabe!\n");
                printf("Bitte erneut Spieleranzahl eingeben (bis zu 2 Spielern moeglich): ");
                scanf("%i", &number_players);
				flush_buff();
        }
}
void gamemode(void){
		printf("\t///AUSWAHL-SPIELMODUS\n");
        printf("1 --> Mastermind\n2 --> Super Mastermind\nBitte Spielmodi auswaehlen: ");
        scanf("%i", &game_mode);
        while (game_mode < 1 || game_mode > 2){
                printf("Falsche Eingabe!\n");
                printf("1 --> Mastermind\n2 --> Super Mastermind\nBitte Spielmodi auswaehlen: ");
                scanf("%i", &game_mode);
        }
		flush_buff();
}

int repeat_play(void){
        char ans[5];
		char ja[3] = "ja";
		char nein[5] = "nein";
		int i;
        printf ("\nWollen sie Ihre Statistiken sehen? Bitte mit Ja/Nein beantworten!\n");
        scanf("%s", ans);
		
		for(i = 0; ans[i] != '\0'; ++i) {
			ans[i] = tolower(ans[i]);
		}
		
        while (strcmp(ans, ja) != 0 && strcmp(ans, nein) != 0){
                printf("Falsche Eingabe!Bitte Antwort erneut eingeben:\n");
                scanf("%s", ans);

        }
        if (strcmp(ans, ja) == 0){
                statistics();
        }
        printf("\nWollen Sie nochmal spielen? Bitte mit Ja/Nein beantworten!\n");
        scanf("%s", ans);
        while (strcmp(ans, ja) != 0 && strcmp(ans, nein) != 0){
                printf("Falsche Eingabe!Bitte Antwort erneut eingeben:\n");
                scanf("%s", ans);
        }
        flush_buff();
        return strcmp(ans, ja);
}
void statistics(void){
        printf("\n\t///STATISTIKEN\n");
        printf("Spieler 1:\n");
        printf("Name: %s\n", name1);
		printf("Gesamt:\n");
		printf("\tGewonnene Spiele: %i\n", won_games1);
		printf("\tVerlorene Spiele: %i\n", lost_games1); 
		if (won_games1 == 0){
			printf("\tDurschnitlliche Spielzüge zum Sieg: 0\n");
        }else{
			printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves1 / (double) won_games1) );	
        }
		printf("MasterMind:\n");
		printf("\tGewonnen: %i\n", won_games1 - won_games1_super);
		printf("\tVerloren: %i\n", lost_games1 - lost_games1_super);
		if (won_games1 == won_games1_super) {
			printf("\tDurschnitlliche Spielzüge zum Sieg: 0\n");
		} else {
			printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves1_classic / ((double) won_games1 - won_games1_super)));
		}
		printf("SuperMasterMind:\n");
		printf("\tGewonnen: %i\n", won_games1_super);
		printf("\tVerloren: %i\n", lost_games1_super);
		if (won_games1_super == 0) {
			printf("\tDurschnitlliche Spielzüge zum Sieg: 0\n");
		} else {
			printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves1_super / (double) won_games1_super));
		}	
		
		if (number_players == 2) {
			printf("\nSpieler 2:\n");
			printf("Name: %s\n", name2);
			printf("Gesamt:\n");
			printf("\tGewonnene Spiele: %i\n", won_games2);
			printf("\tVerlorene Spiele: %i\n", lost_games2); 
			if (won_games2 == 0){
                printf("\tDurschnitlliche Spielzüge zum Sieg: 0\n");
			} else {
                printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves2 / (double) won_games2));
			}
			printf("MasterMind:\n");
			printf("\tGewonnen: %i\n", won_games2 - won_games2_super);
			printf("\tVerloren: %i\n", lost_games2 - lost_games2_super);
			if (won_games2 == won_games2_super) {
				printf("\tDurchschnittliche Spielzüge zum Sieg: 0\n");
			} else {
				printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves2_classic / ((double) won_games2 - won_games2_super)));
			}
			printf("SuperMasterMind:\n");
			printf("\tGewonnen: %i\n", won_games2_super);
			printf("\tVerloren: %i\n", lost_games2_super);
			if (won_games2_super == 0) {
				printf("\tDurschnitlliche Spielzüge zum Sieg: 0\n");
			} else {
				printf("\tDurschnitlliche Spielzüge zum Sieg: %f\n", ((double) winning_moves2_super / (double) won_games2_super));
			}
		}
        
}

void read_statistics(void) {
	FILE *fp;
	if(file_exists(name1) == 1){
		fp = fopen(name1, "r");
		fscanf(fp, "%d\n", &won_games1);
		fscanf(fp, "%d\n", &won_games1_super);
		fscanf(fp, "%d\n", &lost_games1);
		fscanf(fp, "%d\n", &lost_games1_super);
		fscanf(fp, "%d\n", &winning_moves1);
		fscanf(fp, "%d\n", &winning_moves1_classic);
		fscanf(fp, "%d\n", &winning_moves1_super);
		fclose(fp);
	}
	
	if(number_players == 2) {
		if(file_exists(name2) == 1){
			fp = fopen(name2, "r");
			fscanf(fp, "%d\n", &won_games2);
			fscanf(fp, "%d\n", &won_games2_super);
			fscanf(fp, "%d\n", &lost_games2);
			fscanf(fp, "%d\n", &lost_games2_super);
			fscanf(fp, "%d\n", &winning_moves2);
			fscanf(fp, "%d\n", &winning_moves2_classic);
			fscanf(fp, "%d\n", &winning_moves2_super);
			fclose(fp);
		}
	}
	
}

void write_statistics(void){
	FILE *fp;
	int i;
	int statistics1[STATISTICS_MAX];
	int statistics2[STATISTICS_MAX];
	statistics1[0] = won_games1;
	statistics1[1] = won_games1_super;
	statistics1[2] = lost_games1;
	statistics1[3] = lost_games1_super;
	statistics1[4] = winning_moves1;
	statistics1[5] = winning_moves1_classic;
	statistics1[6] = winning_moves1_super;
	statistics2[0] = won_games2;
	statistics2[1] = won_games2_super;
	statistics2[2] = lost_games2;
	statistics2[3] = lost_games1_super;
	statistics2[4] = winning_moves2;
	statistics2[5] = winning_moves2_classic;
	statistics2[6] = winning_moves2_super;
	
	if (file_exists(name1) == 0) {
		fp = fopen(name1, "a+");

		for(i = 0; i < 7; ++i){
			fprintf(fp, "%i\n", statistics1[i]);
		}
	} else {
		fp = fopen(name1, "w");
		
		for(i = 0; i < 7; ++i){
			fprintf(fp, "%i\n", statistics1[i]);
		}
	}
	
	if (number_players == 2) {
		if (file_exists(name2) == 0) {
			fp = fopen(name2, "a+");
			for(i = 0; i < 7; ++i){
				fprintf(fp, "%i\n", statistics2[i]);
			}
		} else {
			fp = fopen(name2, "w");
			for(i = 0; i < 7; ++i){
				fprintf(fp, "%i\n", statistics2[i]);
			}
		}
	}
	
}

int file_exists(char name[]){
	FILE *fp;
	int result;
	
	fp = fopen(name, "r");
	if (fp == NULL) {
		result = 0;
	} else {
		result = 1;
		fclose(fp);
	}
	
	return result;
}


void rules(void){
	char ans[5];
	char ja[3] = "ja";
	char nein[5] = "nein";
	int i;
	printf ("\nWollen sie die Regeln lesen? Bitte mit Ja/Nein beantworten!\n");
	scanf("%s", ans);
		
	for(i = 0; ans[i] != '\0'; ++i) {
		ans[i] = tolower(ans[i]);
	}
		
    while (strcmp(ans, ja) != 0 && strcmp(ans, nein) != 0){
		printf("Falsche Eingabe!Bitte Antwort erneut eingeben:\n");
		scanf("%s", ans);
	}
		if (strcmp(ans, ja) == 0){
			printf("\n\t/// REGELN\n");
			printf("In MasterMind muss durch Setzen von Pins ein Code erraten werden.\n");
			printf("Ziel ist es, in einer Reihe verschiedenfarbige Pins in der richtigen Reihenfolge anzuordnen.\n"); 
			printf("Das so entstandene Muster muss am Ende der versteckten Vorgabe des Codierers gleichen. \n");
			printf("Der Spieler hat bis zu 12 Versuche, um den Code zu knacken. \n");
			printf("Dieser besteht aus 4 Pins, die wiederum aus 6 Farben (dargestellt durch die Ziffern 0-5) ausgewählt werden können. \n");
			printf("Dabei kann eine Farbe/Ziffer auch mehrmals vertreten sein. \n");
			printf("In jeder Runde rät der Spieler den Code durch Eingabe der Ziffern in der entsprechenden Reihenfolge. \n");
			printf("Ob die Pins korrekt platziert wurden, zeigen die weißen und schwarzen Pins an. \n");
			printf("Schwarz bedeutet hierbei, dass entsprechend viele Ziffern an der korrekten Stelle platziert wurden. \n ");
			printf("Weiß bedeutet, dass entsprechend viele Ziffern übereinstimmen (aber an einer falschen Stelle platziert wurden). \n");
			printf("\n");
			printf("Multiplayer: \n");
			printf("Im Multiplayer wird der zu erratende Code vom gegnerischen Spieler erstellt und abwechselnd geraten. \n");
			printf("\n");
			printf("Supermastermind: \n");
			printf("Es gibt 5 statt 4 Pins und 8 statt 6 Farben. \n");
			printf("\n");
			printf("Quelle: https://info.lite.games/de/support/solutions/articles/60000688841-mastermind-spielregeln\n\n");
		}
}