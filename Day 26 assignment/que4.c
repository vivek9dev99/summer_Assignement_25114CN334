//wap to create quiz application

#include <stdio.h>
#include <ctype.h>

struct Question {
    char text[256];
    char options[4][64];
    char correct;
};

int main() {
    struct Question quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. C", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the size of an int data type in C (standard 32-bit system)?",
            {"A. 2 Bytes", "B. 4 Bytes", "C. 8 Bytes", "D. 1 Byte"},
            'B'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. const", "D. mutable"},
            'C'
        }
    };

    int score = 0;
    char guess;

    printf("=== WELCOME TO THE C QUIZ GAME ===\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Your answer (A, B, C, or D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess == quiz[i].correct) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n\n", quiz[i].correct);
        }
    }

    printf("=== QUIZ OVER ===\n");
    printf("Your Final Score: %d out of 3\n", score);

    return 0;
}
