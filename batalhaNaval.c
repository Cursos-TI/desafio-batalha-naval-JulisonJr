#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10 //Para definir um tamanho fixo para o tabuleiro.

// Função para imprimir o tabuleiro.
void imprimir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("  ");
    for (char i = 'A'; i < 'A' + TAMANHO_TABULEIRO; i++)
    {
        printf("%c ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para inicializar o tabuleiro.
void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = '~';
        }
    }
}

// Função para posicionar os navios.
void posicionar_navios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    //Lógica para imprimir o navio na vertical.
    for (int l = 1; l <= 1; l++)
    {
        for (int c = 0; c <= 2; c++)
        {
            tabuleiro[l][c] = 'N';
        }
    }

    //Lógica para imprimir o navio na horizontal.
    for (int l = 3; l <= 6; l++)
    {
        for (int c = 9; c <= 9; c++)
        {
            tabuleiro[l][c] = 'N';
        }
    }

    //Lógica para imprimir o navio na diagonal para a esquerda.
    for (int i = 3; i <= 5; i++)
    {
        tabuleiro[i][i] = 'N';
    }

    //Lógica para imprimir o navio na diagonal para a direita.
    int c = 8;
    for (int i = 1; i <= 3; i++)
    {
        tabuleiro[i][c - 1] = 'N';
        c--;
    }

    //Lógica para imprimir em formato de cone ou pirâmide.
    tabuleiro[7][2] = 'C';
    for (int i = 1; i <= 3; i++)
    {
        tabuleiro[8][i] = 'C';
    }
    for (int i = 0; i <= 4; i++)
    {
        tabuleiro[9][i] = 'C';
    }

    //Lógica para imprimir em formato de Cruz.
    for (int l = 6; l <= 8; l++)
    {
        for (int c = 7; c <= 7; c++)
        {
            tabuleiro[l][c] = 'J';
        }
    }
    for (int l = 7; l <= 7; l++)
    {
        for (int c = 5; c <= 9; c++)
        {
            tabuleiro[l][c] = 'J';
        }
    }

    //Lógica para imprimir em formato de em octaedro.
    for (int l = 4; l <= 6; l++)
    {
        for (int c = 1; c <= 1; c++)
        {
            tabuleiro[l][c] = 'O';
        }
    }
    for (int l = 5; l <= 5; l++)
    {
        for (int c = 0; c <= 2; c++)
        {
            tabuleiro[l][c] = 'O';
        }
    }
}

// Função para realizar um ataque
void atacar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, char y)
{
    int coluna = y - 'A';
    //Validação do movimento de ataque.
    if (coluna < 0 || coluna >= TAMANHO_TABULEIRO)
    {
        printf("Coluna inválida!\n");
        return;
    }
    if (x < 0 || x >= TAMANHO_TABULEIRO)
    {
        printf("Linha inválida!\n");
        return;
    }
    //Caso o ataque esteja correto ira colocar um X no local.
    if (tabuleiro[x][coluna] == 'N')
    {
        printf("Acertou um navio!\n");
        tabuleiro[x][coluna] = 'X';
    }
    //Caso não ira colocar um O pra validar a tentativa.
    else if (tabuleiro[x][coluna] == '~')
    {
        printf("Errou!\n");
        tabuleiro[x][coluna] = 'O';
    }
    else
    {
        printf("Posição já atacada!\n");
    }
}
//O jogo se inicia aqui.
int main()
{
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int x;
    char y;
    //Chamando as funções para iniciar.
    inicializar_tabuleiro(tabuleiro);
    posicionar_navios(tabuleiro);
    //Entrada de dados.
    while (1)
    {
        imprimir_tabuleiro(tabuleiro);
        printf("Digite as coordenadas do ataque (linha coluna): ");
        scanf("%d %c", &x, &y);
        atacar(tabuleiro, x, y);
        // Verificar se todos os navios foram afundados
        int todos_afundados = 1;
        for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            {
                if (tabuleiro[i][j] == 'N')
                {
                    todos_afundados = 0;
                    break;
                }
            }
        }
        if (todos_afundados)
        {
            printf("Parabéns, você afundou todos os navios!\n");
            break;
        }
    }

    return 0;
}