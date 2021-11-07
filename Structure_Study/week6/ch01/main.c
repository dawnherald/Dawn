#include"DisjSet.h"

void 
Initialialize(DisjSet S)
{
	int i;

	for (i = NumSet; i > 0; i--)
		S[i] = 0;
}
//不相交集合初始化

void
SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	S[Root2] = Root1;

}

SetType
Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)
		return 0;
	else
		return Find(S[X], S);

}

//void                      ////这里是按照高度进行合并
//SetUnion(DisjSet S, SetType Root1, SetType Root2)
//{
//	if (S[Root2] < S[Root1])////当root2节点树大小更大（负的更多），就把root内内容存入root2；
//		S[Root1] = Root2;
//	else
//	{
//		if (S[Root1] == S[Root2])////当root1和root2大小一样时，给root1负1，然后把root1放在root2的内容里面；相当于root1是root2的父亲
//			S[Root1]--;
//		S[Root2] =Root1;
//	}
//}

SetType
Find(ElementType X, DisjSet S)
{
	if (X <= 0)
		return X;
	else
	{
		return S[X] = Find(S[X],S);//find里面的S【X】是他的父亲节点，前面的S【X】用来依次保存返回的根地址；
	}
}
