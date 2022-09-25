/* Simple Fighter

This is a simple fighter game.
Don't expect so many functionalities.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// These values will never change!
#define PUNCH 5
#define KICK 10
#define HADOUKEN 20
#define SHORYUKEN 30
#define SENPUKYAKU 25
#define BLOCK 1

// Some global variables to call outside of their functions
int i;
int user_health;
int comp_health;

void game_info(void);
void char_select(void);
void fight(void);
void game_over(void);
void replay(void);

// Fancy ASCII intro screen
void game_info(void) {
  sleep(1);
  printf("\n\n");
  printf("\n  #####                                   #######                  "
         "                   ");
  printf("\n #     # # #    # #####  #      ######    #       #  ####  #    # "
         "##### ###### #####  ");
  printf("\n #       # ##  ## #    # #      #         #       # #    # #    #  "
         " #   #      #    # ");
  printf("\n  #####  # # ## # #    # #      #####     #####   # #      ######  "
         " #   #####  #    # ");
  printf("\n       # # #    # #####  #      #         #       # #  ### #    #  "
         " #   #      #####  ");
  printf("\n #     # # #    # #      #      #         #       # #    # #    #  "
         " #   #      #   #  ");
  printf("\n  #####  # #    # #      ###### ######    #       #  ####  #    #  "
         " #   ###### #    # ");
  printf("\n\n");
  sleep(1);
}

// Character selection screen. It can be expanded with new fighters in the
// future.
void char_select(void) {
  extern int i;
  printf("\nPlease select your figher from the list.\n");
  printf("\n1 - Ryu\n2 - Ken\n\n1 or 2? ");
  scanf("%d", &i);

  if (i == 1) {
    printf("\nYour fighter is Ryu!");
  } else {
    printf("\nYour fighter is Ken!");
  }
}


// This is where the fight happens!
void fight(void) {
  int selection;
  int comp_move;
  extern int user_health;
  extern int comp_health;

  user_health = 100;
  comp_health = 100;

  while (comp_health > 0) {
    printf("\nSelect your move!");
    printf(
        "\n1 - Punch\n2 - Kick\n3 - Hadouken\n4 - Shoryuken\n5 - Senpukyaku");
    printf("\nID: ");
    scanf("%d", &selection);

    if (selection == 1) {
      comp_move = (rand() % 1 + 1);
      if (comp_move == 1) {
        comp_health -= PUNCH;
        printf("\nYou punch is landed well!");
        printf("\nHealth: %d", comp_health);
      } else {
        comp_health -= BLOCK;
        printf("\nYour punch is blocked!");
        printf("\nHealth: %d", comp_health);
      }
    } else if (selection == 2) {
      comp_move = (rand() % 1 + 1);
      if (comp_move == 1) {
        comp_health -= KICK;
        printf("\nYour kick is hit the nuts!");
        printf("\nHealth: %d", comp_health);
      } else {
        comp_health -= BLOCK;
        printf("\nYour kick is well blocked!");
        printf("\nHealth: %d", comp_health);
      }
    } else if (selection == 3) {
      comp_move = (rand() % 1 + 1);
      if (comp_move == 1) {
        comp_health -= HADOUKEN;
        printf("\nYour hadouken is landed well");
        printf("\nHealth: %d", comp_health);
      } else {
        comp_health -= BLOCK;
        printf("\nYour hadouken is blocked!");
        printf("\nHealth: %d", comp_health);
      }
    } else if (selection == 4) {
      comp_move = (rand() % 1 + 1);
      if (comp_move == 1) {
        comp_health -= SHORYUKEN;
        printf("\nYour shoryuken is landed well!");
        printf("\nHealth: %d", comp_health);
      } else {
        comp_health -= BLOCK;
        printf("\nYour shoryuken is blocked!");
        printf("\nHealth: %d", comp_health);
      }
    } else if (selection == 5) {
      comp_move = (rand() % 1 + 1);
      if (comp_move == 1) {
        comp_health -= SENPUKYAKU;
        printf("\nYour senpukyaku is landed well!");
        printf("\nHealth: %d", comp_health);
      } else {
        comp_health -= BLOCK;
        printf("\nYour senpukyaku is blocked!");
        printf("\nHealth: %d", comp_health);
      }
    };

    if (comp_move == (rand() % 5 + 1)) {
      if (comp_move == 1) {
        user_health -= PUNCH;
        printf("\nYou're punched!");
        printf("\nYour Health: %d", user_health);
      } else {
        user_health -= BLOCK;
        printf("\nYou blocked punch!");
        printf("\nYour Health: %d", user_health);
      }
    } else if (comp_move == (rand() % 5 + 1)) {
      if (comp_move == 2) {
        user_health -= KICK;
        printf("\nYou're kicked in the nuts!");
        printf("\nYour Health: %d", user_health);
      } else {
        user_health -= BLOCK;
        printf("\nYou blocked the kick!");
        printf("\nYour Health: %d", user_health);
      }
    } else if (comp_move == (rand() % 5 + 1)) {
      if (comp_move == 3) {
        user_health -= HADOUKEN;
        printf("\nYou hit by a hadouken!");
        printf("\nYour Health: %d", user_health);
      } else {
        user_health -= BLOCK;
        printf("\nYou blocked the hadouken!");
        printf("\nYour Health: %d", user_health);
      }
    } else if (comp_move == (rand() % 5 + 1)) {
      if (comp_move == 4) {
        user_health -= SHORYUKEN;
        printf("\nYou hit by a shoryuken!");
        printf("\nYour Health: %d", user_health);
      } else {
        user_health -= BLOCK;
        printf("\nYou blocked the shoryuken!");
        printf("\nYour Health %d", user_health);
      }
    } else if (comp_move == (rand() % 5 + 1)) {
      if (comp_move == 5) {
        user_health -= SENPUKYAKU;
        printf("\nYou hit by senpukyaku!");
        printf("\nYour Health: %d", user_health);
      } else {
        user_health -= BLOCK;
        printf("\nYou blocked senpukyaku!");
        printf("\nYour Health: %d", user_health);
      }
    };
  };
}

// Lazy replay.
void replay(void) {
  int k;
  printf("\nWould you like to replay?");
  printf("\n1 - Yes\n2 - No\n");
  scanf("%d", &k);

  if (k == 1) {
    char_select();
    fight();
  } else {
    printf("\nThank you for playing!");
  }
}

int main(void) {
  game_info();
  char_select();
  fight();

  // I need to find a better way to create a replay screen. Below is just temporary.
  int j;
  if (user_health > 0 && comp_health <= 0) {
    printf("\n\nYou won!");
    printf("\nWould you like to play again?");
    printf("\n1 - Yes\n2 - No\n");
    scanf("%d", &j);

    if (j == 1) {
      char_select();
      fight();
    } else {
      printf("\nThank you for playing!\n");
      exit(0);
    }
  } else {
    printf("\nYou lost!");
    printf("\nWould you like to play again?");
    printf("\n1 - Yes\n2 - No\n");
    scanf("%d", &j);

    if (j == 1) {
      char_select();
      fight();
    } else {
      printf("\nThank you for playing!\n");
      exit(0);
    }
  };

  replay();

  return 0;
}
