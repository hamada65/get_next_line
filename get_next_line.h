#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

typedef struct s_list
{
    char *buff;
    struct s_list *next;
}   t_list;

char *get_next_line(int fd);
void make_list(t_list **lst, int fd);
int search_line(t_list *lst);
void    add_node(t_list **lst, char *buff);
t_list	*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
char *assemble_line(t_list *lst);
size_t line_len(t_list *lst);
void	del_nodes(t_list **lst);
int check_node(char *s);
size_t	ft_strlen(const char *s);
void	trim_word(char *dst, const char *src, size_t size);
//
void	polish_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int	len_to_newline(t_list *list);
#endif