#include <stdio.h>
#include <ctype.h>

typedef enum {
    NUMBER,
    ADD,
    SUB,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    END
} TokenType;

TokenType current_token;
int current_number;

void next_token() {
    int c;
    while ((c = getchar()) == ' ' || c == '\t');

    if (c == EOF || c == '\n' || c == '\r') {
        current_token = END;
        return;
    }

    if (isdigit(c)) {
        current_number = 0;
        do {
            current_number = current_number * 10 + (c - '0');
            c = getchar();
        } while (isdigit(c));
        ungetc(c, stdin);
        current_token = NUMBER;
        return;
    }

    switch(c) {
        case '+': current_token = ADD; break;
        case '-': current_token = SUB; break;
        case '*': current_token = MUL; break;
        case '/': current_token = DIV; break;
        case '(': current_token = LPAREN; break;
        case ')': current_token = RPAREN; break;
    }
    getchar();
}

int expr();

int factor() {
    int result;
    if (current_token == SUB) {
        next_token();
        result = -factor();
    } else if (current_token == NUMBER) {
        result = current_number;
        next_token();
    } else if (current_token == LPAREN) {
        next_token();
        result = expr();
        next_token(); // пропускаем RPAREN
    }
    return result;
}

int term() {
    int result = factor();
    while (current_token == MUL || current_token == DIV) {
        TokenType op = current_token;
        next_token();
        int rhs = factor();
        result = (op == MUL) ? result * rhs : result / rhs;
    }
    return result;
}

int expr() {
    int result = term();
    while (current_token == ADD || current_token == SUB) {
        TokenType op = current_token;
        next_token();
        int rhs = term();
        result = (op == ADD) ? result + rhs : result - rhs;
    }
    return result;
}

int main() {
    next_token();
    int result = expr();
    printf("%d\n", result);
    return 0;
}
