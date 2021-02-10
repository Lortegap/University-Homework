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
void copiarPersona (TPersona &personaAModificar,TPersona &personaACopiar)
{
	personaAModificar.nombre = personaACopiar.nombre;
	personaAModificar.edad = personaACopiar.edad;
	personaAModificar.DNI = personaACopiar.DNI;
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
		copiarPersona(arbolAModificar->persona,personaAInsertar);
		return;
	}
	arbol *copia = arbolAModificar; 
	// recorrido
	while (arbolAModificar != NULL)
	{
		if (arbolAModificar->persona.DNI > personaAInsertar.DNI)
		{
			arbolAModificar = arbolAModificar->ramaIzq;
			if (arbolAModificar == NULL)
			{
				arbolAModificar = new arbol;
				break;
			}
		}
		else
		{
			arbolAModificar = arbolAModificar->ramaDer;
			if (arbolAModificar == NULL)
			{
				arbolAModificar = new arbol;
				break;
			}
		}
	}
	copiarPersona(arbolAModificar->persona,personaAInsertar);
	arbolAModificar = copia;
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

int main ()
{
	
}
