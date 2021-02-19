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
	arbol *anterior = NULL;
	
};

int contarAltura (arbol *&arbolAExaminar)// usese con un brazo, ya sea el derecho o el izquierdo
{
	arbol *copia = arbolAExaminar;
	int contador = 0;
	while (copia != NULL)
	{
		if (!copia->ramaDer && !copia->ramaIzq)
		{
			return contador;
		}
		else 
		{
			if (copia->ramaIzq)
			{
				copia = copia->ramaIzq;
				contador++;
				break;
			}
			if (copia->ramaDer)
			{
				copia = copia->ramaDer;
				contador++;
				break;
			}
		}
	}
	return contador;
}

void agregarElemento (arbol *&arbolAModificar)
{
	TPersona personaAInsertar;
	leerPersona(personaAInsertar);
	if (!arbolAModificar->ramaDer && !arbolAModificar->ramaIzq) // vacio
	{
		arbolAModificar = new arbol;
		arbolAModificar->persona = personaAInsertar;
		return;
	}
	// añadir
	arbol *copia = arbolAModificar;
	arbol *extra = NULL;
	int alturaDer = contarAltura(copia->ramaDer);
	int alturaIzq = contarAltura(copia->ramaIzq);
	int izq = 0;
	int der = 0;
	while (copia)
	{
		if (copia->persona.DNI == personaAInsertar.DNI)
		{
			std::cout << "No se puede agregar a una persona con el mismo número de DNI. Saliendo...\n";
			return;
		}
		else
		{
			if (copia->persona.DNI > personaAInsertar.DNI) 
			{
				
				if (!copia->ramaIzq)
				{
					alturaIzq = contarAltura(copia->ramaIzq);
					copia->ramaIzq = new arbol;
					if (alturaDer - alturaIzq + 1 < 2)
					{
						if (der && izq)
						{
							copia->ramaIzq->persona = personaAInsertar;
							copia->ramaIzq->ramaDer = copia;
							copia->ramaIzq->ramaIzq = extra;
							extra = copia->ramaIzq;
							break;
						}
						else
						{
							copia->ramaDer = extra;
							copia->ramaIzq->persona = personaAInsertar;
							extra->ramaIzq = NULL;
							extra = copia;
							break;
						}
					}
				}
				extra = copia;
				copia = copia->ramaIzq;
				if (izq != 1)
				{
					izq = 1;
				}
				else
				{
					izq = 0;
				}
			}
			else
			{
				if (!copia->ramaDer)
				{
					alturaDer = contarAltura(copia->ramaDer);
					copia->ramaDer = new arbol;
					if (alturaDer + 1 - alturaIzq > 2)
					{
						if (der && izq)
						{
							copia->ramaDer->persona = personaAInsertar;
							copia->ramaDer->ramaIzq = copia;
							copia->ramaDer->ramaDer = extra;
							extra = copia->ramaDer;
							break;
						}
						else
						{
							copia->ramaIzq = extra;
							copia->ramaDer->persona = personaAInsertar;
							extra->ramaDer = NULL;
							extra = copia;
							break;
						}
					}
				}
				extra = copia;
				copia = copia->ramaDer;
				if (der != 1)
				{
					der = 1;
				}
				else
				{
					der = 0;
				}
			}
			
		}
	}
}

int main ()
{
	float anadirElemento = 0;
	arbol *arbolAUsar;
	do
	{
		std::cout << "¿Deseas añadir un elemento?\n1. Sí 2. No\nElección: ";
		std::cin >> anadirElemento;
		if (anadirElemento)
		{
			agregarElemento(arbolAUsar);
		}
	} while (anadirElemento != 2);
}