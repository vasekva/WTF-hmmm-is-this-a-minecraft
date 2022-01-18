

#ifndef		CHECK_ERRORS_H
# define	CHECK_ERRORS_H
# include   "cub3D.h"

# define ERR			ft_putstr("Error : ")
# define ERR_VAR(var)	ft_putstr(var)
# define ERR_SP			ft_putstr(" :: ")
# define ERR_FILE(file)	ft_putstr(file)


# define ERR_MALLOC     ft_putendl("malloc")
# define ERR_NULL       ft_putendl("set to NULL")

typedef void    (*t_ferr)(void);

enum e_code
{
    MALLOC,
    NUL
};

void        f_malloc(void);
void        f_nul(void);

void        check_errors(t_uint code, char *file_name, char *var_name);

#endif