#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int>::size_type getSoonestBusIndex(vector<int> const& busArrivalTimes, int trainArrivalTime);

vector<int> getBusArrivalTimes();

int getTrainArrivalTime();

int convertToMinutes(int time);

int main() {
    istream::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> busArrivalTimes = getBusArrivalTimes();
    const int trainArrivalTime = getTrainArrivalTime();
    const vector<int>::size_type index = getSoonestBusIndex(busArrivalTimes, trainArrivalTime);

    cout << index << endl;

    return 0;
}

vector<int>::size_type getSoonestBusIndex(vector<int> const& busArrivalTimes, const int trainArrivalTime) {
    int minWaitTime = -1;

    vector<int>::size_type index = 0;
    for (vector<int>::size_type i = 0; i < busArrivalTimes.size(); i++) {
        int min = busArrivalTimes.at(i);
        if (trainArrivalTime < min) {
            continue;
        }

        if (minWaitTime == -1 || trainArrivalTime - min < minWaitTime) {
            minWaitTime = trainArrivalTime - min;
            index = i + 1;
        }
    }
    return index;
}

vector<int> getBusArrivalTimes() {
    vector<int>::size_type busCount;
    cin >> busCount;
    vector<int> busArrivalTimes(busCount);

    int busArrivalTime;
    for (vector<int>::size_type bus = 0; bus < busCount; ++bus) {
        cin >> busArrivalTime;
        busArrivalTimes[bus] = (convertToMinutes(busArrivalTime));
    }
    return busArrivalTimes;
}

int getTrainArrivalTime() {
    int trainArrivalTime;
    cin >> trainArrivalTime;
    trainArrivalTime = convertToMinutes(trainArrivalTime);
    return trainArrivalTime;
}

int convertToMinutes(const int time) {
    return (time / 100) * 60 + (time % 100);
}