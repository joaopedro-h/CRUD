#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
};

typedef struct Produto Produto;

Produto lista[1000];
int total = 0; /*Total foi criado devido não saber quantas listas exatas o usuaário iria criar, caso tenha uma quantidade exata de listas não é necessário.*/

void cadastrar(){

    if (total >= 1000)    /*Nesse caso as listas foram colocados listas[total] para poder armazenar as informações dentro do total ( limite de 1000 listas), e somente usando o [i] para percorrer*/
    {
        printf("Limite atingido!"); 
        return;
    }
    
    printf("Insira o código do produto: ");
    scanf("%d", &lista[total].codigo);
    getchar();

    printf("Insira o nome do produto: ");
    fgets(lista[total].nome, 100, stdin);
    lista[total].nome[strcspn(lista[total].nome, "\n")] = '\0';
    getchar();

    printf("Insira o preço do produto: ");
    scanf("%f", &lista[total].preco);
    getchar();

    printf("Insira o quantidade do produto: ");
    scanf("%d", &lista[total].quantidade);
    getchar();
    
    total++;

    system("cls");
}

void listar(){

        printf("======================================== | Produtos cadastrados. | ========================================\n");
    for (int i = 0; i < total; i++){   /*for serviu para percorrer entre as listas e listar os produtos cadastrados.*/
        
        printf("Código do produto: %d\n", lista[i].codigo);
        printf("Nome do produto: %s\n", lista[i].nome);
        printf("Preço do produto: %.2f\n", lista[i].preco);
        printf("Quantidade do produto: %d\n\n", lista[i].quantidade);
    }
    
}

void buscar(){

        int opcaoBusca; /*Variável foi declarada dentro da função pois foi criada somente para realizar a busca.*/
        int codigoProduto;
        char nomeProduto[100];

        printf("Como deseja realizar a busca?\n1 - Código.\n2 - Nome.\nEscola uma opção: ");
        scanf("%d", &opcaoBusca);
        getchar();

        if (opcaoBusca == 1){
            
            printf("Insira o código do produto: ");
            scanf("%d", &codigoProduto);
            getchar();

                for (int i = 0; i < total; i++){   /*for serviu para percorrer entre as listas procurando pelo produto.*/
                    if (codigoProduto == lista[i].codigo)
                    {
                        printf("\nProduto encontrado!\n\nSegue as informações:\n");
                        printf("Código do produto: %d\n", lista[i].codigo);
                        printf("Nome do produto: %s\n", lista[i].nome);
                        printf("Preço do produto: %.2f\n", lista[i].preco);
                        printf("Quantidade do produto: %d\n\n", lista[i].quantidade);
                        return; /* Return serviu para encerrar a busca assim que o produto foi encontrado, caso contrário iria continuar e imprimir " Não encontrado." junto.*/
                    }
                }

        }else if (opcaoBusca == 2){

            printf("Insira o nome do produto que deseja: ");
            fgets(nomeProduto, 100, stdin);
            nomeProduto[strcspn(nomeProduto, "\n")] = '\0';
    
    
                for (int i = 0; i < total; i++){   /*for serviu para percorrer entre as listas procurando pelo produto.*/
                    if (strcmp(nomeProduto, lista[i].nome) == 0 )
                    {
                        printf("Produto encontrado!\n\nSegue as informações:\n");
                        printf("Código do produto: %d\n", lista[i].codigo);
                        printf("Nome do produto: %s\n", lista[i].nome);
                        printf("Preço do produto: %.2f\n", lista[i].preco);
                        printf("Quantidade do produto: %d\n\n", lista[i].quantidade);
                        return; /* Return serviu para encerrar a busca assim que o produto foi encontrado, caso contrário iria continuar e imprimir " Não encontrado." junto.*/
                    }
                }
                    
        }else{

             printf("Opção inválida!\n\n");
             return;
        }
             printf("Produto não encontrado.\n\n");
}

void atualizar(){

        int novaQuantidade; /*Variável foi declarada dentro da função pois foi criada somente para realizar a atualização.*/
        int opcaoAtualizar, codigoProduto;
        char nomeProduto[100];

            printf("Como deseja realizar a busca?\n1 - Código.\n2 - Nome.\nEscola uma opção: ");
            scanf("%d", &opcaoAtualizar);
            getchar();
        
        if (opcaoAtualizar == 1){

            printf("Digite o código do produto que deseja alterar: ");
            scanf("%d", &codigoProduto);
            getchar();
    
            for (int i = 0; i < total; i++){
                    if (codigoProduto == lista[i].codigo)
                    {
                        printf("Produto encontrado!\nQuantidade atual: %d\n", lista[i].quantidade);
                        printf("Código do produto: %d\n", lista[i].codigo);
                        printf("Nome do produto: %s\n", lista[i].nome);
                        printf("Preço do produto: %.2f\n\n", lista[i].preco);
        
                        printf("Insira a nova quantidade: ");
                        scanf("%d", &novaQuantidade);
        
                        lista[i].quantidade = novaQuantidade;
                        printf("Alteração feita com sucesso!\nNova quantidade: %d\n\n", novaQuantidade);
                        return; /* Return serviu para encerrar a busca assim que o produto foi encontrado, caso contrário iria continuar e imprimir " Não encontrado." junto.*/
                    }
            }     

        }else if (opcaoAtualizar == 2)
        {
            
            printf("Digite o nome do produto que deseja alterar: ");
            fgets(nomeProduto, 100, stdin);
            nomeProduto[strcspn(nomeProduto,"\n")] = '\0';

            for ( int i = 0; i < total; i++){
                    if (strcmp(nomeProduto,lista[i].nome )== 0)
                    {
                            printf("Produto encontrado!\nQuantidade atual: %d\n", lista[i].quantidade);
                            printf("Código do produto: %d\n", lista[i].codigo);
                            printf("Nome do produto: %s\n", lista[i].nome);
                            printf("Preço do produto: %.2f\n\n", lista[i].preco);

                            printf("Insira a nova quantidade: ");
                            scanf("%d", &novaQuantidade);

                            lista[i].quantidade = novaQuantidade;
                            printf("Alteração feita com sucesso!\nNova quantidade: %d\n\n", novaQuantidade);
                            return; /* Return serviu para encerrar a busca assim que o produto foi encontrado, caso contrário iria continuar e imprimir " Não encontrado." junto.*/    
                    }
            }
        }else
        {
             printf("Opção inválida!\n\n");
             return;
        }
             printf("Produto não encontrado.\n\n");
}

void remover(){

        int codigoRemover;  /*Variável foi declarada dentro da função pois foi criada somente para realizar a remoção.*/

        printf("Insira o código do produto que deseja remover: ");
        scanf("%d", &codigoRemover);

        for (int i = 0; i < total; i++){
                if (codigoRemover == lista[i].codigo)
                {
                    printf("Produto encontrado!\nRemoção feita com sucesso.\n\n");
                    printf("Código do produto: %d\n", lista[i].codigo);
                    printf("Nome do produto: %s\n", lista[i].nome);
                    printf("Preço do produto: %.2f\n", lista[i].preco);
                    printf("Quantidade do produto: %d\n\n", lista[i].quantidade);
                    
                    for (int j = i; j < total - 1; j++){ /**/
                    lista[j] = lista[j + 1];
                    }

                    total--; 
                    return;
                }
        }
                printf("Produto não encontrado.\n\n");
}

int main(){
setlocale(LC_ALL, "Portuguese");

int opcao;

    do{
        
        printf("1 - Cadastrar produto.\n");
        printf("2 - Listar produtos.\n");
        printf("3 - Buscar produto.\n");
        printf("4 - Atualizar quantidade.\n");
        printf("5 - Remover produto.\n");
        printf("6 - Sair.\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrar();
             break;
        
        case 2:
            listar();
            break;

        case 3:
            buscar();
            break;
        
        case 4:
            atualizar();
            break;
        
        case 5:
            remover();
            break;

        case 6:
            printf("Desconectando..");
            break;
        
        default:
            printf("Opção inválida!\n");
        }
        
    } while (opcao != 6 );
}