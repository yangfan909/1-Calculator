## 实验描述

实现一个计算器，支持四则运算`+` `-` `*` `/`，括号操作`()`以及指数运算`**`。

## 输入格式

输入的格式为浮点数或整数，不考虑正负数。

## 输出格式

输出的格式统一以浮点数形式呈现。

## 输入输出样例

**输入** #1

```
3 + 5 - 2
```

**输出** #1

```
6.000000
```

**输入** #2

```
3 + 1.5
```

**输出** #2

```
4.500000
```

**输入** #3

```
3 + (-1)
```

**输出** #3

```
Error: syntax error 
```

### Getting Started

- 环境配置

```shell
sudo apt install flex
sudo apt install byacc 或 sudo apt install bison
sudo apt−get install −y build−essential
```

- 编译：`make test`
- 执行：`./test`  
- 退出执行：`ctrl + D`

- 清除编译文件：`make clean`

> 注：
>
> 使用yacc编译：
>
> ```
> yacc -d test.y
> ```
>
> 使用bison编译：
>
> ```
> bison -d test.y
> ```
>
> 保证.lex文件中包含的语法分析器头文件名称与实际名称一致。