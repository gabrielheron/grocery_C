#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LETRAS_PRODUTOS 10
#define MAX_ESTOQUE_PRODUTOS 100

/* --- Quitanda --- */

/*
   1 - Verificar as opcoes
   2 - Escolher uma das opcoes apertando o numero determinado por ela
   3 - Seguir o programa
*/

// Configuracoes padrao para os produtos
struct produto {
        int codigo;
        char nome [MAX_LETRAS_PRODUTOS];
        float preco;
        int qnt [MAX_ESTOQUE_PRODUTOS];
    };

// typedef struct produto produto;

// Gerador de codigo
void produto_codigo(struct codigo cod[], int tam)
{
    for (i = 0; i < tam; i++)
    {
        cod[i].codigo = 1003 + i;
        snprintf(cod[i].nome, sizeof(cod[i].nome), "O codigo do produto %d", cod[i].codigo);
    };
}

void produto_exibir (struct produto produtos[], int est)
{
    printf("Produtos em estoque:\n");
    for (i = 0; i < est; i++){
        printf("Codigo: %d, Nome: %s, Preco: %.2f, Quantidade: %d\n",
               produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].qnt)
    }
}

int produto_adicionar()
{
    for (i=0; i< o; i++)
    {
        printf("Qual o produto escolhido:\n");
        scanf("%s", produtos[i].nome);

        printf("Qual a quantidade:\n");
        scanf("%d", produtos[i].qnt );
    }
}

void produto_remover(struct produto cod[]. int *est, int codigo)
{
    int found = -1;

    // Achar o produto para remover
    for (i = 0; i < *est; i++)
    {
    if(produtos[i].codigo == codigo )
        {
        found = i;
        break
        }
    }

    // O produto encontrado sera removido
    if (found != -1) {
        for (int i = found; i < *est - 1; i++) {
            produtos[i] = produtos[i + 1]; // Mover produtos para a esquerda
        }
        (*est)--; // Diminuir a quantidade de produtos
        printf("Produto %s %d foi removido com sucesso!\n", produtos[i].nome, codigo);
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void estoque_adicionar(struct produto )
{
     printf("Indique o nome do produto:\n");
        canf("%s", cod[i].nome);

        printf("Indique o preco do Produto:\n");
        scanf("%.2f", &cod[i].preco);
        
        printf("Indique q quantidade que vai estar em estoque:\n");
        scanf("%d", &cod[i].qnt);
        
}

//void estoque_remover()
{
}

void estoque_verificar()
{
    printf("printf             ***** ESTOQUE ***** \n");
    printf("---------------------------------------------------------
    ---------\n");
    printf("Numero|    NOME          |   CODIGO  |  QUANTIDADE |  PRECO \n");
    printf("---------------------------------------------------------
    ---------\n")
    
    for (i = 0; i < est; i++)
    {
        printf("%d %s %.2f %d \n", i+1, produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].qnt);
    }
}

void carrinho_verificar(){

}

float carrinho_soma(float *a, float *b){
    float soma;
    return soma = (a+b);
}

int main() {

    int options;
    printf("                    ----- QUITANDA-----\n ");
    printf("---------------------------------------------------------
    ---------\n");
    printf("Numero|    NOME          |   CODIGO  |  QUANTIDADE |  PRECO \n");
    printf("---------------------------------------------------------
    ---------\n")
    printf("")

    do {

        printf("Opcoes:
        1 - Adicionar carrinho\n
        2 - Remover carrinho\n
        3 - Adicionar estoque\n
        4 - Remover estoque\n
        5 - Verificar estoque\n
        6 - Verificar carrinho\n
        7 - Comprar\n
        8 - Sair\n
        ");

        scanf("%d", &options);

            switch (options)
            {
                case 1:

                    do {
                    printf("Indique o nome do produto: ");
                    scanf("%s", produtos[i].nome);
                    } while ()


                break;
                case 2:
                break;
                case 3:
                    

                break;
                case 4:
                    printf("Qual o produto que ira remover (indique o seu codigo):\n");
                    //scanf("%d", &cod[i].codigo);

                    if (cod[i].codigo > 1000 && cod[i].codigo < 1011){
                        produto_remover;
                    } else {
                        printf("Opcao invalida!");
                    }
                break;
                case 5:
                    printf("")
                break;
                case 6:
                break;
                case 7:
                    printf("A compra sera realizada ...");
                    printf("O preco total foi %.2f!", compra_soma);
                    prinft("Comprar agora(1) ou pendurar(2) ?");
                    scanf("%c", result);

                    if (result == "1")
                    { 
                        printf("Compra realizada!");
                        printf("Saindo...");
                        getchar();   
                    } else if (result == "2"){

                    } else {
                        printf("Opcao invalida!");
                    }
                break;
                case 8:
                    printf("Saindo...");
                break;
                default
                printf("Opcao invalida!");
                break;

    } while (options != 8);

    if (options != 8)
    {
        printf("Obrigado pela compra!");
    } else {
        printf("Compre na proxima vez");
    }

    printf("Pressione ENTER para sair!");
    getchar();
    
    return 0;
}
