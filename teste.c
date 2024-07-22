#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { //criando um nó = guarda um valor e o endereço do próximo nó para onde irá apontar
    char valor[4]; //seu valor
    struct Node* prox; //endereço do nó para onde irá apontar (ponteiro de struct = lugar na memória para o endereço da struct Nó)
} Node;

typedef struct Pilha { //criando uma pilha = guarda vários nós e uma referência para o seu topo 
    int tam; //quantidade de nós
    Node* top; //ponteiro de struct = lugar na memória reservado para guardar o endereço da primeira struct nó da pilha
} Pilha;

void push (Pilha *stack, char numero[4]) { //push = inserir; (onde irei inserir, o que irei inserir)
    Node* novo_no = NULL; //criei uma regiao na memória que reservada para guardar o endereço de um nó (que eh uma struct)
    novo_no = (Node *)malloc (sizeof(Node)); //criei um nó = um lugar na memoria que cabe a struct Node e que o ponteiro criado está apontando
    strcpy((*novo_no).valor, numero); //no nó criado coloquei o valor desejado para ele = (*stack).top
    (*novo_no).prox = stack->top; //no nó criado coloquei o endereço de memória para onde o ponteiro top da pilha apontava 
    stack->top = novo_no; //fiz o ponteiro top da pilha ter o mesmo valor(endereço) que o ponteiro novo_no tem = ponteiro top está apontando para o mesmo lugar que o ponteiro novo_no esta 
    stack->tam = stack->tam + 1;
}

void pop (Pilha *stack, char apagado[4]) { //pop = deletar; (de qual pilha irei retirar o nó)
    Node* temp; //lugar na memoria reservado para guardar o endereço da struct Node 
    strcpy(apagado,(*(stack->top)).valor); //valor do nó que estou apagando 
    temp = stack->top; //dois ponteiros apontando para o mesmo nó que está no topo da pilha = temp guardou o endereço do nó que deletarei 
    stack->top = stack->top->prox; //ponteiro do topo da pilha agora irá apontar para onde o ponteiro do primeiro nó da pilha apontava
    free(temp); //deleto o ponteiro temp e, consequentemente, apago as informações na memória do nó que retirei da pilha
    stack->tam = stack->tam - 1;
}

void top (Pilha *stack, char valor_topo[4]) { //valor no topo da pilha
    strcpy(valor_topo,stack->top->valor);
}

void limpa_pilha (Pilha *stack) { //apagando todos os elementos da pilha
    char aux[4];
    while(stack->top != NULL) {
        pop(stack,aux);
    }
}

typedef struct Link {
  char element[4];
  struct Link *next;
} Link;

typedef struct Fila {
  Link *header;
  Link *tail;
  int cnt;
} Fila;

Link *createLink(char element[4], Link *next) {
  Link *n = (Link *)malloc(sizeof(Link));
  strcpy(n->element, element);
  n->next = next;
  return n;
}

void append(Fila *l, char item[4]) {
  l->tail->next = createLink(item, NULL);
  l->tail = l->tail->next;
  l->cnt++;
}

void removeLink(Fila *l, char e[4]) {
  if (l->cnt == 0) return;

  Link *temp = l->header->next;
  strcpy(e, temp->element);

  if (temp == l->tail) {
    l->tail = l->header;
  }

  l->header->next = l->header->next->next; 
  l->cnt--;
  free(temp);
}

int length(Fila *l) { return l->cnt; }

void clear(Fila *l) {
    char aux[4];
    while (l->header->next != NULL) {
        removeLink(l, aux);
    }
}

void destroyFila(Fila *l) {
  clear(l);
  free(l->header);
  free(l);
}

Fila *createFila() {
    char aux[4];
    Fila *temp = (Fila *)malloc(sizeof(Fila));
    temp->header = createLink(aux, NULL);  // Header Link
    temp->tail = temp->header; 
    temp->cnt = 0;
    return temp;
}


int main() {
    int cont = -1;
    char condicao[5];
    char infocarta[5];
    int numero_jogadores;
    Pilha stack_main; //criando uma pilha
    stack_main.tam = 0; //começa sem elementos nela
    stack_main.top = NULL; //começa com o ponteiro que referencia o topo dela apontando para NULL
    scanf("%d", &numero_jogadores);
    Fila* jogador[numero_jogadores];
    for(int i = 0; i < numero_jogadores; i++) {
        jogador[i] = createFila();
    }


    do{
        scanf(" %s", condicao);
        if(strcmp("DEA", condicao) == 0) {
            for(int i = 0; i < numero_jogadores; i++) {
                scanf(" %s", infocarta);
                append(jogador[i], infocarta);
            }
        }
        else if(strcmp("RND", condicao) == 0) {
            limpa_pilha(&stack_main);
            cont++;
            char maior_carta[5];
            strcpy(maior_carta, jogador[0]->header->next->element);
            int melhor_jogador = 0;
            push(&stack_main, jogador[0]->header->next->element);
            for(int i = 1; i < numero_jogadores; i++) {
                push(&stack_main, jogador[i]->header->next->element);
                if(strcmp(jogador[i]->header->next->element, maior_carta) > 0) {
                    strcpy(maior_carta, jogador[i]->header->next->element);
                    melhor_jogador = i;
                }
                else if(strcmp(jogador[i]->header->next->element, maior_carta) == 0) {
                    strcpy(maior_carta, jogador[i]->header->next->element);
                    melhor_jogador = -1;
                }
            }
            printf("%d %d\n", cont, melhor_jogador);
        }
        else if(strcmp("PRT", condicao) == 0) {
            for(int i = 0; i < numero_jogadores; i++) {
                char aux[4];
                pop(&stack_main, aux);
                printf("%s ", aux);
            }
            printf("\n");
        }
    } while(strcmp(condicao, "END") != 0);

    return 0;
}