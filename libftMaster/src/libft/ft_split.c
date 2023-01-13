/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:50:19 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/30 15:42:02 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**create_matrix(char const *s, char c);
void	fill_matrix(char **matrix, char const *s, char c);
void	matrix_free(char **matrix, size_t j);

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = create_matrix(s, c);
	if (!matrix)
		return (NULL);
	fill_matrix(matrix, s, c);
	if (!matrix)
		return (NULL);
	return (matrix);
}

char	**create_matrix(char const *s, char c)
{
	size_t	num_words;
	char	**matrix;

	num_words = 0;
	while ((char)*s == (char)c && *s)
		s++;
	while (*s)
	{
		num_words++;
		while ((char)*s != (char)c && *s)
			s++;
		while ((char)*s == (char)c && c != 0)
			s++;
	}
	matrix = (char **)malloc((num_words + 1) * sizeof(char *));
	return (matrix);
}

void	fill_matrix(char **matrix, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_size;

	j = 0;
	i = 0;
	while ((unsigned char)s[i] == (unsigned char)c && s[i])
		i++;
	while (s[i])
	{
		word_size = 0;
		while (s[i + word_size] != c && s[i + word_size])
			word_size++;
		matrix[j] = ft_substr(s, i, word_size);
		if (!matrix[j])
		{
			matrix_free(matrix, j);
			break ;
		}
		i = i + word_size;
		j++;
		while ((unsigned char)s[i] == (unsigned char)c && s[i])
			i++;
	}
	matrix[j] = NULL;
}

void	matrix_free(char **matrix, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(matrix[j]);
		i++;
	}
	matrix = NULL;
}

/*
void	ftlk(void)
{
	system("leaks -q a.out");
}
int main(int argc, char *argv[])
{
	int i;
	i = 0;

	atexit(ftlk);
	if (argc == 2)
	{
		char **tab = ft_split(argv[1], ' ');
		while(tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
		matrix_free(tab, 4);
	}
}*/