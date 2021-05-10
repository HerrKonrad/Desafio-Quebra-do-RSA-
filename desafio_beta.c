#include <stdio.h>
#include <stdlib.h>


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

long buscarMaiorDivisor(long num, long menor_div)
{
    return  menor_div == 1 ? num : num / menor_div;
}

long buscarMenorDivisor(long num)
{
    size_t i;
    long resultado = 0;
    num = num < 0 ? -num : num;
    long numSQRT = sqrt(num);

   // num = ( num < 0 ) ? - num : num;

    if(num % 2 != 0)
    {
        for( i = 3 ; i <= numSQRT ; i += 2)
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


size_t pedirQuantidadeNumeros()
{
    size_t qtd = 0;
    long temp = 0;
    puts("# Quantos numeros deseja inserir: ");
    scanf("%ld", &temp);
    if( temp <= 0)
    {
        // O numero de quantidade não pode ser menor igual a zero, o programa vai ficar pedindo até vir um válido
        temp = pedirQuantidadeNumeros();
    }
    qtd = temp;

    return qtd;
}

long pedirNumero()
{
    long temp = 0;

    puts("# Qual o valor da chave n? ");
    scanf("%li", &temp);

    return temp;
}

int main()
{
    size_t quantidade = pedirQuantidadeNumeros();
    long valores[quantidade];
    size_t i;
    long maior_div, menor_div;
    int sucesso = 0;
    long maior_num = 0;
    long menor_num = 0;
    long numero = 0;
    long numero_original = 0;

    for( i = 0 ; i < quantidade ; i++)
    {

        numero = pedirNumero();
        if(numero != 0 )
        {

            menor_div = buscarMenorDivisor(numero);
            maior_div =  buscarMaiorDivisor(numero, menor_div);

            printf("%li = %li * %li \n", numero, menor_div, maior_div);


            sucesso += verificarSucesso(numero, menor_div, maior_div);

            if (numero > maior_num)
            {
                maior_num = numero;
            }
            if (menor_num == 0)
            {
                menor_num = numero;
            }
            else if(numero < menor_num)
            {
                menor_num = numero;
            }
        }
    }

    printf("%d %d %li %li", quantidade, sucesso, menor_num, maior_num);
}
