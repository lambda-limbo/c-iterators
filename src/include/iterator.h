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

#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stddef.h>


// This is a linked list iterator
#include "linked_list.h"

#define ERR001 "Null pointer"
#define ERR002 "Could not allocate memory"

//
typedef struct iterator iterator_t;

/**
 * @brief Constructs a new iterator from the list and returns a pointer to the
 * newly created iterator.
 */
iterator_t *iterator_new(list_t *);
/**
 * @brief Free a created iterator.
 */
void iterator_free(iterator_t *);
/**
 * @brief Resets the iterator to its begin position.
 */
void iterator_reset(iterator_t *);
/**
 * @brief Returns the size of the underlying list.
 */
size_t iterator_size(iterator_t *);
/**
 * @brief A method that returns true if it has another element on the list or
 * false otherwise, in addition to that it also goes forward on the list as it
 * iterates if the true statement is verified. It does not modify the
 * pointer passed as parameter to the method.
 */
bool iterator_next(iterator_t const *);
/**
 * @brief Evaluates the value of the current iterator and if there is a next
 * node from the iterator it goes to the next.
 */
char *iterator_eval(iterator_t *);

#endif // ITERATOR_H
