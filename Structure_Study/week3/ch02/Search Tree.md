# 二叉查找树

##  <u>Make Empty</u>

~~~c
SearchRTree MakeEmpty(SearchRTree T)
{
	if (T != NULL)
	{	
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T); 
	}
	return NULL;
}
~~~

这里先把树的左右子树位置给出再free，避免程序终止

###  <u>Delete</u>

~~~c
SearchRTree
Delete(ElementType X, SearchRTree T)
{
	Position TmpCell;

	if (T == NULL)
		Error("Element Not Find");
	else
		if (X < T->Element)
			T->Left = Delete(X,T->Left);
		else
			if (X > T->Element)
				T->Right = Delete(X,T->Right);
			else
				if (T->Left && T->Right)
				{
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					T->Right = Delete(T->Element, T->Right);
				}
				else
				{
					TmpCell = T;                    ///////
					if (T->Left = NULL)
						T = T->Right;
					else
						if (T->Right = NULL)
							T = T->Left;
					free(TmpCell);                     ////////
				}
	return T;
}

~~~

这里关于删除的递归真的很巧妙，把最后递归的底的情况放在最前面，通过递归抵达，再把删除的情况分为满儿子和不满（最终都要回到不满树节点），然后return Tree一级级的返回。==这里有点不清楚的就是因为会先FindMin删除点的右子树最小值，历程走到最后，FindMin找出的结点应该没有左子树，应该只能指向右子树吧。==文中/////之间

