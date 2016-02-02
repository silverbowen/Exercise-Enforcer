#include "ExerciseEnforcer.h"
using namespace std;

ExerciseEnforcer::ExerciseEnforcer()
    : exercise("Not specified"), interval(0), reps(0) {} //ctor

ExerciseEnforcer::ExerciseEnforcer(const string& exercise = "Not Defined", int interval = 0, int reps = 0)
    : exercise(exercise), interval(interval), reps(reps) {} //ctor

void ExerciseEnforcer::setExercise(const string& exercise)
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

const string& ExerciseEnforcer::getExercise() const
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

