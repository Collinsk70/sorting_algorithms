#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * Enum: kind_e
 * Description: Enumeration of card suits.
 * Values:
 *   - SPADE: Represents the Spades suit.
 *   - HEART: Represents the Hearts suit.
 *   - CLUB: Represents the Clubs suit.
 *   - DIAMOND: Represents the Diamonds suit.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * Struct: card_s
 * Description: Structure representing a playing card.
 * Members:
 *   - value: Value of the card, ranging from "Ace" to "King."
 *   - kind: Kind of the card.
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * Struct: deck_node_s
 * Description: Structure representing a node in a deck of cards.
 * Members:
 *   - card: Pointer to the card associated with the node.
 *   - prev: Pointer to the previous node in the list.
 *   - next: Pointer to the next node in the list.
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
