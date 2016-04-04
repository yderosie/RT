/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 12:50:55 by yderosie          #+#    #+#             */
/*   Updated: 2016/04/01 17:40:08 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser/parser.h"

t_json		*parse_obj2(char **json, t_json *value)
{
	if (**json == ',')
	{
		*json += 1;
		value->next = parse_obj(json);
		return (value);
	}
	else if (**json == '}')
	{
		*json += 1;
		return (value);
	}
	else
		return (NULL);
}

t_json		*parse_obj(char **json)
{
	t_json *value;

	value = (t_json*)ft_memalloc(sizeof(t_json));
	value->next = NULL;
	skip_blanks(json);
	if (**json != '"')
		return (NULL);
	*json += 1;
	value->key = ft_strsub(*json, 0, sub_pointer(ft_strchr(*json + 1, '"'),
		*json));
	*json = *json + ft_strlen(value->key) + 1;
	skip_blanks(json);
	if (**json != ':')
		return (NULL);
	*json += 1;
	skip_blanks(json);
	parser_value(json, &value->value);
	skip_blanks(json);
	if (parse_obj2(json, value) == NULL)
		return (NULL);
	else
		return (value);
}

t_json_arr	*parse_arr(char **json)
{
	t_json_arr	*value;

	skip_blanks(json);
	if (**json == ']')
		return (NULL);
	value = (t_json_arr*)ft_memalloc(sizeof(t_json_arr));
	parser_value(json, &value->value);
	skip_blanks(json);
	if (**json == ',')
	{
		*json += 1;
		value->next = parse_arr(json);
	}
	else if (**json == ']')
		return (value);
	return (value);
}

t_value		parser(char *file_name)
{
	int			fd;
	char		*line;
	t_stream	stream;
	size_t		read;
	t_value		value;

	read = 1;
	fd = open(file_name, O_RDONLY);
	create_stream(fd, &stream);
	while (read_until(&stream, &line, '\0') > 0)
	{
		if (*line == '{')
		{
			value.type = 0;
			line += 1;
			value.data.obj = parse_obj(&line);
		}
		else
		{
			ft_printf("%s not a json file\n", file_name);
			exit(0);
		}
	}
	return (value);
}
