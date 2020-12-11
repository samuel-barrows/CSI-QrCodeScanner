
# Table of Contents

1.  [What is it?](#org8c11a8b)
2.  [Dependancies and External Libraries](#org26c28f4)
3.  [Build](#org9e115f3)
4.  [Use](#org961af5c)



<a id="org8c11a8b"></a>

# What is it?

This is a program that will allow users to create a database and use qr codes to validate an identity. It was intended as a proof of concept to verify that people were vaccinated for the current pandemic, inspired by the end of Contagion.


<a id="org26c28f4"></a>

# Dependancies and External Libraries

-   <https://www.nayuki.io/page/qr-code-generator-library> Source for the QR code generator
-   <https://www.dynamsoft.com/barcode-reader/> The scanner library that I will be using
-   <https://wiki.gnome.org/action/show/Projects/LibRsvg?action=show&redirect=LibRsvg> Program to convert svg files to pngs


<a id="org9e115f3"></a>

# Build

-   To build this, all you have to do is run the makefile in the project root. Just run `make`. The libraries are precompiled in the `lib/` directory. The reason that this is this way (I know it is bad practice) but the shared object libraries that come with the external libraries are pre-compiled with no instructions on how to build the libraries. So I included them with the whole program.


<a id="org961af5c"></a>

# Use

The program has a few options that are run from the command line.

-   `-n` will prompt you for details to add a new user to the database found in `data/`
-   `-s PATH/TO/QRCODE/` will scan the qrcode that is provided and check the database for the details
-   `-d` will simply display the contents of the database

