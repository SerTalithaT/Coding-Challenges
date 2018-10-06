#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        //nums1 = a  nums2 = b
    
        double median;
        
        // array info
        int aSize = nums1.size(), bSize = nums2.size();
        int totalSize = aSize + bSize;
        int aEnd = aSize - 1, bEnd = bSize - 1;               

        // for search      


        // if all numbers in one array are >= to all numbers in another              

        // odd totalSize
        //if all #s in a smaller array are <= larger[0]
            //median = larger[totalSize/2 - smallerSize]
        if ((aSize < bSize) && (nums1[aEnd] <= nums2[0]))
        {
                median = nums2[totalSize/2 - aSize];                
        }
        else if ((bSize < aSize) && (nums2[bEnd] <= nums1[0]))
        {
                median = nums1[totalSize/2 - bSize];
        }

        //else all #s in a smaller array are >= larger[size-1]
            //median = larger[totalSize/2]
        else if ((aSize < bSize) && (nums1[0] >= nums2[bEnd]))
        {
                median = nums2[totalSize/2];
        }
         else if ((bSize < aSize) && (nums2[0] >= nums1[aEnd]))
        {
                median = nums1[totalSize/2];
        }
 
        //else if arrays are the same size && (a[size -1] <= b[0]) || (a[0] >= b[size-1])
            //median will be average of numericaly closest ends
        else if ((aSize == bSize) && (nums1[aEnd] <= nums2[0]))
        {
            median = (nums1[aEnd] + nums2[0]) / 2;                
        }
       else if ((aSize == bSize) && (nums1[0] >= nums2[bEnd]))
        {
            median = (nums1[0] + nums2[bEnd]) / 2; 
        }
        
        // else NOT all numbers in one array are <= the other
            // binary search for first place where 
                // (a[currentMid] >= b[currentMid] && a[currentMid] <= b[currentMid + 1]) || (a[currentMid] <= b[currentMid] && a[currentMid] >= b[currentMid - 1])          
                    
        else        
        {
            int aMid = num1Size / 2, bMid = num2Size / 2; 
            int aTop = aEnd, aBottom = 0, bTop = bEnd, bBottom = 0;
            bool sorted = false;

            do 
            {              
              int bPlus = bMid + 1, bMinus = bMid - 1;             

                if ((bPlus < bSize) && (bMinus >= 0))
                {                
                    if ((nums1[aMid] > nums2[bMid]) && (nums1[aMid] > nums2[bPlus]))
                    {
                        //compare the midpoint of the lower half of a vs. the midpoint of the upper half of b
                        aTop = aMid;
                        aMid = currentMid(aTop, aBottom);

                        bBottom = bMid;
                        bMid = currentMid(bTop, bBottom);                        
                    }                    
                    else if ((nums1[aMid] < nums2[bMid]) && (nums1[aMid] < nums2[bMinus]))
                    {
                        //compare the midpoint of the upper half of a vs. the midpoint of the lower half of b
                        aBottom = aMid;
                        aMid = currentMid(aTop,aBottom);

                        bTop = bMid;
                        bMid = currentMid(bTop, bBottom);                        
                    } 
                    else
                    { 
                        sorted = true;
                    }                   
                }
                else
                {
                    sorted = true;
                }
            }    
            while(!sorted);  

            // find median  
                // odd totalSizes must have equal #s above & below
                // even totalSizes must x above and x+1 below and visa versa

           int above, below, diff; 
           int medianGuess = aMid, otherMid = bMid;
           int upperGuess, lowerGuess; 
           bool guessArray = true
                //if true, medianGuess is array a(nums1) 
                // false, median Guess is array b(nums2)

           do
           {   
               
                if(medianGuess > otherMid)
                {
                    below = medianGuess + otherMid + 1;                    
                }
                else
                {
                    below = medianGuess + otherMid;
                }
                above = totalSize - below - 1;
                diff = std::abs(above-below);

           }
           while(diff > 1)

    //TODO mediantGuess & otherMid are indexes NOT values
        // need to compare values for  sorting 
        // probably needs the pass by referencere 

            //currently assuming while check h
                if(above > below)
                {
                    //need to move up
                    if(medianGuess > otherMid)
                    {
                        medianGuess ++;                 
                    }
                    else
                    {
                        int temp = medianGuess;
                        medianGuess = otherMid;
                        otherMid = temp;
                        guessArray = !guessArray
                    }
                }
                else
                {
                    //need to move down
                    if(medianGuess < otherMid)
                    {
                        medianGuess --;      
                            //if the guess goes out of range, then x[] <= y[] and istaken care up top                               
                    }
                    else
                    {
                        int temp = medianGuess;
                        medianGuess = otherMid;
                        otherMid = temp;
                        guessArray = !guessArray
                    }
                }


            
        }         
        
        // median has been found
        return median;
    }


    int currentMid(int top, int bottom)
    {
        int mid;

        if(top%2 == 1)
        {
            mid = ((top - bottom)/2) + bottom + 1;
        }
        else 
        {
             mid = ((top - bottom)/2) + bottom;
        }   
        return mid;
    }
};



                    
                    
                      // [1] [4] =>  2.5

                // 1, 4, 6, 7
                // 8. 10, 13, 17, 17 21, 30

                // 41, 44, 66, 77
                // 8. 10, 13, 17, 17 21, 30, 33

                // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
                // 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
                    // 1, 3, 7
                    // 4, 8
                    // 1, 3, 4, 7, 8
                        // 3 has one below and 3 above
                        // 7 if the first # found to be "sorted"
                        // it has three #s <= to it and one # >= to it 
                        // try b at lower sorted

                    // 3, 10, 21
                    // 1, 9, 14
                    // 1, 3, 9, 10, 14, 21
                        // two #s >= 10 && 3 #s <= 
                        // b[currentMid] > a[mid-1]
                        // average of b[mid] and a[mid] is median

                    // 10, 11, 21
                    // 1, 9, 14
                    // 1, 9, 10, 11, 14, 21
                        // two #s >= 11 && 3 #s <= 
                        // b[mid] < a[mid-1]
                        // average of a[mid] and a[mid-1] = median!
                        

                    // 1, 5, 8, 13
                    // 2, 4, 6, 7
                    //1, 2, 4, 5, 6, 7, 8, 13
                        // four #s >= 5 and three #s <= 5
                        // b[currentMid] < a[currentMid+1]
                        // average of b[currentMid] and a[currentMid] median

                    // 2, 12, 18, 20
                    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 14, 15, 17,19,20
                        // 12 is first sorted
                        // eight #s >= and eleven #s <=
                        // b[mid-1] > a[mid-1] ==> nine #s >= and ten #s <=   






