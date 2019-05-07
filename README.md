Triple encryption program based on RC4A_Spritz, SHA-384 and SHA-256. The program also goes with a salt function; which adds some extra bits after the clear message, in order to reduce the risk collision.
- PROGRAM UNDER GPL-3.0 LICENSEE

# How to run in Linux (Debian / Ubuntu)
- 1) Upload the program
- 2) In command line, go to the folder which contains the program
- 3) Type make and then press enter to compile
- 4) In command line, type ./exe (space) "Your clear message"

# Files included
- Cipher folder: 
    - Basic_Function.c
    - RC4A_Spritz.c

- Header folder:
    - Colors.h
    - Core.h
    
- Main folder:
    - Main.c

- Makefile
- Output.png
