/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:28:39 by hlesny            #+#    #+#             */
/*   Updated: 2022/10/02 21:57:28 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"


char *get_number(char *str, int nb_digits)
{
	int	i;
	int	c;
	char		*nb;

	i = -1;
	c = -1; 
	nb = malloc(sizeof(char) * 3);
	if (! nb)
		return (0);
	while (str[++i] && ++c < nb_digits) // ie tant que n'est pas a la fin de str ET que n'a pas deja max trois chiffres(ou nb_digits, si a moins de 3 chiffres a stocker)  
		nb[i] = str[i];
	return (nb);
}

char **split_number(char *nbr) // retourne un **char, ou chaque *char est un tableau de 3 chiffres => decompose le nombre intial en "paquets" de 3
{
	int	i;
	int	n;
	char		**number; // tableau de "paquets" de 3
	int size; 

	n = 0;
	while (nbr[n]) // n = nombre de chiffres composant le nombre a "traduire" avec le dictionnaire
		n++;
	i = n - 4; // et pas n - 1 car decremente i de 3 dans le while plus bas dans le code
	if ((n % 3) != 0)
		n = (n / 3) + 1;
	else
		n /= 3; // n devient le nombre de "paquets" de 3 chiffres (ie le nombre de *char dans notre **char)
	size = n; // size = taille du tableau number (ie n, cf explication a la ligne du dessus)
	n--;
	number = malloc (sizeof(char*) * size);
	if (! number)
		return (0); // ie return NULL
	while (n > -1) // get_number(nbr[i]) utilise les elements nbr[i], nbr[i+1] et nbr[i+2] pour remplir number[n], 0 < n < (size - 1) => i -= 3 a chaque fois 
									//que l'on decremente n de 1 (decremente car on remplit les "dernieres" cases avec les plus petits digits)
									// pour number = 123456 : nbr = "123456", number[0] = "123" et number[1] = "456"
	{
		number[n] = get_number(&nbr[i], 3);
		if(number[n] == NULL)
		{
			while(n++ < size)
				free(number[n]);
			free(number);
			return (NULL);
		}
		n--;
		i -= 3;
	}
	if (i > -1) // si reste un "paquet" de moins de 3 chiffres, typiquement dans les plus grands digits
	{
		number[n] = get_number(&nbr[0], i + 1); // i + 1 = nombre de chiffres restant a stocker dans number[n]
		if(number[n] == NULL)
		{
			while(n++ < size)
				free(number[n]);
			free(number);
			return (NULL);
		}
	}
	return (number);
}

int sum(char a, char b)
{
	return ((a + b - 96) < 21); // verifie si "ab" < "21"
}
// concatener les deux derniers elements de chaque number[i] 



int	display_number(char *nb, elem_dict *dict) // type de retour : int et non pas void car retourne -1 lorsque l'on rencontre une erreur dans le parsing du dico
{
	int 	i;
	int	length;
	unsigned int nbr;
	char	*tmp;

	nbr = ft_atoi_dict(nb); // convertit nbr (i un des paquets de 3 chiffres) en int
	i = 0;
	length = 0;
	while (nb[++length]); // length devient la taille du nombre a afficher
	if (length == 1) // ie si n'a qu'un digit, p.ex. le 1 du nombre 1234
	{
		printf("%c", nb[i]);
		if (find_and_print(&nb[i], dict)) // le recherche dans le dictionnaire pr l'afficher
		{
			write(2, "Dict Error\n", 11);
			return (-1); // return (-1) si a eu une erreur dans le parsing du dico
		}
	}
	else // ie si length == 2 ou length == 3
	{
		if (length == 3) // 
		{
			tmp = ft_itoa(nbr / 100); // nbr / 100 plutot non ? 
			printf("%s", tmp);
			if (find_and_print(tmp, dict) == 1) //imprimer le digit des centaines	
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
			if (find_and_print("100", dict)) // puis la traduction de "100" dans le dico 
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
			i++; // => si length = 3, i = {0, 1, 2}, et affichera ensuite nb[1] et nb[2]. sinon, i = {0, 1}, i n'est pas incremente et affichera ensuite nb[0] et nb[1] 
		}  
		if (sum(nb[i], nb[i + 1]))
		printf("%s", ft_strcat(&nb[i], &nb[i + 1]));
		if (sum(nb[i], nb[i + 1])) // cas ou les deux derniers digits sont < 21. on a length = {2, 3}, donc, pour i = {0, 1}, nb[i + 1] sera != '\0'
		{
			if (find_and_print(ft_strcat(&nb[i], &nb[i + 1]), dict)) // traduit directement la string "nb[i]nb[i+1]"
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
		}
		else
		{
			printf("%s", ft_itoa(ft_atoi_dict(&nb[i]) * 10));
			if (find_and_print(ft_itoa(ft_atoi_dict(&nb[i]) * 10), dict)) 
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
			printf("%c", nb[i + 1]);
			if (find_and_print(&nb[i + 1], dict))
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
		}
	}
	return (1); // si tt s'est bien passe, ie n'a eu aucune erreur dans le parsing du dico
}

int	convert(char *nbr, elem_dict *dict)
{ 
	int	i;
	int	l; // length of the strings numbers[i], ie le nmbre de "paquets" de 3 chiffres que l'on a obtenu apres decomposition du nombre
	char		**number;
	
	i = -1;
	l = 0;
	number = split_number(nbr); // number est deja valide (already checked in atoi), a juste a verifier qu'a bien ete malloc  
	if(! number)
		return (-1);
	while (number[l])
		l++; 
	while (number[++i]) // les plus grands digits sont stockes au debut de la chaine de caracteres
	{
		display_number(number[i], dict);
		if (i < l - 1) // ie pour tous les number[i] sauf le dernier, car n'a pas besoin d'afficher 10^2 = "cent" apres "deux cent soixante trois" par ex
		{
			if (find_and_print(ft_itoa(ft_pow(10, 3 * (l - i - 1))), dict))
			{
				write(2, "Dict Error\n", 11);
				return (-1);
			}
		}
	}
	return (1);
}