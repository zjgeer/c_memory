#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
	内存相关的函数实现
	1、内存字节复制函数
	2、内存复制n字节函数
	3、内存块复制函数
	4、
*/

/* 1、内存字节复制函数 */
char *mystrcpy(char *dest,const char *src)
{
	assert(dest != NULL && src != NULL);
	
	char *temp = dest;
	
	while((*temp++ = *src++) != '\0');
	if(*(temp) != '\0')
	{
		*temp = '\0';
	}
	return dest;
}

/* 2、内存复制n字节函数 */
char *mystrncpy(char *dest, const char *src, int len)
{
	assert(dest != NULL && src != NULL);
	
	char *temp = dest;
	int i = 0;
	
	while(i++ < len && (*temp++ = *src++) != '\0');
	
	if(*(temp) != '\0')
	{
		*temp = '\0';
	}
	return dest;
}


	
/* 3、内存块复制函数 */
void *memmove(void *dest, const void *src, int count)
{
	assert((src != NULL) && (dest != NULL));	//  判断是否存在未初始化的指针情况
	char *tmp, *s;
	
	if(dest <= src)				// 目标指针在源数据指针之前，考虑到覆盖的问题，按照正常的赋值顺序，从前往后复制
	{
		tmp = (char *) dest;
		s = (char *) src;
		while( count-- )
		{
				*tmp++ = *s++;
		}
	}
	else {						// 目标指针在源数据之后，考虑会将源程序覆盖的问题，从后往前复制
		tmp = (char *) (dest + count);
		s = (char *) (src + count);
		while(count--)
		{
			*--tmp = *--s;
		}
	}
	return dest;
}

int main(int argc,char *argv[])
{
	int x = 12345;
	int y = 0;
	int *xp = &x;
	int *yp = &y;
	memmove(&y,&x,sizeof(x));
	printf("-dest = %x--src = %x-----%d---sizeof(x) = %d ----\n",&y,&x,y,sizeof(x));
	
	return 1;
}