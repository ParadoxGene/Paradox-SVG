# Paradox-SVG
Converts scalable vector graphics (svg) content to a modifiable c/c++ or swift object and vice-versa.

[![C/C++ Unit Testing](https://github.com/ParadoxGene/Paradox-SVG/actions/workflows/c-c++.yml/badge.svg)](https://github.com/ParadoxGene/Paradox-SVG/actions/workflows/c-c++.yml)

[Community Discord](https://discord.gg/KcVBu4n9TU)

# Prerequisites
C compiler that supports C11 standard or higher.
C++ compiler that supports C++11 standard or higher.

# Building the library & Running tests
To check if the header files are supported on your system.

Build the shared library:
```
make
```

The shared libraries will be in `build/paradox-shared`
The static libraries will be in `build/paradox-static`

Build the tests:
```
make build_tests
```

Running C Tests
```
./build/paradox-svg-c-unit-tests/Debug/c_unit_tests
```

Running C++ Tests
```
./build/paradox-svg-cpp-unit-tests/Debug/cpp_unit_tests
```

Running Swift Tests
```
W.i.P.
```

# To Do List
- [ ] Add parsing support for a subset of CSS Version 2.1 Content. ([Standard](https://www.w3.org/TR/CSS2/))
  - **All Parsing Features**
      - None
- [ ] Add parsing support for a subset of XML Version 1.1 Content. ([Standard](https://www.w3.org/TR/xml11/))
  - **All Parsing Features**
      - None
- [ ] Add parsing support for a subset of SVG Version 1.1 Content. ([Standard](https://www.w3.org/TR/SVG11/))
  - **All Parsing Features**
    - None
- [ ] Add a modifiable C/C++ and Swift interface for SVG Version 1.1 objects and values.
  - **All C Interface Features**
    - None
  - **All C++ Interface Features**
    - None
  - **All Swift Interface Features**
    - None
- [ ] Add converter from SVG Version 1.1 content to modifiable C/C++ and Swift interface and vice-versa.
  -  **All Converter Features**
      - None
