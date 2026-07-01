#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 3


typedef struct {
    char question_text[150];
    char options[4][50];
    char correct_option;
} QuizQuestion;

int main() {
    
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. Java", "C. C", "D. C++"},
            'C'
        },
        {
            "What is the correct file extension for a standard C source file?",
            {"A. .cpp", "B. .c", "C. .obj", "D. .exe"},
            'B'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. immutable", "D. const"},
            'D'
        }
    };

    char user_guess;
    int current_score = 0;

    printf("==========================================\n");
    printf("     WELCOME TO THE C PROGRAMMING QUIZ    \n");
    printf("==========================================\n\n");

    
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question_text);
        
        // Print out the 4 multiple-choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        
        printf("Your Answer (A, B, C, or D): ");
        
        scanf(" %c", &user_guess); 
        
        
        user_guess = toupper(user_guess);

        
        if (user_guess == quiz[i].correct_option) {
            printf("\n Correct!\n\n");
            current_score++;
        } else {
            printf("\n Wrong! The correct answer was %c.\n\n", quiz[i].correct_option);
        }
        printf("------------------------------------------\n");
    }

    
    float final_percentage = ((float)current_score / TOTAL_QUESTIONS) * 100;

    printf("\n==========================================\n");
    printf("               QUIZ OVER!                 \n");
    printf("==========================================\n");
    printf("Final Score: %d out of %d\n", current_score, TOTAL_QUESTIONS);
    printf("Percentage: %.2f%%\n", final_percentage);
    printf("==========================================\n");

    return 0;
}
