# Installation Guide

## DiscMathlib Installation Guide

### Download the project first. After a successful download, you should have the following files located in:

    DiscMathlib.dll – the dynamic library
    DiscMathlib.lib – the import library
    DiscMathlib.exp – export file
    DiscMath.h – header file

    Copy these files to a folder where you want to keep your library, for example:
    C:\Libs\DiscMathlib\

    In your new Visual Studio project (for example, a console application), open Project → Properties and configure the following:

### C/C++ → General → Additional Include Directories:

### C:\Libs\DiscMathlib\

### Linker → General → Additional Library Directories:
C:\Libs\DiscMathlib\

### Linker → Input → Additional Dependencies:
DiscMathlib.lib

### Copy DiscMathlib.dll next to your compiled .exe file (for example, in the same folder as ConsoleApp.exe).

### Use the header in your code:
#include "DiscMath.h" (Also add it into your project)
