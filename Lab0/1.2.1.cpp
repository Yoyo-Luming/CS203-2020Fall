# include  <iostream>
int main()
{
	//std::cout<<"Hellow world£¡"<<std::endl;
	std::cout<<"Enter two numbers:"<<std::endl;
	int v1 = 0, v2 = 0;
	std::cin>>v1>>v2;
	if(v1 > v2){
		for(;v2<=v1;v2++ ){
			std::cout<<v2<<" "<<std::endl;
		}
	}else{
	for(;v1<=v2;v1++ ){
			std::cout<<v1<<" "<<std::endl;
		}
	}
	//std::cout<<"The sum of "<<v1<<" and "<<v2
	//						<<" is "<<v1 + v2<< std::endl;
	return 0;
}
