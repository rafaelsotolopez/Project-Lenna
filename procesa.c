/*
Fundamentos de Programación
Autor: Soto López Rafael
Fecha de realización: 21/10/2025
Fecha de última revisión: 25/11/2025
*/
#include <stdio.h>

int bienvenida();

int matricesRBG(FILE *lena, int ancho, int alto, int maxVal);

int matrizIndividual(FILE *lena, int ancho, int alto, int maxVal, int opcion);

int escalaDeGrises(FILE *lena, int ancho, int alto, int maxVal);

int imagenEnBlancoYNegro(FILE *lena, int ancho, int alto, int maxVal);

void imprimirGeneralidades(char P, char tipo, int ancho, int alto, int maxVal);

int main(int argc, char **argv)
{
    // Verificar que el número de argumentos sea correcto
    if(argc < 2)
    {
        printf("\n\n\tERROR DE EJECUCION\n");
        printf("\n\n\tIntenta ejecutar de la forma: programa.exe archivo.ppm\n\n");
        return 1;
    }

    // Declarar apuntador y abrir archivo lena.ppm
    FILE *lena = fopen(argv[1], "r");

    // Verificar que la apertura haya sido correcta
    if(!lena)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    char P, tipo;
    int ancho = 0, alto = 0, maxVal = 0;

    // Leer "P3"
    fscanf(lena, "%c%c", &P, &tipo);

    // Leer "\n" después del P3
    int c = fgetc(lena);

    // Leer comentario del archivo
    char cadena[256];
    fgets(cadena, sizeof(cadena), lena);

    // Leer dimensiones y valor máximo
    fscanf(lena, "%d %d", &ancho, &alto);
    fscanf(lena, "%d", &maxVal);

    // Solicitar al usuario una opción del menú
    int opcion = bienvenida();

    // Ejecución de casos
    switch(opcion)
    {
    case 1: // Crear archivos (red.ppm)(green.ppm) y (blue.ppm)
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...\n");

        if(!matricesRBG(lena, ancho, alto, maxVal))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivos creados:\n");

            printf("\n\tred.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);

            printf("\n\tgreen.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);

            printf("\n\tblue.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir uno de los archivos, vuelva a intentar");

        break;

    case 2: // Crear solo el archivo red.ppm
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...\n");

        if(!matrizIndividual(lena, ancho, alto, maxVal, opcion))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivo creado:\n");

            printf("\n\tred.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir el archivo, vuelva a intentar");

        break;

    case 3: // Crear solo el archivo green.ppm
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...\n");

        if(!matrizIndividual(lena, ancho, alto, maxVal, opcion))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivo creado:\n");

            printf("\n\tgreen.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir el archivo, vuelva a intentar");

        break;

    case 4: // Crear solo el archivo blue.ppm
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...\n");

        if(!matrizIndividual(lena, ancho, alto, maxVal, opcion))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivo creado:\n");

            printf("\n\tblue.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir el archivo, vuelva a intentar");
        break;

    case 5: // Crear archivo .pgm para la escala de grises
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...\n");

        if(!escalaDeGrises(lena, ancho, alto, maxVal))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivo creado:\n");

            printf("\n\tescalaDeGrises.pgm\n");
            imprimirGeneralidades(P, '2', ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir el archivo, vuelva a intentar");
        break;

    case 6: // Crear archivo .pbm para blanco y negro
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);

        if(!imagenEnBlancoYNegro(lena, ancho, alto, maxVal))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivo creado:\n");

            printf("\n\timagenEnBlancoYNegro.pbm\n");
            imprimirGeneralidades(P, '1', ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir el archivo, vuelva a intentar");

        break;

    case 7:
        printf("\n\n\tHa seleccionado la opcion %d:", opcion);
        printf("\n\n\tCargando...");

        if(!matricesRBG(lena, ancho, alto, maxVal) &&
           !escalaDeGrises(lena, ancho, alto, maxVal) &&
           !imagenEnBlancoYNegro(lena, ancho, alto, maxVal))
        {
            printf("\n\n\tEjecucion exitosa");
            printf("\n\n\tArchivos creados:\n");

            printf("\n\tred.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);

            printf("\n\tgreen.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);

            printf("\n\tblue.ppm\n");
            imprimirGeneralidades(P, tipo, ancho, alto, maxVal);

            printf("\n\tescalaDeGrises.pgm\n");
            imprimirGeneralidades(P, '2', ancho, alto, maxVal);

            printf("\n\timagenEnBlancoYNegro.pbm\n");
            imprimirGeneralidades(P, '1', ancho, alto, maxVal);
        }
        else
            printf("\n\n\tERROR al intentar abrir uno de los archivos, vuelva a intentar");

        break;

    default:
        break;
    }

    // Cerrar archivo
    fclose(lena);

    printf("\n\n\n");

    return 0;
}

int bienvenida()
{
    int opcion;

    printf("\n\n\tBIENVENID@ A ESTE PROGRAMA\n");
    printf("\n\n\tEl programa puede procesar una imagen dado el archivo .ppm que se envio:\n\n");
    printf("\t1. Matrices R, G y B\n");
    printf("\t2. Matriz R\n");
    printf("\t3. Matriz G\n");
    printf("\t4. Matriz B\n");
    printf("\t5. Imagen en escala de grises\n");
    printf("\t6. Imagen en blanco y negro\n");
    printf("\t7. Todas las anteriores\n");
    printf("\n\tPor favor digita la opcion que deseas ejecutar: ");
    scanf("%d", &opcion);

    while((opcion < 1) || (7 < opcion))
    {
        printf("\n\tERROR AL SELECCIONAR UNA OPCION\n");
        printf("\n\tPor favor ingresa un valor entre 1 y 7: ");
        scanf("%d", &opcion);
        printf("\n");
    }

    return opcion;
}

// OPCIÓN 1
int matricesRBG(FILE *lena, int ancho, int alto, int maxVal)
{
    int totalPixeles = ancho * alto;

    // Declarar apuntadores y crear archivos (red.ppm)(green.ppm) y (blue.ppm)
    FILE *red = fopen("red.ppm", "w+");
    FILE *green = fopen("green.ppm", "w+");
    FILE *blue = fopen("blue.ppm", "w+");

    // Verificaciones de que los archivos se han creado y abierto correctamente
    if(!red)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    if(!green)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    if(!blue)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    // Hacer que red.ppm sea P3
    fprintf(red, "%s\n","P3");
    fprintf(red, "%d %d\n", ancho, alto);
    fprintf(red, "%d\n", maxVal);

    // Hacer que green.ppm sea P3
    fprintf(green, "%s\n", "P3");
    fprintf(green, "%d %d\n", ancho, alto);
    fprintf(green, "%d\n", maxVal);

    // Hacer que blue.ppm sea P3
    fprintf(blue, "%s\n", "P3");
    fprintf(blue, "%d %d\n", ancho, alto);
    fprintf(blue, "%d\n", maxVal);

    int r, g, b;

    // Leer valores rgb del archivo lena.ppm e imprimirlos en su respectivo archivo
    for(int i = 0; i < totalPixeles; i++)
    {
        fscanf(lena, "%d %d %d", &r, &g, &b);

        fprintf(red, "%d ", r);
        fprintf(green, "%d ", g);
        fprintf(blue, "%d ", b);
    }

    // Cerrar archivos
    fclose(red);
    fclose(green);
    fclose(blue);

    return 0;
}

// OPCIONES 2, 3 Y 4 
int matrizIndividual(FILE *lena, int ancho, int alto, int maxVal, int opcion)
{
    const char *nombre;

    switch(opcion)
    {
    case 2:
        nombre = "red.ppm";
        break;
    case 3:
        nombre = "green.ppm";
        break;
    case 4:
        nombre = "blue.ppm";
        break;
    default:
        break;
    }

    // Declarar apuntador y crear archivo .ppm
    FILE *archivo = fopen(nombre, "w+");

    // Verificación de que el archivo se ha creado y abierto correctamente
    if(!archivo)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    // Hacer que el archivo .ppm sea P3
    fprintf(archivo, "%s\n","P3");
    fprintf(archivo, "%d %d\n", ancho, alto);
    fprintf(archivo, "%d\n", maxVal);

    int totalPixeles = ancho * alto;
    int r, g, b;

    // Leer valores rgb del archivo lena.ppm e imprimir los valores en su respectivo archivo
    switch(opcion)
    {
    case 2:
        for(int i = 0; i < totalPixeles; i++)
        {
            fscanf(lena, "%d %d %d", &r, &g, &b);

            fprintf(archivo, "%d ", r);  // Solo imprimir los valores 'r'
        }
        break;

    case 3:
        for(int i = 0; i < totalPixeles; i++)
        {
            fscanf(lena, "%d %d %d", &r, &g, &b);

            fprintf(archivo, "%d ", g); // Solo imprimir los valores 'g'
        }
        break;

    case 4:
        for(int i = 0; i < totalPixeles; i++)
        {
            fscanf(lena, "%d %d %d", &r, &g, &b);

            fprintf(archivo, "%d ", b); // Solo imprimir los valores 'b'
        }
        break;

    default:
        break;
    }

    // Cerrar archivo
    fclose(archivo);

    return 0;
}

// OPCIÓN 5
int escalaDeGrises(FILE *lena, int ancho, int alto, int maxVal)
{
    // Declarar apuntador y crear archivo .pgm
    FILE *archivo = fopen("escalaDeGrises.pgm", "w+");

    // Verificación de que el archivo se ha creado y abierto correctamente
    if(!archivo)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    // Hacer que el archivo .pgm sea P2
    fprintf(archivo, "%s\n","P2");
    fprintf(archivo, "%d %d\n", ancho, alto);
    fprintf(archivo, "%d\n", maxVal);

    int totalPixeles = ancho * alto;
    int r, g, b, valor;

    // Leer valores rgb del archivo lena.ppm, calcular el promedio e imprimir el resultado en el archivo .pgm
    for(int i = 0; i < totalPixeles; i++)
    {
        fscanf(lena, "%d %d %d", &r, &g, &b);

        valor = (r + g + b) / 3; // El archivo .pgm solo acepta valores enteros

        fprintf(archivo, "%d ", valor);
    }

    // Cerrar archivo
    fclose(archivo);

    return 0;
}

// OPCIÓN 6
int imagenEnBlancoYNegro(FILE *lena, int ancho, int alto, int maxVal)
{
    // Declarar variable umbral para imagen en blanco y negro
    int umbral;

    printf("\n\n\tDigite el valor umbral para la imagen en blanco y negro: ");
    scanf("%d", &umbral);

    while((umbral < 0) || (255 < umbral))
    {
        printf("\n\tERROR AL DIGITAR EL UMBRAL\n");
        printf("\n\tPor favor ingresa un valor entre 0 y 255: ");
        scanf("%d", &umbral);
        printf("\n");       
    }

    printf("\n\tCargando...\n");

    // Declarar apuntador y crear archivo .pbm
    FILE *archivo = fopen("imagenEnBlancoYNegro.pbm", "w+");

    // Verificación de que el archivo se ha creado y abierto correctamente
    if(!archivo)
    {
        printf("\n\n\tERROR AL ABRIR EL ARCHIVO\n\n");
        return 1;
    }

    // Hacer que el archivo .pbm sea P1
    fprintf(archivo, "%s\n","P1");
    fprintf(archivo, "%d %d\n", ancho, alto);
    fprintf(archivo, "%d\n", maxVal);

    int totalPixeles = ancho * alto;
    int r, g, b, valor;

    // Leer valores rgb del archivo lena.ppm, calcular el promedio, con base en el umbral decidir un valor e imprimir el resultado en el archivo .pbm
    for(int i = 0; i < totalPixeles; i++)
    {
        fscanf(lena, "%d %d %d", &r, &g, &b);

        valor = (r + g + b) / 3; // pixel gris = promedio de rgb

        if(valor < umbral)
            fprintf(archivo, "%d ", 0); // (pixel gris < umbral) -> pixel = negro
        else
            fprintf(archivo, "%d ", 255); // (pixel gris >= umbral) -> pixel = blanco
    }

    // Cerrar archivo
    fclose(archivo);

    return 0;
}

void imprimirGeneralidades(char P, char tipo, int ancho, int alto, int maxVal)
{
    printf("\t\tNumero magico: %c%c\n", P, tipo);
    printf("\t\tAncho: %d\n", ancho);
    printf("\t\tAlto: %d\n", alto);
    printf("\t\tValor maximo: %d\n", maxVal);
}
