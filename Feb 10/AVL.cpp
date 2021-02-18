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

void acomodarArbol (arbol *&arbolAAcomodar, int insercionDir)
{
	arbol *copia = arbolAAcomodar;
	int contadorDer = contarAltura(copia->ramaDer);
	int contadorIzq = contarAltura(copia->ramaIzq);
	switch (insercionDir)
	{
	case 1: // izq
		if (contadorDer - contadorIzq < 1)
		{
			copia = copia->ramaIzq;
			copia->ramaDer = arbolAAcomodar;
			arbolAAcomodar->ramaIzq = NULL;
			arbolAAcomodar = copia;
		}
		break;
	
	case 2: // der
		if (contadorDer - contadorIzq > 1)
		{
			copia = copia->ramaDer;
			copia->ramaIzq = arbolAAcomodar;
			arbolAAcomodar->ramaDer = NULL;
			arbolAAcomodar = copia;
		}
		break;
	}
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
	int insercionDir = 0; // 1 para izq, 2 para der
	while (copia != NULL)
	{
		if (copia->persona.DNI > personaAInsertar.DNI)
		{
			if (copia->ramaIzq == NULL) // significa que está vacío
			{
				copia->ramaIzq = new arbol; // creamos un nuevo puntero
				copia->ramaIzq->anterior = copia;
				copia = copia->ramaIzq;
				insercionDir = 1;
				break; // salimos
			}
			copia = copia->ramaIzq;
		}
		else
		{
			if (copia->ramaDer == NULL) // significa que está vacío
			{
				copia->ramaDer = new arbol; // creamos un nuevo puntero
				copia->ramaDer->anterior = copia;
				copia = copia->ramaDer;
				insercionDir = 2;
				break; // salimos
			}
			copia = copia->ramaDer;
		}
	}
	copia->persona.nivel = copia->anterior->persona.nivel + 1;
	copia->persona = personaAInsertar;
	copia = arbolAModificar;
	int alturaDer = 0;
	int alturaIzq = 0;
	arbol *acomodador;
	do
	{
		alturaDer = contarAltura(copia->ramaDer);
		alturaIzq = contarAltura(copia->ramaIzq);
		if (alturaDer - alturaIzq < 1)
		{
			acomodador = copia->ramaIzq;
			
		}
		

	} while (alturaDer - alturaIzq != 0 || alturaDer - alturaIzq != 1);
	
	
	
	
	

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