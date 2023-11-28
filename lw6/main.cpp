#include <iostream>
#include <fstream>
#include <vector>

// Абстрактный базовый класс NPC
class NPC {
public:
    virtual void printInfo() = 0;
    virtual void attack(NPC* enemy) = 0;
    virtual bool isAlive() = 0;
    virtual void accept(class NPCVisitor* visitor) = 0;
    virtual ~NPC() {}
};

// Конкретный класс Медведь
class Bear : public NPC {
private:
    std::string name;
    int x;
    int y;
    bool alive;

public:
    Bear(const std::string& name, int x, int y) : name(name), x(x), y(y), alive(true) {}

    void printInfo() override {
        std::cout << "Bear: " << name << " (" << x << ", " << y << ")" << std::endl;
    }

    void attack(NPC* enemy) override {
        if (dynamic_cast<Werewolf*>(enemy)) {
            enemy->accept(this);
            alive = false;
        }
    }

    bool isAlive() override {
        return alive;
    }

    void accept(NPCVisitor* visitor) override;
};

// Конкретный класс Оборотень
class Werewolf : public NPC {
private:
    std::string name;
    int x;
    int y;
    bool alive;

public:
    Werewolf(const std::string& name, int x, int y) : name(name), x(x), y(y), alive(true) {}

    void printInfo() override {
        std::cout << "Werewolf: " << name << " (" << x << ", " << y << ")" << std::endl;
    }

    void attack(NPC* enemy) override {
        if (dynamic_cast<Robber*>(enemy)) {
            enemy->accept(this);
            alive = false;
        }
    }

    bool isAlive() override {
        return alive;
    }

    void accept(NPCVisitor* visitor) override;
};

// Конкретный класс Разбойник
class Robber : public NPC {
private:
    std::string name;
    int x;
    int y;
    bool alive;

public:
    Robber(const std::string& name, int x, int y) : name(name), x(x), y(y), alive(true) {}

    void printInfo() override {
        std::cout << "Robber: " << name << " (" << x << ", " << y << ")" << std::endl;
    }

    void attack(NPC* enemy) override {
        if (dynamic_cast<Bear*>(enemy)) {
            enemy->accept(this);
            alive = false;
        }
    }

    bool isAlive() override {
        return alive;
    }

    void accept(NPCVisitor* visitor) override;
};

// Посетитель для сохранения NPC в файл
class NPCSaveVisitor : public NPCVisitor {
private:
    std::ofstream file;

public:
    NPCSaveVisitor(const std::string& filename) : file(filename) {}

    void visit(Bear* bear) override {
        file << "Bear " << bear->name << " " << bear->x << " " << bear->y << std::endl;
    }

    void visit(Werewolf* werewolf) override {
        file << "Werewolf " << werewolf->name << " " << werewolf->x << " " << werewolf->y << std::endl;
    }

    void visit(Robber* robber) override {
        file << "Robber " << robber->name << " " << robber->x << " " << robber->y << std::endl;
    }
};

// Посетитель для печати NPC на экран
class NPCPrintVisitor : public NPCVisitor {
public:
    void visit(Bear* bear) override {
        bear->printInfo();
    }

    void visit(Werewolf* werewolf) override {
        werewolf->printInfo();
    }

    void visit(Robber* robber) override {
        robber->printInfo();
    }
};

// Фабрика NPC
class NPCFactory {
public:
    static NPC* create(const std::string& type, const std::string& name, int x, int y) {
        if (type == "Bear") {
            return new Bear(name, x, y);
        }
        else if (type == "Werewolf") {
            return new Werewolf(name, x, y);
        }
        else if (type == "Robber") {
            return new Robber(name, x, y);
        }
        else {
            throw std::runtime_error("Invalid NPC type");
        }
    }
};

// Класс битвы
class Battle {
private:
    std::vector<NPC*> npcs;
    int range;

public:
    Battle(int range) : range(range) {}

    void addNPC(NPC* npc) {
        npcs.push_back(npc);
    }

    void start() {
        for (auto npc : npcs) {
            for (auto enemy : npcs)
{
                if (npc != enemy && distance(npc, enemy) <= range) {
                    npc->attack(enemy);
                }
            }
        }

        npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [](NPC* npc) { return !npc->isAlive(); }), npcs.end());
    }

    void printNPCs() {
        for (auto npc : npcs) {
            npc->printInfo();
        }
    }

    void saveToFile(const std::string& filename) {
        NPCSaveVisitor visitor(filename);

        for (auto npc : npcs) {
            npc->accept(&visitor);
        }
    }

private:
    float distance(NPC* npc1, NPC* npc2) {
        int dx = npc1->getX() - npc2->getX();
        int dy = npc1->getY() - npc2->getY();
        return std::sqrt(dx * dx + dy * dy);
    }
};

// Реализация метода accept для Медведя
void Bear::accept(NPCVisitor* visitor) {
    visitor->visit(this);
}

// Реализация метода accept для Оборотня
void Werewolf::accept(NPCVisitor* visitor) {
    visitor->visit(this);
}

// Реализация метода accept для Разбойника
void Robber::accept(NPCVisitor* visitor) {
    visitor->visit(this);
}

int main() {
    Battle battle(100); // Дальность боя 100

    NPC* bear = NPCFactory::create("Bear", "Yogi", 100, 100);
    NPC* werewolf = NPCFactory::create("Werewolf", "Wolfie", 200, 200);
    NPC* robber = NPCFactory::create("Robber", "Bandit", 300, 300);

    battle.addNPC(bear);
    battle.addNPC(werewolf);
    battle.addNPC(robber);

    // Печать NPC на экран
    NPCPrintVisitor printVisitor;
    bear->accept(&printVisitor);
    werewolf->accept(&printVisitor);
    robber->accept(&printVisitor);

    // Сохранение NPC в файл
    battle.saveToFile("npcs.txt");

    // Запуск боевого режима
    battle.start();

    // Печать оставшихся NPC на экран
    battle.printNPCs();

    delete bear;
    delete werewolf;
    delete robber;

    return 0;
}
