//Headers
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define tamTab 10

//===================================================================================================================================================================================================

//Funções auxiliares

//Desenha a tela de título no console. (Bastante óbvio.)
void telaTitulo() {
    void telaInstrucao();

    //Título
    for(int i = 0; i < 10; i++) { printf("\n"); }
    for(int  i = 0; i < 15; i++) { printf(" "); }
    printf("  ___ __ ____ ____  __     ____ ____ ____  ___  __  _  _ ____ ____ __ _  __  ____  __ \n");
    for(int  i = 0; i < 15; i++) { printf(" "); }
    printf(" \/ __)  (  _ (  _ \\/ _\\   (    (  __) ___)\/ __)\/  \\\/ )( (  __|  _ (  ( \\\/ _\\(    \\\/ _\\ \n");
    for(int  i = 0; i < 15; i++) { printf(" "); }
    printf("( (_(  O ) _ ()   \/    \\   ) D () _)\\___ ( (_ (  O ) \\\/ \/) _) )   \/    \/    \\) D (    \\ \n");
    for(int  i = 0; i < 15; i++) { printf(" "); }
    printf(" \\___)__(____(__\\_)_\/\\_\/  (____(____|____\/\\___\/\\__\/ \\__\/(____|__\\_)_)__)_\/\\_(____|_\/\\_\/ \n");
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
    printf("ai meu cu\n");
}

/*
void telaComando() {}
*/

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

    for(int i = 0; i != tamTab; i++) {
        for(int j = 0; j != tamTab; j++) { tab[i][j] = ' '; }
    }

    telaTitulo();

    return 0;
}
