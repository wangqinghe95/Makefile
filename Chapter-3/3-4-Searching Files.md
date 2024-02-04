# 文件搜索

在一些大工程中，有大量源文件，存放在不同的目录中，当 make 需要去寻找文件的依赖关系时，可以在文件前加上路径。也可以把一个路径告诉 make，让 make 自动搜索

## VPATH
Makefile 中有一个特殊变量 VPATH 用于完成该项功能，如果该变量不被指明， make 只会在当前的目录中去寻找依赖文件和目标文件。
如果定义了该变量，make 就会在当前目录中不到的情况下，到所指定的目录中去寻找文件。

`VAPTH = src:../headers`

以上的命令指定了两个目录，"src" 和 "..headers", make 会按照这个顺序去搜寻，多个目录以“冒号”分割

## vpath

vpath 也是文件搜索路径的关键字，不是变量。它可以指定不同的文件在不同的目录搜索，有三种用法

+ vpath <pattern> <directions>
为符合模式 <pattern> 的文件指定搜索目录 <directions>

+ vpath <directions>
清除符合模式 <pattern> 的文件的搜索目录

+ vpath
清除所有已被设置好了的文件搜索目录

vpath 使用方法中的 <pattern> 需要包含 % 字符，意思是匹配若干或零个字符（如果要使用 % 字符，使用转移）。
比如 %.h 表示所有以 h 结尾的文件。

<pattern> 指定了要所搜索的文件集，<directions> 指明了 <pattern> 的文件的搜索的目录，如
`vpath %.h ../headers`

该语句意思是：要求 make 在 "../headers" 目录下搜索所有以 .h 结尾的文件（如果该文件在当前目录没有找到的话）

我们可以连续使用 vpath 语句，以指定不同搜索策略，如果连续的 vapth 语句中出现了相同的 <pattern>，或是重复了的 <pattern>, 那么 make 会按照 vapth 语句的先后顺序来执行搜索，如
```
vpath %.c foo
vpath % blish
vpath %.c bar
```

配置的意思是：.c 文件先是在 foo 目录中，然后在 blish 中，最后是 bar 目录。

如果是 
```
vpath %.c foo:bar
vpath %     blish
```
表示 .c 文件先在 foo 目录，然后再 bar 目录，最后才是 blish

需要特意说明的是，VPATH，vpath 只是 make 的寻找目录，如果是 gcc/g++ 编译命令的话，还需要额外指定头文件和源文件所在处
如
[文件寻找 Makefile 错误示例](../Code/Chapter-3-4/test/Makefile)