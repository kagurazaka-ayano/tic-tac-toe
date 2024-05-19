## Build instructions:

### With cmake:

At project root, type:
```
mkdir build
cd build
cmake ..
cmake --build .
./tictactoe
```

### With bare compiler

At project root, type:

```
clang++ -I include src/Board.cpp src/main.cpp && ./a.out
```

or with g++

```
g++ -I include src/Board.cpp src/main.cpp && ./a.out
```
