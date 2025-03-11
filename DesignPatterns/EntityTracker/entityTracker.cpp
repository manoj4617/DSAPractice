#include <iostream>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <shared_mutex>
#include <thread>

using namespace std;

class EntityTracker{
    private:
        unordered_map<int, vector<string>> entityMap;
        unordered_map<string, int> tagsCountMap;
        shared_mutex read_write_mtx;

        string generateKey(const vector<string>& tags){
            if(tags.empty()){
                throw invalid_argument("Tag list cannot be empty.");
            }
            stringstream tagStream;
            for(int i=0;i<tags.size();++i){
                if(i > 0) 
                    tagStream << "_";
                tagStream << tags[i];
            }
            return tagStream.str();
        }
    
    public:
        void startTracking(int id, vector<string> tags){
            if(tags.empty()){
                throw invalid_argument("Tag list cannot be empty.");
            }

            lock_guard<shared_mutex> lock(read_write_mtx);
            if(entityMap.find(id) != entityMap.end()){
                throw logic_error("Entity ID: " + to_string(id) + " is already being tracked");
            }
            
            entityMap[id] = tags;
            vector<string> heirarchy;
            for(const string& tag : tags){
                heirarchy.push_back(tag);
                string key = generateKey(heirarchy);
                tagsCountMap[key]++;
            }
        }

        void stopTracking(int id){
            lock_guard<shared_mutex> lock(read_write_mtx);
            if(entityMap.find(id) == entityMap.end()){
                throw logic_error("Entity ID " + to_string(id) + " is not being tracked.");
            }

            vector<string> tags = entityMap[id];
            vector<string> heirarchy;
            for(const string& tag : tags){
                heirarchy.push_back(tag);
                string key = generateKey(heirarchy);
                tagsCountMap[key]--;

                if(tagsCountMap[key] == 0){
                    tagsCountMap.erase(key);
                }
            }
            entityMap.erase(id);
        }

        int getCounts(vector<string> tags){
            shared_lock<shared_mutex> lock(read_write_mtx);
            string key = generateKey(tags);
            return tagsCountMap.count(key) ? tagsCountMap[key] : 0;
        }
};


// Driver functions
void simulateTracking(EntityTracker& tracker, int id, vector<string> tags){
    tracker.startTracking(id, tags);
}

void simulateStopping(EntityTracker& tracker, int id){
    tracker.stopTracking(id);
}

mutex print_mtx;
void simulateGetCount(EntityTracker& tracker, vector<string> tags){
    lock_guard<mutex> lock(print_mtx);
    cout << "Count for ";
    for(const auto& tag : tags){
        cout << tag << " ";
    }
    cout <<": " << tracker.getCounts(tags) << endl;
}

int main(){
    EntityTracker tracker;
    try {
        
        thread t1(simulateTracking, ref(tracker), 1112, vector<string>{"UPI", "Karnataka", "Bangalore"});
        thread t2(simulateTracking, ref(tracker), 2451, vector<string>{"UPI", "Karnataka", "Mysore"});
        thread t3(simulateTracking, ref(tracker), 3421, vector<string>{"UPI", "Rajasthan", "Jaipur"});
        thread t4(simulateTracking, ref(tracker), 1221, vector<string>{"Wallet", "Karnataka", "Bangalore"});
    
        t1.join();
        t2.join();
        t3.join();
        t4.join();
    
        thread t5(simulateGetCount, ref(tracker), vector<string>{"UPI", "Karnataka"});
        thread t6(simulateGetCount, ref(tracker), vector<string>{"Wallet"});
    
        t5.join();
        t6.join();

        thread t7(simulateStopping, ref(tracker), 1112);
        thread t8(simulateStopping, ref(tracker), 2451);
        
        t7.join();
        t8.join();
        
        thread t10(simulateGetCount, ref(tracker), vector<string>{"UPI", "Rajasthan"});
        thread t9(simulateGetCount, ref(tracker), vector<string>{"UPI"});
        t9.join();
        t10.join();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}