#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if((pFile = fopen(path, "r")) != NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        if((pFile = fopen(path, "w")) != NULL)
        {
            printf("\n No se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
        }
    }
    return retorno;


}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    if((pFile = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        if((pFile = fopen(path, "wb")) != NULL)
        {
            printf("\nNo se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
        }
    }

    return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[128], auxNombre[128], auxHorasTrabajadas[128], auxSueldo[128];
    Employee* this = employee_new();

    system("cls");
    printf(" ALTA EMPLEADOS\n");
    getStringNumeros("Ingrese ID: ", auxId);

    while(employee_ControlId(pArrayListEmployee, auxId)==1)
    {
        printf("El ID ingresado ya existe\n");
        getStringNumeros("Ingrese el ID nuevamente: ", auxId);
    }
    getValidStringRango("Ingrese nombre: ", "ERROR, Ingrese el nombre nuevamente: ", auxNombre, 128);

    getStringNumeros("Ingrese horas trabajadas: ", auxHorasTrabajadas);

    getStringNumerosFlotantes("Ingrese sueldo: ", auxSueldo);

    this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    ll_add(pArrayListEmployee, this);

    printf("\n      ID |      Nombre  | Hs. Trabajadas |     Sueldo\n");
    employee_printData(this);

    printf("n\El empleado fue cargado con exito.\n");


    return 1;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int flag = 0;
    char confirmacion;
    int idEmpleado;
    int opcion;
    char auxNombre[51];
    int auxHorasTrabajadas;
    float auxSueldo;
    int id;
    char nombre[51];
    int horasTrabajadas;
    float sueldo;

    int i;
    Employee* this;

    system("cls");
    printf("MODIFICAR EMPLEADO\n\n");
    idEmpleado = getValidInt("Ingrese ID: ", "ERROR, ingrese el id nuevamente:");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        employee_getId(this, &id);
        employee_getNombre(this, nombre);
        employee_getHorasTrabajadas(this, &horasTrabajadas);
        employee_getSueldo(this, &sueldo);
        printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        printf("   %4d | %12s |          %4d  | $ %.2f\n", id, nombre, horasTrabajadas, sueldo);
        printf("\nMenu de opciones\n1- Modificar nombre.\n2- Modificar horas trabajadas.\n3- Modificar sueldo.\n4- Salir.\n");
        opcion = getValidIntRango("Ingrese opcion: ", "ERROR, Ingrese la opcion nuevamente: ", 1, 4);
        switch(opcion)
        {
        case 1:
            printf("\nModificar nombre\n");
            getValidStringRango("Ingrese nuevo nombre: ", "ERROR, solo se admiten letras\n", auxNombre, 51);
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nIngrese nuevamente: \n", 's', 'n');
            if(confirmacion == 's')
            {
                employee_setNombre(this, auxNombre);
                printf("Se modifico el nombre con exito.\n");
                printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n");
                employee_printData(this);
                retorno = 1;
            }
            else
            {
                printf("Se cancelo la modificacion\n");
            }
            break;
        case 2:
            printf("\nModificar horas trabajadas \n");
            auxHorasTrabajadas = getValidIntRango("Ingrese las horas trabajadas: ", "Error, solo se admiten numeros.\n", 0, 500);
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nError de ingreso. Reintente.\n", 's', 'n');
            if(confirmacion == 's')
            {
                employee_setHorasTrabajadas(this, auxHorasTrabajadas);
                printf("Se modificaron las horas trabajadas con exito.\n");
                printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
                employee_printData(this);
                retorno = 1;
            }
            else
            {
                printf("Se cancelo la modificacion\n");
            }
            break;
        case 3:
            printf("\nModificar sueldo -->\n\n");
            auxSueldo = getValidFloat("Ingrese nuevo sueldo: ", "Error, solo se admiten numeros.\n");
            fflush(stdin);
            confirmacion = getValidChar("Confirma la modificacion (s/n)?: ", "\nError de ingreso. Reintente.\n", 's', 'n');
            if(confirmacion == 's')
            {
                employee_setSueldo(this, auxSueldo);
                printf("Se modifico el sueldo con exito.\n\n");
                printf("\n     ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
                employee_printData(this);
                retorno = 1;
            }
            else
            {
                printf("Se cancelo la modificacion\n");
            }
            break;
        case 4:
            break;
        default:
            printf("\nopcion incorrecta.\n\n");
        }
    }
    else
    {
        printf("\nEmpleado Inexistente.\n\n");
    }
    return retorno;


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = 0;
    int flag = 0;
    int index;
    char confirmacion;
    Employee* this;
    int idEmpleado;
    int i;
    system("cls");
    printf("BAJA DE EMPLEADO\n\n");
    idEmpleado = getValidInt("Ingrese ID: ", "ERROR, Ingrese nuevamente:");
    for( i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if(flag == 1)
    {
        printf("\n      ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
        employee_printData(this);
        confirmacion = getValidChar("\nDesea eliminar al empleado (s/n)?: ", "\nERROR, Ingrese nuevamente:", 's', 'n');
        if(confirmacion == 's')
        {
            ll_remove(pArrayListEmployee, index);
            printf("\nEmpleado dado de baja con exito.\n\n");
            retorno = 1;
        }
        else
        {
            printf("\nBaja cancelada\n");
        }
    }
    else
    {
        printf("\nNo existe empleado con el ID ingresado.\n");
    }
    return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* this;
    int i;
    system("cls");
    printf("LISTA DE EMPLEADOS\n\n");
    printf("      ID |      Nombre  | Hs. Trabajadas |     Sueldo\n\n");
    for( i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        employee_printData(this);

        retorno = 1;
    }

    printf("\n");

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int opcion;
    int ordenLista;

    printf(" Menu de opciones:\n");
    printf(" 1. Ordenar por ID.\n");
    printf(" 2. Ordenar por nombre.\n");
    printf(" 3. Ordenar por horas trabajadas.\n");
    printf(" 4. Ordenar por salario.\n");
    printf(" 5. Salir.\n");
    opcion = getValidInt(" Ingrese opcion: ", "Ingrese nuevamente:\n");

    switch(opcion){
    case 1:
        system("cls");
        printf("\n Ordenamiento por ID\n");
        ordenLista = getValidIntOpcion("\n Ingrese 0 para ascendente y 1 para ordenar de forma descendente: ", "\nIngrese nuevamente:\n", 0, 1);
        ll_sort(pArrayListEmployee, employee_SortById, ordenLista);
        printf("\nSe ordeno la lista por ID correctamente.\n\n");
        break;
    case 2:
        system("cls");
        printf("\n Ordenamiento por nombre\n");
        ordenLista = getValidIntOpcion("\n Ingrese 0 para ascendente y 1 para ordenar de forma descendente: ", "\nIngrese nuevamente:\n", 0, 1);
        ll_sort(pArrayListEmployee, employee_SortByName, ordenLista);
        printf("\nSe ordeno la lista por nombre correctamente.\n\n");
        break;
    case 3:
        system("cls");
        printf("\n Ordenamiento por horas trabajadas\n");
        ordenLista = getValidIntOpcion("\n Ingrese 0 para ascendente y 1 para ordenar de forma descendente: ", "\nIngrese nuevamente:\n", 0, 1);
        ll_sort(pArrayListEmployee, employee_SortByHoursWorked, ordenLista);
        printf("\n Se ordeno la lista por horas trabajadas correctamente.\n\n");
        break;
    case 4:
        system("cls");
        printf("\n Ordenamiento por salario\n");
        ordenLista = getValidIntOpcion("\n Ingrese 0 para ascendente y 1 para ordenar de forma descendente: ", "\nIngrese nuevamente:\n", 0, 1);
        ll_sort(pArrayListEmployee, employee_SortBySalary, ordenLista);
        printf("\nSe ordeno la lista por salario correctamente.\n");
        break;
    case 5:
        break;
    default:
        printf("\nIngreso una opcion incorrecta.\n\n");
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* this;
    int retorno = -1;
    int i;

    char nombre[51];
    int id;
    int horasTrabajadas;
    float sueldo;
    //<---
    pFile = fopen(path, "w");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        rewind(pFile);
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
        for( i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this,&id);
            employee_getNombre(this, nombre);
            employee_getHorasTrabajadas(this, &horasTrabajadas);
            employee_getSueldo(this, &sueldo);
            fprintf(pFile, "%d,%s,%d,%f\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("\nDatos guardados correctamente\n");
        retorno = 0;
    }
    fclose(pFile);

    return retorno;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* this;
    int retorno = -1;
    int i;
    int datosLeidos;
    pFile = fopen(path, "wb");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        rewind(pFile);
        for( i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i);
            datosLeidos = fwrite(this, sizeof(Employee), 1, pFile);
            retorno = 0;
            if(datosLeidos != 1)
            {
                printf("\nError al escribir los datos en el archivo.\n");
            }
        }
        printf("\n Datos guardados correctamente\n");
    }
    else
    {
        printf("\nNo se pudo acceder al archivo.\n");
    }
    fclose(pFile);
    return retorno;

    return 1;
}

int controller_freeLinkedList(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            ll_remove(pArrayListEmployee, i);
        }
        ll_deleteLinkedList(pArrayListEmployee);
        retorno = 0;
    }
    printf("\nLa lista de empleados ha sido eliminada\n");
    return retorno;
}
