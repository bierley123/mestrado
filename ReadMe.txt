#***********************************	Gerador de Matrizes para Modified Nodal Analysis	***********************************#
|                                                                                                                              |
|	                                                                                                                           |
#***************************************************	Sobre o Programa 	***************************************************#		
|                                                                                                                              |
|                                                                                                                              |
|		O programa quando pronto ira gerar as matrizes A,x e z do sistema linear Ax=z a partir de uma netlist.                 |
|		                                                                                                                       |
|		O algoritmo utilizado para a formação das matrizes pode ser encontrado no site:                                        |
|			                                                                                                                   |
|				https://lpsa.swarthmore.edu/Systems/Electrical/mna/MNA3.html                                                   |
|                                                                                                                              |
|		Para otimização as matrizes geradas são esparsas e são escritas na formatação para leitura em CUDA onde a              |
|		primeira linha descreve as proporções da matriz e a quantidade elementos não nulos.                                    |
|		                                                                                                                       |
|				<Quantidade de Linhas>		<Quantidade de Colunas>		<Quantidade de elementos não nulos>                    |
|                                                                                                                              |
|		Em seguida serão descritos os valores da seguinte forma                                                                |
|                                                                                                                              |
|				<Linha>		<Coluna>		<Valor>                                                                            |
|				                                                                                                               |
|		Obs: Os valores são limitados a 2 casas decimais.                                                                      |
|		                                                                                                                       |
|                                                                                                                              |
#*******************************************************	Execução 	*******************************************************#		
|	                                                                                                                           |
|	                                                                                                                           |
|		Para executar o programa é preciso criar uma pasta com o nome Files no mesmo diretório do executável MNA.exe e         |
|		esta pasta precisa necessáriamente estar vazia antes da execução do programa ou poderá resultar em falhas.             |
|		                                                                                                                       |
|		O arquivo ckt que será analisado também deve estar no mesmo diretório do executavel e com o nome netlist.ckt.          |
|                                                                                                                              |
|		Após a execução do programa será gerado 2 arquivos:                                                                    |
|		                                                                                                                       |
|			-	"/Files/MatrixA.mtx"                                                                                           |
|			-	"/Files/ElapsedTime.txt"                                                                                       |
|			                                                                                                                   |
|		IMPORTANTE: Para executar novamente é preciso apagar os arquivos da pasta Files.                                       |
|          		                                                                                                               |
|       FYI: um arquivo com as dimensões <3573> <3573> <13482> levou por volta de 70 segundos                      			   |
|                                                                                                                              |
#******************************************************************************************************************************#














