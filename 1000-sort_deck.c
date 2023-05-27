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
	deck_node_t *curr;

	if (deck == NULL || *deck == NULL)
		return;
	curr = *deck;
	while (curr != NULL)
	{
		deck_node_t *smallest = curr;
		deck_node_t *next = curr->next;

		while (next != NULL)
		{
			if (next->card->kind < smallest->card->kind ||
				(next->card->kind == smallest->card->kind &&
				strcmp(next->card->value, smallest->card->value) < 0))
				smallest = next;
			next = next->next;
		}
		if (smallest != curr)
		{
			if (curr->prev != NULL)
				curr->prev->next = smallest;
			if (smallest->prev != NULL)
				smallest->prev->next = curr;

			deck_node_t *tmp = curr->prev;

			curr->prev = smallest->prev;
			smallest->prev = tmp;
			tmp = curr->next;
			curr->next = smallest->next;
			smallest->next = tmp;
			if (curr->prev == NULL)
				*deck = curr;
			if (smallest->prev == NULL)
				*deck = smallest;
		}
		curr = curr->next;
	}
}
