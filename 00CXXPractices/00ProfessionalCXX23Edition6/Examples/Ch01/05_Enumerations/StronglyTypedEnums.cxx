//import <iostream>;
#include <type_traits>  // underlyingValue 获取 枚举类型的底层类型

using namespace std;

enum class PieceType
{
	King = 1,
	Queen,			// 未定义 当前枚举成员的值, 编译器 将上一个枚举成员的值 递增 1 , 此处2 
	Rook = 10,
	Pawn			// 未定义 当前枚举成员的值, 编译器 将上一个枚举成员的值 递增 1 , 此处11 
};

enum class XingQiType
{
	Yi = 1, 
	Er,
	San, 
	Si,
	Wu
};

enum class YueFenType{
	Yi = 1, 
	Er, 
	San, 
	Si, 
	Wu
};

enum class ShengFenDMType : unsigned long 
{
	JiangSu = 3207211998
};

// C++20 中的 to_underlying 函数
template <typename Enum>
constexpr auto to_underlying(Enum e) noexcept {
    return static_cast<std::underlying_type_t<Enum>>(e);
}

int main()
{
	{
		PieceType piece{ PieceType::King };

		auto underlyingValue{ to_underlying(piece) };
	}

	{
		using enum PieceType;
		PieceType piece{ King };
	}

	{
		using PieceType::King;
		PieceType piece{ King };
		piece = PieceType::Queen;
	}
}


/**
		[[枚举类型]]
 整数 代表  某个 数字序列中的值 , 枚举类型 是 允许你 定义自己的序列;   


 老版本的 枚举  使用 const int 标记 ;  存在以下的风险; 
 1. int + 1   无意义 且 无对应的 含义, 

 所以  ,  强类型的 枚举类型 通过 定义变量的 取值范围 解决  风险问题 ; 


  尽管  枚举值  内部是 由 整数值表示的,  但它 不会自动转换为整数 ;    if(PieceType::Queen == 2)  不合法  会报错;  

  枚举值 是 基本类型是 整形, 可采用  下述方式 改变 

  enum class PiectType : unsigned long 



  枚举值名 不会自动超过 封闭的作用域,  ---->  不同的强类型枚举可以拥有  同名的 枚举值;   同时也意味着 必须使用枚举值的全名 或者  使用 using enum 或  using 声明 ;  

  可以使用  using 声明 比年使用某个特定枚举值的全名, 
   作用域 一定要小, 如果 作用域很大的话,  有可能 重新引入名称冲突;   



*/
