# --------------------------
# CONFIGURATION
# --------------------------
CXX      = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -I.

SRC_DIRS = Data Model Services Presentation
BUILD_DIR = bin
TARGET    = $(BUILD_DIR)/airwatcher

# --------------------------
# AUTO-DETECTION DES .cpp
# --------------------------
SOURCES = $(wildcard $(foreach dir,$(SRC_DIRS),$(dir)/*.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

# --------------------------
# REGLES
# --------------------------
all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean