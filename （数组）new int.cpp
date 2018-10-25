int num;
cout<<“请输入数组大小”;
cin>>num;
int *p=new int[num];
//这里就可以使用这个动态数组了。
delete []p; //不用的时候务必自己删除内存

