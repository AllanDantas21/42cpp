#ifndef DATA_HPP
#define DATA_HPP

class Data {
    private:
        int _nbr;
        Data();

    public:
        Data(int nbr);
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);

        int getInt(void) const;
};

#endif