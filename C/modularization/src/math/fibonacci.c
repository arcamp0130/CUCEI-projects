int fibonacci(int n)
{
  // base case, n = 1 or 0
  if (n == 0 || n == 1)
    return n;
  // recursive case, n > 1 
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}