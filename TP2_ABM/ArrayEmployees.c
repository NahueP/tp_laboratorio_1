#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"


/**
 * Inicializa el array de empleados en 1(vacios)
 * \param Recibe array de empleados
 * \param Tamaño del array
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int initEmployees(Employee employees[], int len)
{
  int retorno = -1;
  int i;

  for(i=0;i<len;i++)
  {
     employees[i].isEmpty = 1;
     retorno = 0;
  }

  return retorno;
}

/**
 * Obtiene el primer indice libre del array
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int getEmptyIndex(Employee employees[], int len)
{
    int i;
    int retorno = -1;

    for(i=0;i<len;i++)
    {
       if(employees[i].isEmpty==1)
       {
            retorno = i;
            break;
       }
    }

    return retorno;
}

/**
 * Obtiene el indice de un empleado por ID
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int findEmployeeById(Employee employees[], int len, int id)
{
    int i;
    int retorno = -1;

    for(i=0;i<len;i++)
    {
       if(id == employees[i].id)
       {
            retorno = i;
            break;
       }
    }

    return retorno;

}

/**
 * Agrega en el array de empleados los valores recibidos por parametros en una posicion libre
 * \param Array de empleados
 * \param Tamaño del array
 * \param datos del empleado(id, nombre, apellido, salario, sector)
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int addEmployees(Employee employees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
   int retorno = -1;

   int index;

   index = getEmptyIndex(employees, len);

   if(index != -1)
   {

    employees[index].id = id;
    strcpy(employees[index].name, name);
    strcpy(employees[index].lastName, lastName);
    employees[index].salary = salary;
    employees[index].sector = sector;



    employees[index].isEmpty = 0;
    retorno = 0;

    }

    return retorno;
}

/**
 * Pide la id del empleado y borra (baja logica) el indice donde se encuentra
 * \param Array de empleados
 * \param Tamaño del array
 * \param ID del empleado
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */


int removeEmployee(Employee employees[], int len, int id)
{
   int retorno = -1;
   int flag = 0;
   char rta=' ';
   int index;

   index = findEmployeeById(employees, len, id);

     if(index != -1)
     {
        printf("%d", employees[index].id);
        flag = 1;
        do
        {
            printf("\neliminar registro? s/n");
            fflush(stdin);
            rta = getch();
            rta= toupper(rta);
        }while(rta != 'N' && rta != 'S');

        if(rta=='S')
        {
        employees[index].isEmpty=1;

        printf("\nEl registro fue eliminado\n");
        }
        else
        {
        printf("\nEl registro no se elimino\n");
        }

        retorno = 0;
     }

   if(flag==0)
     {
       printf("DATO INEXISTENTE\n");

     }

     return retorno;
}

/**
 * Pide la id del empleado y habilita la modificacion de sus datos
 * \param Array de empleados
 * \param Tamaño del array
 * \param ID del empleado
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int ModEmployees(Employee employees[], int len, int id)
{
   int retorno = -1;
   int flag = 0;
   char rta=' ';
   int index;
   int opcion=0;


   index = findEmployeeById(employees, len, id);

     if(index != -1)
     {
        printf("%d", employees[index].id);
        flag = 1;
        do
        {
            printf("\nModificar registro? s/n\n");
            fflush(stdin);
            rta = getch();
            rta= toupper(rta);
        }while(rta != 'N' && rta != 'S');

        if(rta=='S')
        {
            do
            {
              printf("1. Modificar Nombre\n");
              printf("2. Modificar Apellido\n");
              printf("3. Modificar Salario\n");
              printf("4. Modificar Sector\n");
              printf("5. Volver al menu principal\n");

              scanf("%d", &opcion);

              system("cls");

              switch(opcion)
              {

                case 1:
                 printf("Ingrese el Nombre: ");
                 scanf("%s", employees[index].name);
                break;

                case 2:
                 printf("Ingrese el Apellido: ");
                 scanf("%s", employees[index].lastName);
                break;

                 case 3:
                 printf("Ingrese el Salario: ");
                 scanf("%f", &employees[index].salary);

                break;

                 case 4:
                 printf("Ingrese el Sector: ");
                 scanf("%d", &employees[index].sector);
                    break;

              }

            }while(opcion != 5);

        }
        else
        {
        printf("\nEl registro no se modifico\n");

        }

        retorno = 0;
     }


   if(flag==0)
     {
       printf("DATO INEXISTENTE\n");
     }

    return retorno;
}


/**
 * Ordenamiento Ascedente y Descendente por Apellido y Sector
 * \param Array de empleados
 * \param Tamaño del array
 * \param Recibe el tipo de ordenamiento
 * \return 0 si esta todo OK, -1 si hay un fallo
 *
 */

int sortEmployees(Employee employees[], int len, int order)
{
    int retorno = -1;
    char aux[51];
    int i, j, aux2;

    if(order == 1)
    {

    for(i=0;i<len-1;i++)
    {
      for(j=i+1;j<len;j++)
      {
        if(strcmp(employees[i].lastName,employees[j].lastName)>0);
        {
            strcpy(aux, employees[i].lastName);
            strcpy(employees[i].lastName,employees[j].lastName);
            strcpy(employees[j].lastName, aux);

        }


        if(employees[i].sector<employees[j].sector)
        {
            aux2 = employees[i].sector;
            employees[i].sector = employees[j].sector;
            employees[j].sector = aux2;
        }
      }

    }
     retorno = 0;
    }

    if(order == 0)
    {
    for(i=0;i<len-1;i++)
    {
      for(j=i+1;j<len;j++)
      {
        if(strcmp(employees[i].lastName,employees[j].lastName)<0);
        {
            strcpy(aux, employees[i].lastName);
            strcpy(employees[i].lastName,employees[j].lastName);
            strcpy(employees[j].lastName, aux);

        }


        if(employees[i].sector>employees[j].sector)
        {
            aux2 = employees[i].sector;
            employees[i].sector = employees[j].sector;
            employees[j].sector = aux2;
        }
      }

    }

     retorno = 0;
    }

    return retorno;


}

/**
 * Lista todos los datos de array de empleados
 * \param Array de empleados
 * \param Tamaño del array
 * \return int
 *
 */

int printEmployees(Employee employees[], int len)
{
   int i;

   for(i=0;i<len;i++)
   {
       if(employees[i].isEmpty == 0)
       {
         printf("%d\t%s\t%s\t%.2f\t%d", employees[i].id, employees[i].name, employees[i].lastName, employees[i].salary, employees[i].sector);
         printf("\n");


       }

   }

   return 0;

}

