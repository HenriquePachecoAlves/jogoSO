#include<stdio.h>
#include<stdlib.h>

// Vari�veis globais
char jogo[3][3];
int l, c;

// Procedimento para iniciar todas as posi��es da matriz
void inicializarMatriz(){
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            jogo[l][c] = ' ';
        }
    }
}

// Procedimento para imprimir o jogo na tela
void imprimir(){
    printf("\n\n\t 0   1   2\n\n");
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            if(c == 0){
                printf("\t");
            }
            printf(" %c ", jogo[l][c]);
            if(c < 2){
                printf("|");
            }
            if(c == 2){
                printf("   %d", l);
            }
        }
        printf("\n");
        if(l < 2){
            printf("\t------------\n");
        }
    }
}

/*
Fun��o para verificar vit�ria por linha
1 - ganhou
0 - n�o ganhou ainda
*/
int ganhouPorLinha(int l, char c){
    if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c){
        return 1;
    } else {
        return 0;
    }
}

/*
Fun��o verificar vit�rias por linhas
1 - ganhou
0 - n�o ganhou ainda
*/
int ganhouPorLinhas(char c){
    int ganhou = 0;
    for(l = 0; l < 3; l++){
        ganhou += ganhouPorLinha(l, c);
    }
    return ganhou;
}

/*
Fun��o para verificar vit�ria por uma coluna
1 - ganhou
0 - n�o ganhou ainda
*/
int ganhouPorColuna(int c, char j){
    if(jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j){
        return 1;
    } else {
        return 0;
    }
}

/* 
Fun��o que verifica vit�ria por colunas
1 - ganhou
0 - n�o ganhou ainda
*/
int ganhouPorColunas(char j){
    int ganhou = 0;
    for(c = 0; c < 3; c++){
        ganhou += ganhouPorColuna(c, j);
    }
    return ganhou;
}

/*
Fun��o para verificar vit�ria na diagonal principal
1 - vit�ria
0 - n�o ganhou ainda
*/
int ganhouPorDiagonalPrin(char c){
    if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c){
        return 1;
    } else {
        return 0;
    }
}

/*
Fun��o para verificar vit�ria por diagonal secund�ria
1 - vit�ria
0 - n�o ganhou ainda
*/
int ganhouPorDiagonalSecun(char c){
    if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c){
        return 1;
    } else {
        return 0;
    }
}

/*
Fun��o que diz se a coordenada � v�lida ou n�o
1 - � v�lida
0 - n�o � v�lida
*/
int ehValida(int l, int c){
    if(l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' '){
        return 1;
    } else {
        return 0;
    }
}

// Procedimento para ler as coordenadas do jogador
void lercoordenadas(char j){
    int linha, coluna;

    printf("Digite linha e coluna: ");
    scanf("%d %d", &linha, &coluna);

    while(ehValida(linha, coluna) == 0){
        printf("Coordenadas inv�lidas. Digite outra linha e coluna: ");
        scanf("%d %d", &linha, &coluna); 
    }
    jogo[linha][coluna] = j;  
}

// Fun��o que retorna a quantidade de posi��es vazias
int quantVazias(){
    int quantidade = 0;

    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){  
            if(jogo[l][c] == ' '){
                quantidade++;
            }
        }
    }
    return quantidade;
}

// Procedimento jogar com o loop principal do jogo
void jogar(){
    int jogador = 1, vitoriaX = 0, vitoriaO = 0;
    char jogador1 = 'X', jogador2 = 'O';

    do{
        imprimir();
        if(jogador == 1){
            lercoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagonalPrin(jogador1);
            vitoriaX += ganhouPorDiagonalSecun(jogador1);
        } else {
            lercoordenadas(jogador2);
            jogador = 1;
            vitoriaO += ganhouPorLinhas(jogador2);
            vitoriaO += ganhouPorColunas(jogador2);
            vitoriaO += ganhouPorDiagonalPrin(jogador2);
            vitoriaO += ganhouPorDiagonalSecun(jogador2);
        }
    } while(vitoriaX == 0 && vitoriaO == 0 && quantVazias() > 0);

    if(vitoriaO == 1){
        printf("\nParab�ns jogador 2. Voc� venceu!!\n");
    } else if(vitoriaX == 1){
        printf("\nParab�ns jogador 1. Voc� venceu!!\n");
    } else {
        printf("\nEmpate! Voc�s perderam!!\n");
    }
}

int main(void){
    int opcao;

    do{
        inicializarMatriz();
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &opcao);

    } while(opcao == 1);  

    return 0;
    
}
