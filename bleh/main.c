//Headers
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//Constantes globais
#define tamTab 10

//===================================================================================================================================================================================================

//Funções prototipos
void telaTitulo();
void telaInstrucao();
void telaComando(char matriz[tamTab][tamTab]);
void passeioDaMinhocaDesgovernada(char matriz[tamTab][tamTab],const char *trem);

//Main

int main() {
    const char minhoca[] = "C***°";
    char tab[tamTab][tamTab];

    setlocale(LC_ALL,"");

    for(int i = 0; i < tamTab; i++) {
        for(int j = 0; j < tamTab; j++) { tab[i][j] = ' '; }
    }

    telaTitulo();
    telaInstrucao();
    telaComando(tab);
    passeioDaMinhocaDesgovernada(tab,minhoca);

  return 0;
}

//===================================================================================================================================================================================================

//Funções auxiliares

//Desenha a tela de título no console. (Bastante óbvio.)
void telaTitulo() {
    char *titulo[] = {
        " _  _ __ __ _  _  _  __   ___  __     ____ ____ ____  ___  __  _  _ ____ ____ __ _  __  ____  __  ",
        "( \\/ |  |  ( \\/ )( \\/  \\ / __)/ _\\   (    (  __) ___)/ __)/  \\/ )( (  __|  _ (  ( \\/ _\\(    \\/ _\\ ",
        "/ \\/ \\)(/    /) __ (  O | (__/    \\   ) D () _)\\___ ( (_ (  O ) \\/ /) _) )   /    /    \\) D (    \\ ",
        "\\_)(_(__)_)__)\\_)(_/\\__/ \\___)_/\\_/  (____(____|____/\\___/\\__/ \\__/(____|__\\_)_)__)_/\\_(____|_/\\_/"
    };
    int tamArr = sizeof(titulo)/sizeof(titulo[0]);

    //Título
    printf("Trabalho feito por:\nAndré Mateus (202510300211)\nGiorgio Bazet(202510298111)");
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
}

//Tela de instruções para o jogador
void telaInstrucao() {
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
}

//Pede ao jogador as coordenadas dos obstáculos
void telaComando(char matriz[tamTab][tamTab]) {
    int numCasas = 0, tabX, tabY;

    // Loop principal para reiniciar em caso de erro
    while(1) {
        system("cls");
        for(int i = 0; i < 3; i++) { printf("\n"); }

        // Desenha o tabuleiro
        for(int i = 0; i < tamTab; i++) {
            for(int k = 0; k < 40; k++) { printf(" "); }
            for(int l = 0; l < 41; l++) { printf("-"); }
            printf("\n");
            for(int k = 0; k < 40; k++) { printf(" "); }
            printf("|");
            for(int j = 0; j < tamTab; j++) { printf(" %c |", matriz[i][j]); }
            printf("\n");
        }
        for(int k = 0; k < 40; k++) { printf(" "); }
        for(int n = 0; n < 41; n++) { printf("-"); }
        printf("\n");

        for(int i = 0; i < 3; i++) { printf("\n"); }

        // Entrada do número de casas
        printf("Digite a quantidade de casas que receberão os obstaculos: ");
        if(scanf("%d", &numCasas) != 1 || numCasas <= 0) {
            printf("Entrada inválida! Digite um número positivo.\n");
            while(getchar() != '\n');
            continue;
        }

        // Entrada das coordenadas
        printf("Digite as coordenadas das casas (x y)\n");
        int erro = 0;
        for(int i = 0; i < numCasas; i++) {
            printf("\n Casa %d: ", i+1);
            if(scanf("%d %d", &tabX, &tabY) != 2 ||tabX <= 0 || tabX > tamTab ||tabY <= 0 || tabY > tamTab) {
                printf("Coordenadas inválidas! Use valores entre 1 e 10");
                while(getchar() != '\n');
                erro = 1;
                break;
            }

            if(matriz[tabX-1][tabY-1] == 'O') {
                printf("Esta casa já contém um obstáculo! Escolha outra.\n");
                i--;
                continue;
            }

            matriz[tabX-1][tabY-1] = 'O';
        }

        if(!erro) { break; }
    }
}

//Minhoca cabeçuda
void passeioDaMinhocaDesgovernada(char matriz[tamTab][tamTab], const char *minhoca) {
    int cabecaX = 0, cabecaY = 0, posVal = 0, qtdMov = 0, corpoX[100] = {0}, corpoY[100] = {0}, tamMinhoca = strlen(minhoca), casasVisitadas = 0, casasNVisitadas = 0; tamAtual = 1


    char matrizVisitadas[tamTab][tamTab]; //Cópia da matriz original para guardar as casas visitadas
    char matrizOriginal[tamTab][tamTab]; //Matriz original com obstáculos
    memcpy(matrizVisitadas, matriz, sizeof(matrizVisitadas));
    memcpy(matrizOriginal, matriz, sizeof(matrizOriginal)); //Copia os obstáculos

    while(!posVal) {
        system("cls");
        //Desenha o tabuleiro
        for(int i = 0; i < 3; i++) { printf("\n"); }
        for(int i = 0; i < tamTab; i++) {
            for(int k = 0; k < 40; k++) { printf(" "); }
            for(int l = 0; l < 41; l++) { printf("-"); }
            printf("\n");
            for(int k = 0; k < 40; k++) { printf(" "); }
            printf("|");
            for(int j = 0; j < tamTab; j++) { printf(" %c |", matriz[i][j]); }
            printf("\n");
        }
        for(int k = 0; k < 40; k++) { printf(" "); }
        for(int n = 0; n < 41; n++) { printf("-"); }
        printf("\n");

        for(int i = 0; i < 3; i++) { printf("\n"); }

        printf("Digite as coordenadas da cabeça da minhoca (x y): ");
        if(scanf("%d %d", &cabecaX, &cabecaY) != 2) {
            printf("Entrada inválida! Digite dois números.\n");
            while(getchar() != '\n');
            continue;
        }

        //Ver se a casa escolhida está dentro dos parâmetros
        if(cabecaX < 1 || cabecaX > tamTab || cabecaY < 1 || cabecaY > tamTab) {
            printf("Coordenadas fora do tabuleiro! Use valores entre 1 e 10.\n");
            continue;
        }

        //Ver se a casa não possui obstáculo
        if(matriz[cabecaX-1][cabecaY-1] != ' ') {
            printf("Esta casa contém um obstáculo! Escolha outra.\n");
            continue;
        }

        //Qtd de movimentos
        printf("Digite a quantidade de movimentos: ");
        if(scanf("%d", &qtdMov) != 1 || qtdMov <= 0) {
            printf("Digite um número positivo.\n");
            while(getchar() != '\n');
            continue;
        }

        posVal = 1;
    }

    //Posição inicial da cabeça
    corpoX[0] = cabecaX-1;
    corpoY[0] = cabecaY-1;
    matriz[cabecaX-1][cabecaY-1] = minhoca[0];
    matriz[corpoX[0]][corpoY[0]] = minhoca[0];

    //Movimentação automática
    srand(time(NULL)); //Inicializa o RNG

    for(int mov = 0; mov < qtdMov; mov++) {
        int dir, novaX, novaY;
        int movVal = 0;
        int tentativas = 0;
        int direcoes[4] = {0};

        //Tenta encontrar uma direção válida
        while(!movVal && tentativas < 4) {
            dir = rand() % 4;
            if(direcoes[dir]) { continue; } //Já tentou essa direção

            direcoes[dir] = 1;
            tentativas++;

            novaX = corpoX[0];
            novaY = corpoY[0];

            switch(dir) {
                case 0: novaX--; break;
                case 1: novaY++; break;
                case 2: novaX++; break;
                case 3: novaY--; break;
            }

            // Verifica se o movimento é válido
            if(novaX >= 0 && novaX < tamTab && novaY >= 0 && novaY < tamTab) {
                if(matriz[novaX][novaY] == ' ' || matriz[novaX][novaY] == minhoca[tamMinhoca-1]) { movVal = 1; }
            }
        }

        if(!movVal) {
            //Se não encontrou movimento válido, fica parado
            novaX = corpoX[0];
            novaY = corpoY[0];
        }

        //Move a minhoca
        for(int i = tamMinhoca-1; i > 0; i--) {
            corpoX[i] = corpoX[i-1];
            corpoY[i] = corpoY[i-1];
        }
        corpoX[0] = novaX;
        corpoY[0] = novaY;

        // Aumenta o tamanho da minhoca gradualmente até o máximo
        if(tamAtual < tamMinhoca && mov > 0) { tamAtual++; }

        //Atualiza o tabuleiro
        for(int i = 0; i < tamTab; i++) {
            for(int j = 0; j < tamTab; j++) {
                if(matrizOriginal[i][j] == 'O') {
                    matriz[i][j] = 'O'; // Restaura obstáculos
                } else if(matriz[i][j] != minhoca[0] &&
                         (strchr(minhoca+1, matriz[i][j]) == NULL)) {
                    matriz[i][j] = ' '; // Limpa apenas partes da minhoca
                }
            }
        }
        //Desenha a minhoca
        for(int i = 0; i < tamMinhoca; i++) {
            if(i == 0) { matriz[corpoX[i]][corpoY[i]] = minhoca[0]; } //Cabeça
            else { matriz[corpoX[i]][corpoY[i]] = minhoca[i < tamMinhoca ? i : tamMinhoca-1]; }
            matrizVisitadas[corpoX[i]][corpoY[i]] = 'V'; // Marca como visitada (marcação pro final)
        }

        //Exibe o movimento
        system("cls");
        for(int i = 0; i < 30; i++) { printf(" "); }
        printf("Movimento %d de %d\n", mov+1, qtdMov);

        //Desenha o tabuleiro
        for(int i = 0; i < 3; i++) { printf("\n"); }
        for(int i = 0; i < tamTab; i++) {
            for(int k = 0; k < 40; k++) { printf(" "); }
            for(int l = 0; l < 41; l++) { printf("-"); }
            printf("\n");
            for(int k = 0; k < 40; k++) { printf(" "); }
            printf("|");
            for(int j = 0; j < tamTab; j++) { printf(" %c |", matriz[i][j]); }
            printf("\n");
        }
        for(int k = 0; k < 40; k++) { printf(" "); }
        for(int n = 0; n < 41; n++) { printf("-"); }
        printf("\n");

        usleep(300000); //Pausa para visualização (0.3 segundos)
    }

    //Calcula qtd. casas visitadas e não visitadas
    for(int i = 0; i < tamTab; i++) {
        for(int j = 0; j < tamTab; j++) {
            if(matrizVisitadas[i][j] == 'V') { casasVisitadas++; }
            else if(matriz[i][j] != 'O') { casasNVisitadas++; }
        }
    }

    system("cls");

    //Desenha o tabuleiro final
    for(int i = 0; i < 3; i++) { printf("\n"); }
    for(int i = 0; i < tamTab; i++) {
        for(int k = 0; k < 40; k++) { printf(" "); }
        for(int l = 0; l < 41; l++) { printf("-"); }
        printf("\n");
        for(int k = 0; k < 40; k++) { printf(" "); }
        printf("|");
        for(int j = 0; j < tamTab; j++) {
            printf(" %c |", matriz[i][j]);
        }
        printf("\n");
    }
    for(int k = 0; k < 40; k++) { printf(" "); }
    for(int n = 0; n < 41; n++) { printf("-"); }

    //Mostra o resultado final
    for(int i = 0; i < 2; i++) { printf("\n"); }
    for(int i = 0; i < 40; i++) { printf(" ");}
    printf("=== RESULTADO FINAL ===\n");
    for(int i = 0; i < 30; i++) { printf(" ");}
    printf("Casas visitadas: %d\n", casasVisitadas);
    for(int i = 0; i < 30; i++) { printf(" ");}
    printf("Casas não visitadas: %d\n", casasNVisitadas);
}
