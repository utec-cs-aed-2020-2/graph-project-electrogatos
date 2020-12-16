# Grafos para realizar testes

## Grafo dirigido
```
DirectedGraph<char, float> graph;
```

### BFS Y DFS
- para ver la evolucion de la stack o queque habilitar los prints en breadthfs.h y depthfs.h
- DFS: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/ (segundo ejemplo)
- BFS: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
```
    DFS
    graph.insertVertex(1, '0');
    graph.insertVertex(2, '1');
    graph.insertVertex(3, '2');
    graph.insertVertex(4, '3');
    graph.createEdge(1, 3, 4);// 0-2
    graph.createEdge(3, 1, 4);// 2-0
    graph.createEdge(1, 2, 4);// 0-1
    graph.createEdge(2, 3, 4);// 1-2
    graph.createEdge(2, 4, 4);// 1-3
    graph.createEdge(3, 3, 4);// 3-3

    execDFS()
    Incio: 2
        Nodo pop stack: 2
            Nodo push stack: 0
        Nodo pop stack: 0
            Nodo push stack: 1
        Nodo pop stack: 1
            Nodo push stack: 3
        Nodo pop stack: 3
    0: 1(1), 
    1: 3(1), 
    2: 0(1), 
    3: 
    Recorrido DFS: 
    2 -> 0 -> 1 -> 3 ->
```

- otro
```
    BFS y dijskstra tmb funciona
    graph.insertVertex(1, '0');
    graph.insertVertex(2, '1');
    graph.insertVertex(3, '2');
    graph.insertVertex(4, '3');
    graph.createEdge(1, 3, 2);//0-2
    graph.createEdge(3, 1, 1);//2-0
    graph.createEdge(1, 2, 3);//0-1
    graph.createEdge(2, 3, 4);//1-2
    graph.createEdge(3, 4, 1);//2-3
    graph.createEdge(4, 4, 2);//3-3

    execBFS()
    Incio: 2
        Nodo pop queque: 2
            Nodo push queque: 0
            Nodo push queque: 3
        Nodo pop queque: 0
            Nodo push queque: 1
        Nodo pop queque: 3
        Nodo pop queque: 1
    0: 1(1), 
    1: 
    2: 0(1), 3(1), 
    3: 
    Recorrido BFS: 
    2 -> 0 -> 3 -> 1 ->



    execDijkstra()
    Incio: 0
                    0         1         2         3
            0         0         3         2       INF
            2         0         3         2         3
            1         0         3         2         3
            3         0         3         2         3
    Result of Dijkstra
    0: 2(2), 1(3), 
    1: 
    2: 3(1), 
    3: 

    Vertex   Distance  
    0         0
    1         3
    2         2
    3         3
```

### Disjkstra
- https://www.cs.dartmouth.edu/~cs10/notes17.html
```
    graph.insertVertex(1, '0');
    graph.insertVertex(2, '5');
    graph.insertVertex(3, '4');
    graph.insertVertex(4, '8');
    graph.insertVertex(5, '7');
    graph.createEdge(1, 2, 6);//0-5
    graph.createEdge(1, 3, 4);//0-4
    graph.createEdge(2, 3, 2);//5-4
    graph.createEdge(3, 2, 1);//4-5
    graph.createEdge(5, 1, 7);//7-0
    graph.createEdge(3, 5, 3);//4-7
    graph.createEdge(3, 4, 9);//4-13
    graph.createEdge(2, 4, 3);//5-13
    graph.createEdge(4, 5, 4);//13-7
    graph.createEdge(5, 4, 5);//7-13

    execDijkstra()
    Incio: 0
                    0         5         4         1         7
            0         0         6         4       INF       INF
            4         0         5         4        13         7
            5         0         5         4         8         7
            7         0         5         4         8         7
            1         0         5         4         8         7
    Result of Dijkstra // este grafo resultante en dirigidos no funciona :(
    0: 5(6), 4(4), 
    5: 1(3), 
    4: 5(1), 7(3), 1(9), 
    1: 
    7: 

    Vertex   Distance  
    0         0
    5         5
    4         4
    1         8
    7         7
```
- geek: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
```
    graph.insertVertex(1, '0');
    graph.insertVertex(2, '1');
    graph.insertVertex(3, '2');
    graph.insertVertex(4, '3');
    graph.createEdge(1, 3, 2);//0-2
    graph.createEdge(3, 1, 1);//2-0
    graph.createEdge(1, 2, 3);//0-1
    graph.createEdge(2, 3, 4);//1-2
    graph.createEdge(3, 4, 1);//2-3
    graph.createEdge(4, 4, 2);//3-3

    Incio: 0
                   1         0         2         3
         0         3         0         2       INF
         2         3         0         2         3
         1         3         0         2         3
         3         3         0         2         3
    Result of Dijkstra
    0: 2(2), 1(3), 
    1: 
    2: 3(1), 
    3: 

    Vertex   Distance  
    1         3
    0         0
    2         2
    3         3
```
### bellmanford
- geek: https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
- inicio A
```
    graph.insertVertex(1, 'A');
    graph.insertVertex(2, 'B');
    graph.insertVertex(3, 'C');
    graph.insertVertex(4, 'D');
    graph.insertVertex(5, 'E');
    graph.createEdge(1, 2, -1);//A-B
    graph.createEdge(1, 3, 4);//A-C
    graph.createEdge(2, 3, 3);//B-C
    graph.createEdge(4, 3, 5);//D-C
    graph.createEdge(4, 2, 1);//D-B
    graph.createEdge(2, 4, 2);//B-D
    graph.createEdge(5, 4, -3);//E-D
    graph.createEdge(2, 5, 2);//B-E

    execBellmanFord()
    Incio: A
    Vertex   Distance  
    A         0
    C         2
    D        -2
    B        -1
    E         1
```

## Grafo no-dirigido

### Prim y Kruskal
- PPT Grafos Kruskal and Prim ejm
```
         1
     0 ------ 1 \-
     |      / |   \1
    6|   4/   |3   - 4
     |  /     |   /1
      2 ----- 3 /
         1
```
- si quieres ver la estructura de disjoint set habilita el print en kruskal.h
```
    graph.insertVertex(1, "0");
    graph.insertVertex(2, "1");
    graph.insertVertex(3, "2");
    graph.insertVertex(4, "3");
    graph.insertVertex(5, "4");
    graph.createEdge(1, 3, 6);  // 0 - 2 | 6
    graph.createEdge(1, 2, 1);  // 0 - 1 | 1
    graph.createEdge(3, 2, 4);  // 2 - 1 | 4
    graph.createEdge(3, 4, 1);  // 2 - 3 | 1
    graph.createEdge(2, 4, 3);  // 1 - 3 | 3
    graph.createEdge(2, 5, 1);  // 1 - 4 | 1
    graph.createEdge(4, 5, 1);  // 3 - 4 | 1


    execKruskal()
    -----------------------
    -------PRINTSETS-------
    Total Sets: 1
    Index:           0         1         2         3         4
    Data:            0         1         2         3         4
    Parent:          4         4         4         4         4
    Rank:            0         0         0         0         1
    -----------------------
    -----------------------
    -------PRINTSETS-------
    Total Sets: 1
    Index:           0         1         2         3         4
    Data:            0         1         2         3         4
    Parent:          4         4         4         4         4
    Rank:            0         0         0         0         1
    -----------------------
    4: 3(1), 1(1), 
    3: 4(1), 2(1), 
    2: 3(1), 
    1: 4(1), 0(1), 
    0: 1(1), 

    execPrim()
    0: 1(1), 
    1: 0(1), 4(1), 
    2: 3(1), 
    3: 2(1), 4(1), 
    4: 3(1), 1(1), 
```

### BFS Y DFS
- For test ppt Presentación 06 (Búsqueda en Grafos) BFS Y DFS

```
    graph.insertVertex(1, "A");
    graph.insertVertex(2, "B");
    graph.insertVertex(3, "C");
    graph.insertVertex(4, "D");
    graph.insertVertex(5, "E");
    graph.insertVertex(6, "F");
    graph.insertVertex(7, "G");
    graph.insertVertex(8, "H");
    graph.insertVertex(9, "I");
    graph.createEdge(1, 2, 6); //A-B
    graph.createEdge(1, 5, 6); //A-E
    graph.createEdge(1, 3, 6); //A-C
    graph.createEdge(2, 3, 6); //B-C
    graph.createEdge(2, 4, 6); //B-D
    graph.createEdge(4, 3, 6); //D-C
    graph.createEdge(3, 5, 6); //C-E
    graph.createEdge(3, 6, 6); //C-F
    graph.createEdge(5, 8, 6); //E-H
    graph.createEdge(5, 7, 6); //E-G
    graph.createEdge(7, 9, 6); //G-I
    graph.createEdge(8, 9, 6); //H-I


execDFS()
Incio: A
 Nodo pop stack: A
  Nodo push stack: B
  Nodo push stack: E
  Nodo push stack: C
 Nodo pop stack: C
  Nodo push stack: D
  Nodo push stack: F
 Nodo pop stack: F
 Nodo pop stack: D
 Nodo pop stack: E
  Nodo push stack: H
  Nodo push stack: G
 Nodo pop stack: G
  Nodo push stack: I
 Nodo pop stack: I
 Nodo pop stack: H
 Nodo pop stack: B
A: B(1), E(1), C(1), 
B: A(1), 
C: A(1), D(1), F(1), 
D: C(1), 
E: A(1), H(1), G(1), 
F: C(1), 
G: E(1), I(1), 
H: E(1), 
I: G(1), 
Recorrido DFS: 
 A -> C -> F -> D -> E -> G -> I -> H -> B ->

execBFS()
Incio: A
 Nodo pop queque: A
  Nodo push queque: B
  Nodo push queque: E
  Nodo push queque: C
 Nodo pop queque: B
  Nodo push queque: D
 Nodo pop queque: E
  Nodo push queque: H
  Nodo push queque: G
 Nodo pop queque: C
  Nodo push queque: F
 Nodo pop queque: D
 Nodo pop queque: H
  Nodo push queque: I
 Nodo pop queque: G
 Nodo pop queque: F
 Nodo pop queque: I
A: B(1), E(1), C(1), 
B: A(1), D(1), 
C: A(1), F(1), 
D: B(1), 
E: A(1), H(1), G(1), 
F: C(1), 
G: E(1), 
H: E(1), I(1), 
I: H(1), 
Recorrido BFS: 
 A -> B -> E -> C -> D -> H -> G -> F -> I ->

```

### Kruskal
- https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/
- hace el sort de las aristas o edges

```
    graph.insertVertex(1, "0");
    graph.insertVertex(2, "1");
    graph.insertVertex(3, "2");
    graph.insertVertex(4, "3");
    graph.insertVertex(5, "4");
    graph.createEdge(1, 2, 2);  // 0 - 1 | 2
    graph.createEdge(2, 3, 3);  // 1 - 2 | 3
    graph.createEdge(3, 5, 7);  // 2 - 4 | 7
    graph.createEdge(1, 4, 6);  // 0 - 3 | 6
    graph.createEdge(2, 4, 8);  // 1 - 3 | 8
    graph.createEdge(2, 5, 5);  // 1 - 4 | 5
    graph.createEdge(4, 5, 9);  // 3 - 4 | 9


    execKruskal()
    4: 1(5), 
    3: 0(6), 
    2: 1(3), 
    1: 0(2), 2(3), 4(5), 
    0: 1(2), 3(6), 

    execPrim()
    0: 1(2), 3(6), 
    1: 0(2), 2(3), 4(5), 
    2: 1(3), 
    3: 0(6), 
    4: 1(5), 
```

### dijkstra
- https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
- para ver la evolucion de la tabla habilitar /* print actual table */ en dijkstra.h
- inicio 0
```
    graph.insertVertex(1, "0");
    graph.insertVertex(2, "1");
    graph.insertVertex(3, "2");
    graph.insertVertex(4, "3");
    graph.insertVertex(5, "4");
    graph.insertVertex(6, "5");
    graph.insertVertex(7, "6");
    graph.insertVertex(8, "7");
    graph.insertVertex(9, "8");
    graph.createEdge(1, 2, 4);//0-1
    graph.createEdge(1, 8, 8);//0-7
    graph.createEdge(2, 8, 11);//1-7
    graph.createEdge(2, 3, 8);//1-2
    graph.createEdge(8, 7, 1);//7-6
    graph.createEdge(8, 9, 7);//7-8
    graph.createEdge(3, 9, 2);//2-8
    graph.createEdge(9, 7, 6);//8-6
    graph.createEdge(3, 4, 7);//2-3
    graph.createEdge(7, 6, 2);//6-5
    graph.createEdge(3, 6, 5);//2-5
    graph.createEdge(4, 6, 14);//3-5
    graph.createEdge(4, 5, 9);//3-4
    graph.createEdge(6, 5, 10);//5-4

    execDijkstra()
    Incio: 0
                    1         2         4         6         0         7         3         5         8
            0         4       INF       INF       INF         0         8       INF       INF       INF
            1         4        12       INF       INF         0         8       INF       INF       INF
            7         4        12       INF         9         0         8       INF       INF        15
            6         4        12       INF         9         0         8       INF        11        15
            5         4        12        21         9         0         8        25        11        15
            2         4        12        21         9         0         8        19        11        14
            8         4        12        21         9         0         8        19        11        14
            3         4        12        21         9         0         8        19        11        14
            4         4        12        21         9         0         8        19        11        14
    Result of Dijkstra
    0: 1(4), 7(8), 
    1: 0(4), 2(8), 
    2: 1(8), 8(2), 3(7), 
    3: 2(7), 
    4: 5(10), 
    5: 6(2), 4(10), 
    6: 7(1), 5(2), 
    7: 0(8), 6(1), 
    8: 2(2), 

    Vertex   Distance  
    1         4
    2        12
    4        21
    6         9
    0         0
    7         8
    3        19
    5        11
    8        14

```

- Dijkstar PPT Presentación 06 (Búsqueda en Grafos) ejemplo
- inico A
```
    graph.insertVertex(1, "A");
    graph.insertVertex(2, "B");
    graph.insertVertex(3, "C");
    graph.insertVertex(4, "D");
    graph.insertVertex(5, "E");
    graph.insertVertex(6, "F");
    graph.insertVertex(7, "G");
    graph.insertVertex(8, "H");
    graph.createEdge(1, 3, 4); //A-C
    graph.createEdge(1, 6, 7); //A-F
    graph.createEdge(3, 6, 2); //C-F
    graph.createEdge(3, 4, 3); //C-D
    graph.createEdge(3, 7, 9); //C-G
    graph.createEdge(6, 7, 8); //F-G
    graph.createEdge(4, 7, 7); //D-G
    graph.createEdge(4, 5, 3); //D-E
    graph.createEdge(7, 8, 3); //G-H
    graph.createEdge(5, 7, 2); //E-G
    graph.createEdge(5, 8, 7); //E-H
    graph.createEdge(5, 2, 9); //E-B
    graph.createEdge(8, 2, 3); //H-B

    execDijkstra()
    Incio: A
                    A         C         B         D         H         E         F         G
            A         0         4       INF       INF       INF       INF         7       INF
            C         0         4       INF         7       INF       INF         6        13
            F         0         4       INF         7       INF       INF         6        13
            D         0         4       INF         7       INF        10         6        13
            E         0         4        19         7        17        10         6        12
            G         0         4        19         7        15        10         6        12
            H         0         4        18         7        15        10         6        12
            B         0         4        18         7        15        10         6        12
    Result of Dijkstra
    A: C(4), 
    B: H(3), 
    C: A(4), F(2), D(3), 
    D: C(3), E(3), 
    E: D(3), G(2), 
    F: C(2), 
    G: E(2), H(3), 
    H: G(3), B(3), 

    Vertex   Distance  
    A         0
    C         4
    B        18
    D         7
    H        15
    E        10
    F         6
    G        12
```
