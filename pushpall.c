void push(stack_t **stack, unsigned int line_number)
{
    int num = 0;/*Variable para almacenar el número que se agregará a la pila*/
    stack_t *top = NULL;
    /*Define un puntero a un nodo de pila, que se utilizará para crear el nuevo nodo que se agregará a la pila*/

    num = atoi(strtok(NULL, " \n")); /*Obtener el número a agregar a la pila*/
    top = malloc(sizeof(stack_t));/*Crear un nuevo nodo de pila*/
    if (top == NULL)/* Verificar si se asignó correctamente la memoria*/
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE)
    }
    node->n = num;/*Asignar el número al nuevo nodo*/
    top->next = *stack;/*Conectar el nuevo nodo al nodo superior actual*/
    top->prev = NULL;/*Establecer el nuevo nodo como el nodo superior de la pila*/
    /*Si la pila ya tenía un nodo, establecer el puntero previo del nodo
    superior actual para que apunte al nuevo nodo superior*/
    if (*stack != NULL)
    {
        (*stack)->prev = top;
    }
    /*Establecer el puntero de pila para que apunte al nuevo nodo superior*/
    *stack = top;
}
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *lec = *stack;
    /* Recorremos la pila hacia el último nodo */
    while (lec != NULL)
    {
        if (!(lec->next))
            break;/* Si llegamos al final de la pila, salimos del bucle */
        lec = lec->next;/* Movemos el puntero hacia el siguiente nodo */
    }
    /* Recorremos la pila de último a primer nodo */
    while (lec != NULL)
    {
        /* Si el nodo actual no es nulo, imprimimos su valor */
        if (lec->n)
            printf("%d\n", lec->n);
        else
            printf("0\n");/* Si es nulo, imprimimos 0 */
        lec = lec->prev;/* Movemos el puntero hacia el nodo anterior */
    }
}
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *lec = *stack;

    if (lec == NULL)/* Verificar si la pila está vacía */
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
    printf("%d\n", lec->n);/* Imprimir el valor en la cima de la pila */
    lec = lec->next;/* Actualizar la cima de la pila */
}
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *lec = *stack;

    if (*stack == NULL)/*Verificar si la pila está vacía*/
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = lec->next/*Actualizar el puntero de la pila al siguiente nodo*/
    if (*stack != NULL)/*Verificar si la pila aún tiene nodos*/
        (*stack)->prev = NULL;/*Actualizar puntero previo del nuevo nodo superior*/
    free(lec);/*Liberar el nodo superior anterior*/
}
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *lec;
}