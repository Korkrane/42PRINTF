/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:51:01 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/26 15:38:48 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// medium.com/@zhang.yine/ft-printf-d95747b7aa5a
//
//Struct of printf : 
//
// 1. Main format		parser
// 2. Flags + Modifier	parser
// 3. Conversion		dispatcher
//
// The main format parsers takes a var amount of var using variadic function 
// --> ft_printf(const char *format, ...)
//
// initialize va_list and assign it to start of var list
	GO FIND INFOS ABOUT VARIADIC FUNCTIONS
// It goes to the main parsers that diff the print content and conversions (%)
//
// If % find, use flag+mod parser to store them in data struct. Then send that
// struct to convert function to process the data in a printable output.

//GLOSS
//
//Ffwp = Format/flags/width/precision
//
// Main idea
//
// ex : printf("Stud %s has joined %d, did you know that %c is after b", "bahaas", 42, 'c');
//
// 1. Parse the given string and differentiate args + following possible modifiers with pure txt
// 		1.1 If it's pure txt just write it (maybe store it and display all at the end only)
// 		1.2 If it encounters a % check the next char (loop) 
// 			1.2.1 If it's not a Ffwp (break loop)
// 			1.2.2 If it's a Ffwp, stock them somewhere to proceed them later
// 			1.2.3 (break loop when next char not cfm)
// 		1.3 repeat until parsing encounters \0
//
// 1.2.2 --> 2.
//
// 2. 
//
// Q. How to link args to the % ?
