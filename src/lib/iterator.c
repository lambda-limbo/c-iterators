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

#include "iterator.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct iterator_s {
    size_t size;
    list_t *begin;
    list_t *end;
    list_t *list;
};

iterator_t *iterator_new(list_t *l) {

    if (l == NULL) {
        fprintf(stderr, "Error creating the iterator, see ERR001.\n");
        return NULL;
    }

    iterator_t *it = malloc(sizeof(iterator_t));

    if (it == NULL) {
        fprintf(stderr, "Error creating the iterator, see ERR002.\n");
    }

    it->list = l;
    it->begin = l;
    it->size = iterator_size(it);
    it->end = l;

    return it;
}


void iterator_free(iterator_t *it) {
    free(it);
}

void iterator_reset(iterator_t *it) {

    it->list = it->begin;
}

size_t iterator_size(iterator_t* it) {

    list_t *l = it->list;

    it->size = 0;

    while (l->next != NULL) {
        it->size++;
        l = l->next;
    }

    return it->size;
}

bool iterator_next(iterator_t const *it) {

    if (it == NULL) {
        fprintf(stderr, "Error trying to evaluate the iterator, see ERR001.\n");
        return false;
    }

    if (it->list == NULL) {
        return false;
    }

    return true;
}

char *iterator_eval(iterator_t *it) {

    if (it == NULL) {
        fprintf(stderr, "Error evaluating the iterator, see ERR001.\n");
        return NULL;
    }

    if (it->list == NULL) {
        fprintf(stderr, "The iterator is ill constructed, construct it again\n");
    }

    char *ret = it->list->value;

    it->list = it->list->next;

    return ret;
}
