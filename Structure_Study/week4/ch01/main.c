//#include <cstddef>
//#ifndef _AvlTree_H
//struct AvlNode;
//typedef struct AvlNode* Position;
//typedef struct AvlNode* AvlTree;
//typedef int ElementType;
//
//AvlTree MakeEmpty(AvlTree T);
//Position Find(ElementType X, AvlTree T);
//Position FindMax(AvlTree T);
//AvlTree Insert(ElementType X, AvlTree T);
//AvlTree Delete(ElementType X, AvlTree T);
//ElementType Retrieve(Position P);
//
//
//#endif // !_AvlTree_H
//
//struct AvlNode
//{
//	ElementType Element;
//	AvlTree Left;
//	AvlTree Right;
//	int Height;
//
//};
//
//static int
//Height(Position P)
//{
//	if (P == NULL)
//		return -1;
//	else
//		return P->Height;
//}
//
////向AVL插入节点，插入后使用Avl旋转不改变AVL性质
//
//AvlTree
//Insert(ElementType X, AvlTree T)
//{
//	if (T == NULL)
//	{
//		T = malloc(sizeof(struct AvlNode));
//		if (T == NULL)
//			FatalError("Out Of Space");
//		else
//		{
//			T->Element = X, T->Height = 0;
//			T->Left = T->Right = NULL;
//		}
//	}
//	else
//		if (X < T->Element)
//		{
//			T->Left = Insert(X, T->Left);
//			if (Height(T->Left) - Height(T->Right) == 2)
//				if (X < T->Left->Element)
//					T = SingleRotateWithLeft(T);
//				else
//					T = DoubleRotateWithLeft(T);
//		}
//		else
//			if (X > T->Element)
//			{
//				T->Right = Insert(X, T->Right);
//				if (Height(T->Right) - Height(T->Left) == 2)
//					if (X > T->Right->Element)
//						T = SingleRotateWithRight(T);
//					else
//						T = DoubleRotateWithRight(T);
//			}
//	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
//	return T;
//
//}
////要注意的是，所有旋转函数，都是接收的来自被破环的最近的根节点
////执行单旋转
//static Position
//SingleRotateWithLeft(Position K2)
//{
//	Position K1;//k1在这里被定义，然后指向K2左子树，k1是共用地址了？？？
//	K1 = K2->Left;
//	K2->Left = K1->Right;
//	K1->Right = K2;
//
//	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
//	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
//	return K1;
//}
//
//static Position
//SingleRotateWithRight(Position K1)
//{
//	Position K2;
//	K2 = K1->Right;
//	K1->Right = K2->Left;
//	K2->Left = K1;
//
//	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
//	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
//	return K2;
//}
////执行双旋转
//static Position
//DoubleRotateWithLeft(Position K3)
//{
//	K3->Left = SingleRotateWithRight(K3->Left);
//	return SingleRotateWithLeft(K3);
//}
//
//static Position
//DoubleRotateWithRight(Position K4)
//{
//	K4->Right = SingleRotateWithLeft(K4->Right);
//	return SingleRotateWithRight(K4);
//}
//
////查找
//Position
//Find(ElementType X, AvlTree T)
//{
//	if (T == NULL)
//		return NULL;
//	else
//	{
//		if (T->Element < X)
//			return Find(X, T->Right);
//		else if (T->Element > X)
//			return Find(X, T->Left);
//		else
//			return T;
//	}
//}
////查找最大值
//Position
//FindMax(AvlTree T)
//{
//	if (T == NULL)
//		return NULL;
//	else
//		if (T != NULL)
//			return FindMax(T->Right);
//	return T;
//}
//Position
//FindMin(AvlTree T)
//{
//	if (T == NULL)
//		return NULL;
//	else
//		if (T != NULL)
//			return FindMin(T->Left);
//	return T;
//}
//
////做空
//AvlTree MakeEmpty(AvlTree T)
//{
//	if (T != NULL)
//	{
//		MakeEmpty(T->Right);
//		MakeEmpty(T->Left);
//		free(T);
//	}
//	return T;
//}
////恢复
//
//ElementType Retrieve(Position P)
//{
//	if (P != NULL)
//		return P->Element;
//	else
//		return -1;
