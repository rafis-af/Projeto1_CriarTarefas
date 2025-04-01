#include "Projeto.h" // Corrigido o nome do arquivo de cabeçalho para "Projeto.h"
#include <stdio.h> // Corrigido o nome do arquivo de cabeçalho para <stdio.h>
#include <string.h> // Corrigido o nome do arquivo de cabeçalho para <string.h>
#include <stdlib.h> // Incluindo biblioteca stdlib.h para usar a função system()

int main(){
    ListaDeTarefas lt;

    char arquivo[] = "tarefas";
    int codigo, opcao;

    codigo=carregarTarefas(&lt, arquivo); 

    if (codigo != 0){
        printf("Lista de tarefas nao carregada");
        lt.qtd = 0; // Inicializa a quantidade de tarefas como 0 se o carregamento falhar
    }

    do{
        exibeMenu();
        scanf("%d", &opcao);

    if(opcao == 0){

    } else if(opcao == 1){
        codigo = criarTarefa(&lt);
        if (codigo == 1)
        printf("erro ao criar tarefa: Sem espaço disponível\n");
    } else if(opcao == 2){
        codigo = deletarTarefa(&lt);
        if (codigo == 1)
            printf("erro ao deletar tarefa: nao existem tarefas para deletar\n");
        else if(codigo == 2)
            printf("erro ao deletar tarefa: posicao invalida\n");
    } else if(opcao == 3){
        codigo = listarTarefas(&lt);
    if (codigo == 1) // Erro de digitação, deve ser 1 pois listarTarefas retorna 1 quando não há tarefas 
        printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
    }
    else {
        printf("opcao invalida\n");
    }
    } while (opcao != 0);

    codigo=salvarTarefas(&lt,arquivo);
    if(codigo != 0) // Erro de digitação, deve ser != 0 pois salvarTarefas retorna 0 quando não há erro
        printf("Erro ao salvar tarefas em arquivo");

    system("pause");
    // A função main não está retornando nada, o que impede a execução do programa
    return 0;

}
