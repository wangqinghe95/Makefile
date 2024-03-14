# 隐含规则使用的变量

隐含规则的命令中使用的都是预先设置的变量。可以在 makefile 中修改或者 make 的命令中传入这些值。
可以使用参数 -R 或者 --no-built-variables 参数取消定义的变量对隐含规则的作用。

比如下面这条命令
`$(CC) -c $(CFLAGS) $(CPPFLAGS)`

make 默认的编译命令是 cc，如果把变量 $(CC) 重新定义为 gcc，把变量 $(CFLAGS) 重定义为 -g
那么，以上的命令就变成了 `gcc -c -g $(CPPCLAGS)`

隐含规则中使用的变量分为两种，一种是和命令相关的，一种是和参数相关的

## 关于命令的变量

|变量|解释|
|--|--|
| AR | 函数库打包命令，默认是 ar |
| AS | 汇编语言编译程序，默认是 as |
| CC | C 语言编译程序，默认是 cc |
| CXX | C++ 语言编译程序，默认命令是 g++ |
| CO | 从 RCS 文件中扩展文件程序，默认命令为 co |
| CPP | C 程序的预处理器，（输出是标准输出设备）。默认命令是 $(CC) -E |
| FC | Fortran 和 Ratfor 的编译器和预处理程序。默认命令是 f77 |
| GET |  从 SCCS 文件中扩展文件的程序。默认命令是 get |
| LEX |  Lex 方法分析器程序（针对于 C 或 Ratfor）。默认命令是 lex |
| PC |  Pascal 语言编译程序。默认命令是 pc |
| YACC |  YACC : Yacc 文法分析器（针对于 C 程序）。默认命令是 yacc |
| YACCR | Yacc 文法分析器（针对于 Ratfor 程序）。默认命令是 yacc –r |
| MAKEINFO | 转换 Texinfo 源文件（.texi）到 Info 文件程序。默认命令是 makeinfo |
| TEX | 从 TeX 源文件创建 TeX DVI 文件的程序。默认命令是 tex |
| TEXI2DVI |  从 Texinfo 源文件创建军 TeX DVI 文件的程序。默认命令是 texi2dvi |
| WEAVE | 转换 Web 到 TeX 的程序。默认命令是 weave |
| CWEAVE | 转换 C Web 到 TeX 的程序。默认命令是 cweave |
| TANGLE | 转换 Web 到 Pascal 语言的程序。默认命令是 tangle |
| CTANGLE | 转换 C Web 到 C。默认命令是 ctangle |
| RM |  删除文件命令。默认命令是 rm –f |

## 关于命令参数的变量

命令参数如果没有指明默认值，那么其默认值都为空

| 变量 | 功能  |
| -- | -- |
| ARFLAGS | 函数库打包程序 AR 命令的参数。默认值是 rv |
| ASFLAGS |  汇编语言编译器参数。（当明显地调用 .s 或 .S 文件时） |
| CFLAGS | C 语言编译器参数 |
| CXXFLAGS | C++ 语言编译器参数 |
| COFLAGS | RCS 命令参数 |
| CPPFLAGS | C 预处理器参数 （C 和 Fortran 编译器也会用到）|
| FFLFAGS | Fortran 语言编译器参数。 |
| GFLAGS |   SCCS “get”程序参数。 |
| LDFLAGS | 链接器参数 |
| LFLAGS | Lex 文法分析器参数 |
| PFLAGS | Pascal 语言编译器参数 |
| RFLAGS | Ratfor 程序的 Fortran 编译器参数 |
| YFLAGS | Yacc 文法分析器参数 |