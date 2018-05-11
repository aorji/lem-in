static void	print_node(t_node *node)
{
	while (node->next)
	{
		printf("name = %s\n", node->name);
		printf("start = %d\n", node->start);
		printf("end = %d\n", node->end);
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