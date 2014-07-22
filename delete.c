//*********************************************************//
//程序功能：删除文件
//实现方法 windons API
//*********************************************************//
#include <Windows.h>
#include <stdio.h>
#include <string.h>

#define MAX 10			//限定待删文件的数量

//定义结构体用于存储待删除的文件名
struct SDelFileName
{
	const char *FileName[MAX];			//存储文件名	
	int iFileCount;						//计算文件数量
};

int main(int argc, char const *agrv[])
{
	int i;
	char ch;							//用来保存y or n
	int iFlag = 0;						//用于标记是否要强制删除
	struct SDelFileName delFile;
	delFile.iFileCount = 0;
	if (argc == 1)
	{
		printf("删除文件格式：\n");
		printf("rm [-选项] <文件名1> <文件名2> <文件名3> ..");
		printf("选项f是强制删除！");
		printf("一次最多能删除10个文件！");
		return 0;
	}
	
	for (i = 1; i < argc; i++)
	{
		if (*agrv[i] == '-')
		{
			if (strcmp(agrv[i], "-f") == 0)
			{
				iFlag = 1;
			}
		}
		else
		{
			delFile.FileName[delFile.iFileCount] = agrv[i];
			delFile.iFileCount++;
		}
	}

	for (i = 0; i < delFile.iFileCount; i++)
	{
		if (iFlag == 1)
		{
			if (!DeleteFileA(delFile.FileName[i]))
			{
				printf("删除文件错误！");
			}
			else 
			{
				printf("删除文件成功！");
			}
		}
		else
		{
			printf("是否要删除文件[%s]？（y/n）", delFile.FileName[i]);
			ch = getchar();
			if (ch == 'y')
			{
				if (!DeleteFileA(delFile.FileName[i]))
				{
					printf("删除文件错误！");
				}
				else 
				{
					printf("删除文件成功！");
				}
			}
		}
	}
	return 0;
}
