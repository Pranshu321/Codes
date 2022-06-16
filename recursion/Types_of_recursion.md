# What is Recursion?

The process of calling of function by itself directly or indirectly is called recursion and the corresponding function is called a recursive function.

### There are five types of recursion

1. Tail Recursion
2. Head Recursion
3. Tree Recursion (It is same as recursive tree)
4. Indirect Recursion
5. Nested Recursion

## Tail Recursion

The calling of the function is taking place at last line or we say at last stage no other statement after the calling of function.

- Note :- Every loop can be converted to Tail recursion and vice versa.
  ![image](https://user-images.githubusercontent.com/86917304/173109627-c4e8f573-2082-4da9-9dc2-563c60be95cd.png)

```cpp
void func(int n){
    if(n>0){
        cout<<n<<"\n";
        func(n-1);
    }
}

```

**Space complexity of recursion O(n)**
**Time complexity of recursion O(n)**

```cpp
// By Loop
void func(int n){
    while(n>0){
        cout<<n<<"\n";
        n--;
    }
}


```

**Time Complexity is O(n)**
**Space by loop space complexity O(1)**

## Head Recursion

The first statement is calling of function there should be nothing statement before that.
![image](https://user-images.githubusercontent.com/86917304/173109699-364b033d-544d-4594-ad74-9e34a37a7e58.png)

- Note :- This cant be directly converted to loop and vice versa.

```cpp
void func(int n){
    if(n>0){
        func(n-1);
        printf("%d",n);
    }
}
```

**Space complexity of recursion O(n)**
**Time complexity of recursion O(n)**

```cpp
// By loop
void func(int n){
    int i=1;
    while(i<=n){
        printf("%d",i);
      i++;
    }
}
```

**Space complexity of recursion O(1)**
**Time complexity of recursion O(n)**

## Tree Recursion

For getting the idea what tree recursion is lets first discuss about **Linear Recursion** , If a recursive function call itself one time then its known to be **Linear Recursion** but if call more than one time then comes under the category of **Tree Recursion**.
![image](https://user-images.githubusercontent.com/86917304/173109721-414b545b-63d7-4a11-b063-1a4fd9ad6b99.png)

```cpp
void func(int n){
    if(n>0){
        printf("%d",n);

        // First calling
        func(n-1);

        // Second Calling
        func(n-1);
    }
}

```

**Space complexity of recursion O(n)**
**Time complexity of recursion O(n)**

## Indirect Recursion

This is the recursion in which one function call another function , or we can say that there is a cycle formed , In this indirect recursion.
![image](https://user-images.githubusercontent.com/86917304/173109737-5d615dcd-1eff-492b-92a0-44c4208acbc1.png)

```cpp
void func_b(int n){
    if(n>1){
        printf("%d",n);
        func_a(n/2);
    }
}

void func_a(int n){
    if(n>0){
        printf("%d",n);
        func_b(n-1);
    }
}
```

**Space complexity of recursion O(n)**
**Time complexity of recursion O(n)**

## Nested Recursion

In this type of recursion , The recursive function is pass as the parameter of the recursive call . This we also say **recursion inside recursion**.
![image](https://user-images.githubusercontent.com/86917304/173109753-3ee5db3a-6f7d-4fd4-a431-ee042696fa0c.png)

```cpp
void func(int n){
    if(n>0){

        func(func(n-1));
        printf("%d",n);
    }
}
```

**Space complexity of recursion O(n)**
**Time complexity of recursion O(n)**

## Why there less Space Complexity when we use loops?

If talk about the case of recursion as function every time calls itself for each call a _separate activation record_ created in stack.So if there’s **n** no of call then it takes **n unit of memory inside stack** so it’s space complexity is **O(n)** . But in case of loop only once activation instance or record is created that's why there time complexity is less than recursion case.
