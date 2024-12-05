/* Calculate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.*/

//  Digit sum using Iteration                       // Complexity: O(log(n))
int Digit_sum_Iteration(int num) {
   int sum = 0;
   while (num > 0) {
     sum += num % 10;
      num /= 10;     }
    return sum; }

int main() {
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);
    int result = Digit_sum_Iteration(number);
    printf("Digit sum Iteration of %d: %d\n", number, result);
    return 0; }

//Pseudo Code:

//Function Digit_sum_Iteration(num):
//Input: num (integer)
//Initialize sum to 0
//While num > 0:
//Add the last digit of num (num % 10) to sum
//Remove the last digit from num (num = num // 10)
//Return sum

//Main Function:
//Declare number
//Display "Enter a natural number"
//Input number
//Call Digit_sum_Iteration(number) and store the result in result
//Display "Digit sum Iteration of", number, ":", result

//End

