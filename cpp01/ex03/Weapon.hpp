#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string type): _type(type) {};
        const std::string &getType() const;
        void setType(const std::string &type); 
};

#endif