# Integrantes do grupo

Rafael Almeida Ferreira | RA: 24.224.013-3;
Renan Sartori Evangelista | RA: 24.224.004-2;

# Corrigindo erros e bugs

1. A função main não está retornando nada, impedindo a execução do programa;
2. No arquivo "projeto.h", o struct está escrito errado, o certo é "ListaDeTarefas";
3. No arquivo "projeto.c", a função "carregarTarefas" estava dando um erro pois o char "nome" não estava como um ponteiro;
4. No arquivo "projeto.c" na função "salvarTarefas", a linha de código "FILE *fp=fopen(nome, "wb")" estava sem ponto e vírgula, impossibilitando a continuação da função;  
5. Na função "deletarTarefa", strcpy deve copiar a string de uma variável para outra, mas aqui está copiando a categoria para a descrição, o que não faz sentido;
6. Na função "deletarTarefa", a condição para verificar se a posição está dentro do intervalo válido está errada;
7. Na função "criarTarefa", o operador "->" do ponteiro está com um erro de digitação que impedia a leitura do código;
8. No arquivo "projeto.h", na função "carregarTarefas", o char *nome está escrito errado, o correto seria "nome" ao invés de "nomes";
9. As bibliotecas estavam com sintaxe erradas, o que impedia a importação das mesmas;
10. Corrigido o número máximo de tarefas;
11. Ajustando a formatação do menu em "Projeto.c";
12. No arquivo "main.c", o código "lt.qtd=2" está errado, o correto seria "lt.qtd=0", para iniciar a quantidade de tarefas como 0;
13. No arquivo "main.c", o código "if (codigo == 2)" em listarTarefas está errado, pois deve ser 1 pois listarTarefas retorna 1 quando não há tarefas;
14. No arquivo "main.c", a condição if(codigo == 0) está errada pois teria que ser diferente de zero, ou seja, (codigo != 0).

# Melhorias e adições 

15. Na função "editarTarefas", é possível mudar a prioridade, categoria e descrição de uma tarefa específica;
16. Função "editarTarefa" adicionada no "Menu" do arquivo "main.c";
17. Função "editarTarefa" declarada no arquivo "Projeto.h";
18. Função "editarTarefa" implementada no arquivo "Projeto.c";
19. Na função "ordenarTarefas", é possível alterar a ordem das tarefas com base na prioridade;
20. Função "ordenarTarefas" adicionada no "Menu" do arquivo "main.c";
21. Função "ordenarTarefas" declarada no arquivo "Projeto.h";
22. Função "ordenarTarefas" implementada no arquivo "Projeto.c";
23. Na função "buscarTarefas", é possível buscar tarefas por categoria;
24. Função "buscarTarefas" adicionada no "Menu" do arquivo "main.c";
25. Função "buscarTarefas" declarada no arquivo "Projeto.h";
26. Função "buscarTarefas" implementada no arquivo "Projeto.c".