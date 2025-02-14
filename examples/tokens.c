/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Temirkhan Myrzamadi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <poica.h>

#include <stdio.h>

// clang-format off
ENUM(
    Token,
    VARIANT(MkIdent OF const char *)
    VARIANT(MkInteger OF int)
    VARIANT(MkComma)
    VARIANT(MkPlus)
    VARIANT(MkOpenParen)
    VARIANT(MkCloseParen)
);
// clang-format on

void print_token(Token token) {
    MATCH(&token) {
        CASE(MkIdent, ident) {
            printf("%s", *ident);
        }
        CASE(MkInteger, integer) {
            printf("%d", *integer);
        }
        CASE(MkPlus) {
            printf(" + ");
        }
        CASE(MkOpenParen) {
            printf("(");
        }
        CASE(MkCloseParen) {
            printf(")");
        }
    }
}

int main(void) {
    Token tokens[] = {
        MkOpenParen(),
        MkIdent("x"),
        MkPlus(),
        MkInteger(123),
        MkCloseParen(),
    };

    /*
     * Output:
     * (x + 123)
     */
    for (int i = 0; i < sizeof(tokens) / sizeof(tokens[0]); i++) {
        print_token(tokens[i]);
    }

    puts("");
}
