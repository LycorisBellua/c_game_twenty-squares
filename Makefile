CC = gcc
CFLAGS = -O2 -fPIC -MMD -Iinclude -Wall -Wextra -pedantic -g
DIR_BUILD = build
DIR_OBJ = $(DIR_BUILD)/unix/objects
EXE = $(DIR_BUILD)/unix/twenty_squares
STATIC_LIB = $(DIR_BUILD)/unix/lib20SQ.a
DYNAMIC_LIB = $(DIR_BUILD)/unix/lib20SQ.so
SRC = $(shell find src -name '*.c')
OBJ = $(patsubst %.c, $(DIR_OBJ)/%.o, $(SRC))

all: $(EXE) $(STATIC_LIB) $(DYNAMIC_LIB)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
-include $(DIR_OBJ)/%.d

$(STATIC_LIB): $(filter-out main.o, $(OBJ))
	ar rcs $@ $^

$(DYNAMIC_LIB): $(filter-out main.o, $(OBJ))
	$(CC) -shared -o $@ $^

.PHONY: all win64 win32 clean clean-unix clean-win64 clean-win32 fclean 
.PHONY: fclean-unix fclean-win64 fclean-win32 re re-win64 re-win32

# Package: gcc-mingw-w64
win64:
	$(MAKE) all \
	CC=x86_64-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win64/objects \
	EXE=$(DIR_BUILD)/win64/TwentySquares-64bit.exe \
	STATIC_LIB=$(DIR_BUILD)/win64/lib20SQ64.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win64/lib20SQ64.dll
win32:
	$(MAKE) all \
	CC=i686-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win32/objects \
	EXE=$(DIR_BUILD)/win32/TwentySquares-32bit.exe \
	STATIC_LIB=$(DIR_BUILD)/win32/lib20SQ32.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win32/lib20SQ32.dll

clean:
	$(MAKE) clean-unix
	$(MAKE) clean-win64
	$(MAKE) clean-win32
clean-unix:
	rm -rf $(DIR_BUILD)/unix/objects
clean-win64:
	rm -rf $(DIR_BUILD)/win64/objects
clean-win32:
	rm -rf $(DIR_BUILD)/win32/objects

fclean:
	$(MAKE) fclean-unix
	$(MAKE) fclean-win64
	$(MAKE) fclean-win32
fclean-unix:
	rm -rf $(DIR_BUILD)/unix
fclean-win64:
	rm -rf $(DIR_BUILD)/win64
fclean-win32:
	rm -rf $(DIR_BUILD)/win32

re: fclean-unix all

re-win64: fclean-win64 win64

re-win32: fclean-win32 win32
