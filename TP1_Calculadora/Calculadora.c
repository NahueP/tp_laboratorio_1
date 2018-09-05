#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

/** \brief
 *
 * \param recibe el primer operando(numeroA)
 * \param recibe segundo operando(numeroB)
 * \return resultado de la sumatoria
 *
 */

float Sumar(float numeroA,float numeroB)
{
  float  resultado;

  resultado = numeroA + numeroB;

  return resultado;
}

/** \brief
 *
 * \param recibe el primer operando(numeroA)
 * \param recibe segundo operando(numeroB)
 * \return resultado de la resta
 *
 */


float Restar(float numeroA, float numeroB)
{
  float  resultado;

  resultado = numeroA - numeroB;

  return resultado;
}

/** \brief
 *
 * \param recibe el primer operando(numeroA)
 * \param recibe segundo operando(numeroB)
 * \return resultado de la division
 *
 */

float  Dividir(float  numeroA, float  numeroB)
{
    float  resultado;

    resultado = numeroA/numeroB;

    return resultado;

}

/** \brief
 *
 * \param recibe el primer operando(numeroA)
 * \param recibe segundo operando(numeroB)
 * \return resultado de la multiplicacion
 *
 */

float  Multiplicar(float  numeroA, float  numeroB)
{
    float  resultado;

    resultado = numeroA * numeroB;

    return resultado;
}

/** \brief
 *
 * \param recibe un numero
 * \return valor del numero factorizado
 *
 */


float Factorial(float numero)
{
    int i;
    int resultado = 1;

    for(i=numero; i>0; i--)
    {
        resultado*=i;
    }

   return resultado;

}



