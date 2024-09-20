# El Faro del Saber
El proyecto a realizar es un desarollo de programa que simula una biblioteca, este programa busca permitir que los usuarios puedan visualizar los libros que se encuentran disponibles en la librería. Por otro lado, la biblioteca permitirá que el usuario pueda crear un perfil y en dicho perfil se guarden sus datos hasta que este decida salir del programa o abandonar la biblioteca. Asimismo, esta biblioteca virtual será capaz de darle la opción al usuario de evaluar aquellos libros que estén disponibles y de agregar otros y calificarlos de igual forma, poniendo los nuevos libros registrados en una lista para futuras adquisiciones de la biblioteca. Por último, este programa se está generando con la idea de ayudar a que el usuario registre sus gustos y vaya teniendo una secuencia de los libros leídos, para ser más conscientes y recordar aquellas lecturas que fueron parte de alguna etapa de su vida. 

## Descripción del avance 1
A continuación, en este primer avance, se muestra como se ha implementado la función básica de imprimir la información previamente establecida acerca de los libros que se encuentran disponibles en la biblioteca virtual. Continuando, el programa cuenta con un algoritmo básico de ordenamiento que se encarga de arreglar de forma ascendente los libros de acuerdo al número de páginas con el que cuenta cada uno. En última instancia, en este primer avance, implementé la funcionalidad básica de búsqueda para saber si el libro predeterminado se encuentra o no dentro de la biblioteca. 

- Guardar y procesar la información de los libros en una lista.
- Utilizar el algoritmo Shell Sort para ordenar los números de páginas de menor a mayor según el libro.
- Mostrar la lista de libros antes y después de ser ordenadas. El algoritmo de Shell Sort fue elegido porque es una buena opción para conjuntos de datos más grandes. 
- Instrucciones para compilar el avance de proyecto. 

## Ejecución 
Para correr el programa, es necesario ejecutar el siguiente comando en la terminal
"g++ main.cpp" y cuando aparezca el ejecutable poner "./a.out". 

## Descripción de las entradas del avance de proyecto

Por ahora, el sistema no recibe entradas de ningún tipo. 

## Descripción de las salidas del avance de proyecto

Las salidas del proyecto en esta fase incluyen:
1. Información de los libros disponibles en la biblioteca.
2. Información organizada de los libros disponibles en la biblioteca.
3. Mensaje de disponibilidad o existencia de libro predeterminado de la biblioteca. 

# Desarrollo de competencias

## SICT0301: Evalúa los componentes

*Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.*

El método de Shell Sort es una variación de la clasificación de inserción que utiliza un enfoque de división y conquista para mejorar el rendimiento. Tiene una complejidad temporal de O(n log n) en el caso promedio, lo que lo convierte en una gran opción para conjuntos y recopilación de datos más grandes y extensos. Sin embargo, es más complejo de implementar que la clasificación de inserción. 

## SICT0302: Toma decisiones

*Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.*

En el proyecto se puede ver cómo implementé en el código un método de ordenamiento de forma correcta, dado que con la función de ordenamiento para los datos de los libros, mostrando una lista de información relevante antes y después del ordenamiento. La decisión de usar Shell Sort fue la más adecuada para resolver el problema del proyecto, maximizando el rendimiento y minimizando el uso de recursos.
