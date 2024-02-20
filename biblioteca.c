#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void book(){
    //funcao para a aba de livros do sistema 
    int opc = 0, i = 0;
    struct liv {  
        char autor[50];
        char titulo[50];
        int id_livro; 

    };

    struct liv livro[100];

    do{
        // menu de interação com o usuario, listando as opcoes ligadas aos livros

        printf("1. Cadastrar Novo Livro\n");
        printf("2. Pesquisar titulo\n");
        printf("3. Listar livros\n");
        printf("4. Remover Livros\n");
        printf("5. Sair\n");
        printf("\n Digite Sua opcao : \n");
        scanf ("%d", &opc);

        switch (opc)
        {
        case 1:
        //cadastro de um novo livro

           livro[i].id_livro = i;
            printf("\nDigite o titulo do Livro:\n ");
                scanf(" %49[^\n]", livro[i].titulo);
            getchar ();
            printf("\nDigite o Nome do Autor: \n");
            scanf(" %49[^\n]", livro[i].autor);
            getchar();
        
            i++;
             break;
        case 2:
        // pesquisa de um titulo ja cadastrado
            char tit[50];
            int find = 1;
            printf("\n Digite o titulo do Livro: ");
            scanf(" %49[^\n]", tit);
                for(int j = 0; j < i; j++){
                    if (strcmp(tit,livro[j].titulo) == 0)
                    {
                        printf("\n Codigo: %d", livro[j].id_livro);
                        printf("\n Titulo : %s", livro[j].titulo);
                        printf("\n Autor: %s", livro[j].autor);
                        printf("\n");
                        find = 0;

                    }
                }
                if (find != 0 ){
                    printf("\n Livro nao encontrado\n");
                }

            
            break;
        case 3:
        //listagem de todos os livros existentes na base de dados;
            for (int k = 0; k <i ; k++)
            {
                    printf("\n Codigo: %d", livro[k].id_livro);
                    printf("\n Titulo : %s", livro[k].titulo);
                    printf("\n Autor: %s\n", livro[k].autor);
                    printf("\n");

            }

            break;
        case 4:
              printf("\nDigite o codigo do livro: \n ");
                scanf("%49[^\n]", livro[i].id_livro);
                

            break;

        default:
            break;
        }
            

    }while(opc != 5);

}



int main(){
    book();





}
