# sese-plugin

sese-core 的插件实现

# Struct & Usage

每一个插件的为一个 模块（Module），模块包含有对应的 模块信息（ModuleInfo）。

例如声明模块：

https://github.com/libsese/sese-plugin/blob/94d593b7da82ffadb9a3df46ad6ab160039230ae/test/MyModule.cpp#L22-L26

每一个插件还有且仅有一个 类工厂（ClassFactory）或实现 类工厂基类接口（BaseClassFactory）的其它类。

例如为类工厂注册类：

假设已实现 Bye 和 Hello 两个类且继承自 **sese::plugin::BaseClass**

https://github.com/libsese/sese-plugin/blob/94d593b7da82ffadb9a3df46ad6ab160039230ae/test/MyModule.cpp#L28-L31

自此模块即配置完成

# More

设计思想来自 https://www.zhihu.com/question/52538590/answer/137136003

模块的导入和使用请转至
[sese-core](https://github.com/libsese/sese-core.git) 
查看相关实现和用法。
