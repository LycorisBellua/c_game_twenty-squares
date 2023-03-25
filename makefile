CC = gcc
CFLAGS = -fPIC -MMD -ansi -pedantic -Wall -Wextra 
LDFLAGS = 

DIR_BUILD = builds
DIR_OBJ = $(DIR_BUILD)/unix/objects

EXECUTABLE = $(DIR_BUILD)/unix/twenty-squares

SOURCE_FILES = $(wildcard sources/*.c)
OBJ_FILES = $(patsubst sources/%.c, $(DIR_OBJ)/%.o, $(SOURCE_FILES))

# -fPIC flag: Needed for the creation of a shared object (dynamic library, also known as a plugin).
#  Certain objects need to be compiled with this flag or they cannot be used to create the lib.

# -MMD flag + The line below: Automatic dependency generation for the source files
# 	Objects are automatically rebuilt if the header files they depend on have changed.
# 	Of course, this only works if both the *.o and *.d files are kept around.
-include $(OBJ_FILES:.o=.d)

# Default rule to build the executable
all: $(EXECUTABLE)

# Rule to build the executable
# 	$^ refers to the list of dependencies
# 	$@ refers to the name of the executable
$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) $^ -o $@

# Rule to build the object files
# 	$(@D) refers to the directory part of target file name
# 	$< refers to the first element of the dependency list (yes, $^ could have been used here)
$(DIR_OBJ)/%.o: sources/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# "make clean"
# 	.PHONY indicates that "clean" is not a file but a command
.PHONY: clean
.PHONY: clean-obj
clean:
	@rm -rf builds/
clean-obj:
	@rm -rf builds/unix/objects/
	@rm -rf builds/win64/objects/
	@rm -rf builds/win32/objects/

# Edit the compiler and executable variables based on the platform specified in the command
# NPM package: gcc-mingw-w64
.PHONY: win64
.PHONY: win32
win64:
	$(MAKE) all \
	CC=x86_64-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win64/objects \
	EXECUTABLE=$(DIR_BUILD)/win64/TwentySquares-64bit.exe
win32:
	$(MAKE) all \
	CC=i686-w64-mingw32-gcc \
	DIR_OBJ=$(DIR_BUILD)/win32/objects \
	EXECUTABLE=$(DIR_BUILD)/win32/TwentySquares-32bit.exe

