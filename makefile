SOURCE_FILES=\
sources/ability.c \
sources/board.c \
sources/cells.c \
sources/input.c \
sources/movement.c \
sources/players.c \
sources/rng.c \
sources/selection.c \
sources/start.c \
sources/turn.c

HEADER_FILES=\
headers/ability.h \
headers/board.h \
headers/cells.h \
headers/input.h \
headers/movement.h \
headers/players.h \
headers/rng.h \
headers/selection.h \
headers/start.h \
headers/turn.h

twenty_squares: $(SOURCE_FILES) $(HEADER_FILES)
	@gcc -ansi -pedantic -Wall -Wextra -o builds/twenty-squares sources/main.c $(SOURCE_FILES) $(HEADER_FILES)

# Package: mingw-w64
# 32-bit Windows executable: i686-w64-mingw32-gcc -o builds/TwentySquares.exe sources/main.c $(SOURCE_FILES) $(HEADER_FILES)
# 64-bit Windows executable: x86_64-w64-mingw32-gcc -o builds/TwentySquares.exe sources/main.c $(SOURCE_FILES) $(HEADER_FILES)

