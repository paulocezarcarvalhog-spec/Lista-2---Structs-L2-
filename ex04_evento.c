#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[30];
    Data data;
} Evento;

int dataMaior(Data d1, Data d2) {
    if (d1.ano != d2.ano) return d1.ano > d2.ano;
    if (d1.mes != d2.mes) return d1.mes > d2.mes;
    return d1.dia > d2.dia;
}

Evento *eventoMaisRecente(Evento v[], int n) {
    int i;
    Evento *maior = &v[0];
    for (i = 1; i < n; i++) {
        if (dataMaior(v[i].data, maior->data)) {
            maior = &v[i];
        }
    }
    return maior;
}

int main() {
    Evento agenda[4] = {
        {"Reuniao de projeto",    {10, 3, 2026}},
        {"Entrega do TCC",        {21, 9, 2026}},
        {"Seminario de pesquisa", {5, 9, 2026}},
        {"Banca",                 {2, 12, 2025}},
    };
    Evento *e;
    e = eventoMaisRecente(agenda, 4);
    printf("Mais recente: %s (%d/%d/%d)\n", e->nome, e->data.dia, e->data.mes,
           e->data.ano);
    return 0;
}
