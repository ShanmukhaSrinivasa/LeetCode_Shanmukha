class Solution {
public:
    int fib(int n) {
     int first = 0;
     int second =1;
     int next;

     if(n==0) return 0;
     if(n==1) return 1;

     for(int i=2; i<=n; i++)   
     {
        next = first + second;
        first = second;
        second = next;
     }

     return second;
    }
};