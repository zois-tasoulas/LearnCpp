#include <array>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Monster
{
public:
    enum Type
    {
        dragon = 0,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

    Monster(Type type, std::string name, std::string roar, int hit) :
        m_type{type},
        m_name{name},
        m_roar{roar},
        m_hitPoints{hit}
    {
    }

    void print(void)
    {
        std::cout << m_name << " the " << getTypeString(m_type) << " has "
                  << m_hitPoints << " hit points and says " << m_roar
                  << std::endl;
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar;
    int m_hitPoints{};

    std::string getTypeString(Type type)
    {
        switch(type) {
            case Type::dragon :
                return "dragon";
            case Type::goblin :
                return "goblin";
            case Type::ogre :
                return "ogre";
            case Type::orc :
                return "orc";
            case Type::skeleton :
                return "skeleton";
            case Type::troll :
                return "troll";
            case Type::vampire :
                return "vampire";
            case Type::zombie :
                return "zombie";
            default:
                throw std::runtime_error("Unrecognized Monster type");
        }
    }
};

class MonsterGenerator
{
public:
    // Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}

    static Monster generateMonster(void)
    {
        Monster::Type type{static_cast<Monster::Type>(getRandomNumber(0, Monster::Type::max_monster_types - 1))};
        int hitPoints{getRandomNumber(1, 100)};
        static std::array<std::string, 6> s_names
        {
            "Bones",
            "Dimitris",
            "Giannis",
            "Giorgos",
            "Nikos",
            "Petros"
        };
        std::string name{s_names[static_cast<size_t>(getRandomNumber(0, 5))]};
        static std::array<std::string, 6> s_roars
        {
            "*rattle*",
            "Arrr",
            "Brrr",
            "Zzzz",
            "Shsh",
            "Satatata"
        };
        std::string roar{s_roars[static_cast<size_t>(getRandomNumber(0, 5))]};

        return {type, name, roar, hitPoints};
    }
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
