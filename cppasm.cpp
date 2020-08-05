#include <iostream>

template<class Unit>
class GameObjects
{
public:
    int m_value;
    Unit *m_data;
public:
    GameObjects(int val, Unit *data) : m_value(val), m_data(data)
    {}

    void seData(Unit *dt)
    {
        m_data = dt;
    }

    Unit *getData();
};

template<class Unit>
Unit* GameObjects<Unit>::getData()
{
    return m_data;
}

template<>
class GameObjects<double>
{
 public:
    int m_value;
    double *m_data;
public:
    GameObjects(int val, double *data) : m_value(val), m_data(data)
    {
        m_value += 100; 
    }

    void seData(double *dt)
    {
        *dt += 1000;
        m_data = dt;
    }

    double *getData();
};

double* GameObjects<double>::getData()
{
    return m_data;
}

int main(int argc, char *argv[])
{
    std::cout.precision(10);

    std::cout << "Repository power!!!" << std::endl;

    int value = 10, value2 = 355, value3 = 777;
    int *pointer = &value2;
    int *pointer2 = &value3;
    double var1 = 20.7, var2 = 33.5878;
    double *pointer3 = &var1;
    double *pointer4 = &var2;

    GameObjects<double> object2(value3, pointer3);
    
    GameObjects<int> object(value, pointer);

    std::cout << object2.m_value << " " << *object2.getData() << std::endl;
    object2.seData(pointer4);
    std::cout << object2.m_value << " " << *object2.getData() << std::endl;

    std::cout << object.m_value << " "  << *object.m_data << std::endl;

    object.seData(pointer2);
    
    std::cout << object.m_value << " " << *object.getData() << std::endl;

    return 0;
}
    
