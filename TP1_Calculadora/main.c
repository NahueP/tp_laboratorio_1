#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#define ESC 27

int main()
{

    char seguir ='-';
    int opcion;
    float numA=0; //primer operando
    float numB=0; //segundo operando
    char opcion3;

/**< MENU CON OPCIONES */

    do
    {

        printf("::Calculadora::\n");

        printf("1.Ingresar el 1er operando(A=%.2f)\n", numA);
        printf("2.Ingresar el 2do operando(B=%.2f)\n", numB);
        printf("3.Calcular todas las operaciones\n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");

        printf("opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
            printf("Ingrese un numero: ");
            scanf("%f", &numA);
            break;

            case 2:
            printf("Ingrese un numero: ");
            scanf("%f", &numB);
            break;

            case 3:
            printf("Eliga una opcion: \n");
            printf("a.Calcular la suma (A+B)\n");
            printf("b.Calcular la resta (A-B)\n");
            printf("c.Calcular la division (A/B)\n");
            printf("d.Calcular la multiplicacion (A*B)\n");
            printf("e.Calcular el factorial (A!)\n");

            printf("opcion: ");
            fflush(stdin);
            scanf("%c", &opcion3);

            printf("\n");

            /**Al elegir la opcion 3 se abre un sub-menu con mas opciones */
            switch(opcion3) //LLAMA A LA FUNCION ELEGIDA Y LA MUESTRA POR PANTALLA
            {
               case 'a':
               printf("%.2f + %.2f: %.2f\n",numA, numB, Sumar(numA,numB));
               system("pause>NULL");
               break;

               case 'b':
               printf("%.2f - %.2f: %.2f\n",numA, numB, Restar(numA,numB));
               system("pause>NULL");
               break;

               case 'c':
               printf("%.2f / %.2f: %.2f\n",numA, numB, Dividir(numA,numB));
               system("pause>NULL");
               break;

               case 'd':
               printf("%.2f * %.2f: %.2f\n",numA, numB, Multiplicar(numA,numB));
               system("pause>NULL");
               break;

               case 'e':
               printf("%.0f!: %.0f\n", numA, Factorial(numA));
               printf("%.0f!: %.0f\n", numB, Factorial(numB));
               system("pause>NULL");
               break;

               default:
               printf("opcion incorrecta: presione una tecla para continuar");
               system("pause>NULL");
               system("cls");
               break;

            }


            break;

            case 4: //LLAMA A TODAS LAS FUNCIONES, SE EJECUTAN, Y MUESTRAN EL RESULTADO POR PANTALLA
            printf("Resultado de la Suma: %.2f\n", Sumar(numA,numB));
            printf("Resultado de la Resta: %.2f\n", Restar(numA, numB));
            if(numB == 0)
            {
              printf("Resultado de la Division: No se puede dividir por 0\n");
            }
            else
            {
              printf("Resultado de la Division: %.2f\n", Dividir(numA, numB));
            }
            printf("Resultado de la Multiplicacion: %.2f\n", Multiplicar(numA, numB));
            printf("Resultado del Factorial de %.0f: %.0f\n", numA, Factorial(numA));
            printf("Resultado del Factorial de %.0f: %.0f\n", numB, Factorial(numB));


            break;

            case 5:
            seguir = ESC;
            break;

            default:
            printf("opcion incorrecta: presione una tecla para continuar");
            system("pause>NULL");
            system("cls");

            break;


        }



    }while(seguir != ESC);

    return 0;
}
