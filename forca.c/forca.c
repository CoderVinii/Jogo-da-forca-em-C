#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra) {
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            return 1;
        }
    }
    return 0;
}

void desenhaforca() {
    printf("Voce ja deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    strcpy(palavrasecreta, "MELANCIA");
}

int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

int enforcou() {
    return tentativas >= 5;
}

int main() {
    escolhepalavra();
    abertura();

    do {
        desenhaforca();
        chuta();
    } while (!acertou() && !enforcou());

    if(acertou()) {
        printf("Parabéns, você ganhou!\n");
    } else {
        printf("Voce foi enforcado! A palavra era %s\n", palavrasecreta);
    }

    return 0;
}
