# 关于数组实现队列

## 	<u>Create Queue</u>

​	在申请Q的内存时有个类型转换：将malloc返回的内存空间地址转成(ElemType*)类型然后赋值给Q

## 	  <u>Front</u>

​	~~~C

	ElementType Front(Queue Q)

{
	if (!Isempty(Q))
	{
		return Q->Array[Q->Front];
	}
	Error("empty queue");
	return 0;
}

这里关于实现Front--不大能理解。

​	
