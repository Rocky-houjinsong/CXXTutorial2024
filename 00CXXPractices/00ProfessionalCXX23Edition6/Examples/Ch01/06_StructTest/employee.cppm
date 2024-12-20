export module employee;				// 模块声明 

export struct Employee {			// 模块导出的内容
	char firstInitial;	// 姓名 首字母
	char lastInitial;	// 姓名 末字母
	int  employeeNumber;// 员工编号
	int  salary;		// 薪资数目
};


/**
		结构体  允许 一个或 多个已有类型封装 到一个新类型中 ;  

		模块接口文件 通常 以 .cppm作为后缀 ;


*/