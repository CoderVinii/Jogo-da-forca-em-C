#include <stdio.h>
#include <string.h>

void abertura() {
    printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta(char chutes[], int* tentativas) {
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int jachutou(char letra, char* chutes, int tentativas) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;

}

void desenhaforca(char* palavrasecreta, char* chutes, int tentativas) {
    
    printf("Voce ja deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        
        if(jachutou(palavrasecreta[i], chutes, tentativas)) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra(char* palavrasecreta) {
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {

    char palavrasecreta[20];

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();
    escolhepalavra(palavrasecreta);

    do {
        desenhaforca(palavrasecreta, chutes, tentativas);
        chute(chutes, &tentativas);

    } while (!acertou && ! enforcou);
    
}
