<h4>***Questions 1 & 2***</h4>
```cpp
void A (char ch){
  if(('A'<= ch) && (ch <= 'H')){
    A(ch-1);
    cout<<ch<<endl;
  }else{
    cout<<endl;
  }
}
```
<h4>1. Trace A('C')</h4>
ch = 'C' => ch - 1 =><br>
cout << 'B'        =><br>
ch = 'B' => ch - 1 =><br>
cout << 'A'        =><br>
ch = 'A' => ch - 1 =><br>
cout << '@'        =><br>
ch = '@' => Fails  =><br>
cout << endl;
<h4>2. Trace A('C')</h4>
ch = '3' => Fails  =><br>
cout << endl;
<h4>***Question 3***</h4>
```cpp
int B (int n){
  if(n==0)
    return 1;
  else{
    cout<<n<<endl;
    return n * B(n-1);
  }
}
```
<h4>3. Trace B(4)</h4>
n = 4    => Else    =><br>
cout << 4 << endl;  =><br>
return 4 => B(4-1)  =><br>
n = 3    => Else    =><br>
cout << 3 << endl;  =><br>
return 3 => B(3-1)  =><br>
n = 2    => Else    =><br>
cout << 2 << endl;  =><br>
return 2 => B(2-1)  =><br>
n = 1    => Else    =><br>
cout << 1 << endl;  =><br>
return 1 => B(1-1)  =><br>
n = 0    => Return 1=><br>
<h5>Output:</h5>
```
4
3
2
1
```
<h4>***Question 4***</h4>
```cpp
int C (int n){
  if(n<2)
    return 0;
  else
    cout<<n<<endl;
    return (1 + C(n/2));
}
```
<h4>4. Trace C(16)</h4>
n = 16    => Else     =><br>
cout << 16 << endl;   =><br>
return    => n/2      =><br>
n = 8     => Else     =><br>
cout << 8 << endl;    =><br>
return    => n/2      =><br>
n = 4     => Else     =><br>
cout << 4 << endl;    =><br>
return    => n/2      =><br>
n = 2     => Else     =><br>
cout << 2 << endl;    =><br>
return    => n/2      =><br>
n = 1     => n IS < 2 =><br>
RETURN 0
<h5>Output:</h5>
```
16
8
4
2
```
