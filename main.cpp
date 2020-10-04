/*
 * Chase Urban
 * Homework 2 - training.cpp
 * COMPSCI 355-01
 * Due 9/25/2020
 */

#include <iostream>

using namespace std;

/**
 * One argument getDays function, our needed  recurrence relation requires two
 * arguments, for our purposes, at first, they will always be the same number.
 * Therefore, for simplicity's sake, this one argument function just calls the two
 * argument function using the one given parameter for both arguments of the
 * two-argument function.
 *
 * @param dist - distance to calculate the number of days needed for new workout plan
 * @return number of days needed for the specific distance
 */
int getDays(int dist);

/**
 * Two argument getDays function, calculates the recurrence relationship described as
 * "a new workout strategy", where  one "runs N miles fast every day, but not all at
 * once, but broken up into intervals with short rests between them" In reality, the
 * number of "days needed" to complete all different combinations of distances per the
 * assignment is the partition of the number being used to represent the total number
 * of miles planned to train for.
 *
 * The partition recurrence relationship I used in this function is modeled from a work
 * by R. Honsberger, found at reference point (59) at
 * https://mathworld.wolfram.com/PartitionFunctionP.html
 *
 * @param dist - the distance to calculate the number of days needed for the new workout
 * @param lrgInterval - the largest interval,
 * @return number of days needed for the specified arguments
 */
int getDays(int dist, int lrgInterval);

int main() {
    for (int i = 0; i < 100; i++) {
        int d;
        cout << "Enter race distance in miles: ";
        cin >> d;
        cout << "Length of training schedule: " << getDays(d) << " days" << endl << endl;
    }
}

int getDays(int dist){
    return getDays(dist, dist);
}

int getDays(int dist, int lrgInterval){

    /*
     * If distance is less than zero, or the largest possible interval is 0, that
     * means there can not be any permutations of the given distance and largest
     * interval, hence return 0
     */
    if (dist < 0 || lrgInterval == 0)
        return 0;

    /*
     * If the distance is 0, or the largest possible interval is 1, that means there is
     * only one possible permutation, either {0} in the case of dist == 0, or {dist}
     * when lrgInterval == 1, hence return 1
     */
    else if (dist == 0 || lrgInterval == 1)
        return 1;

    /*
     * Otherwise, we will return the addition of the two recurring calls to this
     * function, as per the partition recurrence relation.
     */
    else
        return getDays(dist, lrgInterval - 1)
                + getDays(dist - lrgInterval, lrgInterval);
}