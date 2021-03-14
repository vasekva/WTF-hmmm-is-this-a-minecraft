#ifndef EXCEPTION_H
# define EXCEPTION_H

# define ONE		"PARSE ERROR: String can't end with space symbol!\n"
# define TWO		"PARSE ERROR: Unknown param in str!\n"
# define THREE		"PARSE ERROR: There's no map in the file!\n"
# define FOUR		"PARSE ERROR: String can't be without a space after identifier!\n"
# define FIVE		"PARSE ERROR: The screen parameters has already been specified!\n"
# define SIX		"PARSE ERROR: Screen size can't be a negative value!\n"
# define SEVEN		"PARSE ERROR: Screen size can't be not a digit value!\n"
# define EIGHT		"PARSE ERROR: File path can't be empty!\n"
# define NINE		"PARSE ERROR: Color can't be a negative value!\n"
# define TEN		"PARSE ERROR: Color can't be not a digit value!\n"
# define ELEVEN		"PARSE ERROR: Value of color can't be bigger than 255!\n"
# define TWELVE		"PARSE ERROR: Invalid character after color value!\n"
# define THIRTEEN	"Parameter F has already been specified!\n"
# define FOURTEEN	"Parameter C has already been specified!\n"
# define FIVETEEN	"PARSE ERROR: Not all parameters are filled in! The map must be the last!\n"
# define SIXTEEN	"PARSE ERROR: Empty string can't contain characters!\n"
# define SEVENTEEN	"PARSE ERROR: Map_arr malloc error!\n"
# define EIGHTEEN	"PARSE ERROR: Map size must bigger than 2!\n"

# define NINETEEN		"MAP CHECK ERROR: The map must be flush to the left!\n"
# define TWENTY			"MAP CHECK ERROR: There is a hole on the map!\n"
# define TWENTYONE		"MAP CHECK ERROR: Top line must be closed!\n"
# define TWENTYTWO		"MAP CHECK ERROR: Map has a hole over line with spaces!\n"
# define TWENTYTHREE	"MAP CHECK ERROR: Map has a hole under line with spaces!\n"
# define TWENTYFOUR		"MAP CHECK ERROR: Left wall of map might be equals only 1!\n"
# define TWENTYFIVE		"MAP CHECK ERROR: The inner corner of the map must be covered!\n"
# define TWENTYSIX		"MAP CHECK ERROR: Zero symbols must be covered!\n"


# endif