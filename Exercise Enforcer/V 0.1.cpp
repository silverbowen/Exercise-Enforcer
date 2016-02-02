#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>
using namespace std;

int main()
{
    string exercise = "";

    int interval = 0,
        reps = 3;

    time_t current_time = 0,
           target_time = 0;

    while (interval <= 0)
    {
        cout << "Enter your exercise: ";
        getline(cin, exercise);


        cout << "Enter interval (in minutes): ";
        cin >> interval;
        cin.get();  // clear buffer of \n

        if (interval <= 0) cout << "Interval must be positive!";
        // mild error checking
    }

    time(&current_time);
    time(&target_time);
    target_time += interval * 60;

    for (int i = 0; i < reps; ++i)
    {
        cout << '\a' << "\n" << exercise << "!!! - Time for rep #" << i+1 << endl;

        if (i < reps -1)
        {
            cout << "Hit enter when you've exercised to start next countdown.\n";
            cin.get();
            cout << "Next rep in " << interval << " minutes...\n\n";

            int countdown = interval * 60;
            while (countdown > 0)
            {
                cout << countdown << "\n";

                if (countdown > 10)
                {
                    sleep(interval*10);
                    countdown -= 10;
                }

                else
                {
                    --countdown;
                    sleep(interval);
                }
            }

        }

        else
        {
            cout << "Hit enter when you've exercised to end program.\n";
            cin.get();
            cout << "Congrats! You are done!\n";
        }
    }
}
