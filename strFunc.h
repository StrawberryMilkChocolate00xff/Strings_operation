/*
函数描述：
函数：
[函数的功能]
[对返回值的说明]
[对参数的说明]
*/

/*函数：
安全的复制字符串
返回1
其中第三个参数n表示包括0x00的字符串长度
*/
unsigned short int str_Cpy(char *t, char *s, unsigned long int n)
{
    unsigned int i = 0;
    //将字符串进行逐个复制
    for (i = 0; i < n - (unsigned long int)1; i++)
    {
        t[i] = s[i];
    }

    return 1;
}

/*函数：
比较两个字符串是否一致
若返回1则代表一致、返回0则代表不一致
*/
unsigned short int str_Cmp(char *t, char *s)
{
    //判断两个字符串长度是否相等
    unsigned long int a = str_Len(t);
    unsigned long int b = str_Len(s);
    if (a == b)
    {
        //相等，则开始进行比较
        int n = 0;
        //判断是否读到结尾
        while (
            !(unsigned short int)t[n] == (unsigned short int)0 &&
            !(unsigned short int)s[n] == (unsigned short int)0)
        {
            //判断两个字符是否相等
            if ((unsigned short int)t[n] == (unsigned short int)s[n])
            {
            }
            else
            {
                return 0;
            }
            n++;
        }

        //所有字符全部相同，所以两个字符相同，所以返回1
        return 1;
    }
    else
    {
        //不相等，直接返回0
        return 0;
    }
}

/*函数：
包括结尾0x00的获取字符串的长度
返回包括0x00的字符串的长度
*/
unsigned long int str_Len(char *s)
{
    unsigned long int n = 0;
    //一直读取字符串，直到读到0x00
    while (!(unsigned short int)s[n] == 0)
    {
        n++;
    }

    return n + 1;
}

/*函数：
将字符串中的部分内容进行替换、替换的内容不包括0
替换成功则返回1、替换失败则返回0、偏移值过大则返回-1
offset指的是从字符串头开始的偏移值
*/
unsigned short int str_PartCpy(char *t, char *s, unsigned long int offset)
{
    unsigned long int check_Len_target = str_Len(t);
    unsigned long int check_Len_source = str_Len(s);

    //如果目标字符串小于原字符串大小则无法进行替换
    if (check_Len_target < check_Len_source - 1)
    {
        return 0;
    }
    //如果偏移长度与原字符串长度的和大于目标字符串长度则无法进行替换
    else if (offset + check_Len_source > check_Len_target)
    {
        return -1;
    }
    else
    {
        unsigned long int n = 0, i = 0;
        for (
            n = offset, i = 0;
            i < check_Len_source - 1;
            n++, i++)
        {
            t[n] = s[i];
        }
        return 1;
    }
}

