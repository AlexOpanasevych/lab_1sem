#include "stdio.h"

#include "string.h"



#define DIGIT_ROWS 6

#define DIGIT_CHARS 6



int main(int argc, char **args) {

    const char tpl[][DIGIT_ROWS][DIGIT_CHARS + 1] = {

            {

                    " 0000 ",

                    " 0  0 ",

                    " 0  0 ",

                    " 0  0 ",

                    " 0  0 ",

                    " 0000 ",

            },

            {

                    "  1   ",

                    " 11   ",

                    "  1   ",

                    "  1   ",

                    "  1   ",

                    " 111  ",

            },

            {

                    " 2222 ",

                    "    2 ",

                    " 2222 ",

                    " 2    ",

                    " 2    ",

                    " 2222 ",

            },

            {

                    " 3333 ",

                    "    3 ",

                    " 3333 ",

                    "    3 ",

                    "    3 ",

                    " 3333 ",

            },

            {

                    " 4  4 ",

                    " 4  4 ",

                    " 4444 ",

                    "    4 ",

                    "    4 ",

                    "    4 ",

            },

            {

                    " 5555 ",

                    " 5    ",

                    " 5555 ",

                    "    5 ",

                    "    5 ",

                    " 5555 ",

            },

            {

                    " 6666 ",

                    " 6    ",

                    " 6666 ",

                    " 6  6 ",

                    " 6  6 ",

                    " 6666 ",

            },

            {

                    " 7777 ",

                    "    7 ",

                    "   7  ",

                    "  7   ",

                    " 7    ",

                    " 7    ",

            },

            {

                    " 8888 ",

                    " 8  8 ",

                    " 8888 ",

                    " 8  8 ",

                    " 8  8 ",

                    " 8888 ",

            },

            {

                    " 9999 ",

                    " 9  9 ",

                    " 9999 ",

                    "    9 ",

                    "    9 ",

                    " 9999 ",

            },

    };



    for (int j = 0; j < DIGIT_ROWS; ++j) {

        for (int i = 0; i < strlen(args[1]); ++i) {

            int digit = args[1][i] - 48;

            printf("%s  ", tpl[digit][j]);

        }

        printf("\n");

    }



    return 0;

}