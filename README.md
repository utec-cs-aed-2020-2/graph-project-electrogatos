-   [Revisado: *Nota 18*]
-   [Revisar Comentarios en los commits]
-   [En general, extender el algoritmo de busqueda en profundidad y anchura para grafos dirigidos]
-   [Borrar los codigos comentados]

# Algoritmos y Estructura de Datos

## Proyecto sobre Grafos

---

## Integrantes

-   Atachagua, James
-   Garcia, Fernando
-   Paniagua, Estephany

## Ejecución

Software necesario:

-   VScode

Es necesario modificar la ruta de importación del archivo JSON con la ruta completa del sistema operativo desde donde se encuentre en la línea 48 del archivo `src/Tester/tester.cpp`.

### Automático

Independiente del sistema operativo, revisar el archivo `.vscode/tasks.json` y comentar o descomentar la línea de dependencia de la creación del folder de salida (línea 66). Sugerencia: comentar en windows, descomentar en mac o linux.

Ejecutar la tarea por defecto con `Ctrl + Shift + B`.

### Manual

```bash
# Compilar en linux
g++ --std=c++11 \
	-g \
	src/main.cpp \
	src/Tester/*.cpp \
	-o \
	build/main.out   # en linux

# Compilar en Windows
g++ --std=c++11 -g src/main.cpp src/Tester/*.cpp -o build/main.exe

# Ejecutar en linux
./build/main.out

# Ejecutar en windows
build\main.exe
```

---

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:

## Graph data structure

-   El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
-   Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
-   No considerar loops ni multi-arista.

### Methods:

```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected

bool isStronglyConnected() throw(); // Detect if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```

### Algorithms (Part 1):

```cpp
//Given the graph
UndirectedGraph<char, int> graph;

//1- Generates a MST graph using the Kruskal approach (only for undirected graphs)
Kruskal<char, int> kruskal(&graph);
UndirectedGraph<char, int> result = kruskal.apply();//return a tree

//2- Generates a MST graph using the Prim approach (only for undirected graphs)
Prim<char, int> prim(&graph, "A");
UndirectedGraph<char, int> result = prim.apply();//return a tree
```

## JSON file parser

-   Construye un grafo a partir de una archivo JSON de aereopuertos del mundo.

### Methods:

```cpp
void clear(); // Clears parser saved atributes

void readJSON(); // Parses JSON file and saves data into class
// NOTE: each derived class has its own readJSON method

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph
```

## [Git Karma Guidelines](http://karma-runner.github.io/5.2/dev/git-commit-msg.html)

```
<type>(<scope>): <subject>

<body>
```

### Allowed `<type>` values

-   feat (new feature for the user, not a new feature for build script)
-   fix (bug fix for the user, not a fix to a build script)
-   docs (changes to the documentation)
-   style (formatting, missing semi colons, etc)
-   refactor (refactoring production code, eg. renaming a variable)
-   test (adding missing tests, refactoring tests)
-   chore (updating grunt tasks etc)

### Allowed `<scope>` values

-   graph
-   directedGraph
-   undirectedGraph
-   parser
-   main
-   tester

> **PD:** Puntos extras sobre Evaluación Continua si se implementa una GUI.
