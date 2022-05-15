# Problems Using Pointers

## Uninitialize Pointer

When we declare the pointer but dont point the pointer to at any position and try to assign value to it , this cond. will give the run time error that uniniliazed pointer.

```cpp
int *p;
*p=25; // Wrong here p is not pointing to any address.

// here the correct way
int x=10;
1. p = &x;
2. p = (int*)0x5638;
3. p = new int[5];

cout<<*p;
```

## Memory Leak

When we don't DeAllocate the memory this will lead the problem of memory leak.

```cpp
int *p = new int[5];
/*.
.
.
.
.
. work done
.

After all the work done we have to deallocate the memory.
*/
p = NULL;
p = nullptr;
p = 0;
```

## Dangling Pointer

When we try to accessing the memory which is already deAllocated , this situation lead to the problem of dangling pointer.

```cpp
void fun(int *q){
    /*.
    ..
    .
    .
    .*/
    delete []q;
}

void main(){
    int *p  = new int[5];
    /*.
    .
    ..*/
    fun(p);
    cout<<*p;

}
```
