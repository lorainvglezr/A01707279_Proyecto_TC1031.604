/*
*  Autor: Lorain Valeria Gonzalez Rivas
*  Fecha: Viernes, 20 de septiembre de 2024
*  Programa: Version 1 del documento .h para la implementacion 
*  de los metodos de busqueda y ordenamiento en la 
*  libreria creada
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Estructura del libro (variables conjuntas del libro)
struct Book {
    std::string titulo;
    std::string autor;
    std::string categoria;
    int paginas;

    Book();
    Book(std::string, std::string, std::string, int);
};

// Clase madre Libreria
class Library {
public:
    Library();
    ~Library();

    // Agregar a la biblioteca la informacion de un libro
    void agregarlibro(Book libro);

    // Buscar un libro dentro de la biblioteca, identificar con un bool si el libro se encuentra en la base de datos
    bool busquedaBinaria(std::string titulo);

    // Ordenar la lista de libros por el numero de paginas
    void shellSort();

    // Mostrar en pantalla la lista de libros
    void mostrarlibros();

private:
    std::vector<Book> libros;
};

Book::Book() {
    titulo = "";
    autor = "";
    categoria = "";
    paginas = 0;
}

Book::Book(std::string t, std::string a, std::string c, int p) {
    titulo = t;
    autor = a;
    categoria = c;
    paginas = p;
}

Library::Library() {}

Library::~Library() {}

void Library::agregarlibro(Book libro) {
    libros.push_back(libro);
}

bool Library::busquedaBinaria(std::string titulo) {
    int low = 0;
    int high = libros.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (libros[mid].titulo == titulo) {
            return true;
        } 
        else if (libros[mid].titulo < titulo) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return false;
}

void Library::shellSort() {
    int gap = libros.size() / 2;

    while (gap > 0) {
        for (int i = gap; i < libros.size(); i++) {
            Book temp = libros[i];
            int j = i;
            while (j >= gap && libros[j - gap].paginas > temp.paginas) {
                libros[j] = libros[j - gap];
                j -= gap;
            }
            libros[j] = temp;
        }
        gap /= 2;
    }
}

void Library::mostrarlibros() {
    for (Book libro : libros) {
        std::cout << "INFORMACION DEL LIBRO" << std::endl;
        std::cout << "Titulo: " << libro.titulo << std::endl;
        std::cout << "Autor: " << libro.autor << std::endl;
        std::cout << "Categoria: " << libro.categoria << std::endl;
        std::cout <<"Paginas: " << libro.paginas << std::endl;
        std::cout << std::endl;
    }
}

#endif  // LIBRARY_H