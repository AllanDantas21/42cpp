/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:04:11 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/03 00:34:21 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cmath>

/* Constructor */
Brain::Brain() {
    _ideas[0] = "C++"; _ideas[1] = "Python"; _ideas[2] = "Java"; _ideas[3] = "JavaScript"; _ideas[4] = "C#"; _ideas[5] = "Ruby"; _ideas[6] = "Go"; _ideas[7] = "Swift";_ideas[8] = "PHP"; _ideas[9] = "TypeScript"; _ideas[10] = "Kotlin"; _ideas[11] = "Perl";_ideas[12] = "Scala"; _ideas[13] = "Rust"; _ideas[14] = "Haskell"; _ideas[15] = "Objective-C";_ideas[16] = "MATLAB"; _ideas[17] = "R"; _ideas[18] = "SQL"; _ideas[19] = "Dart";_ideas[20] = "Lua"; _ideas[21] = "Groovy"; _ideas[22] = "Visual Basic"; _ideas[23] = "SAS";_ideas[24] = "Shell"; _ideas[25] = "F#"; _ideas[26] = "Erlang"; _ideas[27] = "Solidity";_ideas[28] = "Ada"; _ideas[29] = "COBOL"; _ideas[30] = "ActionScript"; _ideas[31] = "Elixir";_ideas[32] = "Julia"; _ideas[33] = "Smalltalk"; _ideas[34] = "OCaml"; _ideas[35] = "Scheme";_ideas[36] = "Lisp"; _ideas[37] = "XSLT"; _ideas[38] = "Fortran"; _ideas[39] = "ML";_ideas[40] = "AWK"; _ideas[41] = "VHDL"; _ideas[42] = "Verilog"; _ideas[43] = "LabVIEW";_ideas[44] = "Prolog"; _ideas[45] = "Logo"; _ideas[46] = "Simula"; _ideas[47] = "REXX";_ideas[48] = "SML"; _ideas[49] = "Tcl"; _ideas[50] = "Hack"; _ideas[51] = "Crystal";_ideas[52] = "Nim"; _ideas[53] = "Haxe"; _ideas[54] = "Io"; _ideas[55] = "RPG";_ideas[56] = "ABAP"; _ideas[57] = "Eiffel"; _ideas[58] = "Dylan"; _ideas[59] = "Bash";_ideas[60] = "Forth"; _ideas[61] = "Apex"; _ideas[62] = "Modula-2"; _ideas[63] = "D";_ideas[64] = "Ada 95"; _ideas[65] = "PL/SQL"; _ideas[66] = "Squirrel"; _ideas[67] = "PostScript";_ideas[68] = "Zig"; _ideas[69] = "VHDL-AMS"; _ideas[70] = "OpenCL"; _ideas[71] = "GLSL";_ideas[72] = "Eiffel"; _ideas[73] = "Zsh"; _ideas[74] = "XBase"; _ideas[75] = "HCL";_ideas[76] = "Racket"; _ideas[77] = "Fantom"; _ideas[78] = "X++"; _ideas[79] = "NATURAL";_ideas[80] = "ML"; _ideas[81] = "J"; _ideas[82] = "SASL"; _ideas[83] = "RPG";_ideas[84] = "XQuery"; _ideas[85] = "GAMS"; _ideas[86] = "Bourne"; _ideas[87] = "GAMS";_ideas[88] = "ABAP"; _ideas[89] = "Racket"; _ideas[90] = "Turing"; _ideas[91] = "Modula-3";_ideas[92] = "Chapel"; _ideas[93] = "SML/NJ"; _ideas[94] = "Apex"; _ideas[95] = "GAMS";_ideas[96] = "XQuery"; _ideas[97] = "Fantom"; _ideas[98] = "Hack"; _ideas[99] = "J";
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& src){
    std::cout << "Brain copy constructor called\n";
    *this = src;
}

/* Destructor */
Brain::~Brain(){
    std::cout << "Brain destroyed\n";
}

/* Overload */
Brain& Brain::operator=(Brain const& other){
    std::cout << "Brain assignation operator called\n";
    (void)other;
    return *this;
}

/* Methods */
void Brain::getIdea() const
{
    std::cout << _ideas[rand() % 100] << std::endl;
}
