#include <unordered_map>
#include <random>
#include <utility>
#include <fstream>
#include <iostream>

#include "NPC.hpp"
#include "factory.hpp"

class DataSaver {
private:
    std::string filename;

public:
    explicit DataSaver(std::string filename) : filename(std::move(filename)) {}
    void Save(const set_t& arr) const noexcept {
        std::ofstream fs(filename, std::ios::app);
        for (const auto &npc: arr) {
            fs << int(npc->type) << " " << npc->x << " " << npc->y << std::endl;
        }
    }
};

class DataLoader {
private:
    std::string filename;
    void clear() const noexcept {
        std::ofstream out(filename, std::ios::trunc);
        out.close();
    }
public:
    explicit DataLoader(std::string filename) : filename(std::move(filename)) {}
    [[nodiscard]] set_t Load() const noexcept {
        set_t arr;
        std::ifstream fs(filename);
        int npcType;
        int x;
        int y;
        while(fs >> npcType >> x >> y) {
            auto createdNpc = Factory::Create(NPCType(npcType), x, y);
            if(createdNpc) {
                arr.insert(std::move(createdNpc));
            }
        }

        fs.close();

        this -> clear();

        return arr;
    }
};

std::unordered_map<std::string, NPCType> types = {
    {"bear", NPCType::BearType},
    {"werewolf", NPCType::WerewolfType},
    {"outlaw", NPCType::OutlawType}
};

set_t Fight(const set_t& array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array) {
        for (const auto &defender : array) {
            if ((attacker != defender) && (dead_list.find(defender) == dead_list.end()) && (attacker->is_close(defender, distance))) {
                bool win = defender->accept(attacker);
                if (!win) {
                    dead_list.insert(defender);
                }
            }
        }
    }

    return dead_list;
}

int main() {
    DataSaver saver("data.txt");
    DataLoader loader("data.txt");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 500);
    
    std::cout << "\t\tUSAGE" << std::endl;
    std::cout << "create <NPC type> <x> <y>: create NPC" << std::endl;
    std::cout << "save: save state of map" << std::endl;
    std::cout << "load: load map" << std::endl;
    std::cout << "fight <range of attack>: start fight" << std::endl;

    set_t array;
    for(int i = 0; i < 7; ++i) {
        auto npcTypeKey = (i % 2 == 0) ? "bear" : "werewolf";
        NPCType npcType = types[npcTypeKey];
        auto npc = Factory::Create(npcType, dis(gen), dis(gen));
        if(npc) {
            array.insert(std::move(npc));
        }
    }

    std::string action;
    while(std::cin >> action) {
        if(action == "create") {
            std::string npcTypeKey;
            int x, y;
            std::cin >> npcTypeKey >> x >> y;
            if(types.find(npcTypeKey) != types.end()) {
                auto npcType = types[npcTypeKey];
                auto npc = Factory::Create(npcType, x, y);
                if(npc) {
                    array.insert(std::move(npc));
                }
                std::cout << "Created!" << std::endl;
            } 
            else {
                std::cout << "Invalid NPC type!" << std::endl;
            }
        } else if(action == "save") {
            saver.Save(array);
            std::cout << "Saved!" << std::endl;
        } else if(action == "load") {
            array = loader.Load();
            std::cout << "Loaded!" << std::endl;
        } else if(action == "fight") {
            int range;
            std::cin >> range;
            set_t dead_list = Fight(array, range);
            std::cout << "\nDead: " << dead_list.size() << std::endl;
            for(auto& npc : dead_list) {
                std::cout << *npc << std::endl;
            }
            std::cout << std::endl;
            for(const auto& npc : dead_list) {
                array.erase(npc);
            }
        } else {
            std::cout << "Wrong command!" << std::endl;
        }
    }
    return 0;
}
