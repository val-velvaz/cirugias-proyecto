# --- CONFIGURACIÓN DEL COMPILADOR ---
CXX = g++.exe

# --- CONFIGURACIÓN DEL PROYECTO ---
TARGET = output\Cirugias.exe

# --- BANDERAS (FLAGS) DE COMPILACIÓN Y ENLACE ---
CXXFLAGS = -std=c++14 -Iinclude -I/ucrt64/include/SFML -DSFML_STATIC -m64
LDFLAGS = -L/ucrt64/lib -static-libgcc -static-libstdc++ -m64
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype -lopengl32 -lwinmm -lgdi32 -lucrt

# --- BÚSQUEDA AUTOMÁTICA DE ARCHIVOS ---
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# --- REGLAS DE MAKEFILE ---
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- REGLAS ADICIONALES ---
clean:
	rm -f src/*.o $(TARGET)

run: all
	.\$(TARGET)