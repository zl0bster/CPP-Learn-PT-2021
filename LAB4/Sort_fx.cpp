
bool ascend(int x, int y)
{
	return (x < y);
}

bool descend(int x, int y)
{
	return (x > y);
}

void flip_vals(int& px, int& py)
{
	int temp = px;
	px = py;
	py = temp;
}

void sort1(int* arr, int arraySize, bool (*sort_criteria)(int, int)) // or arraySize as int parameter
{
	bool isSortContinues = true;
	//int arraySize = sizeof(arr) / sizeof(arr[0]);
	int leftIter = 0;
	int rightIter = arraySize - 1;

	while (isSortContinues)
	{
		if (leftIter == rightIter)
		{
			isSortContinues = false;
			continue;
		}
		if ((leftIter + 1) == rightIter)
		{
			if ((*sort_criteria)(arr[leftIter], arr[rightIter]))
			{
				/*int* px = &arr[leftIter];
				int* py = &arr[rightIter];*/
				flip_vals(arr[leftIter], arr[rightIter]);
			}
			isSortContinues = false;
			continue;
		}
		// find local max and min
		int i = leftIter + 1;
		int turnsNum = 0;
		int minPos = i;
		int maxPos = i;
		int minVal = arr[i];
		int maxVal = arr[i];
		while (i < rightIter)
		{
			if ((*sort_criteria)(maxVal, arr[i]))
			{
				maxVal = arr[i];
				maxPos = i;
			}
			if ((*sort_criteria)(arr[i], minVal))
			{
				minVal = arr[i];
				minPos = i;
			}
			i++;
		}
		// flip  min and max to iteration limits
		flip_vals(arr[leftIter], arr[minPos]);
		flip_vals(arr[rightIter], arr[maxPos]);
		turnsNum++;
		leftIter++;
		rightIter--;

	}

}