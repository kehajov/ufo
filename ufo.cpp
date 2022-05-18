#include <iostream>
#include "ufo_functions.hpp"
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  while (true)
  {
    srand(time(NULL));
    std::vector<std::string> codewords = {"volvo", "nissan", "volkswagen", "renault", "saab", "dacia"};
    int random = rand() % codewords.size();
    std::string codeword = codewords[random];
    // std::string codeword = codewords.rand();
    std::string answer = "";
    for (int i = 0; i < codeword.length(); i++)
    {
      answer += "_";
    }
    // std::string answer = "__________";
    int misses = 0;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;

    greet();

    while (answer != codeword && misses < 7)
    {
      display_misses(misses);

      display_status(incorrect, answer);

      std::cout << "Please enter your guess: ";
      std::cin >> letter;
      std::cout << "\n";

      for (int i = 0; i < codeword.length(); i++)
      {
        if (tolower(letter) == codeword[i])
        {
          answer[i] = tolower(letter);
          guess = true;
        }
      }

      if (guess)
      {
        std::cout << "Correct!\n";
      }
      else
      {
        std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
        incorrect.push_back(letter);
        misses++;
      }
      std::cout << guess << "\n";
      guess = false;
    }

    end_game(answer, codeword);

    char new_game;
    std::cout << "\nDo you want to play again? y/n: ";
    std::cin >> new_game;
    std::cout << "\n";

    if (new_game == 'y')
    {
      continue;
    }
    else
    {
      return 1;
      break;
    }
  }
}
