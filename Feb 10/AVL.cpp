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
	//arbol *anterior = NULL;
	
};

int contarAltura (arbol *&arbolAExaminar) // usese con un brazo, ya sea el derecho o el izquierdo
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
	//acomodar
	int contadorDer = contarAltura(arbolAModificar->ramaDer);
	int contadorIzq = contarAltura(arbolAModificar->ramaIzq);
	if (contadorDer - contadorIzq > 1 || contadorDer - contadorIzq < 1)
	{
		if (contadorDer - contadorIzq > 1) // acomodar derecho
		{
			
		}
		else // acomodar izquierdo
		{
			
		}
		
	}
	

}