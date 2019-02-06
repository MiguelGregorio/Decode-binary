typedef struct{
	char chave[9];
	char conteudo[265]; //conteudo nao traduzido
	char espiao[6]; //conteudo traduzido
}nt; //Nao Traduzido

typedef struct{
	char nome[20];
	int idade;
	char nacionalidade[15];
	int id;
	char chave[9];
}Agente;

typedef struct{
	char chave[9];
	char conteudo[265];
	char conteudot[10];
}Operacao;

typedef struct{
	char cidade[15];
	
	int ano;
	int mes;
	int dia;
	char nome[20];
	int id;
	char chave[9];
}OP;


