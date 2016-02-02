#include "ExerciseEnforcer.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

void countdown(const int interval);

int main()
{
    ExerciseEnforcer myEE; // create ExerciseEnforcer object
    string exercise = ""; // holding variable
    int interval = 0, // holding variable
        reps = 0; // holding variable
    time_t current_time = 0, // to time the interval
           target_time = 0; // to time the interval

    while (exercise == "") // while loop gets exercise
    {
        cout << "Enter the name of the exercise: ";
        getline(cin, exercise);
        if (exercise == "") cout << "\nExercise can't be blank!\n\n";
        // mild error checking
    }
    myEE.setExercise(exercise);

    while (reps <= 0) // while loop gets reps
    {
        cout << "Enter number of reps: ";
        cin >> reps;
        cin.get();  // clear buffer of \n
        if (reps <= 0) cout << "\nReps must be positive!\n\n";
        // mild error checking
    }
    myEE.setReps(reps);

    while (interval <= 0) // while loop gets interval
    {
        cout << "Enter interval (in minutes): ";
        cin >> interval;
        cin.get();  // clear buffer of \n
        if (interval <= 0) cout << "\nInterval must be positive!\n\n";
        // mild error checking
    }
    myEE.setInterval(interval);

    time(&current_time);
    time(&target_time);
    target_time += myEE.getInterval() * 60;

    for (int i = 0; i < myEE.getReps(); ++i)
    {
        cout << "\n" << myEE.getExercise() << "!!! - Time for rep #" << i+1 << endl;
        // needs a way to sound a tone here!! (or otherwise do an alarm)

        if (i < myEE.getReps() - 1)
        {
            cout << "Hit enter when you've exercised to start the countdown to the next rep.\n";
            cin.get();
            cout << "Next rep in " << myEE.getInterval() << " minutes...\n\n";

            countdown(myEE.getInterval()); // initiate countdown
        }

        else
        {
            cout << "Hit enter when you've exercised to end program.\n";
            cin.get();
            cout << "Congrats! You are done!\n";
        }
    }
}
void countdown (const int interval)
{
    int countdown = interval * 60; // initialize countdown

    while (countdown > 60) // countdown in minutes until 60 seconds is reached
    {
        sleep(60);
        countdown -= 60;
        cout << countdown / 60 << " minutes\n";
    }

    while (countdown > 0) // countdown in seconds until 0 seconds is reached
    {
        --countdown;
        sleep(1);
        cout << countdown << " seconds\n";
    }
}
