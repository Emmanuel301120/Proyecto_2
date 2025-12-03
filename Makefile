ifeq ($(OS),Windows_NT)
    COMPILE = g++ Vehiculo.cpp  main.cpp -o Proyecto2
endif

all:
	cls
	$(COMPILE)
	Proyecto2.exe
