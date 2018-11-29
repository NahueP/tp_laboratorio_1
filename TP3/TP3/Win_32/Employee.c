#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee));

    if(this==NULL)
    {
        printf("No hay espacio para crear un nuevo empleado.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int auxHorasTrabajadas;
    int auxId;
    float auxSueldo;
    int flag = 1;
    Employee* this = employee_new();

    auxId = atoi(idStr);
    if(employee_setId(this,auxId)!= 1)
    {
        flag=0;
    }

    auxHorasTrabajadas = atoi(horasTrabajadasStr);
    if(employee_setHorasTrabajadas(this,auxHorasTrabajadas)!= 1)
    {
        flag=0;
    }

    if(employee_setNombre(this,nombreStr)!= 1)
    {
        flag=0;
    }

    auxSueldo = atof(sueldoStr);
    if(employee_setSueldo(this, auxSueldo)!=1)
    {
        flag=0;
    }
    if(flag == 0)
    {
        printf("\nError al cargar datos, revise la lista.\n");
    }

    return this;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id > 0)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno=1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=0;
    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        retorno=1;
    }
    return retorno;
}


void employee_printData(Employee* this)
{
    int id;
    char nombre[51];
    int horasTrabajadas;
    float sueldo;
    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getHorasTrabajadas(this, &horasTrabajadas);
    employee_getSueldo(this, &sueldo);
    printf("   %5d | %12s |          %4d  |    $ %.2f\n", id, nombre, horasTrabajadas, sueldo);
}

int employee_ControlId(LinkedList* pArrayListEmployee, char* idStr)
{
    int retorno = 0;
    int id;
    int i;
    id = atoi(idStr);
    Employee* this;
    if(pArrayListEmployee != NULL)
    {
        for( i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            if(this->id == id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int employee_SortById(void* employeeA, void* employeeB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    if(employeeA !=NULL && employeeB !=NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if((empA->id) < (empB->id))
        {
            retorno = 1 ;
        }
        else if((empA->id) == (empB->id))
        {
            retorno = 0;
        }
        else if((empA->id) > (empB->id))
        {
            retorno = -1 ;
        }

    }
    return retorno;
}

int employee_SortByName(void* employeeA, void* employeeB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    if(employeeA !=NULL && employeeB !=NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        retorno = strcmp(empB->nombre, empA->nombre);
    }
    return retorno;
}

int employee_SortByHoursWorked(void* employeeA, void* employeeB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    if(employeeA !=NULL && employeeB !=NULL)
        {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if((empA->horasTrabajadas) < (empB->horasTrabajadas))
        {
            retorno = 1 ;
        }
        else if((empA->horasTrabajadas)==(empB->horasTrabajadas))
        {
            retorno = 0;
        }
        else if((empA->horasTrabajadas)>(empB->horasTrabajadas))
        {
            retorno = -1 ;
        }
    }
    return retorno;
}

int employee_SortBySalary(void* employeeA, void* employeeB)
{
    int retorno = 0;
    Employee* empA;
    Employee* empB;
    if(employeeA !=NULL && employeeB !=NULL)
    {
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if((empA->sueldo) < (empB->sueldo))
        {
            retorno = 1 ;
        }
        else if((empA->sueldo) == (empB->sueldo))
        {
            retorno = 0;
        }
        else if((empA->sueldo)>(empB->sueldo))
        {
            retorno = -1 ;
        }
    }
    return retorno;
}




