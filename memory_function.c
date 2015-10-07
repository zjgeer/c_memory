#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
	�ڴ���صĺ���ʵ��
	1���ڴ��ֽڸ��ƺ���
	2���ڴ渴��n�ֽں���
	3���ڴ�鸴�ƺ���
	4��
*/

/* 1���ڴ��ֽڸ��ƺ��� */
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

/* 2���ڴ渴��n�ֽں��� */
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


	
/* 3���ڴ�鸴�ƺ��� */
void *memmove(void *dest, const void *src, int count)
{
	assert((src != NULL) && (dest != NULL));	//  �ж��Ƿ����δ��ʼ����ָ�����
	char *tmp, *s;
	
	if(dest <= src)				// Ŀ��ָ����Դ����ָ��֮ǰ�����ǵ����ǵ����⣬���������ĸ�ֵ˳�򣬴�ǰ������
	{
		tmp = (char *) dest;
		s = (char *) src;
		while( count-- )
		{
				*tmp++ = *s++;
		}
	}
	else {						// Ŀ��ָ����Դ����֮�󣬿��ǻὫԴ���򸲸ǵ����⣬�Ӻ���ǰ����
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