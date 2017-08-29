/*
给定一个以p概率产生0，以1-p概率产生1的随机函数RandomP::f()，p是固定的值，但你并不知道是多少。
除此之外也不能使用任何额外的随机机制，请用RandomP::f()实现等概率随机产生0和1的随机函数。

*/

class RandomP {
public:
	static int f();
};

class Random01 {
public:
    // 用RandomP::f()实现等概率的01返回
    int random01() {
        int a = RandomP::f(), b = RandomP::f();
        while (a == b)  
        {
            a = RandomP::f(), b = RandomP::f();
        }
        if (a == 1 && b == 0)   return 1;
        else    return 0;
    }
};