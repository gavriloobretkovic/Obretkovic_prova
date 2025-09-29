#include <stdio.h>
#include <string.h>

#define MAX_CONTATTI 100


typedef struct {
    char nome[30];
    char cognome[30];
    char telefono[15];
} Contatto;

/
Contatto rubrica[MAX_CONTATTI];
int numContatti = 0;


void aggiungiContatto() {
    if (numContatti >= MAX_CONTATTI) {
        printf("Rubrica piena!\n");
        return;
    }

    printf("Inserisci nome: ");
    scanf("%29s", rubrica[numContatti].nome);

    printf("Inserisci cognome: ");
    scanf("%29s", rubrica[numContatti].cognome);

    printf("Inserisci telefono: ");
    scanf("%14s", rubrica[numContatti].telefono);

    numContatti++;
    printf("Contatto aggiunto con successo!\n");
}

void visualizzaContatti() {
    if (numContatti == 0) {
        printf("Rubrica vuota.\n");
        return;
    }

    printf("\n--- Contatti ---\n");
    for (int i = 0; i < numContatti; i++) {
        printf("%d. %s %s - %s\n", i+1,
               rubrica[i].nome,
               rubrica[i].cognome,
               rubrica[i].telefono);
    }
    printf("----------------\n");
}

void cercaContatto() {
    if (numContatti == 0) {
        printf("Rubrica vuota.\n");
        return;
    }

    char cognomeRicerca[30];
    printf("Inserisci cognome da cercare: ");
    scanf("%29s", cognomeRicerca);

    for (int i = 0; i < numContatti; i++) {
        if (strcmp(rubrica[i].cognome, cognomeRicerca) == 0) {
            printf("Trovato: %s %s - %s\n",
                   rubrica[i].nome,
                   rubrica[i].cognome,
                   rubrica[i].telefono);
            return;
        }
    }
    printf("Contatto non trovato.\n");
}

void eliminaContatto() {
    if (numContatti == 0) {
        printf("Rubrica vuota.\n");
        return;
    }

    char cognomeElimina[30];
    printf("Inserisci cognome da eliminare: ");
    scanf("%29s", cognomeElimina);

    for (int i = 0; i < numContatti; i++) {
        if (strcmp(rubrica[i].cognome, cognomeElimina) == 0) {
            // Sposta indietro tutti i contatti successivi
            for (int j = i; j < numContatti - 1; j++) {
                rubrica[j] = rubrica[j + 1];
            }
            numContatti--;
            printf("Contatto eliminato.\n");
            return;
        }
    }
    printf("Contatto non trovato.\n");
}

int main() {
    int scelta;

    do {
        printf("\n--- Rubrica ---\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza tutti i contatti\n");
        printf("3. Ricerca contatto per cognome\n");
        printf("4. Elimina contatto per cognome\n");
        printf("5. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1: aggiungiContatto(); break;
            case 2: visualizzaContatti(); break;
            case 3: cercaContatto(); break;
            case 4: eliminaContatto(); break;
            case 5: printf("Uscita in corso...\n"); break;
            default: printf("Opzione non valida!\n");
        }
    } while (scelta != 5);

    return 0;
}
