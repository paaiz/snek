# === CONFIG ===
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./src/include
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = $(SRC_DIR)/include

# === SOURCES & OBJECTS ===
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = snake

# === DEFAULT RULE ===
all: $(TARGET)

# Link objects to build final binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

# Compile .cpp to .o in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === CLEAN RULE ===
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# === RUN THE GAME ===
run: all
	./$(TARGET)
