#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <unordered_set>

using namespace std;

enum Status {
    NEW = 1,
    ASSIGNED,
    RESOLVED
};

enum TicketType {
    UPI = 1,
    BANK,
    WALLET,
    UTILITY,
    GENERAL
};

class IAgent;

class Ticket{
    private:
        int id;
        TicketType ticketType;
        Status status;
        IAgent* assignedAgent;

    public:
        Ticket(int id, TicketType type) :
            id(id), ticketType(type), status(Status::NEW), 
            assignedAgent(nullptr){}

        void assignAgent(IAgent* newAgent){
            assignedAgent = newAgent;
            status = Status::ASSIGNED;
        }

        void markResolved(){
            status = Status::RESOLVED;
        }

        
        int getID() { return id; }
        Status getStatus() { return status; }
        TicketType getType() { return ticketType; }
        IAgent* getAssignedAgent() { return assignedAgent; }
    };
    
string ticketTypeToString(TicketType type){
    switch(type){
        case TicketType::BANK: return "BANK";
        case TicketType::GENERAL : return "GENERAL";
        case TicketType::WALLET: return "WALLET";
        case TicketType::UPI: return "UPI";
        case TicketType::UTILITY: return "UTILITY";
    }
    return "UNKOWN";
}

class IAgent {
    public:
        virtual bool assignTicket(Ticket* ticket) = 0;
        virtual bool resolveTicket(Ticket* ticket) = 0;
        virtual bool rejectTicket(Ticket* ticket) = 0;
        virtual bool isAvailable() const = 0;
        virtual bool canHandle(string ticketTypeStr) const = 0;
        virtual string getID() const = 0;
        virtual ~IAgent() = default;
};

class Agent : public IAgent {
    private:
        string id;
        unordered_set<string> specializations;
        queue<Ticket*> backlog;
        int maxBacklogSize;
        bool available;

    public:
        Agent(string Id, unordered_set<string> specialization, int maxSize = 10) : 
            id(Id), specializations(std::move(specialization)), 
            maxBacklogSize(maxSize), available(true) {}
        
        bool assignTicket(Ticket* ticket) override {
            string ticketTypeStr = ticketTypeToString(ticket->getType());

            if(backlog.size() >= maxBacklogSize){
                return false;
            }
            if(specializations.find(ticketTypeStr) != specializations.end()){
                backlog.push(ticket);
                return true;
            }
            return false;
        }
        
        bool resolveTicket(Ticket* ticket) override {
            if(backlog.empty()) return false;
            backlog.pop();
            return true;
        }
        
        bool rejectTicket(Ticket* ticket) override {
            return false; 
        }

        bool isAvailable() const override {
            return available;
        }

        string getID() const override {
            return id;
        }

        bool canHandle(string ticketTypeStr) const override{
            return !(specializations.find(ticketTypeStr) == specializations.end());
        }
};

class TicketManager {
    private:
        vector<unique_ptr<IAgent>> agents;
        queue<unique_ptr<Ticket>> internalBacklog;

    public:
        void registerAgent(unique_ptr<IAgent> agent){
            agents.push_back(std::move(agent));
        }

        void assignTicket(unique_ptr<Ticket> ticket){
            string ticketTypeStr = ticketTypeToString(ticket->getType());
    
            for(auto &agent : agents){
                if(agent->isAvailable() && agent->canHandle(ticketTypeStr)){
                    ticket->assignAgent(agent.get());
                    agent->assignTicket(ticket.get());
                    cout << "Assinged Ticket: " << ticket->getID() << " to specialized agent: " << agent->getID() << endl;
                    return;
                }
            }

            for(auto& agent : agents){
                if(agent->isAvailable()){
                    ticket->assignAgent(agent.get());
                    agent->assignTicket(ticket.get());
                    cout << "Assinged Ticket: " << ticket->getID() << " to general agent: " << agent->getID() << endl;
                    return;
                }
            }
            internalBacklog.push(std::move(ticket));
            cout << "No Agents available, adding ticket: " << ticket->getID() << " to backlog\n";
        }

        void processBacklog(){
            while(!internalBacklog.empty()){
                auto &ticket = internalBacklog.front();
                for(auto& agent : agents){
                    if(agent->isAvailable()){
                        ticket->assignAgent(agent.get());
                        agent->assignTicket(ticket.get());
                        internalBacklog.pop();
                        return;
                    }
                }
            }
        }
};

int main(){
    unique_ptr<IAgent> agent1 = make_unique<Agent>("A1", unordered_set<string>({"UPI", "BANK"}));
    unique_ptr<IAgent> agent2 = make_unique<Agent>("A2", unordered_set<string>({"WALLET", "GENERAL"}));
    unique_ptr<IAgent> agent3 = make_unique<Agent>("A2", unordered_set<string>({"UTILTY"}));

    TicketManager manager;
    manager.registerAgent(std::move(agent1));
    manager.registerAgent(std::move(agent2));
    manager.registerAgent(std::move(agent3));

    auto ticket1 = make_unique<Ticket>(101,TicketType::BANK);
    auto ticket2 = make_unique<Ticket>(102,TicketType::UTILITY);
    auto ticket3 = make_unique<Ticket>(103,TicketType::UPI);
    auto ticket4 = make_unique<Ticket>(104,TicketType::GENERAL);
    auto ticket5 = make_unique<Ticket>(105,TicketType::WALLET);
    auto ticket6 = make_unique<Ticket>(106,TicketType::BANK);

    manager.assignTicket(std::move(ticket1));
    manager.assignTicket(std::move(ticket2));
    manager.assignTicket(std::move(ticket3));
    manager.assignTicket(std::move(ticket4));
    manager.assignTicket(std::move(ticket5));
    manager.assignTicket(std::move(ticket6));


    return 0;
}