#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int a, b, c, d, e, f, g, h;
   cin >> a >> b >> c >> d >> e >> f >> g >> h;
   int A, B, C, D;

   A = a * e, B = b * e + a * f, C = e * c + a * g, D = d;
   if(B % A == 0 && C % A == 0) {
      
      B = B / A, C = C / A;
   }
   
   cout << A << " " << B << " " << C << " " << D << '\n';

   A = a * e, B = b * e - a * f, C = e * c - a * g, D = d;
   if(B % A == 0 && C % A == 0) {
      B = B / A, C = C / A;
   }

   cout << A << " " << B << " " << C << " " << D << '\n';



   return 0;
} 