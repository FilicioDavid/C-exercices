
//----------------------------------------------------------------------------------------------
/*
1) Corrida de motos: 3 motos e 3 voltas cada moto

°tempo medido em segundos
*objetivo: Classificar 


----------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdio.h>

int main(void) {
  int i;
  float tmoto1 = 0.0, tmoto2 = 0.0, tmoto3 = 0.0, m1,m2,m3;

  // Pedir ao usuário o tempo
  for (i = 0; i < 3; i++) 
  {
    printf("\nDigite o Tempo da volta da moto 1 (volta %d): ", i + 1);
    float vt1;
    scanf("%f", &vt1);
    tmoto1 += vt1;

    printf("Digite o Tempo da volta da moto 2 (volta %d): ", i + 1);
    float vt2;
    scanf("%f", &vt2);
    tmoto2 += vt2;

    printf("Digite o Tempo da volta da moto 3 (volta %d): ", i + 1);
    float vt3;
    scanf("%f", &vt3);
    tmoto3 += vt3;
  }

  printf("\nTempo total da moto 1: %.2f", tmoto1);
  printf("\nTempo total da moto 2: %.2f", tmoto2);
  printf("\nTempo total da moto 3: %.2f\n", tmoto3);

  // Calcula qual foi a moto com o melhor tempo
    m1 = tmoto1/3;
    m2 = tmoto2/3;
    m3 = tmoto3/3;
  if (m1 < m2 && m1 < m3) {
        printf("\nPrimeiro Colocado foi a Moto 1");
        if (m2 < m3) {
            printf("\nSegundo Colocado foi a Moto 2");
        } else {
            printf("\nSegundo Colocado foi a Moto 3");
        }
    } else if (m2 < m1 && m2 < m3) {
        printf("\nPrimeiro Colocado foi a Moto 2");
        if (m1 < m3) {
            printf("\nSegundo Colocado foi a Moto 1");
        } else {
            printf("\nSegundo Colocado foi a Moto 3");
        }
    } else {
        printf("\nPrimeiro Colocado foi a Moto 3");
        if (m1 < m2) {
            printf("\nSegundo Colocado foi a Moto 1");
        } else {
            printf("\nSegundo Colocado foi a Moto 2");
        }
    }

  return 0;
}
