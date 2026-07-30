#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prodDelivery(vector<int> orderID) {
    vector<int> answer;
    
    for (int id : orderID) {
        int totalProducts = 0;
        
        // Handle the special case where orderID is 0
        if (id == 0) {
            totalProducts = 0;
        } else {
            // Extract each digit and sum them up
            while (id > 0) {
                totalProducts += id % 10;
                id /= 10;
            }
        }
        
        answer.push_back(totalProducts);
    }
    
    return answer;
}
