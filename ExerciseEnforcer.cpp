#include "ExerciseEnforcer.h"

ExerciseEnforcer::ExerciseEnforcer() {} //ctor

ExerciseEnforcer::ExerciseEnforcer(const std::string& exercise, int interval, int reps)
    : exercise(exercise), interval(interval), reps(reps) {} //ctor

void ExerciseEnforcer::setExercise(const std::string& exercise)
{
    this->exercise = exercise;
}
void ExerciseEnforcer::setInterval(int interval)
{
    this->interval = interval;
}
void ExerciseEnforcer::setReps(int reps)
{
    this->reps = reps;
}

void ExerciseEnforcer::readExercise(std::istream& input)
{
    getline(input, this->exercise);
}
void ExerciseEnforcer::readInterval(std::istream& input)
{
    input >> this->interval;
    std::cin.clear();  // reset stream and ignore, prevents bad input screen loop
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ExerciseEnforcer::readReps(std::istream& input)
{
    input >> this->reps;
    std::cin.clear();  // reset stream and ignore, prevents bad input screen loop
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string& ExerciseEnforcer::getExercise() const
{
    return exercise;
}
int ExerciseEnforcer::getInterval() const
{
    return interval;
}
int ExerciseEnforcer::getReps() const
{
    return reps;
}
