CC = gcc
CFLAGS = -fPIC -MMD -ansi -pedantic -Wall -Wextra 
LDFLAGS = -O2 

DIR_BUILD = builds
DIR_OBJ = $(DIR_BUILD)/unix/objects

EXECUTABLE = $(DIR_BUILD)/unix/twenty-squares
STATIC_LIB = $(DIR_BUILD)/unix/libts.a
DYNAMIC_LIB = $(DIR_BUILD)/unix/libts.so

SOURCE_FILES = $(wildcard sources/*.c)
OBJ_FILES = $(patsubst sources/%.c, $(DIR_OBJ)/%.o, $(SOURCE_FILES))

# -fPIC flag: Needed for the creation of a shared object (dynamic library, also known as a plugin).
#  Certain objects need to be compiled with this flag or they cannot be used to create the lib.

# -MMD flag + The line below: Automatic dependency generation for the source files
# 	Objects are automatically rebuilt if the header files they depend on have changed.
# 	Of course, this only works if both the *.o and *.d files are kept around.
-include $(OBJ_FILES:.o=.d)

# Default rule to build the executable and the libraries
all: $(EXECUTABLE) $(STATIC_LIB) $(DYNAMIC_LIB)

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

$(STATIC_LIB): $(filter-out main.o, $(OBJ_FILES))
	@ar rcs $@ $^

$(DYNAMIC_LIB): $(filter-out main.o, $(OBJ_FILES))
	@$(CC) -shared -o $@ $^

# Edit the compiler and executable variables based on the platform specified in the command
# NPM package: gcc-mingw-w64
# 	-s option for make is the silent mode
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

# "make clean"
# 	.PHONY indicates that "clean" is not a file but a command
.PHONY: clean
.PHONY: clean-unix
.PHONY: clean-win64
.PHONY: clean-win32
.PHONY: clean-obj
.PHONY: clean-obj-unix
.PHONY: clean-obj-win64
.PHONY: clean-obj-win32
clean:
	@make -s clean-unix
	@make -s clean-win64
	@make -s clean-win32
clean-unix:
	@rm -rf builds/unix/
clean-win64:
	@rm -rf builds/win64/
clean-win32:
	@rm -rf builds/win32/
clean-obj:
	@make -s clean-obj-unix
	@make -s clean-obj-win64
	@make -s clean-obj-win32
clean-obj-unix:
	@rm -rf builds/unix/objects/ && rm builds/unix/*.a && rm builds/unix/*.so
clean-obj-win64:
	@rm -rf builds/win64/objects/ && rm builds/win64/*.lib && rm builds/win64/*.dll
clean-obj-win32:
	@rm -rf builds/win32/objects/ && rm builds/win32/*.lib && rm builds/win32/*.dll

