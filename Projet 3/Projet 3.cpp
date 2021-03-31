#include "CMatrice.h"

int main()
{
	CMatrice<int> m1;
	CMatrice<int> m2(m1);
	CMatrice<int> m3(10,10);
	CMatrice<int> m4(20,15, nullptr);
	
    //std::cout << "Hello World!\n";
	return 0;
}
