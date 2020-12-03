#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
vector<int> l()
{
    vector<int> x;
    ifstream f("f");
    while(f.good())
    {   
        int d;
        f >> d;
        x.push_back(d);
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
