# override 命令

如果有变量是 make 的命令行参数设置的，那么 Makefile 中对这个变量的赋值会被忽略，如果你想在 Makefile 中设置这类参数的值，那么可以使用 override 指令

## override 语法
```
override <varable>; = <value>;

override <varable>; := <value>;
```

可以追加
`override <varable>; += <more text>;`


对于多行的变量定义，可以使用 define 指令，在 define 指令前，也可以使用 override 指令，如
```
override define foo
bar endef
```