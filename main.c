#include <stdio.h>

#define TAPE_SIZE 30000

void interpret(const char *code) {
    char tape[TAPE_SIZE] = {0};
    char *ptr = tape;
    const char *c = code;

    while (*c) {
        switch (*c) {
            case '>':
                ptr++;
                if (ptr >= tape + TAPE_SIZE) {
                    ptr = tape;
                }
                break;
            case '<':
                ptr--;
                if (ptr < tape) {
                    ptr = tape + TAPE_SIZE - 1;
                }
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (!*ptr) {
                    int loop_counter = 1;
                    while (loop_counter > 0) {
                        c++;
                        if (*c == '[') {
                            loop_counter++;
                        } else if (*c == ']') {
                            loop_counter--;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr) {
                    int loop_counter = 1;
                    while (loop_counter > 0) {
                        c--;
                        if (*c == ']') {
                            loop_counter++;
                        } else if (*c == '[') {
                            loop_counter--;
                        }
                    }
                }
                break;
        }
        c++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <brainfuck code>\n", argv[0]);
        return 1;
    }

    interpret(argv[1]);
    return 0;
}