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

int editarTarefas(ListaDeTarefas *lt){    // Criação da função de edição de tarefas
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

int ordenarTarefas(ListaDeTarefas *lt, int prioridade){ // Criação da função de ordenar tarefas por prioridade
    if(lt -> qtd <= 1){
        printf("Sem tarefas para ordenar\n");
        return 1;
    }

    for (int i = 0; i < lt -> qtd - 1; i++){
        for (int j = i + 1; j < lt -> qtd; j++){
            if (lt -> tarefas[i].prioridade > lt -> tarefas[j].prioridade){
                Tarefa temp = lt -> tarefas[i];
                lt -> tarefas[i] = lt -> tarefas[j];
                lt -> tarefas[j] = temp;
            }
        }
    }
    printf("Tarefas ordenadas por prioridade\n");
    return 0;
}

int buscarTarefas(ListaDeTarefas *lt, char *categoria){ // Criação da função de buscar tarefas por categoria
    if (lt -> qtd == 0){
        printf("Sem tarefas para buscar\n");
        return 1;
    }

    char buscarCategoria[100];
    printf("Digite a categoria que deseja buscar: ");
    scanf(" %[^\n]s", buscarCategoria);

    int achou = 0;
    printf("Tarefas encontradas na categoria '%s':\n", buscarCategoria);
    
    for (int i = 0; i < lt -> qtd; i++){
        if (strcmp(lt -> tarefas[i].categoria, categoria) == 0){
            printf("Posicao: %d \t Prioridade: %d\n", i, lt -> tarefas[i].prioridade);
            printf("Descricao: %s\n", lt -> tarefas[i].descricao);
            achou = 1;
        }
    }
    if (!achou){
        printf("Nenhuma tarefa encontrada na categoria '%s'\n", buscarCategoria);
    }
    return 0;
}
void exibeMenu(){
    printf("\n======Menu======\n"); // ajustando a formatação
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
	printf("3. Listar tarefa\n");
    printf("4. Editar tarefa\n");
    printf("5. Ordenar tarefas\n");
    printf("6. Buscar tarefas\n");
	printf("0. Sair\n");
}

