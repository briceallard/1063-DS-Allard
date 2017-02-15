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
