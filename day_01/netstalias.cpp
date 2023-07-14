/* 命名空间嵌套 */
#include <iostream>
using namespace std;

namespace ns1{
    int g_value = 100;
    namespace ns2{
        int g_value = 200;
        namespace ns3{
            int g_value = 300;
            namespace ns4{
                int g_value = 400;
            }
        }
    }
}

int main(void){
    // cout << "ns4::g_value = " << ns1::ns2::ns3::ns4::g_value; 

    namespace ns_4 = ns1::ns2::ns3::ns4;
    cout << ns_4::g_value << endl;
    return 0;
}