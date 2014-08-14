#include<iostream>
#include <Merge.h>
#include <cstdlib>
using namespace std;
/*
Code::Blocks/ Release 13.12 rev 0 / 1.19.0
i686-apple-darwin11-llvm-g++-4.2 (GCC) 4.2.1
*
/* - Assumptions : 1. Duplicates are allowed
                   2. list3(n1+n2) = list1 (0..n1) + list2  (0..n2))
                   example:list1 {10,20} and list2 {10,20}
                    then merge list - {10,10,20,20}
                   list3(4)= list1(2) + list2(2)
                   3.Given lists would be ascending order.
                   4.Sample functional testing are done, based on the requirements,
                     further testing can be done
*/

void test_mergelist(int list1data[], unsigned char size1, int list2data[], unsigned char size2);

int main()
{
   /* Sample Input*/
   int list1[] = {10,20,30,40,50,60,70,80,90,100};
   int list2[] = {15,21,32,40,53,62,74,91,93,103};

   /* possible functional tests - negative/positive test */
   cout<<endl<<"**Test1 - Both Lists are empty"<<endl;
   test_mergelist(list1, 0, list2, 0);

   cout<<endl<<"**Test2 - First List is empty"<<endl;
   test_mergelist(list1, 0, list2, 10);

   cout<<endl<<"**Test3 - Second List is empty"<<endl;
   test_mergelist(list1, 10, list2, 0);

   cout<<endl<<"**Test4 - Both  List are non-empty with one node"<<endl;
   test_mergelist(list1, 1, list2, 1);

   cout<<endl<<"**Test5 - Both  List are non-empty with n nodes"<<endl;
   test_mergelist(list1, 10, list2, 10);

   cout<<endl<<"**Test6 - Both  List are non-empty with n1 and n2 nodes"<<endl;
   test_mergelist(list1, 4, list2, 6);

   /* based on the requirements, further non-functional testing can be done*/
}

void test_mergelist(int list1data[], unsigned char size1, int list2data[], unsigned char size2)
{
   unsigned char count;

   list l1; /* list 1 */
   list l2; /* list 2 */
   list l3; /* Merged list 3 = List 1 + List 2*/
   Node *mrgelistptr;

    /*creating list1 */
    for (count=0 ;count < size1; count++)
    {
        l1.insertlist(list1data[count]);
    }

    /*creating list2 */
    for (count=0 ;count < size2; count++)
    {
        l2.insertlist(list2data[count]);
    }

    /*printing list1 */
    cout<<endl<<"First List"<<endl;
    if(l1.getheadptr()!=NULL)
    {
      l1.printlist();
    }else
    {
       cout<<endl<<"--empty first list--"<<endl;
    }

     /*printing list2 */
    cout<<endl<<"Second List"<<endl;
    if(l2.getheadptr()!=NULL)
    {
      l2.printlist();
    }else
   {
       cout<<endl<<"--empty second list--"<<endl;
   }


   /* Merging List1 and List2 */
   cout<<endl<<"Merged List"<<endl;
   mrgelistptr = l3.mergelist(l1.getheadptr(),l2.getheadptr());

   if(mrgelistptr!=NULL)
   {
       /* printing merge list */
       l3.printlist(mrgelistptr);

   }else
   {
       cout<<endl<<"--empty merged list--"<<endl;
   }
}

/* Test Results
**Test1 - Both Lists are empty

First List

--empty first list--

Second List

--empty second list--

Merged List

--empty merged list--

**Test2 - First List is empty

First List

--empty first list--

Second List
 15  21  32  40  53  62  74  91  93  103
Merged List
 15  21  32  40  53  62  74  91  93  103
**Test3 - Second List is empty

First List
 10  20  30  40  50  60  70  80  90  100
Second List

--empty second list--

Merged List
 10  20  30  40  50  60  70  80  90  100
**Test4 - Both  List are non-empty with one node

First List
 10
Second List
 15
Merged List
 10  15
**Test5 - Both  List are non-empty with n nodes

First List
 10  20  30  40  50  60  70  80  90  100
Second List
 15  21  32  40  53  62  74  91  93  103
Merged List
 10  15  20  21  30  32  40  40  50  53  60  62  70  74  80  90  91  93  100  10
3
**Test6 - Both  List are non-empty with n1 and n2 nodes

First List
 10  20  30  40
Second List
 15  21  32  40  53  62
Merged List
 10  15  20  21  30  32  40  40  53  62
Process returned 0 (0x0)   execution time : 0.393 s
Press any key to continue.
*/


































































































