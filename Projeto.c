#include "Projeto.h" // Corrigido o nome do arquivo de cabeçalho para "Projeto.h"
#include <stdio.h> // Corrigido o nome do arquivo de cabeçalho para <stdio.h>
#include <string.h> // Corrigido o nome do arquivo de cabeçalho para <string.h>

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;
    
    Tarefa *t = &lt->tarefas[lt->qtd]; // Erro de digitação no operador "->"

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);

    printf("Entre com a categoria da tarefa: ");
    scanf("%s", t->categoria);

    printf("Entre com a descricao da tarefa: ");
    scanf("%s", t->descricao);

    lt->qtd++;

    return 0;
}

int deletarTarefa(ListaDeTarefas *lt){
   if (lt->qtd == 0)
   return 1;
   
   int pos;
   printf("Entre com a posicao que deseja deletar: ");
   scanf("%d", &pos);
   
   if (pos < 0 || pos >= lt -> qtd) // Para garantir que a posição esteja dentro do intervalo válido, deve-se verificar se pos é menor que 0 ou maior ou igual a lt->qtd.
   return 2;
   
   for (; pos<lt->qtd-1; pos++){
   	lt->tarefas[pos].prioridade=lt->tarefas[pos+1].prioridade; 
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao); // A função strcpy deve copiar a string de uma variável para outra, mas aqui está copiando a categoria para a descrição, o que não faz sentido.
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

   }
   
    lt->qtd--;
	return 0;
}

int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0)
	return 1;
	

int i;
for(i=0; i< lt->qtd; i++){
	printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i, 
	lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
	printf("Descricao: %s\n", lt->tarefas[i].descricao);
}
    return 0;
}

int carregarTarefas(ListaDeTarefas *lt, char *nome){ // agora o char *nome é um ponteiro que aponta para uma string
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb"); // Adicionado ponto e vírgula   
   if (fp == NULL)
   return 1;
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int editarTarefa(ListaDeTarefas *lt){
    if(lt -> qtd == 0){
        printf("Sem tarefas para editar\n");
        return 1;
    }

    int pos;
    printf("Digite a posicao que deseja editar (0 a %d): ", lt -> qtd - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= lt -> qtd){
        printf("Posicao invalida\n");
        return 2;
    }

    Tarefa *t = &lt -> tarefas[pos];

    printf("Digite a nova prioridade: ");
    scanf("%d", &t -> prioridade);

    printf("Digite a nova categoria: ");
    scanf(" %[^\n]s", t -> categoria);

    printf("Digite a nova descricao: ");
    scanf(" %[^\n]s", t -> descricao);

    printf("Tarefa editada!\n");

    return 0;
}

void exibeMenu(){
    printf("\nMenu\n"); // ajustando a formatação
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
    printf("4. Editar tarefa\n");
	printf("0. Sair\n");
}

