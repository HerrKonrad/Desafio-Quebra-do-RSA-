#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Disciplina Algoritmos e Programação
 * Professor: Élgio Schlemer
 * Autor: Arthur Luís Kuck Konrad
 * Algoritmo que encontra o maior e menor divisor de um numero,
 * sendo otimizado para numeros gigantescos dentro do limite dos 64 bits com sinal ( caso o compilador e arquitetura
 * permitam, caso executa em 32bits, o nosso limite será o intervalo de 32 bits com sinal )
 */

 //Calculos e operações

 // Esta função verifica se de acordo com o numeor, o menor e maior divisor o numero era primo, se for primo não houve sucesso
int verificarSucesso(long n, long d1, long d2)
{
    int sucesso = 0;
    n = ( n < 0) ? - n : n;

    if(d2 != n && d1 > 1)
    {
        sucesso = 1;
    }

    return sucesso;
}

// Se já sabemos o menor divisor basta apenas dividir o numero pelo menor divisor que teremos o maior divisor
long buscarMaiorDivisor(long num, long menor_div)
{
    return  menor_div == 1 ? num : num / menor_div;
}


/*
 * Aqui está a parte mais complexa, precisamos fazer algumas otimizações para numeros muito grandes:
 * 1° Quando o numero for par, já sabemos o resultado, o menor divisor é zero e o maior a metade
 * não há necessidade de entrar no laço
 * 2° Agora para os numeros impares, apenas verificaremos até a raiz quadrada do numero, depois da raiz quadrada nada acharemos
 * e também pularemos o laço de 2 em 2, ou seja, só buscando numeros impares, isso reduz as verificações pela metade
 */
long buscarMenorDivisor(long num)
{
    size_t i;
    long resultado = 0;
    num = num < 0 ? -num : num;
    long numSQRT = (long) sqrt(num);

    if(num % 2 != 0)
    {
        for( i = 3 ; i <= numSQRT ; i += 2 )
        {
            if ( num % i == 0)
            {
                resultado = i;
                break;
            }
        }
    }
    else
    {
        resultado = 2;
    }

    return resultado == 0 ? 1 : resultado;
}

long verificarMaiorNumero( long a, long b )
{
    return ( a > b || a == b ) ? a : b;
}


long verificarMenorNumero( long a, long b )
{
    long resultado = 0;
    if( a == 0 )
    {
        resultado = b;
    }
    else if( b == 0 )
    {
        resultado = a;
    }
    else if ( a < b )
    {
        resultado = a;
    }
    else
    {
        resultado = b;
    }
    return resultado;
}

//Entradas
long pedirNumero()
{
    long temp = 0;

    puts("# Qual o valor da chave n? ");
    scanf( "%li", &temp );

    return temp;
}


size_t pedirQuantidadeNumeros()
{
    size_t qtd = 0;
    long temp = 0;
    puts("# Quantos numeros deseja inserir: ");
    scanf("%ld", &temp);
    if( temp <= 0)
    {
        temp = pedirQuantidadeNumeros(); //O numero de quantidade não pode ser menor igual a zero, o programa vai ficar pedindo até vir um válido
    }
    qtd = temp;

    return qtd;
}

//Main
int main()
{
    size_t quantidade = pedirQuantidadeNumeros();
    size_t i;
    long maior_div, menor_div;
    int sucesso = 0;
    long maior_num = 0;
    long menor_num = 0;
    long numero = 0;

    //Pede numeros conforme a quantidade solicitada
    for( i = 0 ; i < quantidade ; i++ )
    {
        numero = pedirNumero();
        if(numero != 0 )
        {
            menor_div = buscarMenorDivisor(numero);
            maior_div =  buscarMaiorDivisor(numero, menor_div);

            printf("%li = %li * %li \n", numero, menor_div, maior_div);

            sucesso += verificarSucesso(numero, menor_div, maior_div); //Se não for primo, houve sucesso

            maior_num = verificarMaiorNumero(numero, maior_num);
            menor_num = verificarMenorNumero(numero, menor_num);
        }
    }

    printf("%d %d %li %li", quantidade, sucesso, menor_num, maior_num);
}
