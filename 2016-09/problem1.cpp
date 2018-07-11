#include <map>
#include <iostream>
#include <string.h>
#include <tuple>

using namespace std;
const int MAX = 1000;
int arr[MAX];

map<char, pair<int, int>> get_distances(char* sentence) {
    map<char, pair<int, int>> distances;
    int i = 0;
    while (i < strlen(sentence)) {
        if (!distances[*(sentence + i)].first) {
            distances[*(sentence + i)].first = i + 1;
        } else {
            distances[*(sentence + i)].second = i + 1;
        }
        i++;
    }
    return distances;
}

pair<int, int> farest_away(char* sentence) {
    int i = strlen(sentence);
    map<char, pair<int, int>> distances = get_distances(sentence);
    pair<int, int> pair_of_farest_away;
    int max_distance = 0;
    char current;
    int distance;

    while (i >= 0) {
        current = *(sentence + i);
        distance = distances[current].second - distances[current].first;
        if (distance >= max_distance) {
            max_distance = distance;
            pair_of_farest_away = distances[current];
        }
        i--;
    }
    return pair_of_farest_away;
}

int main(int argc, const char * argv[]) {
    pair<int, int> result = farest_away("this is just a simple example");
    cout << result.first - 1 << " " << result.second - 1 << " " << result.second - result.first << endl;
    return 0;
}
