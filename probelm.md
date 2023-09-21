## C语言编译undefined reference to ‘pow’

pow内的函数是常数，如果其中一个参数是变量的话就会报异常。所以引用time包的时候一定要在编译的时候加-lm信息。