#define BOOST_PYTHON_STATIC_LIB
#define BOOST_NUMPY_STATIC_LIB

#include <iostream>
#include <boost/python.hpp>

int main()
{
	//名前空間
	namespace py = boost::python;
	//初期化
	Py_Initialize();
	//出力
	std::cout << "Hello World! from C++ \n";

	//Pythonのファイル(.py)をインポート
	py::object module_ns = py::import("test_py").attr("__dict__");
	//インポートしたファイルの関数を定義
	py::object get_and_return = module_ns["hello_from_python"];
	//インポートした関数を実行
	auto return_nd_array = get_and_return();

}
