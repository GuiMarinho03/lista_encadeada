#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no
{
	int info;
	struct no *prox;
};
typedef struct no Lista;

Lista *cria_lista(void)
{
	return NULL;
}

Lista *insere_inicio(Lista *p, int x)
{
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = x;
	novo->prox = p;
	p = novo;
	return p;
}

Lista *insere_final(Lista *p, int x)
{
	Lista *aux, *novo;
	novo= (Lista*)malloc(sizeof(Lista));
	if(p == NULL)
	{
		novo->prox = p;
		p = novo;
	}else
	{
		aux = p;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	return p;	
}

void mostrar (Lista *p)
{
	Lista *aux;
	aux = p;
	while(aux != NULL)
	{
		printf("%d", aux->info);
		aux = aux->prox;
	}
	
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	Lista *L1, *L2, *L3;
	int num;
	char op;
	
	L1 = cria_lista();
	L2 = cria_lista();
	L3 = cria_lista();
	
	do
	{
		puts("\n Digite um número para ser inserido na Lista1 ");
		scanf("%d", &num);
		
		L1 = insere_inicio(L1, num);
		
		puts("\n Deseja inserir outro número? (s/n)");
		scanf(" %c", &op);
		
	}while(op == 's');
	
	do
	{
		puts("\n Digite um número para ser inserido na Lista2 ");
		scanf("%d", &num);
		
		L2 = insere_final(L2, num);
		
		puts("\n Deseja inserir outro número? (s/n)");
		scanf(" %c", &op);		
	}while(op == 's');
}