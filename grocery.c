#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LETRAS_PRODUTOS 10
#define MAX_ESTOQUE 100
#define MAX_CARRINHO 50 

/* --- Quitanda --- */

struct produto {
    int codigo;
    int nome[MAX_LETRAS_PRODUTOS];
    int preco;
    int qnt;
}

void estoque_adicionar (struct produto estoque[], int *qnt_estoque)
// Um array 'estoque[]' que armazena os produtos da struct
// Um ponteiro que '*qnt_estoque' modifica a variável diretamente na função   
{
    if (qnt_estoque >= MAX_ESTOQUE) 
    {
        printf("Estoque cheio!\n");
        return; // Se o estoque estiver cheio a função retorna 
    }

    printf("Nome do produto:\n", MAX_LETRAS_PRODUTOS - 1);
    scanf("%s", estoque[*qnt_estoque].nome);

    do {
        printf("Valor do produto:\n");
        scanf("%.2f", estoque[*qnt_estoque].preco);
        if (estoque[*qnt_estoque].preco < 0) 
        {
            printf("O preco nao pode ser negativo. Tente novamente.\n");
        }
    } while (estoque[*qnt_estoque].preco < 0);    
    
    do {
        printf("A quantidade que vai para o estoque");
        scanf("%d", estoque[*qnt_estoque].qnt);
        if (estoque[*qnt_estoque].qnt < 0)
        {
            printf("A quantidade em estoque nao pode ser negativo. Tente novamente. \n");
        }
    } while (estoque[*qnt_estoque].qnt < 0);
    
    estoque[*qnt_estoque].codigo = 1000 + *qnt_estoque; 
    printf("Produto %s foi adicionado com o codigo %d", estoque[*qnt_estoque].nome, estoque[*qnt_estoque].codigo);

    (*qnt_estoque)++; 
}

void estoque_remover (struct produto estoque[], int *qnt_estoque, int codigo)
{
    int encontrar = -1;

    for (i = 0; i < *qnt_estoque; i++)
    {
        if (estoque[i].codigo == codigo)
        {
            encontrar = i;
            break;
        }
    }

    if (encontrar != -1)
    {
        for (int i = encontrar; i < *qnt_estoque; i++) 
        {
            estoque[i] = estoque[i + 1]; // Irá mover o elemento para a esquerda
        }
        (*qnt_estoque)--;
        printf("Produto removido do estoque. \n");
    } else {
        printf("Produto nao encontrado. \n");
    }
}

void estoque_verificar (struct produto estoque[], int qnt_estoque)
{
    if (qnt_estoque == 0)
    {
        printf("Estoque vazio! \n");
        return;
    }
    printf("printf             ***** ESTOQUE ***** \n");
    printf("---------------------------------------------------------
    ---------\n");
    printf("Numero|    NOME          |   CODIGO  |  QUANTIDADE |  PRECO \n");
    printf("---------------------------------------------------------
    ---------\n")
    
    for (i = 0; i < qnt_estoque; i++)
    {
        printf("%d %s %.2f %d \n", i+1, estoque[i].codigo, estoque[i].nome, estoque[i].preco, estoque[i].qnt);
    }
}

void carrinho_adicionar (struct produto estoque[], int qnt_produtos, struct produto carrinho[], int *qnt_carrinhos)
{
    int encontrar = -1;

    if (qnt_carrinho >= MAX_ESTOQUE) 
    {
        printf("Carrinho cheio!\n");
        return;
    }

    for (i = 0; i < qnt_estoque; i++) // Encontrar no estoque 
    {
        encontrar = i;
        break;
    }

    if (encontrado == -1)
    {
        printf("O produto nao encontrado!");
        return;
    }

    if (estoque[encontrar].qnt < quantity) 
    {
        printf("Não há quantidade o suficiente!");
    }

    // Adicionar ao carrinho 
    carrinho[*qnt_estoque].nome = estoque[encontrar];
    carrinho[*qnt_estoque].qnt = quantity;

    // Diminuir o elemento no array 
    estoque[encontrar].qnt -= quantidade;
    
    (*qnt_carrinho)++;
    
    printf("O produto foi adicionado ao carrinho!");    
}

void carrinho_remover (struct produto carrinho[], int *qnt_carrinho, int codigo)
{
     encontrado = -1;

    for (i = 0; i < *qnt_carrinho; i++)
    {
        if (carrinho[i].codigo == codigo)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1)
    {
        for (int i = encontrado; i < *qnt_carrinho; i++) 
        {
            carrinho[i] = estoque[i + 1]; // Irá mover o elemento para a esquerda
        }

        (*qnt_carrinho)--;
        printf("Produto removido do estoque. \n");
    } else {
        printf("Produto nao encontrado. \n");
    }
}

void carrinho_verificar (struct produto carrinho[], int qnt_carrinho)
{
    if (qnt_carrinho == 0)
    {
        printf("Carrinho vazio! \n");
        return;
    }
    printf("printf             ***** CARRINHO ***** \n");
    printf("---------------------------------------------------------
    ---------\n");
    printf("Numero|    NOME          |   CODIGO  |  QUANTIDADE |  PRECO \n");
    printf("---------------------------------------------------------
    ---------\n")
    
    for (i = 0; i < qnt_carrinho; i++)
    {
        printf("%d %s %.2f %d \n", i+1, estoque[i].codigo, estoque[i].nome, estoque[i].preco, estoque[i].qnt);
    }
}

void carrinho_comprar (struct produto carrinho[], int *qnt_carrinho)
{
    float total = 0.0;
    
    if (*qnt_carrinho == 0) {
        printf("Carrinho vazio.\n");
        return;
    }
    
    printf("A compra vai ser finalizada...\n");
    
    for (int i = 0; i < *qnt_carrinho; i++) {
        total += carrinho[i].preco * carrinho[i].qnt;
    }
    
    printf("Valor total da compra: R$%.2f\n", total);
    printf("Compra realizada com sucesso!\n");
    
    // O carrinho vai ser esvaziado apos a compra
    *qnt_carrinho = 0;
}

int main () 
{
    // Variáveis estoque
    struct produto estoque[MAX_ESTOQUE];
    int qnt_produtos = 0; // Declaração da variável que armazena os produtos

    // Variáveis carrinho
    struct produto carrinho[MAX_CARRINHO];
    int qnt_carrinho = 0;

    // Opções  
    int options, codigo, quantidade;
    do {
        printf("Opcoes:\n"
       "1 - Adicionar ao carrinho\n"
       "2 - Remover do carrinho\n"
       "3 - Adicionar ao estoque\n"
       "4 - Remover do estoque\n"
       "5 - Verificar estoque\n"
       "6 - Verificar carrinho\n"
       "7 - Comprar\n"
       "8 - Sair\n");
       printf("Escolha uma das opcoes:\n");
       scanf("%d", &options);

    
    switch (options) {
        case 1:
            printf("Digite o codigo do produto:\n");
            scanf("%d", &codigo);
            printf("Digite a quantidade:\n");
            scanf("%d", &quantidade);

            carrinho_adicionar(estoque, qnt_produtos, carrinho, *qnt_carrinho, codigo, quantidade);
            break;
        case 2:
            printf("Digite o codigo do produto:\n");
            scanf("%d", &codigo);
            carrinho_remover(codigo, qnt_carrinho);
            break;
        case 3:
            estoque_adicionar(estoque, qnt_produtos);
            break; 
        case 4:
            estoque_remover(estoque, qnt_produtos)
            break; 
        case 5:
            estoque_verificar(estoque, qnt_produtos);
            break;
        case 6:
            carrinho_verificar(carrinho, qnt_carrinho);
            break;
        case 7:
            carrinho_comprar(carrinho, qnt_carrinho);
            break;
        case 8:
            printf("O programa sera fechado!");
            printf("Saindo ...");
        break;
        default:
            printf("Opcao invalida!");
        break;
    }
} while (options != 8);

return 0;
}