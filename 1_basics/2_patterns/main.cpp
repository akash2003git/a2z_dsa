#include <bits/stdc++.h>

using namespace std;

void p1(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p3(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << j + 1;
    }
    cout << endl;
  }
}

void p4(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i;
    }
    cout << endl;
  }
}

void p5(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p6(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
      cout << j;
    }
    cout << endl;
  }
}

void p7(int n) {
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < n - i; k++) {
      cout << " ";
    }
    for (int l = 0; l < (2 * i - 1); l++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p8(int n) {
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < i - 1; k++) {
      cout << " ";
    }
    for (int l = 0; l < 2 * (n - i) + 1; l++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p9(int n) {
  n = n / 2;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < n - i; k++) {
      cout << " ";
    }
    for (int l = 0; l < (2 * i - 1); l++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < i - 1; k++) {
      cout << " ";
    }
    for (int l = 0; l < 2 * (n - i) + 1; l++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p10(int n) {
  for (int i = 1; i < 2 * n; i++) {
    int stars = i;
    if (i > 5)
      stars = 2 * n - i;
    for (int j = 1; j <= stars; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p11(int n) {
  // for (int i = 0; i < n; i++) {
  //   if (i % 2 == 0) {
  //     for (int j = 0; j <= i; j++) {
  //       if (j % 2 == 0)
  //         cout << "1";
  //       else
  //         cout << "0";
  //     }
  //   } else {
  //     for (int j = 0; j <= i; j++) {
  //       if (j % 2 == 0)
  //         cout << "0";
  //       else
  //         cout << "1";
  //     }
  //   }
  //   cout << endl;
  // }
  int start = 1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      start = 1;
    else
      start = 0;
    for (int j = 0; j <= i; j++) {
      cout << start;
      start = 1 - start;
    }
    cout << endl;
  }
}

void p12(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j;
    }
    for (int j = 1; j <= 2 * (n - i); j++) {
      cout << " ";
    }
    for (int j = i; j >= 1; j--) {
      cout << j;
    }
    cout << endl;
  }
}

void p13(int n) {
  int count = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << count << " ";
      count++;
    }
    cout << endl;
  }
}

void p14(int n) {
  for (int i = 1; i <= n; i++) {
    for (char ch = 'A'; ch < 'A' + i; ch++) {
      cout << ch;
    }
    cout << endl;
  }
}

void p15(int n) {
  for (int i = n; i >= 1; i--) {
    for (char ch = 'A'; ch < 'A' + i; ch++) {
      cout << ch;
    }
    cout << endl;
  }
}

void p16(int n) {
  char ch = 'A';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << ch;
    }
    ch++;
    cout << endl;
  }
}

// void p17(int n) {
//   for (int i = 1; i <= n; i++) {
//     for (int k = 0; k < n - i; k++) {
//       cout << " ";
//     }
//     char ch = 'A';
//     int bp = i - 1;
//     for (int l = 0; l < (2 * i - 1); l++) {
//       if (l <= i - 1) {
//         cout << ch;
//         ch = ch + 1;
//       } else {
//         if (l == i) {
//           ch = ch - 1;
//         }
//         ch = ch - 1;
//         cout << ch;
//       }
//     }
//     cout << endl;
//   }
// }

void p17(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << " ";
    }
    char ch = 'A';
    for (int j = 0; j < (2 * i + 1); j++) {
      cout << ch;
      if (j < i)
        ch++;
      else
        ch--;
    }
    cout << endl;
  }
}

void p18(int n) {
  for (int i = 1; i <= n; i++) {
    char ch = 'A' + n - i;
    for (int j = 1; j <= i; j++) {
      cout << ch;
      ch++;
    }
    cout << endl;
  }
}

void p19(int n) {
  n = n / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
      cout << "*";
    }
    for (int j = 1; j <= 2 * (i - 1); j++) {
      cout << " ";
    }
    for (int j = 1; j <= n - i + 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    for (int j = 1; j <= 2 * (n - i); j++) {
      cout << " ";
    }
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p20(int n) {
  n = n / 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    for (int j = 1; j <= 2 * (n - i); j++) {
      cout << " ";
    }
    for (int j = 1; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j < n - i + 1; j++) {
      cout << "*";
    }
    for (int j = 1; j <= 2 * i; j++) {
      cout << " ";
    }
    for (int j = 1; j < n - i + 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void p21(int n) {
  for (int i = 1; i <= n; i++) {
    // if (i == 1 || i == n) {
    //   for (int j = 1; j <= n; j++) {
    //     cout << "*";
    //   }
    //   cout << endl;
    // } else {
    //   for (int j = 1; j <= n; j++) {
    //     if (j == 1 || j == n) {
    //       cout << "*";
    //     } else {
    //       cout << " ";
    //     }
    //   }
    //   cout << endl;
    // }
    for (int j = 1; j <= n; j++) {
      if (i == 1 || j == 1 || i == n || j == n) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void p22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int right = (2 * n - 2) - j;
      int down = (2 * n - 2) - i;
      cout << (n - min(min(top, down), min(left, right))) << " ";
    }
    cout << endl;
  }
}

int main() {
  p22(5);
  return 0;
}
