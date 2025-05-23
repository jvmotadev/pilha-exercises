#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char dados[50];
    int topo;
} PilhaChar;

// Inicializa a pilha vazia
void inicializar(PilhaChar* p) {
    p->topo = -1;
}

// Empilha um caractere, retorna false se estiver cheia
bool pushChar(PilhaChar* p, char c) {
    if (p->topo == 49) {
        // Pilha cheia
        return false;
    }
    p->topo++;
    p->dados[p->topo] = c;
    return true;
}

// Desempilha e retorna o caractere do topo, retorna '\0' se estiver vazia
char popChar(PilhaChar* p) {
    if (p->topo == -1) {
        // Pilha vazia
        return '\0';
    }
    char c = p->dados[p->topo];
    p->topo--;
    return c;
}

// Retorna o caractere do topo sem remover, retorna '\0' se estiver vazia
char topChar(PilhaChar* p) {
    if (p->topo == -1) {
        return '\0';
    }
    return p->dados[p->topo];
}

// Verifica se a pilha está vazia
bool vazia(PilhaChar* p) {
    return p->topo == -1;
}

// Exibe os elementos da pilha do topo ate a base
void exibir(PilhaChar* p) {
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%c ", p->dados[i]);
    }
    printf("\n");
}

// Teste: Empilhe as letras A, B, C, D e depois desempilhe todas
int main() {
    PilhaChar pilha;
    inicializar(&pilha);

    // Empilhando A, B, C, D
    pushChar(&pilha, 'A');
    pushChar(&pilha, 'B');
    pushChar(&pilha, 'C');
    pushChar(&pilha, 'D');

    exibir(&pilha);

    // Desempilhando todos os elementos com o while
    while (!vazia(&pilha)) {
        char c = popChar(&pilha);
        printf("Desempilhado: %c\n", c);
    }

    return 0;
}
