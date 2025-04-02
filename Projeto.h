#define TOTAL_TAREFAS 100 // Número máximo de tarefas ajustado

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[TOTAL_TAREFAS]; // Corrigido o nome da variável para tarefas, ao invés de "tarefas"
    int qtd;
} ListaDeTarefas; // Erro no nome da struct, deve ser ListaDeTarefas
 
int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);
int carregarTarefas(ListaDeTarefas *lt, char *nome); // Corrigido o nome do parâmetro para char *nome, ao invés de "nomes" 
int salvarTarefas(ListaDeTarefas *lt, char *nome);

int editarTarefa(ListaDeTarefas *lt);

void exibeMenu();
