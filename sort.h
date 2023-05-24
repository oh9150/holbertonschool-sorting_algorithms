#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Prints an array of integers*/
void print_array(const int *array, size_t size);

/*Prints a list of integers*/
void print_list(const listint_t *list);

/*General*/
void swap(int *a, int *b);

/*Mandatory*/
/*
 * 0. function that sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 */
void bubble_sort(int *array, size_t size);

/*
 * 1. function that sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 */
void insertion_sort_list(listint_t **list);

/*
 * 2. function that sorts an array of integers in ascending order using the
 * Selection sort algorithm
 */
void selection_sort(int *array, size_t size);

/*
 * 3. function that sorts an array of integers in ascending order using the
 * Quick sort algorithm
 */
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int, int);
int partition(int *array, int, int);

/*Advanced*/
/*
 * 4. function that sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 */
void shell_sort(int *array, size_t size);

/*
 * 5. function that sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 */
void cocktail_sort_list(listint_t **list);

/*
 * 6. function that sorts an array of integers in ascending order using the
 * Counting sort algorithm
 */
void counting_sort(int *array, size_t size);

/*
 * 7. function that sorts an array of integers in ascending order using the
 * Merge sort algorithm
 */
void merge_sort(int *array, size_t size);

/*
 * 8. function that sorts an array of integers in ascending order using the
 * Heap sort algorithm
 */
void heap_sort(int *array, size_t size);

/*
 * 9. function that sorts an array of integers in ascending order using the
 * Radix sort algorithm
 */
void radix_sort(int *array, size_t size);

/*
 * 10. function that sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 */
void bitonic_sort(int *array, size_t size);

/*
 * 11. function that sorts an array of integers in ascending order using the
 * Quick sort algorithm
 */
void quick_sort_hoare(int *array, size_t size);

#endif
