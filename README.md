# 基本的字符串控制函数

文件中的代码都是操作字符串的函数，至于各个函数的具体功能会在下文提供，此代码采用的是一个一个字符操作的方式进行字符串的基本操作，若有大佬有更高效的代码可以与我讨论，或者指出更好的方法解决问题
###
以下为各个函数的具体功能与参数介绍（不要给我在指针的地方加上单个字符！）：  
```
//字符串长度（带\x00），*t是要查询长度的字符串地址
unsigned int strings_length(char *t)

//字符串复制，*t是复制的目标的地址，*s被复制的字符串地址，n复制的长度
unsigned char strings_copy(char *t, char *s, unsigned int n)

//字符串比较，*t是第一个字符串的地址，*s是第二个字符串的地址
unsigned char strings_compare(char *t, char *s)

//字符串部分复制（有bug），*t是复制的目标字符串的地址，*s是被复制的字符串地址，n是复制的个数，offset是在目标字符串的偏移位数
unsigned char strings_partCopy(char *t, char *s, unsigned int n, unsigned int offset)
```
