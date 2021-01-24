# 关于 vector 的各种常用操作

## 插入元素

```
    vector<int> v(4);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    v[3]=5;//此时v为2 7 9 5

    v.insert(v.begin(),8);//在最前面插入新元素,此时v为8 2 7 9 5
    v.insert(v.begin()+3,1);//在迭代器中下标为3的元素前插入新元素,此时v为8 2 7 1 9 5
    v.insert(v.end(),3);//在向量末尾追加新元素,此时v为8 2 7 1 9 5 3
    v.insert(v.end(),3,0);//在尾部插入3个0,此时v为8 2 7 1 9 5 3 0 0 0

    int a[] = {1,2,3,4};
    v.insert(v.end(),a[2],a[1]);//在尾部插入a[2]个a[1],此时v为8 2 7 1 9 5 3 0 0 0 2 2 2
```

## 删除元素

**pop_back()** 来删除容器尾部的元素

```
    data.pop_back(); // Remove the last element
```

## 容器大小

```
    vector<int> v(4);
    v[0]=2;
    v[1]=7;
    v[2]=9;
    v[3]=5;
    s=v.size();
    //s=4
```

## 字符串截取 substr 函数

```
     vector<int> v(7);
     v.substr(3,2);
     //3是开始截取的位置，2是截取的长度
```
