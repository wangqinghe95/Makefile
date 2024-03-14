# 隐含规则一览

有哪些预先设置的 make 隐含规则呢。

如果在文件中不明确地写下规则，那么 make 就会在这些规则中寻找所需要的规则和命令。
我们可以使用 -r / --no-built-rules 选项来取消所有预设置的隐含规则。

即使指定 -r 参数，有些“后缀规则”定义的隐含规则依然会生效。
默认的后缀列表有 ".out, .a, .ln, .o, .c, .cc, .C, .p, .f, .F, .r, .y, .l, .s, .S, .mod, .sym, .def, .h, .info, .dvi, .txt, texinfo, .txinfo, .w, .ch, .web, .sh, .elc, .el"

## 常见的隐含规则

1. 编译 C 程序的隐含规则
   1. <n>.o 的目标依赖目标会自动推导为 <n>.c, 并且生成的命令是 $(CC) -c $(CPPFLAGS) $(CFLAGS)
2. 编译 C++ 程序的隐含规则
   1. <n>.o 的目标的依赖目标会自动推导为 <n>.cc 或者是 <n>.C, 并且其生成命令是 $(CXX) -c $(CPPFLAGS) $(CXXFLAGS).
3. 编译 Pascal 程序的隐含规则。
   1.  <n>.o 的目标的依赖目标会自动推导为 <n>.p ，并且其生成命令是 $(PC) –c $(PFLAGS) 。
4. 编译 Fortran/Ratfor 程序的隐含规则。
   1. <n>.o 的目标的依赖目标会自动推导为 <n>.r 或 <n>.F 或 <n>.f ，并且其生成命令是:
      + .f $(FC) –c $(FFLAGS)
      +  .F $(FC) –c $(FFLAGS) $(CPPFLAGS)
      +  .f $(FC) –c $(FFLAGS) $(RFLAGS)
5.  预处理 Fortran/Ratfor 程序的隐含规则。
    1. <n>.f 的目标的依赖目标会自动推导为 <n>.r 或 <n>.F 。这个规则只是转换 Ratfor 或有预处理的Fortran 程序到一个标准的 Fortran 程序。其使用的命令是：
       +  .F $(FC) –F $(CPPFLAGS) $(FFLAGS)
       +  .r $(FC) –F $(FFLAGS) $(RFLAGS)
6.  编译 Modula-2 程序的隐含规则。
    1.  <n>.sym 的目标的依赖目标会自动推导为 <n>.def ，并且其生成命令是：$(M2C) $(M2FLAGS) $(DEFFLAGS) 。<n>.o 的目标的依赖目标会自动推导为 <n>.mod ，并且其成命令是：$(M2C) $(M2FLAGS) $(MODFLAGS) 。
7.   汇编和汇编预处理的隐含规则。
    1.  <n>.o 的目标的依赖目标会自动推导为 <n>.s ，默认使用编译器 as ，并且其生成命令是：$ (AS) $(ASFLAGS) 。<n>.s 的目标的依赖目标会自动推导为 <n>.S ，默认使用 C 预编译器 cpp ，并且其生成命令是：$(AS) $(ASFLAGS) 。

8.  链接 Object 文件的隐含规则。
    1.  <n> 目标依赖于 <n>.o ，通过运行 C 的编译器来运行链接程序生成（一般是 ld ），其生成命令是：$(CC) $(LDFLAGS) <n>.o $(LOADLIBES) $(LDLIBS) 。这个规则对于只有一个源文件的工程有效，同时也对多个 Object 文件（由不同的源文件生成）的也有效。例如如下规则: `x : y.o z.o` 并且 x.c, y.c 和 z.c 都存在时，隐含规则将执行如下命令
    2.  ```
        cc -c x.c -o x.o
        cc -c y.c -o y.o
        cc -c z.c -o z.o
        cc x.o y.o z.o -o x
        rm -f x.o
        rm -f y.o
        rm -f z.o
        ```
    3. 如果没有一个源文件（如上例中的 x.c）和你的目标名字（如上例中的 x）相关联，那么，你最好写出自己的生成规则，不然，隐含规则会报错的。

9.  Yacc C 程序时的隐含规则。
    1.  <n>.c 的依赖文件被自动推导为 n.y （Yacc 生成的文件），其生成命令是：$(YACC) $(YFALGS)。（“Yacc”是一个语法分析器，关于其细节请查看相关资料）

10. Lex C 程序时的隐含规则。
    1.  <n>.c 的依赖文件被自动推导为 n.l（Lex 生成的文件），其生成命令是：$(LEX) $(LFALGS) 。（关于“Lex”的细节请查看相关资料）
11. Lex Ratfor 程序时的隐含规则。
    1.  <n>.r 的依赖文件被自动推导为 n.l （Lex 生成的文件），其生成命令是：$(LEX) $(LFALGS) 。
12. 从 C 程序、Yacc 文件或 Lex 文件创建 Lint 库的隐含规则。
    1.  <n>.ln（lint 生成的文件）的依赖文件被自动推导为 n.c ，其生成命令是：$(LINT) $(LINTFALGS) $(CPPFLAGS) -i 。对于 <n>.y 和 <n>.l 也是同样的规则。

