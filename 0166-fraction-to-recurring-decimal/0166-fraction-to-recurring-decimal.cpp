class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool flag =true;

        if(numerator<0&&denominator>0||numerator>0&&denominator<0){
            flag =false;
        }

        string ans="";

        

        long long  a=abs( (long long)(numerator));
        long long  b =abs((long long)(denominator));

        if(a==0){
            return "0";
        }
        long long int temp =b;
        while(temp%2==0){
            temp=temp/2;

        }

        while(temp%5==0){
            temp=temp/5;

        }

        if(temp==1){
            //Terminating Decimal
      
            if(a%b==0){

                if(flag){
                     ans= to_string(a/b);
                     return ans;
                }
              
                else{
                    ans= to_string(a/b);
                    ans='-'+ans;
                    return ans;
                }
                
            }

           long long int r =a%b ;
            int q =a/b;

            ans+=to_string(q);
            ans+='.';
            while(r!=0){
                r=r*10;
                q=r/b;
                r=r%b;
                ans+=to_string(q);

            }
        }else{
            //Non Terminating Decimal

            long long  int r =a%b ;
            int q =a/b;

            ans+=to_string(q);
            ans+='.';
            map<int,int> mp;
           
           

            string dum="";
            int len=0;
             while(mp.find(r)==mp.end()){
                 mp[r]=len;
                 len++;
                 
                r=r*10;
                q=r/b;
                r=r%b;
                dum+=to_string(q);

            }



            for(int j=0;j<mp[r];j++){
                ans+=dum[j];
            }
            ans+='(';
            for(int j=mp[r];j<dum.size();j++){
                ans+=dum[j];
            }

            ans+=')';

        }
        if(flag)
        return ans;

        ans='-'+ans;
        return ans;
    }
};