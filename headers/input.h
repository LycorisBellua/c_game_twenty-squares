#ifndef INPUT_H
#define INPUT_H

#ifndef STANDARD_LIBRARY_STDIO
#define STANDARD_LIBRARY_STDIO
    #include <stdio.h>
#endif
#ifndef STANDARD_LIBRARY_STDLIB
#define STANDARD_LIBRARY_STDLIB
    #include <stdlib.h>
#endif
#ifndef STANDARD_LIBRARY_UNISTD
#define STANDARD_LIBRARY_UNISTD
    #include <unistd.h>
#endif
#ifndef STANDARD_LIBRARY_STRING
#define STANDARD_LIBRARY_STRING
    #include <string.h>
#endif
#ifndef STANDARD_LIBRARY_CTYPE
#define STANDARD_LIBRARY_CTYPE
    #include <ctype.h>
#endif
#ifndef STANDARD_LIBRARY_WINDOWS
#define STANDARD_LIBRARY_WINDOWS
    #ifdef _WIN32
    #include <windows.h>
    #endif
#endif

/*
    It's enough to use this function once. Do it at the start of the program, 
    and before any output has been printed.

    Without forcing the encoding like this, Unicode characters such as this "▒" 
    are not displayed on Windows. They would be replaced by weird characters.
    I have tried all sorts of things: changing the encoding of the source file, 
    setting the encoding with a compiler flag, even entering commands in the 
    Windows console... The SetConsoleOutputCP() function is the only thing 
    which worked for me.

    Now, when the Windows app is run as administrator, the correct character is 
    displayed, and when not as admin it's simply replaced by a space. The space 
    thing is not ideal, but it's better than garbage. And, the user can just 
    run the app as admin.
*/
#ifndef TERMINAL_UTF8_ENCODING
    #ifdef _WIN32
        #define TERMINAL_UTF8_ENCODING SetConsoleOutputCP(CP_UTF8);
    #else
        #define TERMINAL_UTF8_ENCODING
    #endif
#endif

/*
    ON THE ANDROID OPTION:
    system("clear") works on all Unix-based systems, but it's too heavy 
    compared to the escape character. It creates another process whenever 
    it's called, which is why "clear" is only used on Android, where the 
    escape character doesn't work.

    ---

    ON THE DEFAULT OPTION:
    printf() could have been used, but since no formatting is needed, 
    write() has less overhead and therefore makes more sense here. 

    As for STDOUT_FILENO, it's the macro for the file descriptor.
    STDOUT_FILENO (1) is for the standard output, which is typically 
    connected to the terminal, and is defined on Unix-based systems. 
    The Windows equivalent is STD_OUTPUT_HANDLE (1).
*/
#ifndef CLEAR_TERMINAL
    #ifdef _WIN32
	    #define CLEAR_TERMINAL system("cls");
    #elif defined(__ANDROID__)
	    #define CLEAR_TERMINAL system("clear");
    #else
	    #define CLEAR_TERMINAL write(STDOUT_FILENO, "\033c", 2);
    #endif
#endif

void get_string_input(char* input, const char context[], const char question[], const char choices[]);
int get_number_input(const int min_number, const int max_number, const char question[]);
int get_number_input_amongst_array(const int number_array[], const int array_count, const char question[]);
void flush_stdin(void);
void only_one_greaterthan_sign_is_printed(void);
void press_enter_to_continue(void);

#define INPUT_SIZE    40

#endif

