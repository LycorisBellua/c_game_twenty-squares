CC = gcc
CFLAGS = -fPIC -MMD -Iinclude -pedantic -Wall -Wextra 
LDFLAGS = -O2 
DIR_BUILD = build
DIR_OBJ = $(DIR_BUILD)/unix/objects
EXECUTABLE = $(DIR_BUILD)/unix/twenty-squares
STATIC_LIB = $(DIR_BUILD)/unix/libts.a
DYNAMIC_LIB = $(DIR_BUILD)/unix/libts.so
SRC_FILES = $(shell find src -name '*.c')
OBJ_FILES = $(patsubst src/%.c, $(DIR_OBJ)/%.o, $(SRC_FILES))

all: $(EXECUTABLE) $(STATIC_LIB) $(DYNAMIC_LIB)

$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) $^ -o $@

$(DIR_OBJ)/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
-include $(DIR_OBJ)/%.d

$(STATIC_LIB): $(filter-out main.o, $(OBJ_FILES))
	@ar rcs $@ $^

$(DYNAMIC_LIB): $(filter-out main.o, $(OBJ_FILES))
	@$(CC) -shared -o $@ $^

# Package: gcc-mingw-w64
.PHONY: win64
.PHONY: win32
win64:
	@$(MAKE) -s all \
	CC=x86_64-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win64/objects \
	EXECUTABLE=$(DIR_BUILD)/win64/TwentySquares-64bit.exe \
	STATIC_LIB=$(DIR_BUILD)/win64/libts64.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win64/libts64.dll
win32:
	@$(MAKE) -s all \
	CC=i686-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win32/objects \
	EXECUTABLE=$(DIR_BUILD)/win32/TwentySquares-32bit.exe \
	STATIC_LIB=$(DIR_BUILD)/win32/libts32.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win32/libts32.dll

.PHONY: clean
.PHONY: clean-unix
.PHONY: clean-win64
.PHONY: clean-win32
clean:
	@make -s clean-unix
	@make -s clean-win64
	@make -s clean-win32
clean-unix:
	@rm -rf build/unix/
clean-win64:
	@rm -rf build/win64/
clean-win32:
	@rm -rf build/win32/

