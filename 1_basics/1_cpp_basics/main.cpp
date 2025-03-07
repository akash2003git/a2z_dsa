// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printName(string name) { cout << "hey " << name; }

int sum(int a, int b) { return a + b; }

void doSomething(int num) {
  cout << num << endl;
  num += 5;
  cout << num << endl;
  num += 5;
  cout << num << endl;
}

void doSomethingRef(int &num) {
  cout << num << endl;
  num += 5;
  cout << num << endl;
  num += 5;
  cout << num << endl;
}

void doSomethingArr(int arr[], int n) {
  arr[0] += 100;
  cout << "Value inside function: " << arr[0] << endl;
}

int main() {

  // ======================= I/O ========================

  // cout << "Hello World" << endl;

  // ======================= Data Types ========================

  // int (4 bytes)
  // unsigned short (4 bytes)
  // long (4 bytes)
  // unsigned long (4 bytes)
  // long long (8 bytes)

  // int x, y;
  // cin >> x >> y;
  // cout << "Value of x: " << x << " and y: " << y;

  // float (4 bytes)
  // double (8 bytes)
  // long double (10 bytes)

  // float x = 5.56;
  // cout << "Value of y: " << x;

  // string s1, s2;
  // cin >> s1 >> s2;
  // cout << s1 << " " << s2;

  // string str;
  // getline(cin, str);
  // cout << str;

  // char ch;
  // cin >> ch;
  // cout << ch;

  // ======================= If Else ========================

  // int age;
  // cin >> age;

  // if (age >= 20) {
  //   cout << "You are an adult";
  // } else if ((age >= 13) && (age <= 19)) {
  //   cout << "You are a teenager";
  // } else {
  //   cout << "You are a child";
  // }

  // if (age < 13) {
  //   cout << "You are a child";
  // } else if (age < 20) {
  //   cout << "You are a teenager";
  // } else {
  //   cout << "You are an adult";
  // }

  // if (age < 18) {
  //   cout << "Not eligible for job";
  // } else if (age <= 57) {
  //   cout << "You are eligible of job";
  //   if (age >= 55) {
  //     cout << ", but retirement soon";
  //   }
  // } else {
  //   cout << "Retirement time";
  // }

  // ======================= Switch Statement ========================

  // int day;
  // cin >> day;
  //
  // switch (day) {
  // case 1:
  //   cout << "Monday";
  //   break;
  // case 2:
  //   cout << "Tuesday";
  //   break;
  // case 3:
  //   cout << "Wednesday";
  //   break;
  // case 4:
  //   cout << "Thursday";
  //   break;
  // case 5:
  //   cout << "Friday";
  //   break;
  // case 6:
  //   cout << "Saturday";
  //   break;
  // case 7:
  //   cout << "Sunday";
  //   break;
  // default:
  //   cout << "Invalid!";
  // }

  // ======================= Arrays and Strings========================

  // int arr[5];
  // cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
  // cout << arr[0] << " " << &arr[0] << endl;
  // cout << arr[1] << " " << &arr[1] << endl;
  // cout << arr[2] << " " << &arr[2] << endl;
  // cout << arr[3] << " " << &arr[3] << endl;
  // cout << arr[4] << " " << &arr[4] << endl;

  // int arr[3][5]; // 2D array
  // arr[3][5] = 100;
  // cout << arr[3][5];

  // string s = "Akash";
  // int len = s.size();
  // cout << "Length of the string is: " << len << endl;
  // cout << "Character at the 3rd position or 2nd index is: " << s[2] << endl;
  // s[len - 1] = 's';
  // cout << s;

  // ======================= Loops ========================

  // string s = "AKASH";
  // cout << "for loop: " << endl;
  // for (int i = 0; i < s.size(); i++) {
  //   cout << s[i] << endl;
  // }
  //
  // int i = 0;
  // cout << "while loop: " << endl;
  // while (i < s.size()) {
  //   cout << s[i] << endl;
  //   i++;
  // }
  //
  // // will run atleast once even if condition not satified
  // cout << "do-while loop: " << endl;
  // i = 0;
  // do {
  //   cout << s[i] << endl;
  //   i++;
  // } while (i < 0);

  // ======================= Functions ========================

  // string name;
  // cin >> name;
  // printName(name);

  // int a, b;
  // cin >> a >> b;
  // cout << "sum = " << sum(a, b);

  // int num = 10;
  // cout << "Pass by value: " << endl;
  // doSomething(num);
  // cout << num << endl;
  // cout << "Pass by reference: " << endl;
  // doSomethingRef(num);
  // cout << num << endl;

  int n = 5;
  int arr[n];
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  doSomethingArr(arr, n);
  cout << "Value inside int main: " << arr[0] << endl;

  return 0;
}
