#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define len 3 //1000 (esta en 3 para hacer un test rapido)


int main()
{
    int opcion=0;
    char seguir='s';
    Employee employees[len];

    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int id = 0;
    int auxId=0;
    int index;
    int orden;

   initEmployees(employees, len);

   do
   {


    printf("1.Altas\n");
    printf("2.Baja\n");
    printf("3.Modificar\n");
    printf("4.Listar\n");
    printf("5.Salir\n");

    scanf("%d", &opcion);

    system("cls");

    switch(opcion)
    {
      case 1:
      index = getEmptyIndex(employees, len);

      if(index!= -1)
      {
      printf("Ingrese el Nombre: ");
      scanf("%s", nombre);

      printf("Ingrese el Apellido: ");
      scanf("%s", apellido);

      printf("Ingrese el Salario: ");
      scanf("%f", &salario);

      printf("Ingrese el Sector: ");
      scanf("%d", &sector);

      id++;
      }

      addEmployees(employees, len, id,nombre,apellido,salario,sector);

      break;

      case 2:
      printf("Ingrese el ID del empleado a borrar: ");
      scanf("%d", &auxId);
      removeEmployee(employees, len, auxId);
      break;
      case 3:
      printf("Ingrese el ID del empleado a modificar: ");
      scanf("%d", &auxId);
      ModEmployees(employees, len, auxId);
      break;
      case 4:
      printf("0 - Listar Ascendente / 1 - Listar Descendente\n");
      scanf("%d", &orden);
      sortEmployees(employees, len, orden);
      printEmployees(employees, len);
      break;
      case 5:
      seguir='n';
      break;

      default:
      printf("Opcion Incorrecta");
      break;
    }




   }while(seguir=='s');



    return 0;
}
