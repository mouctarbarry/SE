#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACTION_SIZE 16
#define WORD_SIZE   48

/**
 * Defines a lexicon.
 */
struct lexc {
	
};

/**
 * Initializes a lexicon data structure.
 * 
 * The lexicon must be freed using the lexc_fini() function.
 *
 * @param[in]  name             Lexicon name.
 * @param[in]  mutable          TRUE if the lexicon is mutable.
 *
 * @return     New lexicon.
 */
struct lexc *lexc_init(const char *name, const int mutable)
{
    return NULL;
}

/**
 * Releases a lexicon data structure.
 *
 * @param      lexc             Lexicon to release.
 */
void lexc_fini(struct lexc *lexc)
{

}

int lexc_add(struct lexc *lexc, const char *word)
{
    return 1;
}

int lexc_remove(struct lexc *lexc, const char *word)
{
    return 1;
}

int lexc_check(struct lexc *lexc, const char *word)
{
    return 1;
}

int cmd_interpret(struct lexc *lexc, const char *cmd)
{
    return 0;
}
