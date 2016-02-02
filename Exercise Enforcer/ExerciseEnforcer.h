#pragma once
#include <string>

class ExerciseEnforcer
{
public:
    ExerciseEnforcer();
    ExerciseEnforcer(const std::string& exercise, int interval, int reps);
    void setExercise(const std::string& exercise);
    void setInterval(int interval);
    void setReps(int reps);
    const std::string& getExercise() const;
    int getInterval() const;
    int getReps() const;

protected:
private:
    std::string exercise;
    int interval, reps;
};
