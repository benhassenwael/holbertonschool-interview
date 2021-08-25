#include "lists.h"

/**
 * reverse_list - reverse the order of a singly linked list
 * @head: pointer to the head of the list
 *
 * Rreturn: pointer to the head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev;
	listint_t *temp;

	prev = NULL;
	while (head)
	{
		temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}

	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 1 if the list is palindrome and 0 if it is not
 */
int is_palindrome(listint_t **head)
{
	listint_t *mid, *temp;

	if (!head || !(*head) || !((*head)->next))
		return (1);

	temp = mid = *head;
	while (temp && temp->next)
	{
		mid = mid->next;
		temp = temp->next->next;
	}
	mid = reverse_list(mid);
	temp = mid;
	while (mid)
	{
		if ((*head)->n != mid->n)
		{
			reverse_list(temp);
			return (0);
		}
		*head = (*head)->next;
		mid = mid->next;
	}
	reverse_list(temp);
	print_listint(*head);
	return (1);
}
