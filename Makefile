# # === CONFIG ===
# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -I./src/include
# LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# SRC_DIR = src
# OBJ_DIR = obj
# INC_DIR = $(SRC_DIR)/include

# # === SOURCES & OBJECTS ===
# SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# TARGET = snake

# # === DEFAULT RULE ===
# all: $(TARGET)

# # Link objects to build final binary
# $(TARGET): $(OBJS)
# 	$(CXX) $(OBJS) -o $@ $(LIBS)

# # Compile .cpp to .o in obj/
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	@mkdir -p $(OBJ_DIR)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # === CLEAN RULE ===
# clean:
# 	rm -rf $(OBJ_DIR) $(TARGET)

# # === RUN THE GAME ===
# run: all
# 	./$(TARGET)

# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -I./src/include -I./src/states

# SRC = \
#     src/main.cpp \
#     src/snake.cpp \
#     src/food.cpp \
#     src/states/StateManager.cpp \
#     src/states/MainMenuState.cpp \
#     src/states/PlayingState.cpp

# OBJ = $(SRC:.cpp=.o)
# EXEC = snake

# all: $(EXEC)

# $(EXEC): $(OBJ)
# 	$(CXX) $(OBJ) -o $@ -lsfml-graphics -lsfml-window -lsfml-system

# clean:
# 	rm -f $(OBJ) $(EXEC)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src/include -I./src/states

SRC_DIR = src
OBJ_DIR = obj

# List semua file .cpp
SRCS = \
    $(SRC_DIR)/main.cpp \
    $(SRC_DIR)/snake.cpp \
    $(SRC_DIR)/food.cpp \
    $(SRC_DIR)/states/StateManager.cpp \
    $(SRC_DIR)/states/MainMenuState.cpp \
    $(SRC_DIR)/states/PlayingState.cpp

# Ganti ekstensi .cpp -> .o dan simpan di folder obj/ sesuai struktur
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

EXEC = snake

# Target utama
all: $(EXEC)

# Link semua .o jadi executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ -lsfml-graphics -lsfml-window -lsfml-system

# Rule untuk generate .o file dari .cpp, dan simpan ke obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object dan binary
clean:
	rm -rf $(OBJ_DIR) $(EXEC)
