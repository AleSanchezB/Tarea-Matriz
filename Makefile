# Makefile para compilar y ejecutar un programa en C++ 

# Nombre del programa
TARGET = Matriz

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++20 -Wall

# Directorios
SRCDIR = src
BUILDDIR = build
BINDIR = bin

# Archivos fuente

SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Archivos objeto generados durante la compilación
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))

# Regla principal
all: $(BINDIR)/$(TARGET)

# Regla para compilar el programa
$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo fuente a objeto
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla para limpiar archivos generados
clean:
	rm -r $(BUILDDIR) $(BINDIR) $(TARGET)

# Regla para ejecutar el programa
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)
# Generar documentación
d:
	@doxygen $(SRCDIR)/Doxyfile
	@echo "Documentación generada en $(DOCDIR)/html/index.html"
