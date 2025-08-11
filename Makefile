CC = gcc
CFLAGS = -fvisibility=hidden -O2 -fPIC -MMD -Iinclude -Wall -Wextra -pedantic -g
DIR_BUILD = build
DIR_OBJ = $(DIR_BUILD)/linux/objects
EXE_NAME = twenty_squares
EXE_NAME_WIN = TwentySquares.exe
EXE = $(DIR_BUILD)/linux/$(EXE_NAME)
LDFLAGS = 
STATIC_LIB = $(DIR_BUILD)/linux/lib20SQ.a
DYNAMIC_LIB = $(DIR_BUILD)/linux/lib20SQ.so
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
	$(CC) -shared -o $@ $^ $(LDFLAGS)

.PHONY: all win64 win32 clean clean-linux clean-win64 clean-win32 fclean 
.PHONY: fclean-linux fclean-win64 fclean-win32 re re-win64 re-win32

# Package: gcc-mingw-w64
win64:
	@$(MAKE) --no-print-directory all \
	CC=x86_64-w64-mingw32-gcc \
	LDFLAGS="-Wl,--exclude-all-symbols" \
	DIR_OBJ=$(DIR_BUILD)/win64/objects \
	EXE=$(DIR_BUILD)/win64/$(EXE_NAME_WIN) \
	STATIC_LIB=$(DIR_BUILD)/win64/lib20SQ64.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win64/lib20SQ64.dll
win32:
	@$(MAKE) --no-print-directory all \
	CC=i686-w64-mingw32-gcc \
	LDFLAGS="-Wl,--exclude-all-symbols -static-libgcc" \
	DIR_OBJ=$(DIR_BUILD)/win32/objects \
	EXE=$(DIR_BUILD)/win32/$(EXE_NAME_WIN) \
	STATIC_LIB=$(DIR_BUILD)/win32/lib20SQ32.lib \
	DYNAMIC_LIB=$(DIR_BUILD)/win32/lib20SQ32.dll

clean:
	@$(MAKE) --no-print-directory clean-linux
	@$(MAKE) --no-print-directory clean-win64
	@$(MAKE) --no-print-directory clean-win32
clean-linux:
	rm -rf $(DIR_BUILD)/linux/objects
clean-win64:
	rm -rf $(DIR_BUILD)/win64/objects
clean-win32:
	rm -rf $(DIR_BUILD)/win32/objects

fclean:
	@$(MAKE) --no-print-directory fclean-linux
	@$(MAKE) --no-print-directory fclean-win64
	@$(MAKE) --no-print-directory fclean-win32
fclean-linux: clean-linux
	rm -f $(DIR_BUILD)/linux/$(EXE_NAME)
	rm -f $(DIR_BUILD)/linux/*.a
	rm -f $(DIR_BUILD)/linux/*.so
fclean-win64: clean-win64
	rm -f $(DIR_BUILD)/win64/$(EXE_NAME_WIN)
	rm -f $(DIR_BUILD)/win64/*.lib
	rm -f $(DIR_BUILD)/win64/*.dll
fclean-win32: clean-win32
	rm -f $(DIR_BUILD)/win32/$(EXE_NAME_WIN)
	rm -f $(DIR_BUILD)/win32/*.lib
	rm -f $(DIR_BUILD)/win32/*.dll

re: fclean-linux all

re-win64: fclean-win64 win64

re-win32: fclean-win32 win32
