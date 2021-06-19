#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "defines.h"


static int getFloat(float*);
static int esNumerica(char*, int);
static int esFlotante(char*, int);
static int esCaracter(char*, int);
static int getDescripcion(char*, int);
static int getString(char*, int);


int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[50];

	fflush(stdin);
	if(pResultado != NULL && getString(buffer, sizeof(buffer))==0 && esNumerica(buffer,sizeof(buffer)))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[50];

	fflush(stdin);
	if(pResultado != NULL && getString(buffer, sizeof(buffer))==0 && esFlotante(buffer,sizeof(buffer)))
	{
		retorno=0;
		*pResultado=atof(buffer);
	}
	return retorno;
}

static int esNumerica(char* cadena, int tam)
{
	int retorno=-1;
	int i;

	if(cadena != NULL && tam >0)
	{
		for(i=0;cadena[i] != '\0' && cadena[i]<tam; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

static int esFlotante(char* cadena, int tam)
{
	int retorno=-1;
	int i;

	if(cadena != NULL && tam >0)
	{
		for(i=0;cadena[i] != '\0' && cadena[i]<tam; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0' || cadena[i]=='.')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

static int getString(char* cadena, int tam)
{
	int retorno=-1;
	char bufferString[50];

	if(cadena != NULL && tam>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=tam)
			{
				strncpy(cadena,bufferString,tam);
				retorno=0;
			}
		}

	}
	return retorno;
}


static int getDescripcion(char* buffer, int tam)
{
	int retorno=-1;
	char bufferString[DESCRIPCION];

	if(buffer != NULL)
	{
		if(getString(bufferString,sizeof(bufferString))==0 && esCaracter(bufferString,sizeof(bufferString)==0))
		{
			strncpy(buffer,bufferString,tam);
			retorno=0;
		}
	}
	return retorno;
}


static int esCaracter(char* cadena, int tam)
{
	int retorno=-1;
	int i;

	if(cadena != NULL && tam > 0)
	{

		for(i=0; cadena[i] != '\0' && i<tam; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9' || cadena[i] < 'A' || cadena[i] > 'Z' || cadena[i] < 'a' || cadena[i] > 'z')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getNombre(char* name,int tam, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[NAME];
	int retorno=-1;
	reintentos=0;


	do{
		printf("%s", mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString))==0)
		{
			strncpy(name,bufferString,tam);
			retorno=0;
			break;
		}
		else
		{
			fflush(stdin);
			printf("%s", mensajeError);
			reintentos--;
		}

	}while(reintentos>=0);

	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferInt) == 0 &&
				bufferInt >= minimo &&
				bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c", &buffer);
			if(esCaracter(&buffer,sizeof(buffer)) == 0)
			{
				retorno = 0;
				*pResultado = buffer;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}

	return retorno;
}
