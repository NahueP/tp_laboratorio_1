#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
  int id;
  char name[51];
  char lastName[51];
  float salary;
  int sector;
  int isEmpty;
}Employee;


int initEmployees(Employee[], int);

int addEmployees(Employee [], int , int , char [] ,char [] ,float ,int);

int findEmployeeById(Employee[], int, int);

int removeEmployee(Employee[], int, int);

int sortEmployees(Employee[], int, int);

int printEmployees(Employee[], int);

int ModEmployees(Employee[], int, int);

int getEmptyIndex(Employee[], int);


#endif // FUNCIONES_H_INCLUDED
