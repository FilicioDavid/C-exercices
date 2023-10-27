
//----------------------------------------------------------------------------------------------
/* 
2) Campeonato de Futebol

°Armazenar nos vetores o valor dos gols 
*objetivo: mostrar o placar  e depois mostrar os pontos de cada time.
Pontos: °vitoria 3pto
        °empate 1pto
        °derrota 0pts


----------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main(void) {
  int  i, gola[3],golb[3],ta = 0, tb = 0 ;


  //Usuario insere os gols dos dois times 
  for (i =0; i < 3;i++)
    {
      printf("\n Digite o número de gols do Time A no jogo %d: ", i + 1);
        scanf("%d", &gola[i]);

      printf("Digite o número de gols do Time B no jogo %d: ", i + 1);
        scanf("%d", &golb[i]);
 
    }
  //verifica se os times possuem vitorias, empates e derrotas e atribui os pontos correlatos 
  for (i = 0; i < 3; i++) {
    if (gola[i] > golb[i]) {
      ta = ta + 3;
    } else if (gola[i] == golb[i]) { 
      ta = ta + 1;
      tb = tb + 1;
    } else {
      tb = tb + 3;
    }
  }
  printf ("\n Pontos Time A: %d\n Pontos Time B: %d", ta, tb);
}