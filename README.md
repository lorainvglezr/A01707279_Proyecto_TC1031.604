# Faro del Saber - Proyecto de Gestión de Biblioteca
El proyecto a realizar es un desarollo de programa que simula una biblioteca, este programa busca permitir que los usuarios puedan visualizar los libros que se encuentran disponibles en la librería. Por otro lado, la biblioteca permitirá que el usuario pueda crear un perfil y en dicho perfil se guarden sus datos hasta que este decida salir del programa o abandonar la biblioteca. Asimismo, esta biblioteca virtual será capaz de darle la opción al usuario de evaluar aquellos libros que estén disponibles y de agregar otros y calificarlos de igual forma, poniendo los nuevos libros registrados en una lista para futuras adquisiciones de la biblioteca. Por último, este programa se está generando con la idea de ayudar a que el usuario registre sus gustos y vaya teniendo una secuencia de los libros leídos, para ser más conscientes y recordar aquellas lecturas que fueron parte de alguna etapa de su vida. 

## Descripción del avance 1
El proyecto "Faro del Saber" es una aplicación de gestión de biblioteca que permite a los usuarios registrarse, iniciar sesión, prestar y devolver libros de una colección de literatura. La información sobre los libros, como el título, autor y disponibilidad, se almacena en un archivo de texto. Los usuarios pueden también registrar sus credenciales en un archivo separado, lo que permite un acceso personalizado a la biblioteca.

### Funcionalidades principales
1. *Registro de Usuarios:* Permite a nuevos usuarios crear una cuenta con un nombre y una contraseña.
2. *Inicio de Sesión:* Los usuarios pueden iniciar sesión con sus credenciales para acceder a las funcionalidades de la biblioteca.
3. *Gestión de Libros:* Los usuarios pueden ver la lista de libros disponibles, así como prestar y devolver libros.
4. *Registro de Devoluciones:* Al devolver un libro, los usuarios pueden dejar una calificación y una reseña.

## Estructuras del proyecto
- *Libros.txt:* Contiene la lista de libros con su ID, título, autor y estado de disponibilidad.
- *Usuarios.txt:* Almacena los nombres de usuario y contraseñas de los usuarios registrados.

## Ejecución 
Para correr el programa, es necesario ejecutar el siguiente comando en la terminal
"g++ -std=c++11 main.cpp" y cuando aparezca el ejecutable poner "./a.out". 

## Descripción de las Clases y Estructuras
- *Libro:* Representa un libro con atributos como ID, título, autor y estado de disponibilidad.
- *Usuario:* Representa un usuario con atributos para el nombre y la contraseña.

**Funciones:**
  1. *cargarLibros():* Carga la información de los libros desde el archivo libros.txt.
  2. *cargarUsuarios():* Carga la información de los usuarios desde el archivo usuarios.txt.
  3. *mostrarLibros():* Muestra la lista de libros disponibles.
  4. *buscarLibro():* Busca un libro por su ID y verifica su disponibilidad.
  5. *registrarUsuario():* Permite a un nuevo usuario registrarse.
  6. *iniciarSesion():* Verifica las credenciales de un usuario.
  7. *prestarLibro():* Permite a un usuario prestar un libro.
  8. *devolverLibro():* Permite a un usuario devolver un libro y dejar una reseña.
  9. *mostrarDevoluciones():* Muestra un historial de libros devueltos.
 
## Descripción de las Entradas
Los usuarios pueden interactuar con el sistema a través de un menú que les permite elegir opciones para registrarse, iniciar sesión, prestar y devolver libros.

## Descripción de las Salidas
El sistema muestra mensajes informativos sobre el estado de las operaciones realizadas, como la confirmación de registro, el inicio de sesión, la disponibilidad de libros, y el estado de las devoluciones.

# Desarrollo de competencias

## SICT0301: Evalúa los componentes

*Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.*
He realizado un análisis de complejidad para las operaciones de búsqueda y ordenamiento en la gestión de libros. La búsqueda de un libro por ID tiene una complejidad de O(n) en el peor de los casos, mientras que el ordenamiento de libros se realiza utilizando sort, que tiene una complejidad promedio de O(n log n). Línea 56 del main.cpp. 

*Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.*
Se ha utilizado un vector para almacenar los libros, lo que permite un acceso rápido a los elementos y un crecimiento dinámico. La pila se utiliza para gestionar las devoluciones, permitiendo un acceso eficiente a los libros devueltos en el orden en que fueron devueltos. Línea 10 del main.cpp. 

*Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.*
He analizado la complejidad de las funciones que manejan la carga de datos y la gestión de usuarios, determinando que las operaciones de lectura y escritura de archivos tienen una complejidad de O(n), donde n es el número de líneas en los archivos. Línea 20 del main.cpp. 

## SICT0302: Toma decisiones

*Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.*
He optado por utilizar el algoritmo sort de la biblioteca estándar de C++, que es eficiente y adecuado para el tamaño de los datos manejados en este proyecto. Esto asegura un rendimiento óptimo al ordenar la lista de libros, manteniendo una complejidad promedio de O(n log n). Línea 56 del main.cpp

*Selecciona una estructura de datos adecuada al problema y la usa correctamente.*
He elegido utilizar un vector para almacenar los libros debido a su capacidad de crecimiento dinámico y facilidad de acceso. Esto permite realizar operaciones de búsqueda y ordenamiento de manera eficiente. Además, he utilizado una pila (stack) para gestionar las devoluciones de libros, lo que permite un manejo eficiente siguiendo el principio LIFO (Last In, First Out). Línea 10 del main.cpp

## SICT0303: Implementa acciones científicas
*Implementa mecanismos para consultar información de las estructras correctos.*
He implementado funciones que permiten a los usuarios consultar la información de los libros disponibles y realizar operaciones de préstamo y devolución. Estas funciones son intuitivas y aseguran que los usuarios puedan acceder a la información relevante de manera rápida y eficiente. Líneas 45-50 del  main.cpp. 

*Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.*
He desarrollado mecanismos de lectura de archivos que permiten cargar correctamente los datos desde libros.txt y usuarios.txt. Utilizo un ciclo que recorre cada línea del archivo, extrayendo la información necesaria y almacenándola en las estructuras de datos adecuadas. Esto garantiza que la información esté organizada y lista para ser utilizada en el programa. Líneas 20-25 del main.cpp. 

*Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.*
He implementado un mecanismo de escritura en archivos que permite guardar de forma precisa y organizada los datos de los libros y usuarios. Al finalizar la sesión, se actualizan los archivos libros.txt y usuarios.txt para reflejar los cambios en la disponibilidad de los libros y la información de los usuarios. Esto asegura que la información se mantenga persistente entre sesiones y que los datos sean consistentes.Líneas 70-75 del main.cpp. 
