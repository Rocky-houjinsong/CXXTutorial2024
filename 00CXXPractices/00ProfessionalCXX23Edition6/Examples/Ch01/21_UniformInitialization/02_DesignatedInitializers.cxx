
// C++20引入 指派初始化器,  以使用它们的名称初始化所谓聚合的数据成员; 
// 聚合类型:   仅public数据成员, 无用户声明或继承的构造函数, 无虚函数 和 无虚基类, private或 protected的基类

// 指派初始化器 以 点开头, 后跟 数据成员的名称 . 


// Warning : 指派初始化的顺序  必须 与 数据成员的 声明顺序一致 
// Warning : 不允许 混合使用 指派初始化器 和 非 指派初始化器.  

// 未使用 指派初始化器初始化的任何数据成员 都将使用其默认值 进行初始化   -->  01 拥有 类内初始化器的数据成员将会得到该值;   02 : 没有类内初始化器的数据成员会被 零初始化; 


// 说人话就是 , 优先 初始化器, 没有就用 类内初始化, 再没有 就 零初始化
struct Employee {
	char firstInitial;
	char lastInitial;
	int  employeeNumber;
	int  salary{ 75'000 };
};



int main()
{
	// 统一初始化器 :  所有 字段 都必须有 填充, 后续若增减字段,破坏原有代码;  其次: 无法理解 正在初始化的内容

	Employee anEmployee0 = {'J', 'D', 42, 80'000}; 

	// 指派初始化器:  更容易理解初始化的内容,;  对某些成员的 默认值感到满意可跳过 其初始化;  当新成员 添加到数据结构中时,  现有代码不会遭到破坏,  新的数据成员 使用其默认值 进行初始化; 

	// Initialize all data members
	Employee anEmployee1{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 42,
		.salary = 80'000
	};

	// Initialize all data members, except employeeNumber
	Employee anEmployee2{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.salary = 80'000
	};

	// Initialize all data members, except employeeNumber, and salary
	Employee anEmployee3{
		.firstInitial = 'J',
		.lastInitial = 'D'
	};
}
