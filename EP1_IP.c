/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 04 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Guilherme A. A. de Souza>                 <5642180>          **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>

/* Variaveis globais utilizas pela função separaNumero */
int unidades;
int dezenas;
int centenas;
int milhares;

/*
	Separa o valor de entrada em unidades, dezenas, centenas e milhares.

	Se o numero passado como parametro for menor que zero ou maior que 9999,
	a função devera colocar o valor -1 nas quatro variaveis globais
	existentes no programa: unidades, dezenas, centenas e milhares.

	Caso contrario, a função devera separar o numero de acordo com suas
	unidades, dezenas, centenas e milhares e colocar esses valores nas
	respectivas variaveis globais.
	Isto e, para o numero 2345, deve atribuir o valor 2 na variavel
	milhares, o valor 3 na variavel centenas, o valor 4 na variavel dezenas
	e o valor 5 na variavel unidades.

	Parametro:
		valor - Valor a ter seus digitos separados
*/
void separaNumero(int valor){

	/* IMPLEMENTE SEU CODIGO AQUI */

int param = 1000;
int resto;

if(valor > 9999 || valor < 0){
unidades = -1;
dezenas = -1;
centenas = -1;
milhares = -1;
}else{
for(valor; param >= 1; param = param/10){
for(valor; param >= 10; param = param/10){
for(valor; param >= 100; param = param/10){
for(valor; param == 1000; param = param/10){
milhares = valor / param;
resto = valor % param;
valor = resto;
}
centenas = resto / param;
resto = valor % param;
valor = resto;
}
dezenas = resto / param;
resto = valor % param;
valor = resto;
}
unidades = resto / param;
resto = valor % param;
}
}
}


/*
	Suponha que a população de um país A seja da ordem de "popA" habitantes com uma taxa anual de crescimento de
	"taxaA" (em %) e que a população de B seja "popB" habitantes com uma taxa de crescimento de "taxab" (em %).
	Escreva uma função que calcule e retorne o número de anos necessários para que a população do país A
	ultrapasse ou iguale a população do país B, mantidas as taxas de crescimento.

	A função irá retornar -1 se algum dos parâmetros for  negativo ou se nunca for possível a população
	do país A ultrapassar a população de B.

	Parametros:
	pA: população do país A
	taxaA: taxa de crescimento de A em porcentagem
	pB: população do país A
	taxaB: taxa de crescimento de B em porcentagem
*/
int ultrapassagem(double popA, double taxaA, double popB, double taxaB){
   
	/* IMPLEMENTE SEU CODIGO AQUI */

double A = 0;
double B = 0;
int anos = 0;


if(popA < 0 || taxaA < 0 || popB < 0 || taxaB < 0){
return -1;
}
if(popB > popA && taxaB >= taxaA){
return -1;
}
else{
for(anos = 0; popA < popB; anos = anos + 1){
A = popA * ((taxaA/100) + 1);
B = popB * ((taxaB/100) + 1);
popA = A;
popB = B;
}
}
return anos;
}


/*

	Esta função recebe tres numeros inteiros (inicio, fim e passo).
	Se qualquer desses numeros for negativo ou nulo a função devera
	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);
	Se o valor de fim for menor do que o valor de inicio, a função tambem
	devera retornar -1 (menos um).

	Caso contrario, a função devera retornar a soma de todos os numeros
	"primos de Germain" que aparecem no intervalo. Sophie Germain foi
	uma matemática francesa nascida no século XVIII.	Um número n é "primo
	de Germain" se n é primo e 2n+1 também é primo.

	Os "primos de Germain" são chamados "primos seguros", devido a uma
	aplicação prática que ela
	nunca poderia ter previsto. Os principais métodos atuais de criptografia
	são baseados no fato de
	que, dado um produto pq de dois primos grandes, é difícil identificar
	os fatores p e q. Mas isso depende da escolha dos primos: por exemplo,
	se p é tal que p–1 pode ser fatorizado em primos pequenos, não é tão
	difícil quebrar a criptografia. Um jeito de evitar esse risco é usar
	p e q que sejam primos seguros. (Marcelo Vianna, Folha de São Paulo,
  01/06/22)

	Por exemplo, para inicio=0, fim=10 e passo=1, a função devera retornar 10,
	pois os "primos de Germain" são 2, 3 e 5, logo, a soma deles é 10.
	Fique à vontade para criar funções auxiliares caso julgue necessário para
	obter o resultado desta função.

	Parametros:
		inicio - Primeiro valor a participar da soma
		fim - Os valores utilizados na soma devem ser menores do que fim
		passo - Variacao aplicada a cada valor a partir do valor de inicio
*/

int germain(int n){

int resto;
int divisor;
int quociente;
int germain = (2 * n) + 1;


for(divisor = 2; divisor != n; divisor = divisor + 1){
resto = germain % divisor;
quociente = germain / divisor;
if (resto == 0 || quociente == 0){
return 0;
}
}
return n;
}


int primo(int n){

int resto;
int divisor;
int quociente;
int verif;


for(divisor = 2; divisor != n; divisor = divisor + 1){
resto = n % divisor;
quociente = n / divisor;
if (resto == 0 || quociente == 0){
return 0;
}
}  
verif = germain(n);
return verif;
}


int somaprimosdegermain(int inicio, int fim, int passo){

	/* IMPLEMENTE SEU CODIGO AQUI */

int soma = 0;


if(inicio <= 0 || fim <= 0 || passo <= 0 || fim < inicio){
return -1;
}
else{

while(inicio <= fim){
soma = soma + primo(inicio);
inicio = inicio + passo;
}
}

return soma;
}


 


/*
  Considere a sequência de números: 1, -1/2, 1/3, -1/4, 1/5,...
	onde n é um número inteiro maior que zero.

	Esta função calcula, para um valor de n passado como parâmetro,
	a somatória de 1 + (-1/2) + 1/3 + (-1/4) + 1/5... + (-1)^(n+1)/n
	onde o símbolo ^ representa a operação de potenciação. Por exemplo,
	2^2 = 4.

	Note que a fórmula (-1)^(n+1)/n dá o n-ésimo elemento
	da sequência. Por exemplo, para n=1, (-1)^(1+1)/1 = 1^2/1 = 1; para
	n = 3, o terceiro elemento será (-1)^(3+1)/3 = (-1)^4/3 = 1/3.

	A função recebe como parâmetro um número inteiro e retorna a somatória
	da sequência. O valor da somatória será um número real, logo, o retorno
	dela será um double.

	Se o parâmetro de entrada representando n for menor ou igual a zero, a
	função irá	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);

		Parametros:
		n - inteiro positivo

*/

double verif(int y){

int x;

x = y % 2;
  
if(x != 0 || y == 1){
return ((double) 1 / y);
}else{
return ((double) -1 / y);
}
}

double somasequencia(long n){

	/* IMPLEMENTE SEU CODIGO AQUI */

double soma = 0;
int y;


if(n <= 0){
return -1;
}else{
for(y = 1; y <= n; y = y + 1){
   soma = soma + verif(y);
}
}
return soma;
}


/*
	Esta função calcula o fatorial de um número natural n (lembre-se
  que os números naturais são inteiros maiores ou iguais a zero)

	Ela recebe um numero inteiro como parâmetro (n).
	Se este numero for menor do que zero, a função devera retornar -1.

	Caso contrario, a função devera retornar o fatorial de n, isto é, n!

	Parametro:
		n - indica o numero natural para o qual será calculado o fatorial
*/

long fatorial(int n){

	/* IMPLEMENTE SEU CODIGO AQUI */

int fat;
  
if (n == 0){
return fat = 1;
}  
if (n < 0){
return -1;
}

else{

for(fat = 1; n > 1; n = n - 1){
fat = n * fat;
}
}
      
return fat;
}



/*
	função main criada apenas para seus testes.
	Voce pode adicionar novos testes se quiser.
	ESTA função SERA IGNORADA NA CORRECAO
*/
int main() {

	/* Exemplos de testes para a função separaNumero: */
	int valor;

	valor = 2345;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

	valor = 606;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

	valor = -1;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = 0;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = -10;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = 10000;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = 1;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");


     valor = 29;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = 305;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

     valor = 6010;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");


	/* Exemplos de testes para a função ultrapassagem: */
	double taxaA, taxaB;
	int popA, popB;

	taxaA = 2; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

	taxaA = 2; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = 37000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

	taxaA = 2; // % de crescimento
	taxaB = 1.0;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

	taxaA = 0.2; // % de crescimento
	taxaB = 1.0;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

	taxaA = 2; // % de crescimento
	taxaB = -1.0;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

taxaA = -9; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

taxaA = 2; // % de crescimento
	taxaB = -1.5;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

taxaA = 2; // % de crescimento
	taxaB = 1.5;

	popA = -37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));

taxaA = 2; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = -400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));


taxaA = 1; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));


taxaA = 0.5; // % de crescimento
	taxaB = 1.5;

	popA = 400000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));


taxaA = 0.5; // % de crescimento
	taxaB = 1.5;

	popA = 37000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));


taxaA = 4.9; // % de crescimento
	taxaB = 1.5;

	popA = 390000;
	popB = 400000;

	printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA,\
	taxaB, popB, ultrapassagem(popA, taxaA, popB, taxaB));



	/* Exemplos de testes para a função somaprimosdegermain: */
	int inicio;
	int fim;
	int passo;

	inicio = 0;
	fim = 10;
	passo = 1;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

	inicio = 1;
	fim = 30;
	passo = 1;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

     inicio = 1;
	fim = 10;
	passo = 1;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));


inicio = 2;
	fim = 100;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = -2;
	fim = 100;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 2;
	fim = -100;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 2;
	fim = 100;
	passo = -2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 10;
	fim = 2;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 2;
	fim = 100;
	passo = 3;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = -20;
	fim = -2;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 8;
	fim = 99;
	passo = 3;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 4;
	fim = 100;
	passo = 2;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));

inicio = 5;
	fim = 200;
	passo = 6;
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i\n\n", inicio, fim, passo, somaprimosdegermain(inicio, fim, passo));


	/* Exemplos de testes para a função somasequencia:  */
  long n = 5;

	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

  n = 50;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

	n = 1000;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

	n = 25000;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

	n = 32000;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

	n = 32000000;
  printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

n = -10;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));

n = 0;
	printf("Soma da sequencia para n=%ld: %f\n\n", n, somasequencia(n));



	/* Exemplos de testes para a função fatorial: */
	int valorDeN;

	valorDeN = -1;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 0;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 1;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 2;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 3;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 4;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 5;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 6;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 7;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 10;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));

	valorDeN = 50;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fatorial(valorDeN));


	/* se desejar, escreva seu codigo (para testes) aqui */


	return 0;
}
