#include <iostream>
#include <bits/stdc++.h>

// https://vjudge.net/problem/UVA-11559

using namespace std;

struct Hotel {
    int price;
    vector<int> beds;
};

vector<Hotel> filterHotelsByAmountBeds(vector<Hotel> hotels, int numberOfParticipants) {
    vector<Hotel> acc;

    for (Hotel hotel: hotels){
        if(hotel.beds[0] >= numberOfParticipants){
            acc.push_back(hotel);
        }
    }

    return acc;
}

bool compareHotelsByPrice(Hotel a, Hotel b) {
        return a.price < b.price;
}

int main() {

    int numberOfParticipants, budget, numberOfHotels, numberOfweeks;
    while (cin >> numberOfParticipants >> budget >> numberOfHotels >> numberOfweeks){
        vector<Hotel> hotels;

        for (int i = 0; i < numberOfHotels; ++i) {
            Hotel hotel;
            cin >> hotel.price;

            for (int j = 0; j < numberOfweeks; ++j) {
                int bed;
                cin >> bed;
                hotel.beds.push_back(bed);
            }
            sort(hotel.beds.begin(), hotel.beds.end(), greater<int>());
            hotels.push_back(hotel);
        }

        vector<Hotel> filterHotels = filterHotelsByAmountBeds(hotels, numberOfParticipants);
        sort(filterHotels.begin(), filterHotels.end(), compareHotelsByPrice);

        if(filterHotels.empty()){
            cout << "stay home" << endl;
        }
        else {
            int result = filterHotels[0].price * numberOfParticipants;

            if(result > budget){
                cout << "stay home" << endl;
            }
            else {
                cout << result << endl;
            }
        }

    }

    return 0;
}
