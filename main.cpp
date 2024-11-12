#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

struct Libro {
    int id;
    string titulo;
    string autor;
    bool disponible;
};

struct Usuario {
    string nombre;
    string password;
};

vector<Libro> cargarLibros() {
    vector<Libro> libros;
    ifstream archivo("libros.txt");
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Libro libro;
        string estado;

        getline(ss, estado, ';');
        libro.id = stoi(estado);
        getline(ss, libro.titulo, ';');
        getline(ss, libro.autor, ';');
        getline(ss, estado, ';');
        libro.disponible = (estado == "Disponible");

        libros.push_back(libro);
    }
    return libros;
}

vector<Usuario> cargarUsuarios() {
    vector<Usuario> usuarios;
    ifstream archivo("usuarios.txt");
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Usuario usuario;
        getline(ss, usuario.nombre, ';');
        getline(ss, usuario.password, ';');
        usuarios.push_back(usuario);
    }
    return usuarios;
}

void mostrarLibros(const vector<Libro>& libros) {
    cout << "Libros disponibles:\n";
    for (const auto& libro : libros) {
        if (libro.disponible) {
            cout << libro.id << ". " << libro.titulo << " de " << libro.autor << endl;
        }
    }
}

int buscarLibro(const vector<Libro>& libros, int id) {
    for (size_t i = 0; i < libros.size(); ++i) {
        if (libros[i].id == id && libros[i].disponible) {
            return i;
        }
    }
    return -1;
}

void ordenarLibros(vector<Libro>& libros) {
    sort(libros.begin(), libros.end(), [](const Libro& a, const Libro& b) {
        return a.id < b.id;
    });
}

void registrarUsuario(vector<Usuario>& usuarios) {
    Usuario nuevoUsuario;
    cout << "Ingrese su nombre: ";
    cin >> nuevoUsuario.nombre;
    cout << "Ingrese su contraseña: ";
    cin >> nuevoUsuario.password;
    usuarios.push_back(nuevoUsuario);

    ofstream archivo("usuarios.txt", ios::app);
    archivo << nuevoUsuario.nombre << ";" << nuevoUsuario.password << endl;
    cout << "Usuario registrado con éxito.\n";
}

bool iniciarSesion(const vector<Usuario>& usuarios) {
    string nombre, password;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> password;

    for (const auto& usuario : usuarios) {
        if (usuario.nombre == nombre && usuario.password == password) {
            return true;
        }
    }
    cout << "Credenciales incorrectas.\n";
    return false;
}

void prestarLibro(vector<Libro>& libros) {
    mostrarLibros(libros);
    int idLibro;
    cout << "Ingrese el número del libro que desea prestar: ";
    cin >> idLibro;

    int index = buscarLibro(libros, idLibro);
    if (index != -1) {
        libros[index].disponible = false;
        cout << "Libro prestado: " << libros[index].titulo << endl;
    } else {
        cout << "Libro no disponible o no existe.\n";
    }
}

void devolverLibro(vector<Libro>& libros, stack<pair<Libro, string>>& devoluciones) {
    mostrarLibros(libros);
    int idLibro;
    cout << "Ingrese el número del libro que desea devolver: ";
    cin >> idLibro;

    int index = buscarLibro(libros, idLibro);
    if (index == -1) {
        cout << "Libro no existe o no está prestado.\n";
        return;
    }

    // Verificar si el libro está prestado
    if (!libros[index].disponible) {
        // Calificación y reseña
        string reseña;
        cout << "Ingrese una calificación (1-5): ";
        int calificacion;
        cin >> calificacion;
        cout << "Ingrese su reseña: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, reseña);

        // Devolver el libro
        libros[index].disponible = true;
        devoluciones.push(make_pair(libros[index], reseña));
        cout << "Libro devuelto: " << libros[index].titulo << endl;
        cout << "Calificación: " << calificacion << ", Reseña: " << reseña << endl;
    } else {
        cout << "El libro no estaba prestado.\n";
    }
}

void mostrarDevoluciones(stack<pair<Libro, string>>& devoluciones) {
    cout << "\nLibros devueltos:\n";
    while (!devoluciones.empty()) {
        auto devolucion = devoluciones.top();
        cout << "Libro: " << devolucion.first.titulo << ", Reseña: " << devolucion.second << endl;
        devoluciones.pop();
    }
}

int main() {
    vector<Libro> libros = cargarLibros();
    vector<Usuario> usuarios = cargarUsuarios();
    stack<pair<Libro, string>> devoluciones;

    int opcion;
    do {
        cout << "\n--- Biblioteca ---\n";
        cout << "1. Registrarse\n";
        cout << "2. Iniciar sesión\n";
        cout << "3. Préstamo\n";
        cout << "4. Devolución\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarUsuario(usuarios);
                break;
            case 2:
                if (iniciarSesion(usuarios)) {
                    cout << "Sesión iniciada con éxito.\n";
                }
                break;
            case 3:
                prestarLibro(libros);
                break;
            case 4:
                devolverLibro(libros, devoluciones);
                break;
            case 5:
                cout << "Saliendo de la biblioteca...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    mostrarDevoluciones(devoluciones);

    // Guardar los cambios en los libros
    ofstream archivo("libros.txt");
    for (const auto& libro : libros) {
        archivo << libro.id << ";" << libro.titulo << ";" << libro.autor << ";" 
                 << (libro.disponible ? "Disponible" : "No Disponible") << endl;
    }

    return 0;
}
