#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"

Program* InitMain() {
	Program* startup = malloc(sizeof(Lib) * 1);
	startup->loadedFileName = NULL;
	startup->f = NULL;
	startup->totalWords = 0;
	return startup;
}

int main()
{
    Program* startup = InitMain();
    InitLibrary(startup);
    do{
        int choice;
        printf("------- Dictionnaire C -------\n\n");
        printf("Fichier charge : ");
        if (startup->loadedFileName == NULL) {
            printf("Aucun fichier charge\n");
        }else {
            printf("%s\n", (char*)startup->loadedFileName);
        }
        printf("Nombre total de mots : %i\n\n", startup->totalWords);
        printf("1. Charger un dictionnaire\n2. Recherche avancee\nChoix : ");
        scanf("%i", &choice);
        switch(choice){
            case 1:
                FileMenu(startup);
                break;
            case 2:
                DicoMenu(startup);
                break;
        }
    }while (1);
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
        printf("/!\\ : Aucun fichier dictionnaire charge, veuillez charger un fichier dictionnaire !\n\n");
        return;
    }
    system("cls");
    printf("     ------- Dictionnaire C -------\n------- Recherche avancee -------\n\n");
    AdvancedWordSearch(startup);
}
