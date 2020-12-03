#include <array>
#include <fstream>
#include <iostream>

using namespace std;
auto l()
{
    array<int, 200> x;
    ifstream f("f");
    for(int& d : x)
    {
        f >> d;
    }
    return x;
}
int main()
{
#define f(V) for(int V : l()) {
        f(x)
        f(y)
        f(z)
                if(x+y+z == 2020)
                {
                    cout<<x*y*z;
                    return 0;
                }
            }
        }
    }
}
