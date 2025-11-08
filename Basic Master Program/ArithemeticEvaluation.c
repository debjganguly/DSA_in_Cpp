#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char opstack[100];
int optop=-1;
double valstack[100];
int valtop=-1;

// Push Function for Values
void valpush(int num) {
    valstack[++valtop]=num;
}

// Push Function for Operators
void oppush(char op) {
    opstack[++optop]=op;
}

// Poppping Value from Stack of Values
int valpop() {
    return valstack[valtop--];
}

// Popping Op from Stack of Operators
int oppop() {
    return opstack[optop--];
}

// Performing Calculations and returning the Value
int opapply(int n1, int n2, char op) {
    switch(op) {
        case '+': return n2+n1; 
        case '-': return n2-n1;
        case '*': return n2*n1;
        case '/': return n2/n1; 
        case '^': return pow(n2,n1);
        default: return 0; break;
    }
}

//  Returning Precedence of Characters
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// Calculation of String
double evaluate(char s[]) {
    for(int i=0;s[i]!='\0';i++) {

        char c=s[i];
        // If we get a number like 123, it gets stored in a variable like 1*10*10+2*10+3=123, then pushed into stack
        if(isdigit(c)) {
            double num=0;
            while(isdigit(s[i])) {
                num=num*10+(s[i]-'0');
                i++;
            }
            i--;
            valpush(num);
        }

        // If we get a opening bracket, push into Operator stack
        else if(c=='(') oppush(c);

        // If ch==) we pop items from op and val stack and push the cslculated value back to stack
        else if(c==')') {
            while(optop!=-1 && opstack[optop]!='(') {
                int num1 = valpop();
                int num2 = valpop();
                char op = oppop();

                valpush(opapply(num1,num2,op));
            }
            oppop(); // Popping out the (
        }

        // If the char i am about to enter has a lower or equal precedence to the ones currentky in stack
        else {
            while(optop!=-1 && precedence(opstack[optop])>=precedence(c)) {
                double num1 = valpop();
                double num2 = valpop();
                char op = oppop();
                valpush(opapply(num1,num2,op));
            }
            oppush(c);
        }
    }

    // Calulating the extra things left behind
    while(optop!=-1) {
            double num1 = valpop();
            double num2 = valpop();
            char op = oppop();
            valpush(opapply(num1,num2,op));
    }

    return valstack[valtop];
}

int main() {
    char s[100]; //Initialise Strings
    printf("Enter the Equation exclude spaces: ");
    scanf("%s",s);
    double soln = evaluate(s);
    printf("The answer is: %.2lf",soln);
}