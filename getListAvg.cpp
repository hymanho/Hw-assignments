/* 

Pitfall 1: divide by 0
solve divide by 0 error by checking if counter == 0
if counter is 0, the sum must be 0.

Pitfall 2: sum overflow or underflow

range of num values would be INT_MIN to INT_MAX - 1

highest possible average? Int_max - 1, as no value can go beyond this.
lowest possible average? INT_MIN. no value can go below this

if every value in the list is within this range, the avg will never be above INT_MAX-1,
and below INT_MIN

that means a variable that keeps track of average has no chance of overflowing, if
we recalculate the AVERAGE after every iteration until we reach the sentinel value (INT_MAX)

tldr: use a running average strategy to solve issue of overflow and underflow with a sum, discarding
the use of a sum variable 

to solve overflow on counter, we can set it to be a double. double's do not overflow or underflow
like integers, and instead result in a loss of precision. this loss of precision is
extremely minute, to the point if negligiblity, and does not cause the program to crash. 

 

for example, if we had 2^53 1's in a list, and then the 2^53 + 1 value is INT_MAX - 1.
Even though the counter value loses precision, the overall average would still be 1,
as there is still many more 1's than there were INT_MAX's. 

*/
double getListAvg() {

    double avg = 0;
    double counter = 0; 

    int num = getNum();

    while(num != INT_MAX) {

        if (counter == INT_MAX) {
            counter = 0; 
        }

        counter++; 
        
        avg = avg + ((num - avg)/counter);
        num = getNum();

    }

    if (counter == 0) { return 0; }

    return avg;

}
