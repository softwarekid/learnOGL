//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <iostream>
//#include <boost/type_index.hpp>
//using namespace std;
//
//
//#define STATIC_CHECK(expr) {char unname[expr?1:0];}
//
//template<class To, class From> To safe_reinterpret_cast(From from)
//{
//	STATIC_CHECK(sizeof(From) <= sizeof(To));
//	return reinterpret_cast<To>(from);
//}
//
//
//template<class T, class U> T* Create(const U& arg, T)
//{
//	return new T(arg);
//}
//
//template<int a> void Fun()
//{
//	cout << "int template select\n";
//}
//
//template<> void Fun<1>()
//{
//	cout << "int spec select\n";
//}
//
//// The MAIN function, from here we start our application and run our Game loop
//int main()
//{
//	glewInit();
//	//char a;
//	//void* somePointer = &a;
//	//char c = safe_reinterpret_cast<int>(somePointer);
//	//int a[sizeof(int) > 2 ? 1 : 2];
//
//	Fun<2>();
//	Fun<1>();
//
//	return 0;
//}