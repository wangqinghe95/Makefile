# 环境变量 Makefiles

如果在当前环境中定义了环境变量 MAKEFILES，那么 make 会将这个变量中的值做一个类似于 include 动作。

这个变量的值是其他的 Makefile，用空格分隔，只是与 include 不同的是，这个环境变量中引入的 Makefile 的目标不会起作用，如果环境变量中的文件发现错误，make 也不会理会。

但是建议不适用这个环境变量，因为这个变量一旦被定义，那么当你使用 make 时，所有的 Makefile 都会受到它的影响。