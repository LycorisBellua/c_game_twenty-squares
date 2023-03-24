CC = gcc
CFLAGS = -fPIC -MMD -ansi -pedantic -Wall -Wextra 
LDFLAGS = 

OBJDIR = builds
OBJDIR_OBJ = $(OBJDIR)/objects

EXECUTABLE = $(OBJDIR)/twenty-squares

SOURCE_FILES = $(wildcard sources/*.c)
OBJ_FILES = $(patsubst sources/%.c, $(OBJDIR_OBJ)/%.o, $(SOURCE_FILES))

# -fPIC flag: Needed for the creation of a shared object (dynamic library, also known as a plugin).
#  Certain objects need to be compiled with this flag or they cannot be used to create the lib.

# -MMD flag + The line below: Automatic dependency generation for the source files
# 	Objects are automatically rebuilt if the header files they depend on have changed.
# 	Of course, this only works if both the *.o and *.d files are kept around.
-include $(OBJ_FILES:.o=.d)

# Default rule: Build the executable
all: $(EXECUTABLE)

# Rule to build the executable
# 	$^ refers to the list of dependencies
# 	$@ refers to the name of the executable
$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) $^ -o $@

# Rule to build the object files
# 	The pipe is used to specify that the directories are to be created first
# 	$(@D) refers to the directory part of target file name
# 	$< refers to the first element of the dependency list (yes, $^ could have been used here)
$(OBJDIR_OBJ)/%.o: sources/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# "make clean"
# 	.PHONY indicates that "clean" is not a file but a command
.PHONY: clean
clean:
	@rm -rf $(OBJDIR_OBJ)

# Package: mingw-w64
# 32-bit Windows executable: i686-w64-mingw32-gcc -o ${OBJDIR}/TwentySquares.exe ${MAIN_FILE} $(SOURCE_FILES) $(HEADER_FILES)
# 64-bit Windows executable: x86_64-w64-mingw32-gcc -o ${OBJDIR}/TwentySquares.exe ${MAIN_FILE} $(SOURCE_FILES) $(HEADER_FILES)

