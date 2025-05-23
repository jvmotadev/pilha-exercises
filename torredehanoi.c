#include <stdio.h>
#include <stdbool.h>

#define MAX 50

// Pilha para discos
typedef struct {
    int dados[MAX];
    int topo;
} PilhaEstatica;

// Inicializa pilha vazia
void inicializarPilha(PilhaEstatica* p) {
    p->topo = -1;
}

// Verifica se pilha está vazia
bool pilhaVazia(PilhaEstatica* p) {
    return p->topo == -1;
}

// Retorna elemento do topo
int topoPilha(PilhaEstatica* p) {
    if (pilhaVazia(p)) return -1;
    return p->dados[p->topo];
}

// Empilha um elemento, retorna false se cheia
bool push(PilhaEstatica* p, int valor) {
    if (p->topo == MAX - 1) return false;
    p->topo++;
    p->dados[p->topo] = valor;
    return true;
}

// Desempilha e retorna o valor, retorna -1 se vazia
int pop(PilhaEstatica* p) {
    if (pilhaVazia(p)) return -1;
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

// Estrutura do jogo de hanoi com 3 torres
typedef struct {
    PilhaEstatica torre[3];  // torres A, B, C
    int num_discos;
} JogoHanoi;

// Inicializa o jogo com n discos na torre A
void inicializarHanoi(JogoHanoi* jogo, int n) {
    jogo->num_discos = n;
    // Inicializa as 3 torres vazias
    for (int i = 0; i < 3; i++) {
        inicializarPilha(&jogo->torre[i]);
    }
    // Empilha discos na torre A, do maior (n) na base para o menor (1) no topo
    for (int i = n; i >= 1; i--) {
        push(&jogo->torre[0], i);
    }
}

// Move disco da torre origem para torre destino se válido
bool moverDisco(JogoHanoi* jogo, int origem, int destino) {
    if (pilhaVazia(&jogo->torre[origem])) {
        // Torre origem vazia, não pode mover
        return false;
    }
    int discoOrigem = topoPilha(&jogo->torre[origem]);
    int discoDestino = topoPilha(&jogo->torre[destino]);

    // Movimento válido se a torre destino estiver vazia ou topo destino for maior que disco origem
    if (discoDestino == -1 || discoOrigem < discoDestino) {
        // Realiza movimento
        pop(&jogo->torre[origem]);
        push(&jogo->torre[destino], discoOrigem);
        printf("Movendo disco %d da torre %c para torre %c\n",
            discoOrigem, 'A' + origem, 'A' + destino);
        return true;
    }
    // Movimento inválido
    return false;
}

// Resolve o jogo Torre de Hanói recursivamente
void resolverHanoi(JogoHanoi* jogo, int n, int origem, int destino, int auxiliar) {
    if (n == 1) {
        moverDisco(jogo, origem, destino);
    } else {
        resolverHanoi(jogo, n - 1, origem, auxiliar, destino);
        moverDisco(jogo, origem, destino);
        resolverHanoi(jogo, n - 1, auxiliar, destino, origem);
    }
}

int main() {
    JogoHanoi jogo;
    int discos = 3;

    inicializarHanoi(&jogo, discos);

    printf("Início do jogo Torre de Hanói com %d discos\n", discos);
    resolverHanoi(&jogo, discos, 0, 2, 1);

    return 0;
}
