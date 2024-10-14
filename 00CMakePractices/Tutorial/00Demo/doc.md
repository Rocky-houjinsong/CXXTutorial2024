> 项目结构 : 
>
> * `calc.hxx`   头文件   函数 和 数据的 声明
>   * `implementation.cxx`  函数实现文件 
>   * `storage.cxx`  数据 实现文件 
> * `main.cxx`  程序入口 

CMake 仅将 所有需要编译的文件放到一起, 这个 Demo仅展示   头文件机制  不做复杂化处理

> ⭐ `extern` 关键字  必要性 分析 : 
>
> 若 移除 `storage.cxx` 中的 声明, 移除 `calc.hxx` 中的extern关键字,  
> 因为  该头文件  被其余三个`cxx`文件引用, 在最终组装的 程序文件中  重复引用  则 数据被重复声明 
>
> ```cmd
> // 查看报错信息 变量重复赋值声明
> duplicate symbol '_data2' in:
>     CMakeFiles/CXXDecImpSeparation.dir/main.cxx.o
>     CMakeFiles/CXXDecImpSeparation.dir/implementation.cxx.o
> duplicate symbol '_data1' in:
>     CMakeFiles/CXXDecImpSeparation.dir/main.cxx.o
>     CMakeFiles/CXXDecImpSeparation.dir/implementation.cxx.o
> duplicate symbol '_data2' in:
>     CMakeFiles/CXXDecImpSeparation.dir/main.cxx.o
>     CMakeFiles/CXXDecImpSeparation.dir/storage.cxx.o
> duplicate symbol '_data1' in:
>     CMakeFiles/CXXDecImpSeparation.dir/main.cxx.o
>     CMakeFiles/CXXDecImpSeparation.dir/storage.cxx.o
> ld: 4 duplicate symbols for architecture x86_64
> clang++: error: linker command failed with exit code 1 (use -v to see invocation)
> gmake[2]: *** [CMakeFiles/CXXDecImpSeparation.dir/build.make:129: CXXDecImpSeparation] Error 1
> gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/CXXDecImpSeparation.dir/all] Error 2
> gmake: *** [Makefile:91: all] Error 2
> ```
>
> 

