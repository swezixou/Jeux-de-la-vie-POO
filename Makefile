# ======================================================
# COMPILATEUR + FLAGS
# ======================================================
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# ======================================================
# LIBSFML
# ======================================================
# Sous Linux
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Sous Windows (MinGW)
# SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lfreetype

# ======================================================
# STRUCTURE DES DOSSIERS
# ======================================================
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Recherche automatique de tous les .cpp
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET = $(BIN_DIR)/game_of_life

# ======================================================
# RÈGLE PAR DÉFAUT
# ======================================================
all: $(TARGET)

# ======================================================
# LINKAGE FINAL
# ======================================================
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(SFML_LIBS)
	@echo "Compilation terminée ✔"

# ======================================================
# COMPILATION INDIVIDUELLE DES .CPP
# ======================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ======================================================
# COMMANDES UTILES
# ======================================================
run:
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Nettoyage terminé ✔"

re: clean all

# ======================================================
# FIN
# ======================================================

#test unitaire
test:
	@mkdir -p bin
	g++ -std=c++17 -Wall -Wextra -Iinclude \
	    testuni/TestUnit.cpp \
	    src/application/FileManager.cpp \
	    src/domain/Grid.cpp \
	    -o bin/testunit
	./bin/testunit


# ======================================================

