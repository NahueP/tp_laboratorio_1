#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
   int seguir = 's';
    int controllerFromText = 0;
    int controllerFromBinary = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int opcion;


    do
    {
        system("cls");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10. Limpiar la lista de empleados.\n");
        printf("11. Salir\n");

        opcion = getValidInt("Ingrese opcion: ", "Ingrese nuevamente:\n");


        switch(opcion)
        {
        case 1:
            if(controllerFromText == 0 && controllerFromBinary == 0){
                controller_loadFromText("data.csv", listaEmpleados);
                controllerFromText = 1;
            }
            else{
                if(controllerFromText == 1){
                    printf("\nLa lista en modo texto ya ha sido cargada\n");
                }
                if(controllerFromBinary == 1){
                    printf("\nLa lista en modo binario ya ha sido cargada\n");
                }
            }
            system("pause");
            break;
        case 2:
            if(controllerFromText == 0 && controllerFromBinary == 0){
                controller_loadFromBinary("data.bin", listaEmpleados);
                controllerFromBinary = 1;
            }
            else{
                if(controllerFromBinary == 1){
                    printf("\nLa lista en modo texto ya ha sido cargada\n\n");
                }
                if(controllerFromText == 1){
                    printf("\nLa lista en modo binario ya ha sido cargada\n");
                }
            }
            system("pause");
            break;
        case 3:
            if(controllerFromText || controllerFromBinary){
                controller_addEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 4:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_editEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 5:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_removeEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 6:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_ListEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 7:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                controller_sortEmployee(listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 8:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                  controller_saveAsText("data.csv",listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 9:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                  controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else{
                printf("\nNo se han cargado empleados\n");
            }
            system("pause");
            break;
        case 10:
                ll_clear(listaEmpleados);
                printf("\nSe limpio la lista de empleados\n\n");
            system("pause");
            break;
        case 11:
            if(controllerFromText == 1 || controllerFromBinary == 1){
                  controller_freeLinkedList(listaEmpleados);
            }
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta");
            system("pause");
            system("cls");
        }
    }

    while(seguir == 's');

    return 0;
}
