#include <iostream>
#include <ctime>
using namespace std;
int main()
{
        srand(time(0));
        long long n = rand() % 9 + 2;
        //long long n = 100;
        long long array[n][n];
        cout<<"\tArray"<<endl;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        array[i][j] = rand() % 9 + 1;
                        cout<<array[i][j]<<" ";
                }
                cout<<endl;
        }
        long long *ptr_array = &array[0][0];
        long long *end_array = &array[n-1][n-1];
        long long *ptr_array1 = &array[n-1][0];
        long long *end_array1 = &array[0][n-1];
        if (n<=1)
        {
                cout<< "Bad array size!"<<endl;
                return -1;
        }
        asm(
        	"mov %[ptr_array], %%rax\n\t"
        	
        	"loop1:\n\t"
        	"push (%%rax)\n\t"
        	"add $8, %%rax\n\t"
        	"cmp %%rax, %[end_array]\n\t"
        	"jne loop1\n\t"
        	"push (%%rax)\n\t"
        	
	//	"mov %[ptr_array], %%rax\n\t"
	//	"loop2:\n\t"
        //        "pop (%%rax)\n\t"
      //          "add $8, %%rax\n\t"
    //            "cmp %%rax, %[end_array]\n\t"
  //              "jne loop2\n\t"
//                "pop (%%rax)\n\t"
//                "add $8, %%rax\n\t"
  //              "pop (%%rax)\n\t"
		"mov %[ptr_array1], %%rbx\n\t"
        	"mov $8, %%rax\n\t"
        	"mulq %[n]\n\t"
        	"mov %[ptr_array], %%rcx\n\t"
        	"mov %%rbx, %%rdx\n\t"

        	"loop2:\n\t"
        	"pop (%%rbx)\n\t"
		"sub %%rax, %%rbx\n\t"
        	"cmp %%rbx, %%rcx\n\t"
        	"jne loop2\n\t"
        	"pop (%%rbx)\n\t"
        	"add $8, %%rcx\n\t"
		"add $8, %%rdx\n\t"
		"mov %%rdx, %%rbx\n\t"
        	"cmp %%rbx, %[end_array]\n\t"
        	"jne loop2\n\t"
        	
        	"loop3:\n\t"
        	"pop (%%rbx)\n\t"
        	"sub %%rax, %%rbx\n\t"
        	"cmp %%rbx, %%rcx\n\t"
        	"jne loop3\n\t"
        	"pop (%%rbx)\n\t"
                "end_asm:\n\t"
                :
                :[ptr_array]"m"(ptr_array), [end_array]"m"(end_array), [ptr_array1]"m"(ptr_array1), [end_array1]"m"(end_array1), [n]"m"(n)
                :"%rax", "%rbx", "%rcx"
        );
        cout<<endl<<"--------------------------------"<<endl;
        cout<<"\tArray(T)"<<endl;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cout<<array[i][j]<<" ";
                }
                cout<<endl;
        }
        return 0;
}
