#include "get_next_line.h"

//static void print_list(t_list *lst)
//{
//    //if (!lst)
//        //printf("empty\n");
//    while (lst)
//    {
//        printf("%s\n", lst->buff);
//        lst = lst->next;
//    }
//}

char *get_next_line(int fd)
{
    char *next_line;
    static t_list *lst;

    //print_list(lst);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    make_list(&lst, fd);
    if (!lst)
        return (NULL);
    //print_list(lst);
    next_line = assemble_line(lst);
    //next_line = get_line(lst);
    del_nodes(&lst);
    //printf("++++++++");
    //print_list(lst);
    //printf("++++++++");
    //polish_list(&lst);
    return (next_line);
}

char *assemble_line(t_list *lst)
{
    char *line;
    int len;
    int i;
    int j;

    len = line_len(lst);
    if  (!len)
        return (NULL);
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (lst)
    {
        j = 0;
        while (lst->buff[j])
        {
            line[i] = lst->buff[j];
            i++;
            if (lst->buff[j] == '\n')
            {
                line[i] = '\0';
                return (line);
            }
            j++;
        }
        lst = lst->next;
    }
    line[i++] = '\0';
    return (line);
}

size_t line_len(t_list *lst)
{
    size_t len;
    size_t i;
    if (!lst)
        return (0);
    len = 0;
    while (lst)
    {
        i = 0;
        while (lst->buff[i])
        {
            len++;
            if (lst->buff[i] == '\n')
                return len;
            i++;
        }
        lst = lst->next;
    }
    return (len);
}

void make_list(t_list **lst, int fd)
{
    char *buff;
    int num_read;

    while (!search_line(*lst))
    {
        buff = malloc(BUFFER_SIZE + 1);
        if (!buff)
            return ;
        num_read = read(fd, buff, BUFFER_SIZE);
        if (num_read <= 0)
		{
			free(buff);
            return ;
		}
        buff[num_read] = '\0';
        add_node(lst, buff);
    }
}

void    add_node(t_list **lst, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*lst);
    new_node = malloc((sizeof(t_list)));
    if (!new_node)
        return ;
    if (!last_node)
        *lst = new_node;
    else
        last_node->next = new_node;
    new_node->buff = buff;
    new_node->next = NULL;
}

 int main()
 {  
     int fd = open("multiple_nlx5", O_RDONLY);
     //get_next_line(fd);
     //get_next_line(fd);
 	char *s = get_next_line(fd);
     printf("%s", s);
 	free(s);
 	s = get_next_line(fd);
     printf("%s", s);
 	free(s);
 	s = get_next_line(fd);
     printf("%s", s);
 	free(s);
    s = get_next_line(fd);
     printf("%s", s);
 	free(s);
    s = get_next_line(fd);
     printf("%s", s);
 	free(s);
    s = get_next_line(fd);
     printf("%s", s);
 	free(s);
 	//s = get_next_line(fd);
    // printf("%s", s);
 	//free(s);
 	//s = get_next_line(fd);
    // printf("%s", s);
 	//free(s);
 	// while(1);
     //printf("%s", get_next_line(fd));
     //printf("%s", get_next_line(fd));
     //printf("%s", get_next_line(fd));
 }
