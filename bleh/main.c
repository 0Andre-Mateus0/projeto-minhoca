//Headers
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Constantes globais
#define tamTab 10

//===================================================================================================================================================================================================

//Funções auxiliares

//Desenha a tela de título no console. (Bastante óbvio.)
void telaTitulo() {
    void telaInstrucao();
    char *titulo[] = {
        " _  _ __ __ _  _  _  __   ___  __     ____ ____ ____  ___  __  _  _ ____ ____ __ _  __  ____  __  ",
        "( \\/ |  |  ( \\/ )( \\/  \\ / __)/ _\\   (    (  __) ___)/ __)/  \\/ )( (  __|  _ (  ( \\/ _\\(    \\/ _\\ ",
        "/ \\/ \\)(/    /) __ (  O | (__/    \\   ) D () _)\\___ ( (_ (  O ) \\/ /) _) )   /    /    \\) D (    \\ ",
        "\\_)(_(__)_)__)\\_)(_/\\__/ \\___)_/\\_/  (____(____|____/\\___/\\__/ \\__/(____|__\\_)_)__)_/\\_(____|_/\\_/"
    };
    int tamArr = sizeof(titulo)/sizeof(titulo[0]);

    //Título
    for(int i = 0; i < 10; i++) { printf("\n"); }
    for(int i = 0; i < tamArr; i++) {
        for(int  j = 0; j < 10; j++) { printf(" "); }
        printf("%s\n",titulo[i]);
    }
    for(int i = 0; i < 2; i++) { printf("\n"); }
    for(int  i = 0; i < 45; i++) { printf(" "); }
    printf("Pressione <ENTER> para jogar");
    getc(stdin);

    //Limpa a tela
    system("cls");

    telaInstrucao();
}

//Tela de instruções para o jogador
void telaInstrucao() {
    char telaComando();
    char *textoInstr[] = {
        "O jogador deve:",
        "1. Indicar quantas e quais casas deverão receber os obstáculos.",
        "2. Indicar a posição da cabeça da minhoca no tabuleiro."
    };
    int tamArr = sizeof(textoInstr)/sizeof(textoInstr[0]);

    for(int i = 0; i < 10; i++) { printf("\n"); }
    for(int i = 0; i < 50; i++) { printf(" "); }
    for(int i = 0; i < 16; i++) { printf("="); }
    printf("\n");
    for(int i = 0; i < 50; i++) { printf(" "); }
    printf("|| INSTRUÇÕES ||\n");
    for(int i = 0; i < 50; i++) { printf(" "); }
    for(int i = 0; i < 16; i++) { printf("="); }
    for(int i = 0; i < 3; i++)  { printf("\n"); }
    for(int i = 0; i < tamArr; i++) {
        for(int j = 0; j < 40; j++) { printf(" "); }
        printf("%s\n",textoInstr[i]);
    }
    for(int i = 0; i < 3; i++) { printf("\n"); }
    for(int  i = 0; i < 45; i++) { printf(" "); }
    printf("Pressione <ENTER> para continuar");
    getc(stdin);
    //Limpa a tela
    system("cls");

    telaComando();
}

//Pede ao jogador as coordenadas dos obstáculos
char telaComando() {

    printf("ai meu cu\n");

    //return ;
}


/*


int montarTabuleiro(char tab[][]) {

    for(int i = 0; i < 41; i++) {
        printf("-");
    }
    printf("\n");
    for(int i = 0; i != tamTab; i++) {
        for(int j = 0; j != tamTab; j++) {
            printf("| %c ",tab[i][j]);
        }
        printf("|\n");
        for(int k = 0; k != 41; k++) {
            printf("-");
        }
        printf("\n");
    }
}
*/

//===================================================================================================================================================================================================

//Main

int main() {

    const char minhoca[] = "C***•";
    char tab[tamTab][tamTab];

    setlocale(LC_ALL,"");

    for(int i = 0; i != tamTab; i++) {
        for(int j = 0; j != tamTab; j++) { tab[i][j] = ' '; }
    }

    telaTitulo();

    return 0;
}
