#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"

Program* InitMain() {
	Program* startup = malloc(sizeof(Lib) * 1);
	startup->loadedFileName = NULL;
	startup->f = NULL;
	startup->totalWords = 0;
	startup->log = malloc(sizeof(char) * 150);
	startup->log = "initlog";
	return startup;
}

int main()
{
    Program* startup = InitMain();
    InitLibrary(startup);
    char choice;
    do{
        if(strlen(startup->log) > 10){
            printf(startup->log);
        }
        printf("------- Dictionnaire C -------\n\n");
        printf("Fichier charge : ");
        if (startup->loadedFileName == NULL) {
            printf("Aucun fichier charge\n");
        }else {
            printf("%s\n", (char*)startup->loadedFileName);
        }
        printf("Nombre total de mots : %i\n\n", startup->totalWords);
        printf("1. Charger un dictionnaire\n2. Recherche avancee\n3. Quitter\nChoix : ");
        scanf("%c", &choice);
        switch(choice){
            case '1':
                free(startup->log);
                startup->log = malloc(sizeof(char) * 150);
                FileMenu(startup);
                break;
            case '2':
                free(startup->log);
                startup->log = malloc(sizeof(char) * 150);
                DicoMenu(startup);
                break;
            case '3':
                return 0;
                break;
            default:
                system("cls");
                break;
        }
    }while (choice != '1' || choice != '2' || choice != '3');
    return 0;
}

void FileMenu(Program* startup){
    system("cls");
    printf("     ------- Dictionnaire C -------\n------- Charger un dictionnaires -------\n\n");
    LoadFile(startup);
    system("cls");
}

void DicoMenu(Program* startup){
    if(startup->f == NULL){
        system("cls");
        sprintf(startup->log, "/!\\ : Aucun fichier dictionnaire charge, veuillez charger un fichier dictionnaire !\n\n");
        return;
    }
    system("cls");
    printf("     ------- Dictionnaire C -------\n------- Recherche avancee -------\n\n");
    AdvancedWordSearch(startup);
}
