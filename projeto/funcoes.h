#include <math.h>

int menu()
{
	int opcao;
	printf("\n");
	printf("*********E.S.C.U.D.O.**********************\n");
	printf("MENU\n");
	printf("****************************************************\n");
	printf("1 - Ler ficheiro\n");
	printf("2 - Pesquisa de conteudo\n");
	printf("3 - Copiar informacoes para Ficheiros \n");
	printf("0 - Sair\n");
	printf("****************************************************\n");
	printf("Introduza uma das opcoes:");
	scanf("%d", &opcao);
	printf("***************************************\n");
	return opcao;
}


int bin2dec( char* binary)
{
    int len,dec=0,i,exp;

    len = strlen(binary);
    exp = len-1;

    for(i=0;i<len;i++,exp--)
        dec += binary[i]=='1'?pow(2,exp):0;
    return dec;
}

unsigned long binarioToDecimal(char *binario, int length){

        int a;

        unsigned long decimal = 0;
        unsigned long peso = 1;

        binario += length - 1;
        peso = 1;


        for(a = 0; a < length; ++a, --binario){

            if(*binario == '1'){
                decimal += peso;
            }

            //
            peso *= 2;
        }

        return decimal;
    }


void binarioToText(char *vetorbin, int tamanho, int sim, char *text ){

        int a;

        for(a = 0; a < tamanho; a += 8, vetorbin += 8){

            char *byte = vetorbin;

            
            byte[8] = '\0';

            
            *text ++ = binarioToDecimal(byte, 8);
        }

        //text -= sim;
    }


void BubbleSort(Agente *v,  int  N)
{
	int  i, trocas;
	Agente aux;
	do{
		trocas = 0;
		for (i =0; i<N-1; i++)
		{
			if (v[i].id > v[i+1].id)
			{
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				trocas++;
			}
		}
	}while (trocas != 0);
}
