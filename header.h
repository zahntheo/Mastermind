#ifndef MASTERMIND
#define MASTERMIND

#define CORRECT_COLOUR 0
#define WRONG_COLOUR 1

/*Globale Variable für Anzahl Spieler*/
/*Globale Variabel für Namen der Spieler (des Spielers)*/

/*Hauptfunktionen*/
void headcount_players(void); /*Anzahl Spieler*/
void gamemode(void);/*Auswahl Spielmodi*/
void names_player(void);/*Eingabe Namen der Spieler*/
void rules(void); /*Gibt bei Bedarf die Regeln aus*/
int repeat_play(void); /*nochmal spielen?*/
void statistics(void);/*Statistiken berrechnen und Ausgabe*/
void write_statistics(void); /*Statistiken werden in eine Datei geschrieben*/
void read_statistics(void); /*Statistiken werden aus einer Datei gelesen*/
int file_exists(char name[]); /*prüft, ob der Spieler schon eine Datei hat*/
/*"normales" Mastermind*/
void create_code(void);/*Farbcode für Einzelspieler*/
int choose_code(char player[]);/*Eingabe Farbcode bei 2 Spielern*/
int game_surface(void);/*Spieleroberfläche (eingabe der farben)*/
int game_surface_2(char player1[], char player2[]);/*Spieleroberfläche (eingabe der farben) 2 Spieler*/
int checking(char set_code[], char guess[]); /*auf Richtigkeit überprüfen*/
/*Super Mastermind*/
void create_code_sm(void);/*Farbcode für Einzelspieler*/
int choose_code_sm(char player[]);/*Eingabe Farbcode bei 2 Spielern*/
int game_surface_sm(void);/*Spieleroberfläche (eingabe der farben)*/
int game_surface_2_sm(char player1[], char player2[]);
int checking_sm(char set_code[], char guess[]); /*auf Richtigkeit überprüfen*/
/*Puffer*/
int flush_buff(void);



#endif
