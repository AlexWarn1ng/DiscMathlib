# DiscMathlib Installation Guide

## Step 1. Download

Download the project. After a successful download, you should have the following files:

- DiscMathlib.dll — the dynamic library  
- DiscMathlib.lib — the import library  
- DiscMathlib.exp — export file  
- DiscMath.h — header file  

---

## Step 2. Place the Files

Copy these files to a folder where you want to keep your library, for example:
C:\Libs\DiscMathlib\

---

## Step 3. Configure Visual Studio

Open your project and go to:

Project → Properties

Configure the following settings.

### C/C++ → General → Additional Include Directories:
C:\Libs\DiscMathlib\

### Linker → General → Additional Library Directories:
C:\Libs\DiscMathlib\

### Linker → Input → Additional Dependencies:
DiscMathlib.lib

---

## Step 4. Runtime Setup

Copy `DiscMathlib.dll` next to your compiled `.exe` file  
(for example, into the same folder as `ConsoleApp.exe`).

---

## Step 5. Include in Code

#include "DiscMath.h" !
Make sure the header file is added to your project.
