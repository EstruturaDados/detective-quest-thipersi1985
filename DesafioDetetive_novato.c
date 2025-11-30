#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

//função que cria e inicializa um novo nó, armazenando o valor recebido
struct No* criarSala(char* valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No)); //aloca dinamicam. memória para um novo nó e guarda o endereço em 'novo'
    strcpy(novo->valor, valor); //copia o valor passado como parâmetro (string) para o campo 'valor' do nó
    novo->esquerda = NULL; // inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
    novo->direita = NULL;
    return novo; // retorna o endereço do novo nó criado.
}

//função que libera toda a memória alocada para uma árvore binária de forma recursiva.
void liberar(struct No* raiz) {
    if (raiz != NULL) {             //se o nó atual existir
        liberar(raiz->esquerda);    //libera primeiro a subárvore esquerda
        liberar(raiz->direita);     //depois a subárvore direita
        free(raiz);                 //por último, libera o próprio nó atual
    }
}

//função para limpar o buffer de entrada
void limparBuffer() {     
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcao; //variável que será usada no menu de opções abaixo

    //cria o nó raiz da árvore, representando o 'hall de entrada'
    struct No* raiz = criarSala("Hall de Entrada");
    
    //liga os nós 'sala, quarto e banheiro' como filhos à esquerda da raiz
    raiz->esquerda = criarSala("Sala");
    raiz->esquerda->esquerda = criarSala("Quarto");
    raiz->esquerda->direita = criarSala("Banheiro");
    
    //liga os nós 'biblioteca, salão de jogos e salão de festas' como filhos à direita da raiz
    raiz->direita = criarSala("Biblioteca");
    raiz->direita->direita = criarSala("Salão de Jogos");
    raiz->direita->esquerda = criarSala("Salão de Festas");

    do {
        printf("BEM-VINDO AO JOGO DETECTIVE QUEST\n");
        printf("Vamos explorar a mansão a partir do Hall de Entrada.\n");
        printf("==========================================\n");
        printf("Digite 1 - Se deseja ir para a esquerda\n");
        printf("Digite 2 - Se deseja ir para a direita\n");
        printf("0 - Sair\n");
        printf("==========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();     // Limpa o '/n' deixado pelo scanf.

        // processamento das opções
        switch (opcao) {
            case 1:
                if (opcao == 1) {
                    if (raiz != NULL) {  
                        printf("Você chegou à(o) %s\n", raiz->esquerda);     
                        raiz = raiz->esquerda;
                    } else {
                        printf("Não há mais cômodos a explorar!");
                    }
                }
                // a pausa abaixo é crucial para que o usuário veja a lista antes do próximo loop limpar a tela.
                printf("\nPressione enter para continuar...");
                getchar();
            break; 
            case 2:
                if (opcao == 2) {
                    if (raiz != NULL) {
                        printf("Você chegou à(o) %s\n", raiz->direita);
                        raiz = raiz->direita;
                    } else {
                        printf("Não há mais cômodos a explorar!");
                    }
                }
                // a pausa abaixo é crucial para que o usuário veja a lista antes do próximo loop limpar a tela.
                printf("\nPressione enter para continuar...");
                getchar();
            break;
            case 0:
                printf("saindo do jogo...\n");
            break;
            default:
                printf("Você escolheu uma opção inválida. Tente novamente!\n");
            break;
        }
    } while (opcao !=0);

    //libera toda a memória alocada para a árvore
    liberar(raiz);

    return 0; 

}