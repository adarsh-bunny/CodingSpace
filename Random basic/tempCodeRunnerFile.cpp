// The function returns true if there exist three
// elements in AP Assumption: set[0..n-1] is sorted.
// The code strictly implements the algorithm provided
// in the reference.
bool arithmeticThree(vector<int> set, int n)
{
	
	// One by fix every element as middle element
	for(int j = 1; j < n - 1; j++)
	{
		
		// Initialize i and k for the current j
		int i = j - 1, k = j + 1;

		// Find if there exist i and k that form AP
		// with j as middle element
		while (i >= 0 && k <= n-1)
		{
			if (set[i] + set[k] == 2 * set[j])
				return true;
				
			(set[i] + set[k] < 2 * set[j]) ? k++ : i--;
		}
	}
	return false;
}

// This code is contributed by Samim Hossain Mondal.
