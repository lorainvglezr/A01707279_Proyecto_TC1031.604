/*
*  Autor: Lorain Valeria Gonzalez Rivas
*  Fecha: Viernes, 20 de septiembre de 2024
*  Programa: Version 1 del main.cpp para la implementacion de 
*  los metodos de busqueda y ordenamiento en la libreria creada
*/

#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

int main(){
    Library lib;

    Book libro1("Orgullo y Prejuicio", "Jane Austen","Libros de literatura", 192);
    Book libro2("Monet. The Triumph of Impressionism", "Daniel Wildenstein", "Libros artísticos e ilustrados", 616);
    Book libro3("Cómo hacer que te pasen cosas buenas", "Marian Rojas Estapé", "Libros de autoayuda", 336);
    Book libro4("Libro de Mormón", "José Smith", "Libros religiosos y sagrados", 532);
    Book libro5("El mono desnudo", "Desmond Morris", "Libros de texto", 225);
    Book libro6("El lenguaje de programación Python de principio a fin", "Angel Pablo Hinojosa Gutiérrez", "Libros técnicos o especializados", 1064);
    Book libro7("Las recetas de Blanca", "Blanca Garcia", "Libros prácticos", 288);
    Book libro8("¡No quiero el cabello rizado!", "Lura Ellen Anderson", "Libros infantiles", 26);
    Book libro9("Diccionario Pocket Francés-Español Larousse", "Equipo Editorial Larousse", "Libros de consulta y referencia", 366);
    Book libro10("Mentiras cuánticas", "Chris Ferrie", "Libros divulgativos", 208);

    lib.agregarlibro(libro1);
    lib.agregarlibro(libro2);
    lib.agregarlibro(libro3);
    lib.agregarlibro(libro4);
    lib.agregarlibro(libro5);
    lib.agregarlibro(libro6);
    lib.agregarlibro(libro7);
    lib.agregarlibro(libro8);
    lib.agregarlibro(libro9);
    lib.agregarlibro(libro10);

    std::cout << "BIENVENIDO A LA BIBLIOTECA ESTATAL" << std::endl;
    std::cout << "'EL FARO DEL SABER'" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    std::cout << std::endl;
    std::cout << "LISTA DE LIBROS DISPONIBLES" << std::endl;
    std::cout << "NOTA: Los libros se muestran en desorden de acuerdo al número de páginas de todos ellos" << std::endl;
    std::cout << std::endl;
    lib.mostrarlibros();

    lib.shellSort();

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "LISTA DE LIBROS DISPONIBLES EN ORDEN NUMERICO" << std::endl;
    std::cout << "NOTA: Los libros se muestran de mayor a menor de acuerdo al número de páginas de todos ellos" << std::endl;
    std::cout << std::endl;
    lib.mostrarlibros();

    std::string titulo = "El Jardín de las Mariposas";
    if (lib.busquedaBinaria(titulo)) {
        std::cout << "El libro '" << titulo << "' SI se encuentra en la biblioteca" << std::endl;
    }
    else {
        std::cout << "El libro '" << titulo << "' NO se encuentra en la biblioteca" << std::endl;
    }

    return 0;
}
