#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"estruturas.h"
#include "funcoes.h"




int main(){
	
	FILE *f, *o;
	FILE *ag, *oo;
	char *v=NULL, *op=NULL;
	int tam=0, tam1=0, tamagente=0, tamo=0, tamop =0, tamoper=0;
	char chave[9];
	nt *vetor=NULL;
	OP *oper=NULL;
	Agente *agente=NULL;
	Operacao *operacao=NULL;
	char resto[264];
	char cont[264];
	int l=0, j=0, h=0, z=0;
	int k,i,w,c,hh=0, valorP, valorS, valorT,tamanho, sim, id, idade,g,chaveINT,ss, num;
	char p[8], s[8], t[8], idadeC[2], idC[3],ch1,ch2,ch3,chaveC[9], ano[5], mes[3], dia[3], ch4;
	char *textDeco;
	
	
	int opcao = menu();
    if(opcao == 0){
    	return 0;
	}
	while(opcao != 0){
		switch(opcao){
			case 1:
				f = fopen("espiao.txt", "rb"); 
				if(f == NULL){
					printf("Erro ao abrir o ficheiro espiao!\n");
				}
				
				else{
					printf("Ficheiro espiao aberto com sucesso!\n");
					
					while(!feof(f)){
						v = (char*)realloc(v, ++tam*sizeof(char));
						fscanf(f, "%c", &v[tam-1]);
					}
					printf("conteudo copiado com sucesso para vetor v \n");
				}
				
				
				o = fopen("ops.txt", "rb");
				if(o==NULL)
					printf("Erro ao abrir o ficheiro ops! \n");
					
				else{
					printf("Ficheiro ops aberto com sucesso! \n");
					
					while(!feof(o)){
						op = (char*) realloc (op, ++tamo*sizeof(char));
						fscanf(o, "%c", &op[tamo-1]);
					}
					printf("conteudo copiado com sucesso para vetor op \n");
				}
				break;
				
			case 2:
					printf("Introduza a chave:");
					scanf("%s", &chave);printf("\n");
					
					for(i=0 ; i<tam ; i++){
					if(chave[j]==v[i] && chave[j+1]==v[i+1] && chave[j+2]==v[i+2] && chave[j+3]==v[i+3] && chave[j+4]==v[i+4] && chave[j+5]==v[i+5] && 
						chave[j+6]==v[i+6] && chave[j+7]==v[i+7]){  //procurar chave no vetor v
						
						
						vetor=(nt*)realloc(vetor, ++tam1*sizeof(nt));
						
						strcpy(vetor[tam1-1].chave, chave);  //copiar chave para vetor 
						
						for(k=i+8 ; k<=i+272 ; k++){
							resto[l]=v[k];
							l++;
							}
						l=0;

						strcpy(vetor[tam1-1].conteudo , resto); //copiar o resto do conteudo para o vetor
					}
				}
				
				
				for(i=0 ; i<tamo ; i++){
					if(chave[j]==op[i] && chave[j+1]==op[i+1] && chave[j+2]==op[i+2] && chave[j+3]==op[i+3] && chave[j+4]==op[i+4] && chave[j+5]==op[i+5] && 
					chave[j+6]==op[i+6] && chave[j+7]==op[i+7]){
						
						operacao= (Operacao*) realloc (operacao, ++tamop*sizeof(Operacao));
						
						strcpy(operacao[tamop-1].chave, chave);
						
						for(k=i+8 ; k<=i+272 ; k++){
							cont[l]=op[k];
							l++;
							}
						l=0;
						
						strcpy(operacao[tamop-1].conteudo , cont);
						
					}
				}
				
	
				
				
	for(w=0 ; w<tam1 ; w++){
	
		for(c=0 ; c<8 ; c++){
			p[c]=vetor[w].conteudo[c]; //primeiros 8 bits do conteudo
		}
	
		for(c=0 ; c<8 ; c++){
			s[c]=vetor[w].conteudo[c+8]; //segundos 8 bits
		}
		
		for(c=0 ; c<8; c++){
			t[c]=vetor[w].conteudo[c+16];
		}
	
			valorP= binarioToDecimal(p,8);
			valorS= binarioToDecimal(s,8);
			valorT= binarioToDecimal(t,8);
	
	
	
	
	
	if(valorP>=65 && valorP<=90 && valorS>=97 && valorS<=122 && ((valorT>=97 && valorT<=122) || (valorT == 32))  ){
		 
    	tamanho = strlen(vetor[w].conteudo);
	    
	    sim = tamanho / 8 +1;

	    textDeco =(char*) malloc(sim + 1);
  
	    binarioToText(vetor[w].conteudo, tamanho, sim, textDeco);

	    //printf(" ASCII: %s\n", textDeco);
	    
	    strcpy(vetor[w].espiao, textDeco); // copiar conteudo traduzido
	    
	   
	    
	}
	else
		vetor[w].espiao[1]='n';	//flag
	}
	
	
	for(c=0 ; c< tam1 ; c++){
		if((vetor[c].espiao[1]!='n')&&(vetor[c].conteudo[0]!='c' )){
			
		
		agente=(Agente*) realloc (agente, ++tamagente*sizeof(Agente));
		
		
		
		z=0;
		h=0; //acompanha as posicoes da nacionalidade
		
		while(vetor[c].espiao[z]!='#'){ //copiar nome do espiao para vetor agente
			agente[tamagente-1].nome[z]=vetor[c].espiao[z];
			z++;
		}
		
			ch1=vetor[c].espiao[z+1];   //copiar a idade para o vetor agente
			ch2=vetor[c].espiao[z+2];
			
			idadeC[0]=ch1;
			idadeC[1]=ch2;
			
			idade=atoi(idadeC);
			
			agente[tamagente-1].idade= idade;
			z=z+3;
			
			
		while(vetor[c].espiao[z]!='#'){ //copiar nacionalidade do espiao para vetor agente
			agente[tamagente-1].nacionalidade[h]=vetor[c].espiao[z];
			z++;
			h++;
		}
		
		
	for(ss=0 ; ss<10 ; ss++){ // copiar chave
		agente[tamagente-1].chave[ss]=vetor[c].chave[ss];
	}
		
		
		
		
		
		ch1=vetor[c].espiao[z+1]; //copiar id do espiao para vetor agente
		ch2=vetor[c].espiao[z+2];
		ch3=vetor[c].espiao[z+3];
		
		
		idC[0]=ch1;
		idC[1]=ch2;
		idC[2]=ch3;
		id= atoi(idC);
		agente[tamagente-1].id=id;
		
		vetor[c].conteudo[0]='c'; //flag
		hh++;
		
		printf("copiado com sucesso");	
	}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	for(w=0 ; w<tamop ; w++){ //precorre as operacoes
	
		for(c=0 ; c<8 ; c++){
			p[c]=operacao[w].conteudo[c]; //primeiros 8 bits do conteudo
		}
	
		for(c=0 ; c<8 ; c++){
			s[c]=operacao[w].conteudo[c+8]; //segundos 8 bits
		}
		
		for(c=0 ; c<8; c++){
			t[c]=operacao[w].conteudo[c+16];
		}
	
			valorP= binarioToDecimal(p,8);
			valorS= binarioToDecimal(s,8);
			valorT= binarioToDecimal(t,8);
			
			
		if(valorP>=65 && valorP<=90 && valorS>=97 && valorS<=122 && valorT>=97 && valorT<=122){
		 
    		tamanho = strlen(operacao[w].conteudo);
	    
	    	sim = tamanho / 8 +1;

	    	textDeco =(char*) malloc(sim + 1);
  
	    	binarioToText(operacao[w].conteudo, tamanho, sim, textDeco);

	    	//printf(" ASCII: %s\n", textDeco);
	    
	    	strcpy(operacao[w].conteudot, textDeco);
	}
	else
		operacao[w].conteudot[0]='n';	
	}
	
	
	for(c=0 ; c< tamop ; c++){
		if((operacao[c].conteudot[0]!='n')&&(operacao[c].conteudo[0]!='c' )){
			
		
		oper=(Operacao*) realloc (oper, ++tamoper*sizeof(Operacao));
		
		
		
		z=0;
		
		
		while(operacao[c].conteudot[z]!='2'){ //copiar cidade da operacao
			oper[tamoper-1].cidade[z]=operacao[c].conteudot[z];
			z++;
		}
		
		
			
			ano[0]=operacao[c].conteudot[z]; // copiar ano
			ano[1]=operacao[c].conteudot[z+1];
			ano[2]=operacao[c].conteudot[z+2];
			ano[3]=operacao[c].conteudot[z+3];
			num=atoi(ano);
			oper[tamoper-1].ano=num;
			
			
			mes[0]=operacao[c].conteudot[z+4]; //copiar mes
			mes[1]=operacao[c].conteudot[z+5];			
			num=atoi(mes);
			oper[tamoper-1].mes=num;
			
			
			dia[0]=operacao[c].conteudot[z+6]; //copiar dia
			dia[1]=operacao[c].conteudot[z+7];
			num=atoi(dia);
			oper[tamoper-1].dia=num;
			
			
		for(ss=0 ; ss<10 ; ss++){ // copiar chave para opecacoes
		oper[tamoper-1].chave[ss]=operacao[c].chave[ss];
		}
			
				operacao[c].conteudo[0]='c'; //flag
		}
		}
	
	

	
	
	
	
			break;
			
			case 3:
				
				BubbleSort(agente, hh); //ordena o ficheiro espiao
				
				ag = fopen("relatorio_espiao.txt", "w");
			for(g=0 ; g<tamagente ; g++){
		
			fprintf(ag, "ID do agente : %d  ", agente[g].id);
			fprintf(ag, "nome do agente : %s   ", agente[g].nome);
			fprintf(ag, "idade do agente : %d   ", agente[g].idade);
			fprintf(ag, "chave do agente : %s   ", agente[g].chave);
			fprintf(ag, "nacionalidade do agente : %s   \n", agente[g].nacionalidade);
			}
			
			
				oo=fopen("relatorio_operacoes.txt", "w");
					for(g=0 ; g<tamoper ; g++){
						
						
						
						fprintf(oo, "cidade : %s  ", oper[g].cidade);
						fprintf(oo, "chave : %s   ", oper[g].chave);
						fprintf(oo, "agentes : ");
						for(i=0; i<tamagente; i++){ //escreve o nome e ID dos agentes atribuidos a cada missão
							if(strcmp(agente[i].chave , oper[g].chave)==0){
								fprintf(oo, "id:%d  %s, ",agente[i].id, agente[i].nome);
							}
						}
						fprintf(oo, "data : %d/%d/%d  \n", oper[g].dia , oper[g].mes , oper[g].ano);
					}
			
				break;
			default:
			printf("Deve introduzir uma opcao valida!\n");
					}
		opcao = menu();
	}
}

