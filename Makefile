ifeq ($(OS),Windows_NT)
    COMPILE = g++ main.cpp -o Proyecto2
endif

all:
	cls
	$(COMPILE)
	Proyecto2.exe