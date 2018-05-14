
#include "lemin.h"
void	print_node(t_node *node)
{
	while (node->next)
	{
		printf("name = %s\n", node->name);
		printf("start = %d\n", node->start);
		printf("end = %d\n", node->end);
		printf("step = %d\n", node->step);
		printf("previous = %s\n", node->previous);
		printf("x = %d\n", node->x);
		printf("y = %d\n", node->y);
		while (node->kid)
		{
			printf("linked with = %s\n", node->kid->name);
			node->kid = node->kid->next;
		}
		printf("\n");
		node = node->next;
	}
}

// static void	print_way(t_node *s, t_node *e, t_node *node)
// {
// 	t_node	*head;
// 	t_list	*list;

// 	head = node;
// 	if (!(e->previous))
// 		error();
// 	printf("%s", e->name);
// 	while (ft_strcmp(e->name, s->name))
// 	{
// 		printf("-%s", e->previous);
// 		e = previous(head, e->previous);
// 	}
// 	printf("\n");
// }

// static void	print_way(t_list *list)
// {
// 	int i = 0;
// 	while(list->next)
// 	{
// 		i++ ? printf("-") : 0;
// 		printf("[%s]", list->content);
// 		list = list->next;
// 	}
// 	printf("\n");
// }
