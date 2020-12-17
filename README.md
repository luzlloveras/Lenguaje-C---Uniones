# Lenguaje-C---Uniones
Ejercicio de práctica de uniones en lenguaje C

Enunciado:
Se desea llevar el control de los elementos de una biblioteca que tiene 3000 ítems.
Estos ítems pertenecen a 3 categorías: CDs, libros y revistas.
Estas categorías o grupos tienen datos que son comunes a todos los elementos y otros que son particulares de cada grupo.

Los datos comunes a todos ellos son:
- Código de elemento (int)
- Número de socio al que fue prestado o 0 si no esta prestado (int)

Los datos particulares de cada categoría son:

- CDs:
       + Nombre del CD (string de 20 caracteres)
       + Ubicación en la biblioteca (string de 10)
       + Soporte de ejecución [W (windows), L (Linux), M (MacOs)] (char)

- Libros
       + Nombre del libro (string de 30)
       + Nombre del autor (string de 20)
       + Nombre de la editorial (string de 20)
   
- Revisstas
       + Nombre de la revista (string de 20)
       + Volumen (int)
       + Numero (int)
       
Se pide realizar un programa que permita el ingreso de los datos y luego muestre en pantalla agrupados por categoría, utilizando funciones para cada caso.
