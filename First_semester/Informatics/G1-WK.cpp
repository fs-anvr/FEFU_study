#include <fstream>
#include <vector>
#include <queue>

using namespace std;
typedef queue<pair<int, int>> qpss;

class User
{
public:
    bool contacts[100]{};
    bool got[100]{};
    bool send = false;
    int counter = 0;
};

void receive(qpss &messages, vector<User> &users, int currentUser)
{
    if(users[currentUser].send) return;

    for(int i = 0; i < users.size(); ++i) {
        if(users[currentUser].contacts[i] && !users[currentUser].got[i]) {
            messages.emplace(i, currentUser);
        }
    }
}

void event(qpss &messages, vector<User> &users)
{
    bool sent_to[100]{};
    while(!messages.empty()) {
        auto pos = messages.front();
        users[messages.front().first].counter++;
        users[messages.front().first].got[messages.front().second] = true;
        users[messages.front().second].send = true;
        sent_to[messages.front().first] = true;
        messages.pop();
    }

    for(int i = 0; i != 100; ++i) {
        if(sent_to[i]) receive(messages, users, i);
    }
}


int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    User user;
    vector<User> users;
    queue<pair<int, int>> messages;
    int number; fin >> number;
    for (int i = 0; i < number; i++)
        users.push_back(user);
    
    
    for(size_t i = 0; i != number; ++i)
    {
        size_t contacts; fin >> contacts;
        for(size_t j = 0; j != contacts; ++j)
        {
            int pos; fin >> pos;
            users[i].contacts[pos - 1] = true;
        }
    }

    receive(messages, users, 0);
    while(!messages.empty())
    {
        event(messages, users);
    }

    for(size_t i = 0; i != number; ++i)
    {
        fout << users[i].counter << " ";
    }
}