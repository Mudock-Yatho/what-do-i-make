#include <iostream>
void test(){
	for(int a=0;a<5;a++){
		if(a==4){
			std::cout<<"test";
		}else{
			std::cout<<"test\n";
		}
	}
}
int test2(){
	for(int a=0;a<3;a++){
		std::cout<<".";
	}
	return 0;
}
int main (){
	int a=1;
	float b=299.5;
	std::cout<<"testing\n";
	std::cout<<"testx2\n";
	std::cout<<a+b<<std::endl;
	test();
	test2();
	return 0;
}
