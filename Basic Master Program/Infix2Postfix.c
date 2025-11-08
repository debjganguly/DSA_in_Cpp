#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int MAX=100;
int stack[100];
int top=-1;

int isEmpty() {
    return top==-1;
}
void push(char c) {
    if(top==MAX-1) {
        printf("Stack Overflow\n");
        return;
    } else {
        stack[++top]=c;
    }
}

char pop() {
    if(top==-1) {printf("Stack is Empty\n"); return ' ';}
    else {top--;}
    return stack[top+1];
}

char peek() {
    if(top==-1) {
        printf("Stack is Empty\n");
        return ' ';
    } else {
        return stack[top];
    }
}

int precedence(char c) {
    if(c=='+'|| c=='-') return 1;
    else if(c=='*' || c=='/') return 2;
    else if(c=='^') return 3;
    else return 0;
}

void Infix2Postfix(char in[]) {
    int i=0;
    while(in[i]!='\0') {
        char c = in[i++];

        if(isalnum(c)) {printf("%c",c);}
        else if(c=='(') {push(c);}
        else if(c==')') {
            while(top!=-1 && stack[top]!='(') { printf("%c",pop());}
        }
        else {
            while(!isEmpty() && precedence (peek())>=precedence(c)) {
                printf("%c",pop());
            }
            push(c);
        }
    }

    while(!isEmpty()) printf("%c",pop());
}

int main() {
    char in[MAX];

    // Asking for Expression without any space
    printf("Enter infix expression (Ignore entering Spaces): ");
    scanf("%s", in);

    printf("The Infix Expression is: %s\n", in);
    printf("The Postfix Expression is: ");
    Infix2Postfix(in);
}