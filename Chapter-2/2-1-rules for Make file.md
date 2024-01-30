# Makefile 的规则

Makefile 的书写规则如下
```
target ... : prerequisites ...
    recipe
    ...
    ...
```

1. target: 要生成的目标文件，可是是一个 object file，也可以是一个执行文件，还可以是一个标签，即一个伪目标
2. prerequisites: 生成 target 所依赖的文件或者其他 target
3. recipe: 生成 target 所要执行的命令

上述规则的意思是，使用 prerequisites 这些文件，执行 recipe 命令，生成 target 目标
需要说明的是，如果 prerequisites 中有一个文件要比 target 文件更 “新” 的话，就会触发 recipe 的执行命令

这就是 Makefile 的核心规则，剩下的内容都是围绕这个规则展开