#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Structure to elegantly organize customer information
struct Buyer {
    int id;
    int wantedQuantity;
    int bidPrice;
    int orderTime;
    int itemsReceived;
};

vector<int> getUnfulfilledCustomers(vector<vector<int>> requests, int totalInventory) {
    // Automatically sorts keys (bids) from highest to lowest using greater<int>
    map<int, vector<Buyer>, greater<int>> groupedBids;
    vector<int> originalIds;
    
    // Map to keep an absolute record of what each customer ID received
    map<int, int> deliveryTracker;

    // Phase 1: Parse and group input data
    for (const auto& record : requests) {
        Buyer buyer;
        buyer.id = record[0];
        buyer.wantedQuantity = record[1];
        buyer.bidPrice = record[2];
        buyer.orderTime = record[3];
        buyer.itemsReceived = 0;

        groupedBids[buyer.bidPrice].push_back(buyer);
        originalIds.push_back(buyer.id);
        deliveryTracker[buyer.id] = 0; 
    }

    // Phase 2: Distribute inventory starting from the highest bid group
    for (auto& structuralPair : groupedBids) {
        auto& currentGroup = structuralPair.second;

        if (totalInventory <= 0) {
            break; // Stop immediately if stock is gone
        }

        // Sort by arrival time (timestamp) to establish round-robin sequence
        sort(currentGroup.begin(), currentGroup.end(), [](const Buyer& x, const Buyer& y) {
            return x.orderTime < y.orderTime;
        });

        // Evaluate collective demand for this specific bid tier
        long long collectiveDemand = 0;
        for (const auto& client : currentGroup) {
            collectiveDemand += client.wantedQuantity;
        }

        if (totalInventory >= collectiveDemand) {
            // Optimization: Fulfill everyone in this tier entirely
            for (auto& client : currentGroup) {
                client.itemsReceived = client.wantedQuantity;
                deliveryTracker[client.id] += client.itemsReceived;
            }
            totalInventory -= collectiveDemand;
        } else {
            // Partial fulfillment: Execute round-robin distribution loop
            bool itemDistributedInCycle = true;
            while (totalInventory > 0 && itemDistributedInCycle) {
                itemDistributedInCycle = false;

                for (auto& client : currentGroup) {
                    if (totalInventory == 0) break;

                    if (client.itemsReceived < client.wantedQuantity) {
                        client.itemsReceived++;
                        deliveryTracker[client.id]++;
                        totalInventory--;
                        itemDistributedInCycle = true;
                    }
                }
            }
        }
    }

    // Phase 3: Identify who left completely empty-handed
    vector<int> zeroAllocationIds;
    for (int customerId : originalIds) {
        if (deliveryTracker[customerId] == 0) {
            zeroAllocationIds.push_back(customerId);
        }
    }

    // Sort the final zero-allocation list in ascending order as requested
    sort(zeroAllocationIds.begin(), zeroAllocationIds.end());
    
    // Clean up duplicates if the same customer submitted multiple identical requests
    zeroAllocationIds.erase(unique(zeroAllocationIds.begin(), zeroAllocationIds.end()), zeroAllocationIds.end());

    return zeroAllocationIds;
}
