#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pfile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    pFile = fopen("data.csv","r");
    Employee* this;
    int r;
    char auxId[50], auxNombre[50], auxHorasTrabajadas[50], auxSueldo[50];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

    do
    {
        r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

        if(r==4)
        {
            this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, this);
        }
        else
        {
            if(r != 4 && this != NULL)
            {
                if(!feof(pFile))
                {
                    printf("\nError al leer el ultimo dato.");
                    break;
                }
                else
                {
                    printf("\nSe leyo todo el archivo.");
                }
            }
        }

    }while(!feof(pFile));

    printf("\nLos empleados fueron cargados correctamente\n");
    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pfile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* this;
    int r;

    do
    {
        this = employee_new();
        r = fread(this, sizeof(Employee), 1, pFile);

        if(r == 1 && this != NULL)
        {
            ll_add(pArrayListEmployee, this);
        }
        else
        {
            if(r != 1)
            {
                if(!feof(pFile))
                {
                    printf("\nError al leer el ultimo dato.");
                    break;
                }
                else
                {
                    printf("\nLos empleados fueron cargados correctamente\n");
                }
            }
        }
    }while(!feof(pFile));


    fclose(pFile);

    return 1;

}
