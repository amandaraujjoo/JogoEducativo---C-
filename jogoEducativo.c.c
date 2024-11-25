#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { // Estrutura do jogador
    char nome[10];
    int pontuacao;
} Jogador;

typedef struct { // Estrutura das operações
    int dificuldade;
    float valor1;
    float valor2;
    int operacao; // 0: Soma, 1: Subtração, 2: Multiplicação, 3: Divisão
    float resultado;
} Calcular;

// Funções Auxiliares
void randomizarValores(Calcular *c){// Funcao para gerar numeros aleatorios para os dois valores da operacao dependendo da dificuldade
	if(c->dificuldade == 1){
        c->valor1 = rand() % 11;  // gera o valor para a variavel 'valor1' da struct Calcular entre 0 e 10
        c->valor2 = rand() % 11;
	}else if(c->dificuldade == 2){
        c->valor1 = rand() % 101;
        c->valor2 = rand() % 101;
	}else if(c->dificuldade == 3){
        c->valor1 = rand() % 1001;
        c->valor2 = rand() % 1001;
	}else if(c->dificuldade == 4){
        c->valor1 = rand() % 10001;
        c->valor2 = rand() % 10001;
	}
}


void gerarOperacao(Calcular *c) {
    randomizarValores(c);
    switch (c->operacao) {
        case 0: c->resultado = c->valor1 + c->valor2; break;
        case 1: c->resultado = c->valor1 - c->valor2; break;
        case 2: c->resultado = c->valor1 * c->valor2; break;
        case 3: c->resultado = c->valor1 / c->valor2; break;
    }
}




// Função para Jogar uma Operação
void jogarOperacao(Calcular *c, Jogador *j) {
    float resposta;
    char *operacoes[] = {"+", "-", "x", "/"};

    printf("\nResolva: %.2f %s %.2f\n", c->valor1, operacoes[c->operacao], c->valor2);
    printf("Digite sua resposta: ");
    scanf("%f", &resposta);

    if (resposta == c->resultado) {
        printf("Correto!\n");
        j->pontuacao += 1 * c->dificuldade;
    } else {
        printf("Errado! Resposta correta: %.2f\n", c->resultado);
    }
}


// Função Principal
int main() {
    srand(time(NULL)); // Somente para números aleatórios

    Jogador jogador = {0};
    Calcular calc = {0};
    char jogarNovamente;
    int rodadas, dificuldade;

    printf("Bem-vindo ao jogo de Operações Matemáticas!\n");
    printf("Digite seu nome (máx 10 caracteres): ");
    scanf("%s", jogador.nome);






    printf("Escolha o nivel de dificuldade (1-4):\n");
    printf("1 - Facil (0-10)\n2 - Medio (0-100)\n3 - Dificil (0-1000)\n4 - Insano (0-10000)\n");
    scanf("%d", &dificuldade);

    if (dificuldade < 1 || dificuldade > 4) {
        printf("Nivel invalido! Escolha entre 1 e 4.\n");
        return 1;
    }

    jogador.pontuacao = 0;
    calc.dificuldade = dificuldade;

    do {
        // Sorteia uma operação e executa
        calc.operacao = rand() % 4;
        gerarOperacao(&calc);
        jogarOperacao(&calc, &jogador);






        // Pergunta se o jogador quer jogar novamente
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nJogo encerrado. Até a próxima!\n");
    printf("Jogador: %s\nPontuação Final: %d\n", jogador.nome, jogador.pontuacao);

    return 0;
}