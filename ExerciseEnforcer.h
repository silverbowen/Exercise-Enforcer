#pragma once
#include <string>
#include <iostream>
#include <limits>

class ExerciseEnforcer
{
public:
    ExerciseEnforcer();
    ExerciseEnforcer(const std::string& exercise, int interval, int reps);
    void setExercise(const std::string& exercise);
    void setInterval(int interval);
    void setReps(int reps);
    void readExercise(std::istream& input); // write istream directly to myEE.exercise
    void readInterval(std::istream& input); // ditto myEE.interval
    void readReps(std::istream& input);     // ditto myEE.reps
    const std::string& getExercise() const;
    int getInterval() const;
    int getReps() const;

protected:
private:
    std::string exercise = "exercise not defined";
    int interval = 0, reps = 0;
};
