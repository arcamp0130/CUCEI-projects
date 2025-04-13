unsigned int factorial(int n)
{
  // Base case
  if (n == 0 || n == 1)
    return 1;
  // Recursive case
  else
    return n * factorial(n - 1);
}