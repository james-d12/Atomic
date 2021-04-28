## Table of Content

### Overview
* [About](#About)
* [Main Features](#Main-Features)

# **About**
Atomic is a header only modern C++ library. It currently contains linear-algebra, geometry and general mathematical functions not present within the standard library. It aims to be lightweight and easy to integrate into existing projects with low overhead using a variety of modern C++ features and practices. It is currently structured as split into 'modules' these are purely organisational, do not confuse these with c++ modules. Each module aims to be independent however all depend upon the core module. This library aims to be easy to use and all you have to do is simply include the .hpp files into your project no source file compilation is required.

# **Main Features**
**Matrices**
- Can create NxM matrices of type T.
- Supports row and column major ordering for matrices. 
- Can be managed using fixed or dynamic memory management, and work together. 
- Matrix Arithmetic operations can be performed between varying types of matrices. (e.g. dynamic 4x3 integer matrix multiplied by a fixed 3x4 real matrix)#

**Vectors**
- Can create N-dimensional vectors of type T 
- Can and can be managed using fixed or dynamic memory management. 
- Arithmetic and comparison operations can be performed between varying types and dimensions of vectors. (e.g. a vector4 multiplied by a vector2)

**Other**
- Can create Quarternions of type T (Fixed as quarternions have a fixed number of components - x,y,w,z)
- Contains basic structures for geometrical structures like rays, segments and lines.
- Contains basic random number generation for a variety of arithmetic types.

