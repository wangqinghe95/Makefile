# 操作文件名的函数

每个函数的参数字符串都会被当作一个或者一系列的文件名来对待

## dir
`$(dir <name>)`

1. 名称：取目录函数
2. 功能：从文件名寻 <names> 中取出目录部分。
   1. 目录部分是指最后一个反斜杠之前的部分
   2. 如果没有反斜杠，则返回 ./
3. 返回：返回文件名序列 <names> 的目录部分
4. 示例
`$(dir src/foo.c hacks)` 
返回值就是 src/ ./

## notdir

`$(notdir <names...)`

1. 名称：取文件名--notdir
2. 功能：从文件名序列 <names> 中取出非目录部分
   1. 非目录部分是最后一个反斜杠之后的部分
3. 返回：返回文件名序列 <names> 的非目录部分
4. 示例
`$(notdir src/foo.c hacks)`
返回 foo.c hacks

## suffix
`$(suffix <names...>)`

1. 名称：取后缀函数 suffix
2. 功能：从文件名序列 <names> 中取出各个文件名的后缀
3. 返回：返回文件名序列 <names> 的后缀序列，如果文件没有后缀，则返回空字符串
4. 示例
`$(suffix src/foo.c src-1.0/bar.c hacks)`
返回值是 .c .c

## basename
`$(basename <names...>)`

1. 名称：取前缀函数 basename
2. 功能：从文件名序列 <names> 中取出各个文件名的前缀
3. 返回：返回文件名序列 <names> 的前缀序列，如果文件没有前缀，则返回空字符串
4. 示例
`$(suffix src/foo.c src-1.0/bar.c hacks)`
返回值是 src/foo src-1.0/bar hacks

## addsuffix
`$(addsuffix <suffix>,<names...>)`
1. 名称：加后缀函数
2. 功能：把后缀 <suffix> 加到 <names> 中的每一个单词后面
3. 返回：返回加过后缀的文件名序列
4. 示例
`$(addsuffix .c,foo bar)`
返回值是 foo.c bar.c

## addprefix
`$(addprefix <prefix>,<names...>)`
1. 名称：加前缀函数
2. 功能：把前缀 <prefix> 加到 <names> 中的每一个单词后面
3. 返回：返回加过前缀的文件名序列
4. 示例
`$(addprefix src/,foo bar)`
返回值是 src/foo,src.bar

## join

`$(join <list1>,<list2>)`
1. 名称：连接函数
2. 功能：把 <list2> 中的单词对应地加到 <list1> 的单词后面。
   1. 如果后者的单词个数要比前者的个数多，那么多出去的单词将保持原样
   2. 反之，<list2> 中多出来的单词将被复制到 <list1> 中去
3. 返回：返回连接后的字符串
4. 示例
`$(join aa bbb, 111 222 333)`
返回 aa111 bbb2222 333