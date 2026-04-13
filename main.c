#include <stdio.h>

#define MAX 100

// fonctions pour gérer les notes
void ajouterNote(int notes[], int *n) {
    if(*n < MAX) {
        printf("Entrer la note : ");
        scanf("%d", &notes[*n]);
        (*n)++;
    } else {
        printf("Tableau plein !\n");
    }
}

void afficherNotes(int notes[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", notes[i]);
    }
    printf("\n");
}

float calculMoyenne(int notes[], int n) {
    if(n == 0) return 0;

    float somme = 0;
    for(int i = 0; i < n; i++) {
        somme += notes[i];
    }
    return somme / n;
}

int maxNote(int notes[], int n) {
    int max = notes[0];
    for(int i = 1; i < n; i++) {
        if(notes[i] > max) max = notes[i];
    }
    return max;
}

int minNote(int notes[], int n) {
    int min = notes[0];
    for(int i = 1; i < n; i++) {
        if(notes[i] < min) min = notes[i];
    }
    return min;
}

void supprimerNote(int notes[], int *n) {
    int pos;
    printf("Position à supprimer : ");
    scanf("%d", &pos);

    if(pos >= 0 && pos < *n) {
        for(int i = pos; i < *n - 1; i++) {
            notes[i] = notes[i + 1];
        }
        (*n)--;
    } else {
        printf("Position invalide\n");
    }
}

int main() {
    int notes[MAX];
    int n = 0;
    int choix;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter une note\n");
        printf("2. Afficher les notes\n");
        printf("3. Moyenne\n");
        printf("4. Note max\n");
        printf("5. Note min\n");
        printf("6. Supprimer une note\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterNote(notes, &n); break;
            case 2: afficherNotes(notes, n); break;
            case 3: printf("Moyenne = %.2f\n", calculMoyenne(notes, n)); break;
            case 4: printf("Max = %d\n", maxNote(notes, n)); break;
            case 5: printf("Min = %d\n", minNote(notes, n)); break;
            case 6: supprimerNote(notes, &n); break;
        }

    } while(choix != 0);

    return 0;
}