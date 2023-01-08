#ifndef MYLIBC_H
# define MYLIBC_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		myisalpha(int c);
int		myisdigit(int c);
int		myisalnum(int c);
int		myisascii(int c);
int		myisprint(int c);
size_t	mystrlen(const char *s);
void	*mymemset(void *s, int c, size_t n);
void	mybzero(void *s, size_t n);
void	*mymemcpy(void *dest, const void *src, size_t n);
void	*mymemmove(void *dest, const void *src, size_t n);
size_t	mystrlcpy(char *dst, const char *src, size_t size);
size_t	mystrlcat(char *dst, const char *src, size_t size);
int		mytoupper(int c);
int		mytolower(int c);
char	*mystrchr(const char *s, int c);
char	*mystrrchr(const char *s, int c);
int		mystrncmp(const char *s1, const char *s2, size_t n);
void	*mymemchr(const void *s, int c, size_t n);
int		mymemcmp(const void *s1, const void *s2, size_t n);
char	*mystrnstr(const char *big, const char *little, size_t len);
int		myatoi(const char *nptr);
void	*mycalloc(size_t nmemb, size_t size);
char	*mystrdup(char *s);
char	*mysubstr(char const *s, unsigned int start, size_t len);
char	*mystrjoin(const char *s1, const char *s2);
char	*mystrtrim(char const *s1, char const *set);
char	**mysplit(char const *s, char c);
char	*myitoa(int n);
char	*mystrmapi(char const *s, char (*f)(unsigned int, char));
void	mystriteri(char *s, void (*f)(unsigned int, char*));
void	myputchar_fd(char c, int fd);
void	myputstr_fd(char *s, int fd);
void	myputendl_fd(char *s, int fd);
void	myputnbr_fd(int n, int fd);

t_list	*mylstnew(void *content);
void	mylstadd_front(t_list **lst, t_list *new);
int		mylstsize(t_list *lst);
t_list	*mylstlast(t_list *lst);
void	mylstadd_back(t_list **lst, t_list *new);
void	mylstdelone(t_list *lst, void (*del)(void *));
void	mylstclear(t_list **lst, void (*del)(void*));
void	mylstiter(t_list *lst, void (*f)(void *));
t_list	*mylstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char	*dst, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);

#endif
