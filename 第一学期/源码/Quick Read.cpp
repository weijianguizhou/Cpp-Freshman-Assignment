// 快速读入：用 getchar 逐字符读取，比 cin 快很多
#include <cstdio>

inline void read(int& a)
{
   int s = 0, w = 1;
   char ch = getchar();
   // 跳过非数字字符，遇到负号记为 -1
   while (ch != EOF && (ch < '0' || ch>'9'))
   {
           if (ch == '-')
                   w = -1;
           ch = getchar();
   }
   // 读入连续数字
   while (ch >= '0' && ch <= '9')
   {
           s = s * 10 + ch - '0';
           ch = getchar();
   }
   a = s * w;
}

int main()
{
   int a, b;
   read(a);
   read(b);
   printf("%d + %d = %d\n", a, b, a + b);
   return 0;
}
