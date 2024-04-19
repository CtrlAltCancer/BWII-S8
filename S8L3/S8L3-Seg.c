#include <stdio.h>

int main() {
    int vector[10], i, j, k;
    int swap_var;
    int scelta;
//Menù con scelta programma
    printf("Benvenuto, i NetRaiders sono qui per aiutarti, o forse no!\n");
    printf("Scegli il programma da eseguire:\n");
    printf("1. Programma corretto\n");
    printf("2. Programma con errore di segmentazione\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    if (scelta == 1) {
        printf("Esecuzione del programma corretto...\n");

        printf("Inserire 10 interi:\n");
        for (i = 0; i < 10; i++) {
            printf("[%d]:", i + 1);
            while (scanf("%d", &vector[i]) != 1) { //in caso di inserimento lettera o simbolo, restituisce un messaggio di errore e non prosegue con l'array
                printf("Input non valido. Devi inserire un numero intero.\n");
                while (getchar() != '\n'){
                printf("[%d]:", i + 1);
                }
            }
        }
        //Stampa output vettore inserito
        printf("Il vettore inserito e':\n");
        for (i = 0; i < 10; i++) {
            int t = i + 1;
            printf("[%d]: %d\n", t, vector[i]);
        }

        //Ordinamento del vettore
        for (j = 0; j < 10 - 1; j++) {
            for (k = 0; k < 10 - j - 1; k++) {
                if (vector[k] > vector[k+1]) {
                    swap_var = vector[k];
                    vector[k] = vector[k+1];
                    vector[k+1] = swap_var;
                }
            }
        }
		//Stampa del vettore ordinato
        printf("Il vettore ordinato e':\n");
        for (j = 0; j < 10; j++) {
            int g = j + 1;
            printf("[%d]: %d\n", g, vector[j]);
}
    } 
    else if (scelta == 2) {
        printf("Esecuzione del programma con errore di segmentazione...\n");
		//Scopo: Provocare un errore di segmentazione inserendo più interi del consentito
        printf("Inserire 23 numeri interi:\n");
        for (i = 0; i < 23; i++) {
            printf("[%d]:", i + 1);

            //Inserimento di soli numeri
            while (scanf("%d", &vector[i]) != 1) {
                printf("Input non valido. Devi inserire un numero intero.\n");
                while (getchar() != '\n'){ 
                printf("[%d]:", i + 1);
                }
            }
        }

        printf("Il vettore inserito e':\n");
        for (i = 0; i < 15; i++) {
            int t = i + 1;
            printf("[%d]: %d\n", t, vector[i]);
			//Si verifica un errore di segmentazione perche' sono stati inseriti più numeri di quanti il vettore ne possa gestire.
        }
    } 
    else { //Controllo dell'input di scelta
        printf("Scelta non valida.\n");
        return 1; // Uscita con codice di errore 1
    }

    return 0; //Uscita senza errori
}
