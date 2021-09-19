#include<bits/stdc++.h>
using namespace std;

void printbinary(int num)
{
	for(int i=10;i>=0; i--)
	{
		cout<<(  (num >>i) & 1 );           // printing binary using right shift operattor
	}
	cout<<endl;
}


int main()
{

//1. To convert lowercase to uppercase
	char c='a';
	cout<< char(c & '_' )<<endl;

//2. TO convert uper to lowercase : take or with (space binary)
char  c1='B';
cout<< char( c1 |' ')<<endl;

//printbinary(7);

//3. TO check i th bit is "set" or not of given num;: TAKE & WITH no whose i th bit is set(1<<i)
int num=7;
printbinary(num);
int i=3;
if( num & 1<<i )
 cout<<"bit is set \n";
else cout<<"bit not set\n";

//4. To set the i th bit manually : take or with no whose i bit is set(1<<i)
i=4;
int num1=5;

cout<<"before   ";   printbinary(num1); 

num1=(num1 | 1<<i);
 cout<<"after   ";    printbinary(num1) ;

cout<<endl;

// 5. To manually unset i th bit 
 i=0; num1=5;
 cout<<"before   ";   printbinary(num1); 

num1=(num1 & ~(1<<i));
 cout<<"after   ";    printbinary(num1) ;


cout<<endl;
// 6. To toggle the  i th bit only   (0 <-> 1 ) take ^ with (1<<i)
num1=15; i=4;
cout<<"before   ";   printbinary(num1); 

num1= num1 ^ (1<<i);
 cout<<"after toggle  ";    printbinary(num1) ;

cout<<endl;

//7. TO count how many set bits are there in no;
num1= 31;
printbinary(num1);
cout<<"count of set bits : "<<__builtin_popcountll(num1)<<endl;

// or manually using a loop to check bit is set or not.
int cnt=0;
for(int i=31 ;i>=0 ;i-- )   //valid for 32 bit no
{
if( num1 & (1<<i)) cnt++;
}
cout<<"manualy calculated  : "<<cnt<<endl;


// 8. Calculations :"  <<  "   means left shift <- .... just add required  '0' at last
int x=5;
printbinary(x);      //101              5
printbinary(x<<1);  //1010            10  just added one more 0 at last 
cout<<"To multiply no by 2 use << (left shift) 5* 2 =10 .....";
printbinary(x<<1);

cout<<endl;

// 9. Calculations :"  >>  "   means right shift --> .... just delete digits at last
 x=5;
printbinary(x);      //101              5
printbinary(x>>1);  //  10            2  just delete  last 
cout<<"To Divide no by 2 use << (right shift) 5/2 =2 .....";
printbinary(x>>1);

cout<<endl;

// 10 .Exercise Find outputs
int y=59;              // 111011
printbinary(y);         
printbinary(y<<2);     // 11100`00
printbinary(y>>3);    //  111


// 11. To check any num is pow of two or not.
int number=16;
if( number & (number-1) )         // 10000 & 1111 = 00000  ,so this will be false cond ,hece pow of 2
{
	cout<<"Not power of two\n";
}
else cout<<"power of two \n";

cout<<endl;

//12. to check even/ odd  .   eg   8 = 1000   , 7 = 111   so if LSB is set itt will be odd
number=4;
if(number & 1) cout<<"Odd";
else cout<<"even";
cout<<endl;

//NOT IMPORTANT 
// 13.   TO unset till i th bits from the right to left (LSB to i)

number=59; printbinary(number);

i=4;                                          // will claer till i bits from LSB
number = ( number & ~( (1<<i+1) -1 ) );
printbinary(number);

cout<<endl;

// 
// calculation : 59 --- 00000111011
//  we need to unset bits from LSB to 4 th bit (ie need to unset all)
//                we need no to do & oprattion   :  111111,00000         
//    this will come from  invert                :  000000,11111        
//    and this will come from                    : 100000-1  will give this: 
// 
//                                so basically :   number & ~( (1<<i+1) -1 )  
// 
// 
// 
 


// 13.   TO unset till i (index always start from right to lleft in binary no )th bits from the   left to right (MSB to i)

number=59; printbinary(number);
i=0;                                        // means it will clear all bits from MSB (right ) till before  the i index of left 
number=(number & ((1<<(i+1))-1) ) ;             // if (i=0) means clear all bits excluding 0 bit
printbinary(number);










	return 0;
}