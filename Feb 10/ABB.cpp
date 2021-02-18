#include <iostream>
#include <string>
#include <stdio.h>
typedef struct TPersona
{
	std::string nombre = "";
	float DNI = 0;
	float edad = 0;
	int nivel = 0;
};

bool isFloat (float valor)
{
	if (valor != int(valor))
	{
		return 1;
	}
	return 0;
}

void leerPersona (TPersona &persona)
{
	std::cout << "Ingrese el nombre de la persona: ";
	std::cin >> persona.nombre;
	do
	{
		std::cout << "Ingrese la edad de la persona: ";
		std::cin >> persona.edad;
	} while (isFloat(persona.edad));
	do
	{
		std::cout << "Ingrese el DNI de la persona: ";
		std::cin >> persona.DNI;
	} while (isFloat(persona.DNI));
}

typedef struct arbol 
{
	TPersona persona;
	arbol *ramaDer = NULL;
	arbol *ramaIzq = NULL;
};

void agregarElemento (arbol *&arbolAModificar,TPersona personaAInsertar)
{
	if (!arbolAModificar->ramaDer && !arbolAModificar->ramaIzq) // empezamos desde ramaDer
	{
		arbolAModificar->ramaDer = new arbol;
		arbolAModificar = arbolAModificar->ramaDer;
		arbolAModificar->persona = personaAInsertar;
		return;
	}
	arbol *copia = arbolAModificar; 
	// recorrido
	while (copia != NULL)
	{
		if (copia->persona.DNI > personaAInsertar.DNI)
		{
			copia = copia->ramaIzq;
			if (copia == NULL) // significa que está vacío
			{
				copia = new arbol; // creamos un nuevo puntero
				break; // salimos
			}
		}
		else
		{
			copia = copia->ramaDer;
			if (copia == NULL) // significa que está vacío
			{
				copia = new arbol; // creamos un nuevo puntero
				break; // salimos
			}
		}
	}
	copia->persona = personaAInsertar;
}

arbol* buscarRama(arbol *&arbolAExaminar,TPersona personaABuscar)
{
	arbol *copia = arbolAExaminar;
	if (copia == NULL)
	{
		return NULL;
	}
	while (copia)
	{
		if (copia->persona.DNI == personaABuscar.DNI)
		{
			return copia;
		}
		
		if (copia->persona.DNI > personaABuscar.DNI)
		{
			copia = copia->ramaIzq;
		}
		else
		{
			copia = copia->ramaDer;
		}
	}
	return NULL;
}

arbol* eliminarRama(arbol *&arbolAModificar)
{
	arbol *copia = arbolAModificar;
	float DNIAEliminar = 0;
	int ramaDir = 0;
	arbol *aEliminar; // a este puntero le hago delete
	arbol *acomodador; // este puntero me facilita la acomodación de los elementos que están en el nodo que voy a usar para reemplazar
	do
	{
		std::cout << "Ingrese el DNI que va a Eliminar: ";
		std::cin >> DNIAEliminar;
	} while (isFloat(DNIAEliminar));
	while (copia)
	{
		if (copia->ramaIzq->persona.DNI == DNIAEliminar || copia->ramaDer->persona.DNI == DNIAEliminar)
		{
			if (copia->ramaIzq->persona.DNI == DNIAEliminar)
			{
				ramaDir = 1;
			}
			else
			{
				ramaDir = 2;
			}
			break;
		}
		else
		{
			if (copia->persona.DNI > DNIAEliminar)
			{
				copia = copia->ramaIzq;
			}
			else
			{
				copia = copia->ramaDer;
			}
		}
	}
	switch (ramaDir)
	{
	case 1: // izq
		aEliminar = copia->ramaIzq;
		break;
	
	case 2: // der
		aEliminar = copia->ramaDer;
		break;
	}
	if (!aEliminar->ramaDer && !aEliminar->ramaIzq)
	{
		copia = aEliminar;
		copia = NULL;
		return aEliminar;
	}
	else
	{
		if (aEliminar->ramaDer)
		{
			acomodador = aEliminar->ramaDer;
			if (acomodador->ramaIzq)
			{
				if (acomodador->ramaDer)
				{
					acomodador->ramaDer->ramaIzq = acomodador->ramaIzq;
				}
				if (aEliminar->ramaIzq)
				{
					acomodador->ramaIzq = aEliminar->ramaIzq;
				}
			}
		}
		else
		{
			acomodador = aEliminar->ramaIzq;
			/*
			if (acomodador->ramaIzq)
			{
				if (acomodador->ramaDer)
				{
					acomodador->ramaDer->ramaIzq = acomodador->ramaIzq;
				}
			}*/
		}
	}
	switch (ramaDir)
	{
	case 1: // izq
		copia->ramaIzq = acomodador;
		break;
	case 2: // der
		copia->ramaDer = acomodador;
		break;
	}
	return aEliminar;
}
int main ()
{
	float anadirElemento = 0;
	arbol *arbolAUsar;
	do
	{
		std::cout << "¿Deseas añadir un elemento?\n1. Sí 2. No\nElección: ";
		std::cin >> anadirElemento;
	} while (anadirElemento != 2);

	float buscarElemento = 0;
	do
	{
		std::cout << "Ingrese el DNI que desea buscar. Ingrese 0 para salir.";
	} while (buscarElemento != 0);
	
	float eliminarElemento = 0;
	do
	{
		std::cout << "Ingrese el DNI que desea eliminar. Ingrese 0 para salir.";
	} while (eliminarElemento != 0);
	
}
