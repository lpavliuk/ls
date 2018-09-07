/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 19:11:45 by opavliuk          #+#    #+#             */
/*   Updated: 2018/08/31 19:11:48 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/include_lib/libft.h"

# define FLAG_L 0x01
# define FLAG_A 0x02
# define FLAG_R 0x04
# define FLAG_RR 0x08
# define FLAG_T 0x10
# define FLAG_N 0x20
# define FLAG_G 0x40
# define FLAG_D 0x80

typedef struct	s_info
{
	char			*name_file;
	char 			*pwd;
	char			mode[12];
	char			data[25];
	nlink_t			nlinks;
	dev_t			rdev;	
	off_t			size;
	uid_t			uid;
	gid_t			gid;
	blkcnt_t		blocks;
	size_t			atime;
	size_t			mtime;
	size_t			ctime;
	short int 		list_xattr;
	struct s_info	*next;
}				t_info;

typedef struct	s_dir
{
	char 			*name;
	size_t			total;
	t_info			*head;
	struct s_dir	*next;
}				t_dir;

typedef struct	s_ls
{
	DIR				*fd_dir;
	struct dirent	*file;
	struct stat		stat;
	unsigned char 	flag;
	t_dir			*dirs;
}				t_ls;

void			check_mode(t_info *file, unsigned int mode, char *permfile);
void			check_flags(t_ls *ls, const char *flag);
char			*ft_strjoin_dir(char const *s1, char const *s2);
void			read_dir_info(t_ls *ls, const char *dir_name);
t_info			*new_file(t_info **head);
t_dir			*new_dir(t_dir **dir, const char *name);
void			free_lists(t_dir *head);

#endif
