import <iostream>;  
import employee; // Import our employee module

using namespace std;

int main()
{
	// create and populate an employee
	Employee anEmployee;
	anEmployee.firstInitial = 'J';
	anEmployee.lastInitial = 'D';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	// output the values of an employee
	cout<< format("Employee: {}{}\n", anEmployee.firstInitial,
		anEmployee.lastInitial);
	cout<< format("Number: {}\n", anEmployee.employeeNumber);
	cout<< format("Salary: ${}\n", anEmployee.salary);
}

/**

	声明为 Employee类型的变量anEmployee拥有 全部内建的字段; 使用 . 运算符 访问  结构体的各个字段;  

	导入自定义模块时, 不得使用 尖括号? 为什么? 
	
		
*/
