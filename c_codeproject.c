 1  /*Program Description: Recieves an inputted array from the user and converts all even values to octal equivalents and all odd values to binary equivalents and outputs them */
     
      #include <stdio.h>
      #include <math.h>
      #include <stdlib.h>
      #define SIZE 20
     
      void getinputs(int []);
      int convert_decoct(int);
      void numoddeven(int [],int *,int * );
      int convert_decbin(int);
      void conversions(int [], int, int);
      void outputs( int [], int [], int , int );
     
      int main()
      {
        //Local Declarations
        int inputs[SIZE]; // array of integer inputs
        int numodd = 0; // number of odd integers
        int numeven = 0; // number of even integers
     
        //Executable statements
        getinputs(inputs);
        numoddeven(inputs, &numeven, &numodd);
        conversions(inputs, numeven, numodd);
     
        return 0;
      }
     
      void getinputs(int inputs[])
      {
        int counter ; //value used in for loop to iterate 20 times for the 20 integer values
 
        printf("Enter 20 integer values -> ");
     
        for (counter = 0; counter < SIZE; counter++)
        {
          scanf("%d", &inputs[counter]);
        }
        return;
      }

      int convert_decoct(int decinput)
      {
        int temp = 1;  // temporary value
        int octval = 0; // the octal value starts at 0
 
       while (decinput != 0)
       {
         octval = octval + (decinput % 8) * temp;
         decinput = decinput / 8;
         temp = temp * 10;
       }
       return octval;
     }

     void numoddeven(int inputs[], int *numeven,int *numodd)
     {
       int counter ; //value used to count the number of iterations in the for loop
    
       for (counter = 0; counter < 20; counter++)
       {
         if(inputs[counter] % 2 == 0  && (inputs[counter] != 1))
         {
           *numeven += 1;
         }
         else
         {
           *numodd += 1;
         }
       }
       return;
     }
    
     void conversions(int inputs[], int numeven,int numodd)
     {
       int octs[SIZE]; // even integers converted to octal values
       int bin[SIZE]; // odd integers converted to binary values
       int inputcounter; // value used to count the number of iterations
       int oddcounter = 0; // the index of the octal value array
       int evencounter = 0; // the index of the binary value array
    
       for (inputcounter = 0; inputcounter < 20; inputcounter++)
       {
         if((inputs[inputcounter] % 2 == 0) && (inputs[inputcounter] != 1))
         {
           octs[evencounter] = convert_decoct(inputs[inputcounter]);
           evencounter += 1;
         }
         else
         {
           bin[oddcounter] = convert_decbin(inputs[inputcounter]);
           oddcounter += 1;        
         }
       }
    
       outputs(octs, bin, numeven, numodd);
    
       return;
     }
    
     void outputs( int octals[], int binary[], int numeven, int numodd)
     {
       int counter; // counter for loops
    
       printf("\nBinary values: ");
    
       if (numodd == 0)
       {
         printf("None");
       }
       else
       {
         for (counter = 0; counter < numodd; counter++)
         {
           printf("%d ",binary[counter]);
         }
       }
    
       printf("\nOctal values: ");
    
       if (numeven == 0)
       {
         printf("None\n");
       }
       else
       {
         for (counter = 0; counter < numeven; counter++)
         {
           printf("%d ",octals[counter]);
         }
         printf("\n");
       }
       return;
     }

     int convert_decbin(int decvalue)
     {
       int binvalue = 0; //initialize the bin value
       int temp = 1; // temporary value
    
       while(decvalue != 0)
       {
         binvalue = binvalue + (decvalue % 2) * temp;
         decvalue /= 2;
         temp *= 10;
       }
    
       return binvalue;
    } 