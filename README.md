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
