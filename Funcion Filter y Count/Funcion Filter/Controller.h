#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* pArrayListCliente);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_showCliente(LinkedList* pArrayListCliente, int sizeList);

#endif
