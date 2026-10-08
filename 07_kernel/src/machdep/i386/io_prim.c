/*
 * Out-of-line io space access routines (plan 244).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes
 * (D024); Darwin 0.1 machdep/i386/io_prim.c was consulted for
 * structure only.  The inline routines themselves come from
 * machdep/i386/io_inline.h.
 */

#define DEFINE_INLINE_FUNCTIONS

#import <machdep/i386/io_inline.h>

void
linw(
    unsigned short	port,
    unsigned short	*addr,
    unsigned int	count
)
{
    while (count-- > 0)
	*addr++ = inw(port);
}

void
loutw(
    unsigned short	port,
    unsigned short	*addr,
    unsigned int	count
)
{
    while (count-- > 0)
	outw(port, *addr++);
}
