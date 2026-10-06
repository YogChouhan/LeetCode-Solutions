class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int highest6Place = 0;
        int currentPlace = 1; 
        // here the places are like ones, tens, hundreds,..
        while(temp > 0){
            int lastDigit = temp % 10;
            temp = temp / 10;
            
            if(lastDigit == 6) highest6Place = currentPlace;

            currentPlace *= 10;
        }

        return num + (highest6Place * 3);
    }
};