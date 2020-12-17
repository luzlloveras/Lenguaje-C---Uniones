#include <stdio.h>
#define N 3000

// Declaracion de tipo de datos

struct CDS {
    char NOMBRE[20];
    char UBIC[10];
    char SOPORTE; };

struct LIBROS {
    char NOMBRE[30];
    char AUTOR[20];
    char EDITORIAL[20]; };

struct REVISTAS {
    char NOMBRE[20];
    int VOL;
    int NUM; };

union TODOS {
    struct CDS CD;
    struct LIBROS LIBRO;
    struct REVISTAS REVISTA; };

enum TIPOS { CD, LIBRO, REVISTA };

struct DATOS {
    int CODIGO;
    int PRESTADO;
    enum TIPOS TIPO;
    union TODOS ITEM; };

// Prototipos
void INGRESO (struct DATOS[], int);
struct CDS LEECD (void);
struct LIBROS LEELIBRO (void);
struct REVISTAS LEEREVISTA (void);
void IMPRESION (struct DATOS[], int);
void PRINTCD (struct CDS);
void PRINTLIBRO (struct LIBROS);
void PRINTREVISTA (struct REVISTAS);

int main ()
{
    struct DATOS DATO[N];
    INGRESO (DATO, N);
    IMPRESION(DATO, N);
}

void INGRESO (struct DATOS D[], int CANT)
{
    int i;
    for (i=0; i<CANT; i++)
    {
        printf("\nIngrese el codigo\n");
        scanf("%d", &D[i].CODIGO);
        printf("\nIngrese el tipo de dato\n");
        printf("\0:CD   1:LIBRO     2:REVISTA\n");
        scanf("%d", &D[i].TIPO);

        D[i].PRESTADO = 0;

        switch (D[i].TIPO)
        {
            case CD: D[i].ITEM.CD = LEECD(); break;
            case LIBRO: D[i].ITEM.LIBRO = LEELIBRO(); break;
            case REVISTA: D[i].ITEM.REVISTA = LEEREVISTA(); break;
        }
    }
}

// LEECD 
// Permite el ingreso de los datos particulares de tipo CD

struct CDS LEECD ()
{
    struct CDS C;
    
    printf("\n Ingrese el nombre\n");
    fflush(stdin);
    gets(C.NOMBRE);

    printf("\nIngrese la ubicacion\n");
    gets(C.UBIC);

    printf("\n Ingrese el soporte\n");
    C.SOPORTE = getchar();

    return C;
}

// LEELIBRO
// Permite el ingreso de los datos particulares de tipo LIBRO

struct LIBROS LEELIBRO ()
{
    struct LIBROS C;
    
    printf("\n Ingrese el nombre\n");
    fflush(stdin);
    gets(C.NOMBRE);

    printf("\nIngrese el nombre del autor\n");
    gets(C.AUTOR);

    printf("\n Ingrese el nombre de la editorial\n");
    gets(C.EDITORIAL);

    return C;
}

// LEEREVISTA
// Permite el ingreso de los datos particulares de tipo REVISTA

struct REVISTAS LEEREVISTA ()
{
    struct REVISTAS C;
    
    printf("\n Ingrese el nombre\n");
    fflush(stdin);
    gets(C.NOMBRE);

    printf("\nIngrese el numero de volumen\n");
    scanf("%d", &C.VOL);

    printf("\n Ingrese el numero de la revista\n");
    scanf("%d", &C.NUM);

    return C;
}

void IMPRESION (struct DATOS D[], int CANT)
{
    int i, j;

    for (j=0; j<REVISTA; j++)
        printf("\n\nCATEGORIA = ");

    switch (j) 
    {
        case CD: printf("CD\n"); break;
        case LIBRO: printf("LIBRO\n"); break;
        case REVISTA: printf("REVISTA\n"); break;
    }

    for (i=0; i<CANT; i++)
        if (D[i].TIPO == J)
        {
            printf("\n%6d%6d", D[i].CODIGO, D[i].PRESTADO);
            switch (D[i].TIPO)
            {
                case CD: PRINTCD(D[i].ITEM.CD); break;
                case LIBRO: PRINTLIBRO(D[i].ITEM.LIBRO); break;
                case REVISTA: PRINTREVISTA(D[i].ITEM.REVISTA); break;
            }
        }
}

void PRINTCD (struct CDS C)
{
    printf("%20s%20s%20s", C.NOMBRE, C.UBIC, C.SOPORTE);
}

void PRINTLIBRO (struct LIBROS C)
{
    printf("%20s%20s%20s", C.NOMBRE, C.AUTOR, C.EDITORIAL);
}

void PRINTREVISTA (struct REVISTAS C)
{
    printf("%30s%10d%10d", C.NOMBRE, C.VOL, C.NUM);
}