#include <stdio.h>

int main(void) {
  char palavra[] = "ato"; 
  char letra;
  int i, acerto = 0, tentativa = 5; 

  printf("\nBem vindo ao Jogo da Forca\n");

  printf("\n Palavra: ");
  for (i = 0; i < 3; i++) {
    printf(" _ ");
  }

  printf("\n");

  for (int j = 0; j < tentativa; j++) {
    printf("\n Digite uma letra: ");
    scanf(" %c", &letra); 

    
    for (i = 0; i < 3; i++) {

      if (letra == palavra[i]) {
        printf("\n %c ", letra);
        acerto++; 
      } 
    }

    if (acerto == 3) {
      printf("Parabéns, você acertou a palavra: %s\n", palavra);
      break; // Saia do loop externo quando a palavra for adivinhada corretamente
    }
  }

  if (acerto != 3) {
    printf("Você não adivinhou a palavra. A palavra era: %s\n", palavra);
  }

  return 0;
}
