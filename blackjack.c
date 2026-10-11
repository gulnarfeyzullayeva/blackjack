#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int draw_card(void) {
    return rand() % 13 + 1;
} //this function returns random card from 1 to 13

int card_points(int card) {
    if (card == 1) {
        return 1;
    } else if (card >= 2 && card <= 10) {
        return card;
    } else {
        return 10;
    }
} //this returns the points of the card

void print_card(int card) {
    if (card == 1) {
        printf("A");
    } else if (card >= 2 && card <= 10) {
        printf("%d", card);
    } else if (card == 11) {
        printf("J");
    } else if (card == 12) {
        printf("Q");
    } else if (card == 13) {
        printf("K");
    }
} //prints card as A,2-10,J,Q,K

int read_choice(void) {
    int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    while (choice != 1 && choice !=2) {
        printf("Please type 1 or 2.\n");
        printf("Choice: ");
        scanf("%d", &choice);
    }
    return choice;
} //this function reads user choice and asks again untill it is 1 or 2

int player_turn(void) {
    int total = 0;
    int choice = 1;
    printf("\nPLAYER TURN\n");
    while (choice == 1) {
        int card = draw_card();
        printf("You draw: ");
        print_card(card);
        total = total + card_points(card);
        printf("\nYour total: %d\n", total);
        if (total > 21) {
            return total;  //it returns total points, if it exceeds 21
        }
        printf("1. Hit\n2. Stand\n");
        choice = read_choice();
    }
    return total;
} //this is player's turn loop, it returns the player's final total

int dealer_turn(void) {
    int total = 0;
    printf("\nDEALER TURN\n");
    
    while (total < 17) {
        int card = draw_card();
        printf("Dealer draws: ");
        print_card(card);
        total = total + card_points(card);
        printf("\nDealer total: %d\n", total);
    }
    if (total <= 21) {
        printf("Dealer stands.\n");
    }
    return total;
} //dealer draws cards untill reachs 17, it returns the dealer's final total

int play_game(void) {
    int player_total = player_turn();
    if (player_total > 21) {
        printf("BUST! Your total is above 21.\n");
        printf("Dealer wins.\n");
        return -1;
    }

    int dealer_total = dealer_turn();
    if (dealer_total > 21) {
        printf("Dealer busts!\n");
        printf("You win!\n");
        return 1;
    }

    printf("\nPlayer total: %d\n", player_total);
    printf("Dealer total: %d\n", dealer_total);

    if (player_total > dealer_total) {
        printf("You win!\n");
        return 1;
    } else if (dealer_total > player_total) {
        printf("Dealer wins.\n");
        return -1;
    } else {
        printf("Draw!\n");
        return 0;
    }
} //in this part, after one game round, it returns the result: player won=>1, dealer won=>-1, draw=>0

int main(void) {
    srand(time(NULL));
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int choice = 1; //1 means play again
    printf("\n=== SIMPLIFIED BLACKJACK ===\n");
    while(choice == 1) {
        int result = play_game();
        if (result == 1) {
            wins++;
        } else if (result == -1) {
            losses++;
        } else {
            draws++;
        }
        printf("\n1. Play again\n2. Quit\n");
        choice = read_choice();
    } //this loop lets the user play the game as many time as they want
    printf("\nWins: %d, losses: %d, draws: %d\n", wins, losses, draws); //prints total score
    printf("Goodbye!\n");
    return 0;
}
