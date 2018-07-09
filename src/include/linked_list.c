/**
 * MIT License
 *
 * Copyright (c) 2018 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_s {
    char value[64];
    list_t *next;
};

list_t *list_init(const char *value) {

    list_t *l = malloc(sizeof(list_t));

    if (l == NULL) {
        fprintf(stderr, "ERR: The list couldn't be created\n");
        exit(EXIT_FAILURE);
    }

    strcpy(l->value, value);
    l->next = NULL;

    return l;
}

list_t *list_push(list_t *l, const char *value) {

    if (l == NULL) {
        l = list_init(value);
        return l;
    }

    list_t *tmp = l;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    list_t *e = malloc(sizeof(list_t));

    strcpy(e->value, value);
    e->next = NULL;

    tmp->next = e;

    return l;
}

const char *list_head(const list_t *l) {
    return l->value;
}

const list_t *list_search(list_t *l, const char *value) {

    if (l == NULL) {
        fprintf(stdout, "WARN: Can't find any value on an empty list.\n");
        return NULL;
    }

    while (l->next != NULL) {
        if (strcmp(l->value, value) == 0) {
            return l;
        }

        l = l->next;
    }

    return NULL;
}

void list_free(list_t *list) {

    // element pointer
    list_t *e = list;
    // previous pointer
    list_t *p;

    while(e->next != NULL) {
        p = e;
        e = e->next;
        free(p);
    }

    free(e);
}
