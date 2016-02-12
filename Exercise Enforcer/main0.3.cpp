#include "ExerciseEnforcer.h"
#include <time.h>
#include <unistd.h>
#include <SFML/Audio.hpp>

void countdown(const int interval);

int main()
{
    ExerciseEnforcer myEE; // create ExerciseEnforcer object

    time_t current_time = 0, // to time the interval
           target_time = 0; // to time the interval

    do // while loop gets exercise
    {
        std::cout << "Enter the name of the exercise: ";
        myEE.readExercise(std::cin);
        if (myEE.getExercise() == "")
            std::cout << "\nExercise can't be blank!\n\n"; // mild error checking
    }
    while (myEE.getExercise() == "");   // repeat if blank

    do // while loop gets reps
    {
        std::cout << "Enter number of reps: ";
        myEE.readReps(std::cin);
        if (myEE.getReps() <= 0)
            std::cout << "\nReps must be positive!\n\n"; // mild error checking
    }
    while (myEE.getReps() <= 0);

    do // while loop gets interval
    {
        std::cout << "Enter interval (in minutes): ";
        myEE.readInterval(std::cin);
        if (myEE.getInterval() <= 0)
            std::cout << "\nInterval must be positive!\n\n"; // mild error checking
    }
    while (myEE.getInterval() <= 0);

    time(&current_time);
    time(&target_time);
    target_time += myEE.getInterval() * 60;

    for (int i = 1; i <= myEE.getReps(); ++i)
    {
        std::cout << "\n" << myEE.getExercise() << "!!! - Time for rep #" << i << "\n";

        if (i < myEE.getReps())
        {
            std::cout << "Hit enter when you've exercised to start the countdown to rep #"
                      << i + 1 << ".\n";
            std::cin.get();
            std::cout << "Rep #" << i + 1 << " in " << myEE.getInterval() << " minutes...\n\n";

            countdown(myEE.getInterval()); // initiate countdown
        }

        else
        {
            std::cout << "Hit enter when you've exercised to end program.\n";
            std::cin.get();
            std::cout << "Congrats! You're done!\n";
        }
    }
} // end main

void countdown (const int interval)
{
    int countdown = interval * 60; // initialize countdown
    sf::SoundBuffer beepBuffer, alarmBuffer;
    sf::Sound alarm, beep;

    if (!beepBuffer.loadFromFile("beep.wav"))
        std::cout << "beep.wav not found!";
    if (!alarmBuffer.loadFromFile("alarm.wav"))
        std::cout << "alarm.wav not found!";

    beep.setBuffer(beepBuffer);

    alarm.setLoop(true);
    alarm.setBuffer(alarmBuffer);

    while (countdown > 60) // countdown in minutes until 60 seconds is reached
    {
        sleep(60);
        countdown -= 60;
        std::cout << countdown / 60 << " minutes\n";
    }

    while (countdown > 1) // countdown in seconds until 1 seconds is reached
    {
        --countdown;
        sleep(1);
        std::cout << countdown << " seconds\n";
        if (countdown <= 10) beep.play();
    }

    sleep(1); // countdown last second
    std::cout << "\nHit enter to stop alarm!";

    do
    {
        alarm.play();
    }
    while (std::cin.get()!='\n');
}
