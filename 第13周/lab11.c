#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct Card Card;
typedef struct CardStack CardStack;

struct Card {
    char suit;
    char rank;
};

Card *createCard(char *s) {
    Card card;
    card.suit = s[0];
    card.rank = s[1];
}

int cardComp(Card a, Card b) {
    return (a.rank == b.rank || a.suit == b.suit);
}

struct CardStack {
    int top;
    Card **stack;
};

void push(CardStack *stack, Card *card) {
    // if(top == N-1)
    //     return;
    // printf("Overflow State: can't add more elements into the stack\n");
    stack->top++;
    stack->stack[stack->top] = card;
}

Card *peek(CardStack *stack) {
    return stack->stack[stack->top];
}

int isEmpty(CardStack *stack) {
    return stack->top == -1;
}

CardStack *arrayCardStack;

int main(void) {
    arrayCardStack = (CardStack*)malloc(52 * sizeof(CardStack));

    for(int i = 0; i < 52; ++i) {
        arrayCardStack[i].top = -1;
    }

    char s[3 * 26 + 10000];
    int counter = 0;

    
    while(scanf("%s", s)) {
        if(s[0] == '#') break;        
        
        int top = -1;

        top++;

        int *temp = &arrayCardStack[top].top;

        arrayCardStack[top].stack[*temp]->rank = s[0];
        arrayCardStack[top].stack[*temp]->suit = s[1];

        *temp++;
        printf("%s\n", s);
    }

    return 0;
}