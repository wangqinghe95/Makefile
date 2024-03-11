# 字符串处理函数

## subst

`$(subst) <from>,<to>,<text>`

1. 名称：字符串替换函数
2. 功能：把字串<text> 中的 <from> 字符串替换成 <to>
3. 返回：函数返回被替换过后的字符串
4. 示例
   1. `$(subst) ee,EE,feet on the street`
   2. 把 feet on the street 中的 ee 替换成 EE

## patsubst

`$(patsubst <pattern>,<replacement>,<text>)`

1. 名称：模式字符串替换函数
2. 功能：查找 <text> 中的单词（单词以“空格”、“Tab”或“回车”“换行”分隔）是否符合模式<pattern> ，如果匹配的话，则以 <replacement> 替换。
    + <pattern> 可以包含通配符 %，表示任意长度的字符串。
    + 如果 <replacement> 中也包含 %，那么 <replacement> 中的 % 将代表 <pattern> 中的 % 所代表的字符串
    + 可以用 \ 来转义真正含义的 % 字符
3. 返回：函数返回被替换过后的字符串
4. 示例
   + `$(patsubst) %.c, %.o,x.c.c bar.c`
   + 将字串 x.c.c bar.c 符合模式 %.c 的单词都替换成 %.o，返回结果是 x.c.o bar.o
5. 等同于
```
obejcts = foo.o bar.o baz.o
$(objects:.o=.c)
```

## strip

`$strip <string>`
1. 名称：去空格函数
2. 功能：去掉<string> 字符串中开头和结尾的空字符
3. 返回：返回被去掉空格的字符串值
4. 示例
   1. `$(strip a b c)`
   2. 将字串去掉开头和结尾的空格，结果是 a b c

## finstring

`$(findstring <find>,<in>)`

1. 名称：查找字符串函数
2. 功能：在字符串 <in> 中查找 <find> 字串
3. 返回：如果找到，则返回 <find>，否则返回空字符串
4. 示例
```
$(findstring a,a b c)
#(findstring a,b c)
```
第一个函数返回 a 字符串，第二个返回空字符串

## filter

`filter <pattern...>,<text>`
1. 名称：过滤函数
2. 功能：以 <pattern> 模式过滤 <text> 字符串中的单词，保留符合模式 <pattern> 的单词。可以有多个模式
3. 返回：返回符合模式 <pattern> 的字串
4. 示例
```
sources := foo.c bar.c baz.s ugh.h
foo : $(fources)
    cc $(filter %.c %.s,$(sources)) -o foo  # 返回的值就是 foo.c bar.c baz.s
```

## filter-out

`$(filter-out <pattern...>,<text>)`

1. 名称：反过滤函数
2. 功能：以 <pattern> 模式过滤 <text> 字符串中的单词，去除符合模式 <pattern> 的单词。可以有多个模式
3. 返回：返回不符合模式 <pattern> 的字串
4. 示例
```
objects=main1.o main2.o bar.o
mains=main1.o main2.o
$(filter-out $(mains),$(objects)) 返回值是 foo.o, bar.o
```

## sort

`$(sort <list>)`

1. 名称：排序函数
2. 功能：给字符串 <list> 中的单词排序（升序）
3. 返回：返回排序后的字符串
4. 示例：`$(sort foo bar lose)`  返回 bar foo lose
5. 备注：sort 函数会去掉 <list> 中相同的单词

## word

`$(word <n>,<text>)`

1. 名称：取单词函数
2. 功能：取字符串 <text> 中的第 n 个单词（index 从 1 开始）
3. 返回：返回字符串 <text> 中第 n 个单词。如果 n 比 <text> 中的单词数要大，那么返回空字符串
4. 示例：
`$(word 2, foo bar baz)` 
返回的值 bar

## wordlist

`$(wordlist <ss>,<e>,<text>)`

1. 名称：取单词串函数
2. 功能：从字符串 <text> 中取从 <ss> 开始到 <e> 的单词串，<ss> 和 <e> 是一个数字
3. 返回：返回字符串 <text> 中从 <ss> 开始到 <e> 的单词串。
   1. 如果 <ss> 比 <text> 中的单词数要大，那么返回空字符串
   2. 如果 <e> 大于 <text> 中的单词数，那么就返回 <ss> 到 <text> 结束的单词串
4. 示例：
`$(wordlist 2,3, foo bar, baz)`
返回 bar baz

## words
1. 名称：单词个数统计函数
2. 功能：统计 <text> 中字符串中的单词个数
3. 返回：返回 <text> 中的单词数
4. 示例：
`$(words, foo, bar baz)` 
返回值是 3
5. 备注：如果想要去最后一个单词，`$(word $(words <text>), <text>)`

## firstword
1. 名称：取首单词函数
2. 功能：取字符串 <text> 中的第一个单词
3. 返回：字符串 <text> 中的第一个单词
4. 示例：$(firstword foo bar) 返回值是 foo
5. 备注：效果等同于 `word 1,<text>`

## 应用

以上所有字符串操作函数，搭配使用可以完成比较复杂的功能

make 使用 VPATH 变量来指定依赖文件的搜索路径，我们可以利用这个搜索路径来指定编译器对头文件的搜索路径参数 CFLGAS
如：
`override CFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH)))`

比如，$(VPATH) 的值是  src:../headers，那么上个这个命令返回的字符串就是 -Isrc -I../headers，这正是 cc 或者 gcc 搜索头文件路径的参数