#include "sort.h"

int main(void)
{
	int data[] = {4, 2, 6, 24};
	int n = sizeof(data) / sizeof(data[0]);

	quick_sort(data, n);
}
