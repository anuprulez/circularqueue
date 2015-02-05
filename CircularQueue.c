// Circular Queue implementation through linked list
// 1. Enqueues an element
// 2. Dequeues an element
// 3. Gets Size
// 4. Checks if queue is empty
// 5. Prints the queue

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct circular_queue
{
	char data;
	struct circular_queue *next;
}	circular_queue_node;

typedef circular_queue_node *list;
list temp, head, tail;

int main()
{
	int action_key = 0, is_queue_empty = 0;
	do {
	    printf("\nEnter 1: Enqueue, 2: Dequeue, 3: Print, 4: Size, 5: Is Queue empty, 6: Exit \n");
		scanf("%d", &action_key);
		switch(action_key){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				print_circular_queue();
				break;
			case 4:
				find_size();
			    break;
			case 5:
				is_queue_empty = is_empty();
				if(is_queue_empty == 1){
					printf("\nThe circular queue is not empty\n");
				}
				else{
					printf("\nThe circular queue is empty\n");
				}
			    break;
			case 6:
				break;
			default:
				break;
		}
	} while(action_key < 6);
	getch();
	return 0;
}

// Computes the size of the circular queue
int find_size(){
    if(is_empty() == 0){
		printf("\nThe circular queue is empty\n");
	}
	else{
		list iterator = NULL;
		int size = 0;
		iterator = head;
		iterator = iterator->next;
		size++;
		while(iterator != head){
			iterator = iterator->next;
			size++;
		}
		printf("\nThe size of the circular queue is: %d\n", size);
	}									
	return 0;
}

// Checks if the circular queue is empty or not
int is_empty(){
	if(head == NULL){
		return 0;
	}
	else{
		return 1;
	}
}

// Adds an element in the circular queue
int enqueue()
{
	char c;
	list temp_element = NULL;
	printf("\nEnter a character\n");
    scanf(" %c", &c);
	temp_element = (list) malloc(sizeof(circular_queue_node));
	temp_element->next = temp_element;

    if(tail == NULL)
	{
		temp_element->data = c;
		tail = head = temp_element;
	}
	else
	{
		temp_element->next = head;
		tail->next = temp_element;
		temp_element->data = c;
		tail = temp_element;
	}
	print_circular_queue();
	return 0;
}

// Removes an element in the circular queue
int dequeue()
{
	if(is_empty() == 0){
		printf("\nThe circular queue is empty\n");
	}
	else{
		list current_top = NULL;
		current_top = head;
		current_top = current_top->next;
		free(head);
		if(current_top != head){
			head = current_top;
			tail->next = head;
		}
		else{
			head = NULL;
			tail = NULL;
		}
		print_circular_queue();
	}
	return 0;
}

// Displays the elements in the circular queue
int print_circular_queue()
{
	list iterator = NULL;
    iterator = head;
    if (is_empty() == 0)
    {
        printf("\nThe circular queue is empty\n");
    }
	else{
		printf("\nThe circular queue is: \n");
		printf("%c \n", iterator->data);
		iterator = iterator->next;
		while (iterator != head){
			printf("%c \n", iterator->data);
			iterator = iterator->next;
		}
	}
	return 0;
}
