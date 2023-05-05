#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct C {
    char c;
    struct C *next;
};

int main(void) {
    char s[200];
    int n;

    scanf("%s %d", s, &n);

    struct C *c = (struct C*)malloc(sizeof (struct C));
    c->c = s[0];
    struct C *T = c;

    for(int i = 1; i < strlen(s); ++i) {
        struct C *t = (struct C*)malloc(sizeof (struct C));
        t->c = s[i];
        T->next = t;
        T = t;
    };

    for(int i = 0; i < n; ++i) {
        int index;
        char source[200], target[200];

        scanf("%d %s %s", &index, source, target);

        struct C *p;
        int j = 0;
        for(p = c; j < index; ++j, p = p->next);

        int flag = 0;
        j = 0;
        for(struct C *w = p; j < strlen(source); ++j, w = w->next) {
            if(w->c != source[j]) {
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        for(int i = 0; i < )
    }



    return 0;
}