/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgering <mgering@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:11:45 by mgering           #+#    #+#             */
/*   Updated: 2024/04/20 16:55:49 by mgering          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array of strings obtained
by splitting ’s’ using the character ’c’ as a delimiter. The array
must end with a NULL pointer.
s: The string to be split.
c: The delimiter character.
Return: The array of new strings resulting from the split. 
NULL if the allocation fails. */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int		count;
	int		toggle;

	count = 0;
	toggle = -1;
	while (*s)
	{
		if (*s != c && toggle < 0)
		{
			count++;
			toggle = 1;
		}
		else if (*s == c)
			toggle = -1;
		s++;
	}
	return (count);
}

static void	word_len(char const *s, char c, size_t *start_s, size_t *end_s)
{
	int		toggle;

	toggle = -1;
	while (*s)
	{
		if ((s[*end_s] == c || s[*end_s] == '\0') && toggle > 0)
		{
			toggle = -1;
			return ;
		}
		else if (s[*end_s] != c && toggle < 0)
		{
			*start_s = *end_s;
			toggle = 1;
		}
		(*end_s)++;
	}
	return ;
}

static char	*word_writer(char const *s, size_t start_s, size_t end_s)
{
	char	*word;

	word = malloc((end_s - start_s + 1) * sizeof (char));
	if (!word)
		return (NULL);
	if (word)
		ft_strlcpy(word, &s[start_s], (end_s - start_s + 1));
	return (word);
}

static char	**splitter(char const *s, char c, int word_count, char	**split)
{
	size_t	start_s;
	size_t	end_s;
	int		i;

	start_s = 0;
	end_s = 0;
	i = 0;
	while (word_count > i)
	{
		word_len(s, c, &start_s, &end_s);
		split[i] = word_writer(s, start_s, end_s);
		if (!split[i])
		{
			while (--i >= 0)
				free(split[i]);
			free(split);
			return (NULL);
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**split;

	word_count = word_counter(s, c);
	split = malloc((word_count) * sizeof(char *) + sizeof(void *));
	if (!split)
		return (NULL);
	if (!splitter(s, c, word_count, split))
		return (NULL);
	split[word_count] = NULL;
	return (split);
}

/* #include <stdio.h>

int main(void) {
    char *input_string = "hello!xxhix";
    char delimiter = 'x';
    char **result = ft_split(input_string, delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]); // Remember to free each word
        }
        free(result); // Finally, free the array of words
    } 
	else {
        printf("ft_split returned NULL\n");
    }

    return 0;
} */