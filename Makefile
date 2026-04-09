# compilador
CC = gcc

# Banderas de compilacion
CFLAGS = -Wall -Wextra -IInclude

# Archivos a compilar 
src=SRC/*.c main.c

# Nombre del ejecutable
TARGET=lista_ligada

# Regla principal para compilar
all:
	$(CC) $(CFLAGS) $(src) -o $(TARGET)

# Regla para ejecutar
run: all	./$(TARGET)

# Regla para borrar los archivos generados al compilador
clean:
	rm -f $(TARGET)