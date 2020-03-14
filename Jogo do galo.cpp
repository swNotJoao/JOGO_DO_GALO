#include <stdio.h>
#include <stdlib.h>

int jogo = 1; // Jogo é 1 no inicio, se for 0 quer dizer que acabou
int XO[] = {3,3,3,3,3,3,3,3,3}; // Espaços possiveis de ocupar(9) quer com "X" ou com "O", no inicio desocupados, ou seja, com valor 3, correspondente a um espaço(" ")
int jogador = 1; // Jogador que começa
char nomeDoJogador1[10]; // Variável para guardar o nome do jogador 1
char nomeDoJogador2[10]; // Variável para guardar o nome do jogador 2
int nomes = 0; // Pode ser 0(Nomes iguais) ou 1(Nomes novos)
int vitoria = 3; // Pode ser 1(Jogador 1 ganhou), 2(Jogador 2 ganhou), 3(Ainda ninguem ganhou) ou 0(Empate)

void JogarNovo() // Função para restaurar o estado das variáveis caso o jogador quiser jogar de novo
{
    printf("Tecla: 1---> Jogar de novo\n"); // Perguntar se querem jogar outra vez
    scanf("%d", &jogo); // Ler a escolha
    
    if(jogo == 1)
    {
        printf("Tecla: 0--->Mudar os nomes dos jogadores\n"); // Manter os nomes
        printf("Tecla: 1--->Manter os nomes dos jogadores\n"); // Mudar os nomes
        scanf("%d", &nomes); // Ler a escolha
        
        for(int i=0;i<9;i++)
            XO[i] = 3; // Espaços possiveis de ocupar(9) quer com "X" ou com "O", no inicio desocupados, ou seja, com valor 3, correspondente a um espaço(" ")
        
        jogador = 1; // Jogador que começa
        vitoria = 3; // Pode ser 1(Jogador 1 ganhou), 2(Jogador 2 ganhou), 3(Ainda ninguem ganhou) ou 0(Empate)
    }
}

void nomeDosJogadores() // Função que pede o nome de 2 jogadores
{
    for(int i=0;i<2;i++)
    {
        printf("Escreva o nome do jogador %d:   ", (i+1)); // Pede o nome do jogador 1 e depois do jogador 2
        
        if(i == 0) // Nome do jogador 1
        {
            scanf("%s", nomeDoJogador1);
        }
        else // Nome do jogador 2
        {
            scanf("%s", nomeDoJogador2);
        }
    }
    system("clear"); // Após ler os nomes dos 2 jogadores, limpar a janela antes de chamar a função quadricula() // system("cls");
}

void Vitoria() // Função que verifica se há vitória de algum jogador
{
    for(int i=4;i<6;i++) // Verificar se há vitoria para "X"(4) e para "Y"(5)
    {
        if(XO[0] == i && XO[4] == i && XO[8] == i) // Diagonal 1,5,9
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[2] == i && XO[4] == i && XO[6] == i) // Diagonal 3,5,7
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[0] == i && XO[1] == i && XO[2] == i) // Horizontal 1,2,3
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[3] == i && XO[4] == i && XO[5] == i) // Horizontal 4,5,6
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[6] == i && XO[7] == i && XO[8] == i) // Horizontal 7,8,9
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[0] == i && XO[3] == i && XO[6] == i) // Vertical 1,3,6
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[1] == i && XO[4] == i && XO[7] == i) // Vertical 2,4,7
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else if(XO[2] == i && XO[5] == i && XO[8] == i) // Vertical 3,6,9
        {
            if(jogador == 1) // Se quem fez a sequéncia foi o jogador 1 então a vitória é dele
            {
                vitoria = 1;
            }
            else // Se quem fez a sequéncia foi o jogador 2 então a vitória é dele
            {
                vitoria = 2;
            }
        }
        else // Verificar se ha empate
        {
            int temp = 0; // Numero de espaços oucupados por "X" ou "Y"
            
            for(int i = 0; i<9 ; i++) // Ver o valor de temp
            {
                if(XO[i] == 4 || XO[i] == 5)
                    temp++;
            }
            if(temp == 9) // Se estiverem todos oucupados(temp=9) há empate
                vitoria = 0; // Empate
        }
    }
}

void Jogador() // Função que vai operar todas ações de o jogador que estiver a jogar
{
    int escolha; // Variável que representa o espaço que o jogador escolheu para marcar o seu "X" ou "Y"
    
    do // Pede para o jogador escolher um espaço para marcar o seu "X" ou "Y"
    {
        if(jogador == 1) // Se for a vez do Jogador 1
        {
            printf("\n%s, escreva aqui o sitio para marcar:   ", nomeDoJogador1);
        }
        else // Se for a vez do jogador 2
        {
            printf("\n%s, escreva aqui o sitio para marcar:   ", nomeDoJogador2);
        }
        scanf("%d", &escolha); // Lê a escolha do jogador
        
        if((XO[escolha-1] == 3) && (escolha > 0 && escolha < 10)) // Se o jogador escolher um espaço vazio e válido:
        {
            system("clear"); // Limpa a janela para ficar mais bonito // system("cls");
            
            switch(jogador) // Depois de o jogador escolher um espaço válido é a vez do jogador seguinte
            {
                case 1: // Se o jogador 1 tiver feito uma escolha válida:
                    
                    XO[escolha-1] = 4; // Marcar o sitio com um "X", representado pelo valor 4
                    
                    Vitoria(); // Antes de trocar a vez de quem está a jogar verificar se alguém ganhou
                    
                    jogador = 2; // O jogador 1 acabou o turno, logo o jogador que deve jogar é o 2
                    break;
                    
                case 2:
                    
                    XO[escolha-1] = 5; // Marcar o sitio com um "Y", representado pelo valor 5
                    
                    Vitoria(); // Antes de trocar a vez de quem está a jogar verificar se alguém ganhou
                    
                    jogador = 1; // O jogador 2 acabou o turno, logo o jogador que deve jogar é o 1
                    break;
            }
        }
    }while(escolha < 1 || escolha > 9); // Efectuar de novo caso a escolha seja inválida
}

void quadricula() // Função que vai desenhar os 9 quadrados necessários para jogar o jogo do galo // Interface pricipal
{
    int quadricula[]={3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,3,3,3,3,XO[0],3,3,2,3,3,XO[1],3,3,2,3,3,XO[2],3,3,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,3,3,3,3,XO[3],3,3,2,3,3,XO[4],3,3,2,3,3,XO[5],3,3,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,3,3,3,3,XO[6],3,3,2,3,3,XO[7],3,3,2,3,3,XO[8],3,3,3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,3,3}; // "Mapa" da interface. Cada numero representa um output. 1( "_" ); 2( "|" ); 3( " " ); 4( "X" ); 5( "O" )
    
    system("clear"); // Limpar a janela a cada chamada da função quadricula() // system("cls");
    
    printf("%s - X\n%s - O\n\n",  nomeDoJogador1, nomeDoJogador2); // Indica qual jogador tem o "X" ou o "Y"
    
    for(int i=0;i<9;i++) // Linhas verticais
    {
        for(int j=0;j<17;j++) // Linhas horizontais
        {
            switch(quadricula[(i*17)+j]) // Faz print de "_" se 1, "|" se 2, " " se 3, "X" se 4 e "O" se 5
            {
                case 1:            //      |     |
                                   //   *  |  *  |  *
                    printf("_");   // _____|_____|_____       A interface deve ficar assim
                                   //      |     |
                    break;         //   *  |  *  |  *
                                   // _____|_____|_____
                case 2:            //      |     |            * - Espaços a serem ocupados pelos "X" e "O" dos jogadores
                                   //   *  |  *  |  *
                    printf("|");   //      |     |
                    
                    break;
                    
                case 3:
                    
                    printf(" ");
                    
                    break;
                    
                case 4:
                    
                    printf("X");
                    
                    break;
                    
                case 5:
                    
                    printf("O");
                    
                    break;
            }
            
            if(j == 16) // No final de cada linha horizontal é preciso uma mudança de linha
                printf("\n");
        }
    }
    Jogador(); // No final de cada quadricula() é necessário chamar a função Jogador() para se vereficar as suas ações
}

int main() // Função main()
{
    
Inicio: // Inicio do programa
    
    system("clear"); // Antes de iniciar o jogo limpamos a janela para nos livrarmos de quaisquer outputs que o computador possa ter feito por defeito  // system("cls");
    
    if(nomes == 0)
        nomeDosJogadores(); // Mesmo antes do jogo começar é preciso saber os nomes dos jogadores
    
    while(jogo == 1 && vitoria == 3) // Enquanto o jogo estiver ativo (= 1) Desenhar a quadricula e a parir dai as funções todas funcionarão enquanto jogo = 1
    {
        quadricula();
    }
    
    switch(vitoria) // Ver o estado do jogo
    {
        case 0: // Caso haja empate
            
            system("clear"); // Limpar janela  // system("cls");
            
            printf("Lamento mas houve um empate\n");
            
            JogarNovo();
            
            if(jogo == 1)
                goto Inicio; // Voltar ao inicio do programa
            
            break;
            
        case 1: // Caso a vitória seja do jogador 1
            
            system("clear"); // system("cls");
            
            printf("O vencedor é: %s\n", nomeDoJogador1);
            
            JogarNovo();
            
            if(jogo == 1)
                goto Inicio; // Voltar ao inicio do programa
            
            break;
            
        case 2: // Caso a vitória seja do jogador 2
            
            system("clear"); // system("cls");
            
            printf("O vencedor é: %s\n", nomeDoJogador2);
            
            JogarNovo();
            
            if(jogo == 1)
                goto Inicio; // Voltar ao inicio do programa
            
            break;
    }
    return 0;
}
