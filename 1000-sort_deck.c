#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the head of the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (!node2->prev)
		*deck = node2;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *next;
	int sorted;

	if (!deck || !*deck || !(*deck)->next)
		return;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		curr = *deck;
		while (curr->next)
		{
			next = curr->next;
			if (next->card->kind < curr->card->kind ||
				(next->card->kind == curr->card->kind &&
					strcmp(next->card->value, curr->card->value) < 0))
			{
				swap_nodes(deck, curr, next);
				sorted = 0;
				print_deck(*deck);
			}
			else
			{
				curr = curr->next;
			}
		}
	}
}
