### Commands to build and check:
Debug:
```
cmake -B build/debug -S . -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++
cmake --build build/debug

# run program
./build/debug/source/application/fibonacci_app 
```

Release:
```
cmake -B build/release -S . -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++
cmake --build build/release  

# run program
./build/release/source/application/fibonacci_app 
```

### Task 1 answer
Adding a directory only instructs CMake to process that folder's Cmake files and add them to the build tree. It does not automatically create a dependency between targets, so linking is still needed.

### Task 3 answer
Include has to be PUBLIC because we need to expose library header to the final use application. Other featres as sources and language aren't useful or requiered for the final user, so we do not expose them.

### Task 5 answer
Problem:
```
> cmake --build build/debug                                                                   
[1/2] Building CXX object source/application/CMakeFiles/fibonacci_app.dir/src/main.cpp.obj
FAILED: [code=1] source/application/CMakeFiles/fibonacci_app.dir/src/main.cpp.obj 
"C:\Program Files\LLVM\bin\clang++.exe"   -O0 -g -Xclang -gcodeview -std=c++23 -D_DEBUG -D_DLL -D_MT -Xclang --dependent-lib=msvcrtd -MD -MT source/application/CMakeFiles/fibonacci_app.dir/src/main.cpp.obj -MF source\application\CMakeFiles\fibonacci_app.dir\src\main.cpp.obj.d -o source/application/CMakeFiles/fibonacci_app.dir/src/main.cpp.obj -c "C:/Projects Kate/c++/CPP_Course/source/application/src/main.cpp"
C:/Projects Kate/c++/CPP_Course/source/application/src/main.cpp:2:10: fatal error: 'fibonacci.hpp' file not found
    2 | #include "fibonacci.hpp"
      |          ^~~~~~~~~~~~~~~
1 error generated.
ninja: build stopped: subcommand failed.
```
Stage: compilation - preprocessing
Because the include path is set to PRIVATE, it is restricted only to the library target. The application target cannot see the path to find the header file, but the library still can because the path belongs to its own configuration.

### Build results:
Debug:
```
> ./build/debug/source/application/fibonacci_app
1
55
1
55
```

Release:
```
> ./build/release/source/application/fibonacci_app                                  
1         
55
1
55
```