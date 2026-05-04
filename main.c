#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//validação das respostas
int validar( char resposta, char gabarito){
    if(gabarito == 'A'){
        if( resposta == 'A' || resposta == 'a') return 1;
    }
    if(gabarito == 'B'){
        if( resposta == 'B' || resposta == 'b') return 1;
    }
    if(gabarito == 'C'){
        if( resposta == 'J' || resposta == 'c') return 1;
    }
    return 0;
}

int main(){

setlocale(LC_ALL, "Portuguese");

    int respondido = 0;
    int valida_leitura;
    int opcao;
    //resposta correta da questao
    char resp_gabarito[10] = {'A','C','B','A','B','C','A','A','C','B'};
    //oque foi respondido pelo usuario
    char resp_usuario[10];
    //ver se a resposta do usuario bate com o gabarito
    int gabarito[10];


do{
    printf("\n=/=/QuizVetor/=/=\n");
    printf("\n1. Responder Quiz\n2. Ver Gabarito\n3. Sair\n");
    printf("\nEscolha uma opcao:");
    valida_leitura = scanf("%d", &opcao);
    //pra nao aceitar caractere invalido
    if (valida_leitura == 0){// Não aceitar letra nem caractere invalido
        printf("Erro! Voce digitou uma letra ou caractere invalido. \n");
        //limpar o buffer
        while(getchar() != '\n');
        opcao= -1;
    }
    //Condição para iniciar
    else if(opcao>3 || opcao<1){
            printf("Opcao Invalida!\n");
            break;
    }
    switch(opcao){

        case 1:

            if(respondido==0){
                respondido = 1;
                printf("\nQuiz Iniciado!\n");
            }


            printf("\nQ01. Qual o tipo para números inteiros?");
            printf("\n (A) int (B) float (C) char");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[0]);
            gabarito[0] = validar(resp_usuario[0], resp_gabarito[0]);


            printf("\nQ02. Qual símbolo indica o operador 'E' lógico?");
            printf("\n (A) || (B) ! (C) &&");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[1]);
            gabarito[1] = validar(resp_usuario[1], resp_gabarito[1]);


            printf("\nQ03. Qual comando sai de um loop?");
            printf("\n (A) continue (B) break (C) exit");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[2]);
            gabarito[2] = validar(resp_usuario[2], resp_gabarito[2]);


            printf("\nQ04.  Caractere que indica o fim de uma string?");
            printf("\n (A) \\0 (B) \\n (C) \\t");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[3]);
            gabarito[3] = validar(resp_usuario[3], resp_gabarito[3]);


            printf("\nQ05. Qual função lê dados do teclado?");
            printf("\n  (A) printf (B) scanf (C) main");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[4]);
            gabarito[4] = validar(resp_usuario[4], resp_gabarito[4]);


            printf("\nQ06. Qual operador indica o 'OU' lógico?");
            printf("\n (A) && (B) ! (C) ||");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[5]);
            gabarito[5] = validar(resp_usuario[5], resp_gabarito[5]);


            printf("\nQ07. Declaração correta de vetor de 5 inteiros?");
            printf("\n  (A) int v[5] (B) v{5} (C) int v5");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[6]);
            gabarito[6] = validar(resp_usuario[6], resp_gabarito[6]);


            printf("\nQ08. Biblioteca necessária para usar o printf?");
            printf("\n  (A) stdio.h (B) math.h (C) string.h");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[7]);
            gabarito[7] = validar(resp_usuario[7], resp_gabarito[7]);


            printf("\nQ09. Qual o resultado da operação 10 %% 3?");
            printf("\n  (A) 0 (B) 3 (C) 1");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[8]);
            gabarito[8] = validar(resp_usuario[8], resp_gabarito[8]);


            printf("\nQ10. O que significa void em uma função?");
            printf("\n  (A) Erro (B) Sem retorno (C) Inteiro");
            printf("\nAlternativa: ");
            scanf(" %c", &resp_usuario[9]);
            gabarito[9] = validar(resp_usuario[9], resp_gabarito[9]);

            break;


        case 2:

            int i;


            if (respondido < 1){
                printf("\nResponda o Quiz antes de verificar o Gabarito!!\n");
                break;
            }

            printf("\n/=/= Gabarito =/=/\n");

            //pra printar se ta errado ou certo
            for(i=0;i < 10; i++){
                //Q%02d: É PRA DEIXAR ARRUMADO CERTINHO
                printf("Q%02d: ", i+1);

                if(gabarito[i] == 1){
                    printf("RESPOSTA CORRETA\n");
                }
                else {
                    printf("RESPOSTA ERRADA\n");
                }

            }
            //Pontos de acerto do quiz
            int nota = 0;

            for(int i = 0; i < 10; i++){
                //mostrar a quantidade de acerto das perguntas no total
                nota += gabarito[i];
            }

            printf("\nPontuacao final: %d Pontos\n", nota);

            break;

    }

}while (opcao!=3);

 return 0;
}