# DFS & BFS

### Pre-requisites
* Network input file: specify number of nodes as well as whether the graph is directed or undirected.
  * Example network input:
```text
[7]
A
B
C
D
E
F
G
[undirected]
A - B
A - C
B - C
B - D
D - G
D - F
D - E
G - F
E - F
```

### Instructions
1. Create a __*ControlFile.txt*__ that contains a set of commands to be processed by the program.
   * **`or` - Open a file for reading. Takes one argument - the file name. 
   * **`ow` - set the output file. Takes one argument - the name of the file. 
   * `dfs` - Depth first search. Takes one argument - the start node.
   * `bfs` - Breadth first search. Takes one argument - the start node.
   * `mc` - Make a Connection with the smallest number of introductions. Takes two arguments - the two people to attempt to connect. 
     * Output: A set of connections that need to be made in order for node A to get to Node B.
     * Ex: `{(A - B), (B - D)}`
2. Compile/Build the project `$ g++ std=c++11 *.cpp -o LinkingSearch.o`
3. Run the project `$ LinkingSearch.o ControlFile.txt`

Example __*ControlFile.txt*__:
```text
or g1.txt
ow g1-output.txt
dfs E
bfs G
mc A D
```

** Note: Required commands  