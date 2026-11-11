#include <stdio.h>

typedef struct {
    char nome[20];
    float nota;
} Aluno;

/* Insertion sort: estavel, empates mantem a ordem original (Bruno antes de Elis). */
void ordenarPorNota(Aluno v[], int n) {
    int i, j;
    Aluno chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j].nota < chave.nota) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int main() {
    Aluno turma[5] = {
        {"Ana",   7.0f},
        {"Bruno", 9.5f},
        {"Carla", 6.0f},
        {"Diego", 8.5f},
        {"Elis",  9.5f},
    };
    int i;
    ordenarPorNota(turma, 5);
    for (i = 0; i < 5; i++) {
        printf("%dº: %s (%.1f)\n", i + 1, turma[i].nome, turma[i].nota);
    }
    return 0;
}
