#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    char nome[30];
    int prioridade;
    struct Tarefa *prox;
} Tarefa;

Tarefa *inserirTarefa(Tarefa *inicio, char nome[], int prioridade) {
    Tarefa *novo = (Tarefa *) malloc(sizeof(Tarefa));
    Tarefa *atual;
    if (novo == NULL) {
        return inicio; /* sem memoria: lista permanece inalterada */
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->prioridade = prioridade;

    /* Insercao no inicio (lista vazia ou menor prioridade) */
    if (inicio == NULL || prioridade < inicio->prioridade) {
        novo->prox = inicio;
        return novo;
    }

    /* Avanca ate o ultimo no com prioridade <= nova (empates mantem ordem de chegada) */
    atual = inicio;
    while (atual->prox != NULL && atual->prox->prioridade <= prioridade) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return inicio;
}

void imprimirLista(Tarefa *inicio) {
    Tarefa *p;
    for (p = inicio; p != NULL; p = p->prox) {
        printf("%s (%d)\n", p->nome, p->prioridade);
    }
}

int main() {
    Tarefa *fila = NULL;
    Tarefa *p;
    fila = inserirTarefa(fila, "Corrigir bug critico", 1);
    fila = inserirTarefa(fila, "Responder e-mails", 5);
    fila = inserirTarefa(fila, "Preparar aula", 2);
    fila = inserirTarefa(fila, "Revisar artigo", 3);
    imprimirLista(fila);
    while (fila != NULL) {
        p = fila;
        fila = fila->prox;
        free(p);
    }
    return 0;
}
