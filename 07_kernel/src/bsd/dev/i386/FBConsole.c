/*
 * FBConsole.c (plan 379; earlier diagnosis plans 341, 369).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original object __text [0x19ba18, 0x19f09d), __data [0x1e4704, 0x1e488b)).
 * The text is nearly the same as Darwin 0.1
 * kernel/bsd/dev/i386/FBConsole.c except the lines marked plan 341, 369
 * and 379; kept as project-authored under D027/D030, without Darwin's
 * notices (license judgement: D017).
 */

// TO DO:
// * Implement other cases of FlipCursor, HorizLine, VertLine, ClearWindow.
//   Erase
// * Find the #defines for np and del are, then get rid of our #defines.
//
// Notes:
// * This module implements the console functionality required by the
//   ConsoleSupport protocol. If you have a device which is a framebuffer
//   with a depth supported by this module, then you can use this code. 
// * To find things that need to be fixed, search for FIX, to find questions
//   to be resolved, search for ASK, to find stuff that still needs to be
//   done, search for TO DO.

#import <sys/syslog.h>
#import	<bsd/dev/i386/FBConsole.h>
#import	<bsd/dev/i386/FBConsPriv.h>
#import <architecture/ascii_codes.h>

#if defined(NOTINKERNEL)
#define panic(str)
#define copyin(src, dst, size) bcopy(src, dst, size)
#define kalloc(size) malloc(size)
#define kfree(ptr, size) free(ptr)
#endif

#define	NIL	(0)

/* Window margins */
#define BG_MARGIN	2	// pixels of background to leave as margin
#define FG_MARGIN	1	// pixels of foreground to leave as margin
#define TOTAL_MARGIN	(BG_MARGIN + FG_MARGIN)

/*
 * Ansi sequence state.
 */
typedef enum {
	AS_NORMAL,
	AS_ESCAPE,
	AS_BRACKET,
	AS_R
} ansi_state_t;

#define ANSI_STACK_SIZE	3

typedef struct _t_Console {
    ScreenMode		window_type;

    IODisplayInfo	display;

    //
    // The remaining fields are window parameters. These are only 
    // meaningful for text-type windows (window_type == SCM_TEXT or 
    // SCM_ALERT).
    //
	
    //
    // Current window origin in pixels, relative to origin of screen.
    //
    int			window_origin_x;
    int			window_origin_y;

    //
    // Window size information, in pixels and in characters.
    //
    int			chars_per_row;	
    int			pixels_per_row;	
    int			chars_per_column;
    int 		pixels_per_column;

    //
    // Cursor location, in characters. Origin is top 
    // left corner of window = {0,0}. 
    //
    int			curr_row;		// in characters
    int 		curr_column;		// in characters
    
    //
    // Misc. video parameters. The background and foreground fields
    // are slightly dependent on the hardware implementation; they'll
    // work as long as bits per pixel <= 32.
    //
    unsigned int	baseground;	// bits for base color
    unsigned int	background;	// bits for background pixel
    unsigned int	foreground;	// bits for foreground pixel
    unsigned int	dark_grey;	// bits for dark grey
    unsigned int	light_grey;	// bits for light grey
    boolean_t		has_title;

    //
    // Storage for saved region under an alert panel.
    //
    unsigned char *saveBits;
    int saveHeight;
    int saveRowBytes;
    int saveBytes;
    unsigned char *saveLocation;
    ansi_state_t ansi_state;	/* track ansi escape sequence state */
    u_char ansi_stack[ANSI_STACK_SIZE];
    u_char *ansi_stack_p;

} ConsoleRep, *ConsolePtr;

//
// BEGIN:	Private utility routines
//
static unsigned int BPPToPPW(int bpp)
{
  if (bpp == IO_2BitsPerPixel) return(16);
  if (bpp == IO_8BitsPerPixel) return(4);
  if (bpp == IO_12BitsPerPixel) return(2);
  if (bpp == IO_15BitsPerPixel) return(2);
  if (bpp == IO_24BitsPerPixel) return(1);
  else return(-1);
}

static unsigned char *PixelAddress(ConsolePtr console, int xPix, int yPix)
{
    switch (console->display.bitsPerPixel) {
        case IO_8BitsPerPixel:
	    return ((unsigned char *)console->display.frameBuffer) +
		    yPix * console->display.rowBytes + xPix;
        case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:
	    return ((unsigned char *)console->display.frameBuffer) +
		    yPix * console->display.rowBytes + xPix * 2;
	case IO_24BitsPerPixel:
	    return ((unsigned char *)console->display.frameBuffer) +
		    yPix * console->display.rowBytes + xPix * 4;
	default:
	    panic("FBConsole/PixelAddress: bogus bitsPerPixel");
    }
}

static void Fill(ConsolePtr console,
    unsigned char *dst,		// Where to start filling
    unsigned pixel, 		// pattern to fill
    unsigned len)		// in pixels
// Descritpion:	Fill the framebuffer with 'pixel' starting at dst
//		and for 'len' pixels.
{
    switch (console->display.bitsPerPixel) {
        case IO_8BitsPerPixel:
	    {
	    unsigned char *dst8 = (unsigned char *)dst;
	    for (; len--; dst8++)
	        *dst8 = pixel;
	    break;
	    }
        case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:
	    {
	    unsigned short *dst16 = (unsigned short *)dst;
	    for (; len--; dst16++)
	        *dst16 = pixel;
	    break;
	    }
	case IO_24BitsPerPixel:
	    {
	    unsigned int *dst32 = (unsigned int *)dst;
	    for (; len--; dst32++)
	        *dst32 = pixel;
	    break;
	    }
	default:
	    panic("FBConsole/Fill: bogus bitsPerPixel");
    }
}

static void FlipCursor(ConsolePtr console)
// Description: Turn cursor on/off. This just inverts every pixel at the
// character at (curr_rown, curr_column).
{
    int y;
    unsigned char *dst8;
    unsigned short *dst16;
    unsigned int *dst32;
    unsigned pixel_num;
    
    // Screen-relative pixel coordinates of bounds of current  character.
    int start_y = console->window_origin_y +
        console->curr_row * CHAR_H;
    int end_y   = start_y + CHAR_H;
    int start_x = console->window_origin_x +
        console->curr_column * CHAR_W;
    
    for (y=start_y; y < end_y; y++) {
	switch (console->display.bitsPerPixel) {
	    case IO_8BitsPerPixel:
		dst8 = (unsigned char *)PixelAddress(console, start_x, y);
		for (pixel_num = 0; pixel_num < CHAR_W; pixel_num++) {
			if ((*dst8 & PIXEL_MASK_16) ==
			    (console->background & PIXEL_MASK_16)) {
				*dst8 = console->foreground;
			}
			else {
				*dst8 = console->background;
			}
			dst8++;
		}
		break;
	    case IO_12BitsPerPixel:
	    case IO_15BitsPerPixel:
		dst16 = (unsigned short *)PixelAddress(console, start_x, y);
		for (pixel_num = 0; pixel_num < CHAR_W; pixel_num++) {
			if ((*dst16 & PIXEL_MASK_16) ==
			    (console->background & PIXEL_MASK_16)) {
				*dst16 = console->foreground;
			}
			else {
				*dst16 = console->background;
			}
			dst16++;
		}
		break;
	    case IO_24BitsPerPixel:
		dst32 = (unsigned int *)PixelAddress(console, start_x, y);
		for (pixel_num = 0; pixel_num < CHAR_W; pixel_num++) {
			if ((*dst32 & PIXEL_MASK_32) ==
			    (console->background & PIXEL_MASK_32)) {
				*dst32 = console->foreground;
			}
			else {
				*dst32 = console->background;
			}
			dst32++;
		}
		break;
		
	    default:
		panic("FBConsole/FlipCursor: bogus bits per pixel");
	}	
    }
}

static void SwapForegroundAndBackground(ConsolePtr console)
{
    int temp_color;
    
    temp_color = console->foreground;
    console->foreground = console->background;
    console->background = temp_color;
}

static void Rect(
    ConsolePtr console,
    int origin_x, int origin_y,
    int width, int height,
    unsigned pixel)
// Description:	Draws a single pixel wide horizontal line
{
    while (height--) {
	Fill(console,
	    PixelAddress(console, origin_x, origin_y++),
	    pixel, width);
    }
}

#if notdef
static void HorizLine(
    ConsolePtr console,
    int origin_x, int origin_y, int length,
    unsigned pixel)
// Description:	Draws a single pixel wide horizontal line
{
    Fill(console, PixelAddress(console, origin_x, origin_y), pixel, length);
}

static void VertLine(
    ConsolePtr console,
    int origin_x, int origin_y, int length,
    unsigned pixel)
// Description:	Draws a single pixel wide vertical line
{
    unsigned char *dstPixel = PixelAddress(console, origin_x, origin_y);

    switch(console->display.bitsPerPixel) {
	case IO_8BitsPerPixel:
	    {
		unsigned char *dst = (unsigned char *)dstPixel;
		while (length--) {
		    *dst = pixel;
		    dst += console->display.totalWidth;
		}
	    }
	    break;
	case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:
	    {
		unsigned short *dst = (unsigned short *)dstPixel;
		while (length--) {
		    *dst = pixel;
		    dst += console->display.totalWidth;
		}
	    }
	    break;
	case IO_24BitsPerPixel:
	    {
		unsigned long *dst = (unsigned long *)dstPixel;
		while (length--) {
		    *dst = pixel;
		    dst += console->display.totalWidth;
		}
	    }
	    break;
	    
	default:
	    panic("FBConsole/VertLine: bogus bits per pixel");
    }
}
#endif

static void ClearWindow(ConsolePtr console)
// Description:	 Set contents of entire current window to background.
// Preconditions:
// *	Cursor is off on entry and will remain so on exit.
{
    int line;
    unsigned char *dstPixel = PixelAddress(
        console, console->window_origin_x, console->window_origin_y);

    for (line=0; line < console->pixels_per_column; line++) {
	// One loop per scan line in the window.
	Fill(console, dstPixel, console->background,
	     console->pixels_per_row);
	dstPixel += console->display.rowBytes;
    }
}

static void WipeScreen(ConsolePtr console, const unsigned pixel)
// Description:	Fill the screen with specific pixel value.  
{
    unsigned count;			// total # of pixels to clear
    
    count = console->display.totalWidth * console->display.height;
    Fill(console, PixelAddress(console, 0, 0), pixel, count);
}

static void ClearToEOL(ConsolePtr console)
// Description:	Clear to end of line (within window), including current pos.
// Preconditions:
// *	Cursor is 'off' on entry and will remain so on exit.
{
    unsigned pixel_count;
    int starting_x;			// window-relative 'x' coordinate
    int y;
    int line;	

    starting_x = console->window_origin_x + 
	(console->curr_column * CHAR_W);
    y = console->window_origin_y + (console->curr_row * CHAR_H);

    pixel_count = console->pixels_per_row -
        (starting_x - console->window_origin_x);

    for (line=0; line < CHAR_H; line++) {
	// One loop per scan line in the row.
	Fill(
	    console, PixelAddress(console, starting_x, y++),
	    console->background, pixel_count);
    }
}

static void Erase(ConsolePtr console)
// Description: Erase current cursor location.
{
    int y;
    unsigned char *dst8;
    unsigned short *dst16;
    unsigned int *dst32;
    int x;
    // Screen-relative pixel coordinates of bounds of current character.
    int start_y = console->window_origin_y +
        console->curr_row * CHAR_H;
    int end_y   = start_y + CHAR_H;
    int start_x = console->window_origin_x +
        console->curr_column * CHAR_W;
    
    for (y=start_y; y<end_y; y++) {
	// I think it's quicker not to use Fill() here...
	switch (console->display.bitsPerPixel) {
	    case IO_8BitsPerPixel:
		dst8 = (unsigned char *)PixelAddress(console, start_x, y);
		for (x=0; x < CHAR_W; x++) {
		    *dst8++ = console->background;
		}
		break;
	    case IO_12BitsPerPixel:
	    case IO_15BitsPerPixel:
		dst16 = (unsigned short *)PixelAddress(console, start_x, y);
		for (x=0; x < CHAR_W; x++) {
		    *dst16++ = console->background;
		}
		break;
	    case IO_24BitsPerPixel:
		dst32 = (unsigned int *)PixelAddress(console, start_x, y);
		for (x=0; x < CHAR_W; x++) {
		    *dst32++ = console->background;
		}
		break;
		
	    default:
		panic("FBConsole/Erase: bogus bits per pixel");	
	}	
    }
}

#define ENCODEBASE ' '

static void BltChar(ConsolePtr console, const char c)
// Description: Paint one character at (curr_column, curr_row).
{
    unsigned char *glyphbase;	// the glyph we're rendering
    unsigned char byte;
    int x,y;			// location of upper left corner of glyph
    int source_y;
    unsigned char *dst8, fg8;
    unsigned short *dst16, fg16;
    unsigned int *dst32, fg32;

    // Erase current contents of {curr_row, curr_column}.
    Erase(console);
    
    // Skip non-printing characters.
    if (c < ENCODEBASE) {
	return;
    }
	    
    glyphbase = ohlfs12[c - ENCODEBASE];
    x = console->window_origin_x + console->curr_column * CHAR_W;
    y = console->window_origin_y + console->curr_row * CHAR_H;

    switch (console->display.bitsPerPixel) {
	case IO_8BitsPerPixel:
	    fg8 = (unsigned char) console->foreground;
	    dst8 = (unsigned char *)PixelAddress(console, x, y);
	    for (source_y = CHAR_H; source_y != 0; source_y--) {
		byte = *glyphbase++;
		if (byte & 0x80) dst8[0] = fg8;
		if (byte & 0x40) dst8[1] = fg8;
		if (byte & 0x20) dst8[2] = fg8;
		if (byte & 0x10) dst8[3] = fg8;
		if (byte & 0x08) dst8[4] = fg8;
		if (byte & 0x04) dst8[5] = fg8;
		if (byte & 0x02) dst8[6] = fg8;
		if (byte & 0x01) dst8[7] = fg8;
		dst8 = (unsigned char *)
				((int)dst8 + console->display.rowBytes);
	    }
	    break;
	case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:
	    fg16 = (unsigned short) console->foreground;
	    dst16 = (unsigned short *)PixelAddress(console, x, y);
	    for (source_y = CHAR_H; source_y != 0; source_y--) {
		byte = *glyphbase++;
		if (byte & 0x80) dst16[0] = fg16;
		if (byte & 0x40) dst16[1] = fg16;
		if (byte & 0x20) dst16[2] = fg16;
		if (byte & 0x10) dst16[3] = fg16;
		if (byte & 0x08) dst16[4] = fg16;
		if (byte & 0x04) dst16[5] = fg16;
		if (byte & 0x02) dst16[6] = fg16;
		if (byte & 0x01) dst16[7] = fg16;
		dst16 = (unsigned short *)
				((int)dst16 + console->display.rowBytes);
	    }
	    break;
	case IO_24BitsPerPixel:
	    fg32 = (unsigned int) console->foreground;
	    dst32 = (unsigned int *)PixelAddress(console, x, y);
	    for (source_y = CHAR_H; source_y != 0; source_y--) {
		byte = *glyphbase++;
		if (byte & 0x80) dst32[0] = fg32;
		if (byte & 0x40) dst32[1] = fg32;
		if (byte & 0x20) dst32[2] = fg32;
		if (byte & 0x10) dst32[3] = fg32;
		if (byte & 0x08) dst32[4] = fg32;
		if (byte & 0x04) dst32[5] = fg32;
		if (byte & 0x02) dst32[6] = fg32;
		if (byte & 0x01) dst32[7] = fg32;
		dst32 = (unsigned int *)
				((int)dst32 + console->display.rowBytes);
	    }
	    break;
    }

    console->curr_column++;
    return;
}

static void FBPutC(ConsolePtr console, char c)
// Write one character to screen. Cursor is 'on' on entry and exit.
{
int	repeat;
int	i;

	if (console->window_type == SCM_GRAPHIC)	/* plan 341 */
		return;
	/*
	 * First deal with ANSI escape sequences.
	 * This is a very bizarre implementation, copied from the m68k
	 * version. 
	 */
	switch(console->ansi_state) {
	    case AS_NORMAL:
	    	if(c == esc) {
			console->ansi_state = AS_ESCAPE;
			return;
		}
		else {
			break;				// continue
		}
		
	    case AS_ESCAPE:
	        switch(c) {
	  	    case '[':
			console->ansi_state = AS_BRACKET;
			return;
		    default:
			console->ansi_state = AS_NORMAL;
			break;				// continue
		}
	
	    case AS_BRACKET:
		if(c >= '0' && c <= '9') {
			*console->ansi_stack_p = 
				*console->ansi_stack_p * 10 + (c - '0');
			return;
		} 
		else if (c == ';') {
			if(console->ansi_stack_p < 
			    &console->ansi_stack[ANSI_STACK_SIZE]) {
				console->ansi_stack_p++;
			}
			return;
		} 
		else {
			for(i=0; i<ANSI_STACK_SIZE; i++) {
				if (console->ansi_stack[i] == 0) {
					console->ansi_stack[i] = 1; 
				}
			}
			repeat = *console->ansi_stack_p;
			FlipCursor(console);		// cursor off
			switch (c) {

			    case 'A':
				while (repeat--) {
					if(console->curr_row) {
						console->curr_row--;
					}
				}
				break;

			    case 'B':
				while (repeat--) {
					console->curr_row++;
				}
				break;

			    case 'C':		// non destructive space
				while (repeat--) {
					console->curr_column++;
				}
				break;

			    case 'D':		// not in termcap
				while (repeat--) {
					if(console->curr_column) {
						console->curr_column--;
					}
				}
				break;

			    case 'E':		// not in termcap
				console->curr_column = 0;
				while (repeat--) {
					console->curr_row++;
				}
				break;

			    case 'H':		// should be home
			    case 'f':		// not in termcap
				console->curr_column = 
					*console->ansi_stack_p - 1;
				console->ansi_stack_p--;
				console->curr_row = 
					*console->ansi_stack_p - 1;
				console->ansi_stack_p--;
				break;

			    case 'K':
				ClearToEOL(console);
				break;
				
			    case 'm': /* FIXME */
				console->ansi_stack_p--;
				console->ansi_stack_p--;
				break;
			}
		}
		console->ansi_stack_p = &console->ansi_stack[1];
		for(i=0; i<ANSI_STACK_SIZE; i++)
			console->ansi_stack[i] = 0;
		console->ansi_state = AS_NORMAL;
		goto proceed;
	}

    FlipCursor(console);		// cursor off
    switch(c) {
	case '\r':			// Carriage return
	    console->curr_column = 0;
	    break;    	
	    
	case '\n':			// line feed
	    console->curr_column = 0;
	    console->curr_row++;
	    break;
	    
	case '\b':			// backspace
	    if (console->curr_column == 0)
		    break;
	    console->curr_column--;
	    break;
	    
	case '\t':
	    // tab. Erase all characters up to and including the 
	    // next tab stop.
	    {
	    int col, num_cols;
	    
	    num_cols = TAB_SIZE - (console->curr_column % TAB_SIZE);
	    FlipCursor(console);			// cursor on
	    for (col = 0; col<num_cols; col++) {
	    	FBPutC(console, ' ');			// cursor on at return
	    }
	    FlipCursor(console);			// cursor off
	    break;
	    }
	    
	case np:				// aka ff, form feed
	    console->curr_row = console->curr_column = 0;
	    ClearWindow(console);
	    break;

	case del:
	    console->curr_column++;
	    break;
	    
	default:
	    // Normal case.
	    BltChar(console, c);
	    break;
    }
    
    // Cursor is off.
proceed:	
    if (console->curr_column >= console->chars_per_row) {
	// End-of-line wrap. 
	console->curr_column = 0;
	console->curr_row++;
    }
    
    if (console->curr_row >= console->chars_per_column) {
	//
	// Screen scroll. Copy the whole window down in memory 
	// (pixels_per_row * CHAR_H) pixels, starting at 
	// the first character in row 1.
	//
	unsigned char *src;	
	unsigned char *dst;
	int source_y;
	unsigned windowRowBytes;
	
	console->curr_row = console->chars_per_column - 1;
	switch (console->display.bitsPerPixel) {
	    case IO_8BitsPerPixel:
	        windowRowBytes = console->pixels_per_row;
		break;
	    case IO_12BitsPerPixel:
	    case IO_15BitsPerPixel:
	        windowRowBytes = 2*console->pixels_per_row;
		break;
	    case IO_24BitsPerPixel:
		windowRowBytes = 4*console->pixels_per_row;
		break;
	    default:
		panic("FBConsole/FBPutC: bogus bitsPerPixel");	
	}

	// Copy one row at a time, moving each one up
	// CHAR_H rows. Within the loop, just increment
	// pixel pointers by one row's worth of pixels.
	// Source starts at the left top of row 1; destination 
	// starts at left top of row 0.
	//
	src = PixelAddress(console, 
	    console->window_origin_x,
	    console->window_origin_y + CHAR_H);
	dst  = PixelAddress(console,
		console->window_origin_x,
		console->window_origin_y);
	for (source_y = CHAR_H;		// top, row 1
	    source_y < console->pixels_per_column;	// bottom
	    source_y++) {
	    memmove(dst, src, windowRowBytes);
	    src += console->display.rowBytes;
	    dst += console->display.rowBytes;
	}

	console->curr_column = 0;
	ClearToEOL(console);
}
    
    // Cursor back on.
    FlipCursor(console);
}

static void SetTitle(ConsolePtr console, const char *title)
// Description:	Draw title bar if none exists, write specified title into it.
//		Drawing a title bar involves snarfing up row 0 of the window
//		and decreasing the usable size of the window by one row.
// Preconditions:
// *	Cursor is 'on' on entry and will remain so on exit.
{
    int saved_curr_row = console->curr_row;
    int saved_curr_column = console->curr_column;
    int saved_origin_y;
    int title_len = strlen(title);
    int pixel_num;
    
    if ((title_len == 0) || (title_len > console->chars_per_row)) {
	    IOLog("console: Illegal title length (%d)\n", title_len);
	    return;
    }
    FlipCursor(console);			// old cursor off
    if (console->has_title) {
	// First grow window by two rows - this absorbs the existing 
	// title bar.
	console->window_origin_y -= CHAR_H * 2;
	console->chars_per_column += 2;
	console->pixels_per_column += CHAR_H * 2;
	saved_curr_row += 2;
    }

    // Clear row 0, center new title in it.
    console->curr_row = 0;
    Rect(console,
	console->window_origin_x,
	console->window_origin_y,
	CHAR_W * console->chars_per_row,
	CHAR_H * 2 - BG_MARGIN,
	console->foreground);
    saved_origin_y = console->window_origin_y;
    console->window_origin_y += CHAR_H / 2;
    console->curr_column = (console->chars_per_row - title_len) / 2;
    FlipCursor(console);				// new cursor on	
    SwapForegroundAndBackground(console);
    while (*title) {
	FBPutC(console, *title++);
    }
    SwapForegroundAndBackground(console);
    FlipCursor(console);			// new cursor off	
    console->window_origin_y = saved_origin_y;
    
    // Draw grey lines one pixel away from border of title bar.
    // Origin is currently at first pixel in top line of title bar.

    Rect(console,				// inside top
	console->window_origin_x - BG_MARGIN,
	console->window_origin_y - BG_MARGIN,
	console->pixels_per_row + (BG_MARGIN * 2),
	BG_MARGIN,
	console->light_grey);
    Rect(console,				// inside bottom
	console->window_origin_x - BG_MARGIN,
	console->window_origin_y + CHAR_H * 2 - TOTAL_MARGIN - BG_MARGIN,
	console->pixels_per_row + BG_MARGIN * 2,
	BG_MARGIN,
	console->dark_grey);
    for (pixel_num = 0; pixel_num < BG_MARGIN; pixel_num++) {
        Rect(console,				// left
	    console->window_origin_x - BG_MARGIN + pixel_num,
	    console->window_origin_y - BG_MARGIN + pixel_num,
	    1,
	    CHAR_H * 2 - 1 - (pixel_num * 2),
	    console->light_grey);
    }
    for (pixel_num = 1; pixel_num <= BG_MARGIN; pixel_num++) {
        Rect(console,				// right
	    console->window_origin_x + console->pixels_per_row + pixel_num - 1,
	    console->window_origin_y - pixel_num,
	    1,
	    CHAR_H * 2 - 1 - (BG_MARGIN - pixel_num) * 2,
	    console->dark_grey);
    }
    Rect(console,				// outside bottom
	console->window_origin_x - TOTAL_MARGIN,
	console->window_origin_y + CHAR_H * 2 - FG_MARGIN - BG_MARGIN,
	console->pixels_per_row + TOTAL_MARGIN * 2,
	FG_MARGIN,
	console->foreground);
	    
    // Diminish window size by two rows.
    console->window_origin_y += CHAR_H * 2;
    console->chars_per_column -= 2;
    console->pixels_per_column -= CHAR_H * 2;
    

    // Restore old cursor. Careful, the y axis just changed...
    console->curr_column = saved_curr_column;
    if (saved_curr_row > 0) {
	console->curr_row = saved_curr_row - 2;
    } 
    else {
	// New row 0 - clear it.
	ClearToEOL(console);
    }
    FlipCursor(console);			// old cursor on
    console->has_title = TRUE;	
}

static void UpdateWindowChars(ConsolePtr console)
// Description:	Calculate window size in characters. Used when either window
//		size or font changes.
{
    console->chars_per_row = console->pixels_per_row / CHAR_W;
    console->chars_per_column =
        console->pixels_per_column / CHAR_H;
}



static void InitWindow(ConsolePtr console,
	int		width,
	int 		height,
	const char 	*title,
	boolean_t 	initWindow,
	boolean_t	saveUnder)
// Description:	Initialize window parameters. If initWindow is TRUE, an empty
//		window is drawn in the screen, else we assume that a window
//		already  exists. Screen and font parameters must be valid on
//		entry.
{
    // Truncate specified size to integral mutliple of character size
    // in both dimensions.
    width  /= CHAR_W;		// now in chars
    height /= CHAR_H;
    width  *= CHAR_W;		// now in pixels
    height *= CHAR_H;
    
    // Ensure there's enough room for a border.
    if (width > (console->display.width - TOTAL_MARGIN * 2))
	width = console->display.width - TOTAL_MARGIN * 2;
    if (height > (console->display.height - TOTAL_MARGIN * 2))
	height = console->display.height - TOTAL_MARGIN * 2;
	    
    //
    // Init console window variables. The window is centered in the 
    // screen, minus a pixel or two to guarantee double word alignment
    // for the first pixel of a row (until further developments...when 
    // we do alert panels, we can enumerate some cases here...).
    //
    console->window_origin_x   = (console->display.width - width) / 2;
    console->window_origin_y   = (console->display.height - height) / 2;
    console->pixels_per_row    = width;
    console->pixels_per_column = height;
    (unsigned)console->window_origin_x &= ~0x07;

    UpdateWindowChars(console);
    
    console->curr_column = 0;
    console->has_title = FALSE;
    
    if (initWindow) {
	// Before we start drawing anything, save under if needed
	if (saveUnder) {
	    int i, bytesPerPixel = 0;
	    unsigned char *save, *sp;

	    // Compute size of save under region in bytes and allocate
	    switch (console->display.bitsPerPixel) {
		case IO_8BitsPerPixel:  bytesPerPixel = 1; break;
		case IO_12BitsPerPixel:
		case IO_15BitsPerPixel: bytesPerPixel = 2; break;
		case IO_24BitsPerPixel: bytesPerPixel = 4; break;
	    }
	    console->saveHeight = height + TOTAL_MARGIN * 2;
	    console->saveRowBytes = (width + TOTAL_MARGIN * 2)*bytesPerPixel;
	    console->saveBytes = console->saveHeight*console->saveRowBytes;
	    save = console->saveBits = (unsigned char *)
                                        IOMalloc(console->saveBytes);	/* plan 379 (Darwin 0.1: kalloc_noblock) */
	    sp = console->saveLocation = 
		PixelAddress(console, console->window_origin_x - TOTAL_MARGIN, 
			      console->window_origin_y - TOTAL_MARGIN);

	    // Copy the window contents into the save under
	    /* plan 341: no "if (save)" test (Darwin 0.1 has one) */
                for (i = console->saveHeight; i != 0; i--) {
                    memmove(save, sp, console->saveRowBytes);
                    sp += console->display.rowBytes;
                    save += console->saveRowBytes;
                }
	}
    
	// New window - cursor at origin.
	console->curr_row = 0;
	console->has_title = FALSE;
	
	// Draw the border. The border goes outside of the specified
	// window. Outside lines are black; inside lines are 
	// half-tone.
	Rect(console,				// outside top
	    console->window_origin_x - TOTAL_MARGIN,
	    console->window_origin_y - TOTAL_MARGIN,
	    width + TOTAL_MARGIN * 2,
	    FG_MARGIN,
	    console->foreground);
	Rect(console,				// inside top
	    console->window_origin_x - BG_MARGIN,
	    console->window_origin_y - BG_MARGIN,
	    width + BG_MARGIN * 2,
	    BG_MARGIN,
	    console->background);
	Rect(console,				// inside bottom
	    console->window_origin_x - BG_MARGIN,
	    console->window_origin_y + height,
	    width + BG_MARGIN * 2,
	    BG_MARGIN,
	    console->background);
	Rect(console,				// outside bottom
	    console->window_origin_x - TOTAL_MARGIN,
	    console->window_origin_y + height + BG_MARGIN,
	    width + TOTAL_MARGIN * 2,
	    FG_MARGIN,
	    console->foreground);
	Rect(console,				// outside left
	    console->window_origin_x - TOTAL_MARGIN,
	    console->window_origin_y - TOTAL_MARGIN,
	    FG_MARGIN,
	    height + TOTAL_MARGIN * 2,
	    console->foreground);
	Rect(console,				// inside left
	    console->window_origin_x - BG_MARGIN,
	    console->window_origin_y - BG_MARGIN,
	    BG_MARGIN,
	    height + BG_MARGIN * 2,
	    console->background);
	Rect(console,				// inside right
	    console->window_origin_x + width,
	    console->window_origin_y - BG_MARGIN,
	    BG_MARGIN,
	    height + BG_MARGIN * 2,
	    console->background);
	Rect(console,				// outside right
	    console->window_origin_x + width + BG_MARGIN,
	    console->window_origin_y - TOTAL_MARGIN,
	    FG_MARGIN,
	    height + TOTAL_MARGIN * 2,
	    console->foreground);
		
	// Clear the contents of the window and draw a cursor.
	ClearWindow(console);
	FlipCursor(console);			// cursor on
	SetTitle(console, title);
    }
    else {
	    /* Leave current window contents, just updating title. 
	     * We'll do a newline to make sure we have room for 
	     * our font and proceed.Initial cursor will be at 
	     * lower left corner.
	     */
	    console->curr_row = console->chars_per_column - 1;
	    SetTitle(console, title);
	    FBPutC(console, '\n');
    }
    return;
}

//
// END:		Private utility routines
//

//
// BEGIN:	Implementation of IOConsoleInfo functions
//
static void Free(IOConsoleInfo *cso)
// Description: Free a FB Console object
{
    IOFree(cso->priv, sizeof(ConsoleRep));
    IOFree(cso, sizeof(IOConsoleInfo));
}

static void Init(
    IOConsoleInfo *cso,
    ScreenMode mode,
    boolean_t initScreenOrSaveUnder,
    boolean_t initWindow,
    const char *title)
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    int i;
	
    /* plan 341: 4.2 colour values for 8, 15 and 24 bit (Darwin 0.1 differs) */
    switch (console->display.bitsPerPixel) {
        case IO_8BitsPerPixel:
	    if (console->display.colorSpace == IO_OneIsWhiteColorSpace) {
		console->baseground = 0x55;
		console->background = 0xff;
		console->foreground = 0x00;
		console->dark_grey  = 0x55;
		console->light_grey = 0xaa;
	    } else {
		console->baseground = 0x63;
		console->background = 0xef;
		console->foreground = 0x00;
		console->dark_grey  = 0xf5;
		console->light_grey = 0xfa;
	    }
	    break;
        case IO_12BitsPerPixel:
	    console->baseground = 0x55ff;
	    console->background = 0xffff;
	    console->foreground = 0x000f;
	    console->dark_grey  = 0x555f;
	    console->light_grey = 0xaaaf;
	    break;
	case IO_15BitsPerPixel:
	    console->baseground = 0x295f;
	    console->background = 0x7bde;
	    console->foreground = 0x0000;
	    console->dark_grey  = 0x294a;
	    console->light_grey = 0x5294;
	    break;
	case IO_24BitsPerPixel:
	    console->baseground = 0xff5555ff;
	    console->background = 0xffffffff;
	    console->foreground = 0xff000000;
	    console->dark_grey  = 0xff555555;
	    console->light_grey = 0xffaaaaaa;
	    break;
    }
    
    console->ansi_state = AS_NORMAL;
    for(i=0; i<ANSI_STACK_SIZE; i++) {
		console->ansi_stack[i] = 0;
	}
    console->ansi_stack_p = &console->ansi_stack[1];	// FIXME - why not 0?

    // Initialize the screen, if appropriate.
    if (initScreenOrSaveUnder && (console->window_type != SCM_ALERT)) {	/* plan 341 (Darwin 0.1: mode) */
	WipeScreen(console, console->baseground);
    }

    console->window_type = mode;
    switch(console->window_type) {
	case SCM_TEXT:
	    InitWindow(console,	console->display.width * 3 / 4,	/* plan 341 */
		console->display.height * 3 / 4,
		title, initWindow, 0 /* Don't save under */);
	    break;
	case SCM_GRAPHIC:	/* plan 341 */
	    break;
	case SCM_ALERT:
	    InitWindow(console,	ALERT_WIN_WIDTH, ALERT_WIN_HEIGHT,
		title, initWindow, 1 /* Save under */);	/* plan 341 */
	    break;
	default:
	    panic("FBConsole/FBInitConsole: can't init");
    }
    return;
}

static int Restore(IOConsoleInfo *cso)
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    unsigned char *save, *dp;
    int i;

    if (console->window_type != SCM_ALERT) {
	IOLog("frameBuffer: bogus restore, mode %d\n", console->window_type);
	return -1;
    }

    // Copy save under bits back onto screen
    /* plan 369: no "if (save)" test and no saveBits = 0; IOFree (Darwin 0.1: kfree) */
    save = console->saveBits;
    dp = console->saveLocation;
    for (i = console->saveHeight; i != 0; i--) {
	memmove(dp, save, console->saveRowBytes);
	dp += console->display.rowBytes;
	save += console->saveRowBytes;
    }

    // Free bits
    IOFree(console->saveBits, console->saveBytes);
    return 0;
}

#define	VIDEO_W	640	/* plan 341: 4.2 values (Darwin 0.1: 1132) */
#define	VIDEO_H	480	/* plan 341 (Darwin 0.1: 832) */

/*
 * plan 341: the 4.2 DrawRect/EraseRect draw through a four-entry colour table
 * (darkest last) built by ColorTable() for the display depth; Darwin 0.1 returns -1.
 */
static unsigned int table2Bit[4] = { 3, 2, 1, 0 };
static unsigned int table8Bit[4] = { 0xff, 0xf6, 0xf2, 0x00 };
static unsigned int colorTable[4] = { 0 };

static unsigned int *ColorTable(IOConsoleInfo *cso)
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    IODisplayInfo *display = &console->display;
    unsigned int *table = 0;
    int bits, i;
    int rBits, gBits, bBits, rPos, gPos, bPos;
    int level;

    switch (display->bitsPerPixel) {
	case IO_2BitsPerPixel:	table = table2Bit; break;
	case IO_8BitsPerPixel:	table = table8Bit; break;
	case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:	bits = 16; break;
	case IO_24BitsPerPixel:	bits = 32; break;
	default:
	    panic("FBConsole/Fill: bogus bitsPerPixel");
    }
    if (table == 0) {
        rBits = 0;
        gBits = 0;
        bBits = 0;
        rPos = -1;
        gPos = -1;
        bPos = -1;
        for (i = 0; i < bits; i++) {
    	switch (display->pixelEncoding[i]) {
    	    case 'R':
    		if (rPos == -1) rPos = i;
    		rBits++;
    		break;
    	    case 'G':
    		if (gPos == -1) gPos = i;
    		gBits++;
    		break;
    	    case 'B':
    		if (bPos == -1) bPos = i;
    		bBits++;
    		break;
    	}
        }
        for (i = 0; i <= 3; i++) {
    	level = 3 - i;	/* plan 379: masks and shifts written in the loop body */
    	colorTable[i] = (((1 << rBits) - 1) * level / 3 << (bits - rPos - rBits))
    		     | (((1 << gBits) - 1) * level / 3 << (bits - gPos - gBits))
    		     | (((1 << bBits) - 1) * level / 3 << (bits - bPos - bBits));
        }
	table = colorTable;
    }
    return table;
}

/*
 * plan 341, 379: the DrawRect and EraseRect bodies are written from the
 * original bytes (D024); Darwin 0.1 returns -1 before drawing.  They work
 * on local x and y (rect is not changed except width), address the frame
 * buffer by rowBytes (Darwin 0.1: pixel from totalWidth; no size check),
 * take the colours from ColorTable(), EraseRect fills per depth, and
 * DrawRect reads x and y through km_rect (plan 379).  Darwin's Description
 * and Preconditions comments (1132x832 screen) are not kept.
 */
static int DrawRect(IOConsoleInfo *cso,  const struct km_drawrect *km_rect)
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    int i, x, y, xx, yy;
    unsigned char *data;
    unsigned int *table;
    unsigned char value;
    struct km_drawrect *rect = (struct km_drawrect *) km_rect;

    table = ColorTable(cso);

    /* Correct the x and y values for screen size */
    x = km_rect->x + (console->display.width - VIDEO_W)/2;
    y = km_rect->y + (console->display.height - VIDEO_H)/2;

    x &= ~3;					// Trunc to 4 pixel bound
    rect->width = (rect->width) & ~3;		// Round dn to 4 pixel boundary

    /* Sanity check */
    if ((x + rect->width > console->display.width)
    || (y + rect->height) > console->display.height)
	return( -1 );

    /* copyin is done in km */
    data = rect->data.bits;
    
    switch ( console->display.bitsPerPixel )
    {
	case IO_2BitsPerPixel:	/* 2 bit pixels */
	{
	    unsigned char *dst = (unsigned char *)console->display.frameBuffer
				 + x / 4 + y * console->display.rowBytes;
	    unsigned char *fb;
	    unsigned char final_value;
	    
	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx += 4) {
			value = *data++;
			final_value = 0;
			for ( i = 0; i < 8; i += 2 ) {
			    final_value |= ((table[(value>>i)&3] & 3) << i);
			}
			*fb++ = final_value;
		}
		dst += console->display.rowBytes;
	    }
	    break;
	}
	case IO_8BitsPerPixel:	/* 8 bit pixels */
	{
	    unsigned char *dst = (unsigned char *)console->display.frameBuffer
				 + x + y * console->display.rowBytes;
	    unsigned char *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx += 4) {
			value = *data++;
			*fb++ = table[(value >> 6) & 3];
			*fb++ = table[(value >> 4) & 3];
			*fb++ = table[(value >> 2) & 3];
			*fb++ = table[value & 3];
		}
		dst += console->display.rowBytes;
	    }	    	
	    break;
	}
	case IO_12BitsPerPixel:	/* 16 bit pixels */
	case IO_15BitsPerPixel:	/* 16 bit pixels */
	{
	    unsigned short *dst = (unsigned short *)
		((char *)((unsigned short *)console->display.frameBuffer + x)
		 + y * console->display.rowBytes);
	    unsigned short *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx += 4) {
			value = *data++;
			*fb++ = table[(value >> 6) & 3];
			*fb++ = table[(value >> 4) & 3];
			*fb++ = table[(value >> 2) & 3];
			*fb++ = table[value & 3];
		}
		dst = (unsigned short *)(((char*)dst) +
		    console->display.rowBytes);
	    }	    	
	    break;
	}
	case IO_24BitsPerPixel:	/* 32 bit pixels */
	{
	    unsigned int *dst = (unsigned int *)
		((char *)((unsigned int *)console->display.frameBuffer + x)
		 + y * console->display.rowBytes);
	    unsigned int *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx += 4) {
			value = *data++;
			*fb++ = table[(value >> 6) & 3];
			*fb++ = table[(value >> 4) & 3];
			*fb++ = table[(value >> 2) & 3];
			*fb++ = table[value & 3];
		}
		dst = (unsigned int *)(((char*)dst) +
		    console->display.rowBytes);
	    }	    	
	    break;
	}
    }
    return 0;
}
static int EraseRect(IOConsoleInfo *cso,  const struct km_drawrect *km_rect)
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    int x, y, xx, yy;
    unsigned int value;
    struct km_drawrect *rect = (struct km_drawrect *) km_rect;
    
    /* Correct the x and y values for screen size */
    x = rect->x + (console->display.width - VIDEO_W)/2;
    y = rect->y + (console->display.height - VIDEO_H)/2;

    x &= ~3;					// Trunc to 4 pixel boundary
    rect->width = (rect->width) & ~3;		// Round dn to 4 pixel boundary

    /* Sanity check */
    if ((x + rect->width > console->display.width)
    || (y + rect->height) > console->display.height)
	return( -1 );

    value = ColorTable(cso)[rect->data.fill & 3];

    switch ( console->display.bitsPerPixel )
    {
	case IO_2BitsPerPixel:
	{
	    unsigned char *dst = (unsigned char *)console->display.frameBuffer
				 + x / 4 + y * console->display.rowBytes;
	    unsigned char *fb;

	    value = (value << 2) | value | (value << 4) | (value << 6);
	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx += 4 )
		    *fb++ = value;
		dst += console->display.rowBytes;
	    }
	    break;
	}
	case IO_8BitsPerPixel:
	{
	    unsigned char *dst = (unsigned char *)console->display.frameBuffer
				 + x + y * console->display.rowBytes;
	    unsigned char *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx++ )
		    *fb++ = value;
		dst += console->display.rowBytes;
	    }
	    break;
	}
	case IO_12BitsPerPixel:
	case IO_15BitsPerPixel:
	{
	    unsigned short *dst = (unsigned short *)
		((char *)((unsigned short *)console->display.frameBuffer + x)
		 + y * console->display.rowBytes);
	    unsigned short *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx++ )
		    *fb++ = value;
		dst = (unsigned short *)((char *)dst + console->display.rowBytes);
	    }
	    break;
	}
	case IO_24BitsPerPixel:
	{
	    unsigned int *dst = (unsigned int *)
		((char *)((unsigned int *)console->display.frameBuffer + x)
		 + y * console->display.rowBytes);
	    unsigned int *fb;

	    for ( yy = 0; yy < rect->height; ++yy ) {
		fb = dst;
		for ( xx = 0; xx < rect->width; xx++ )
		    *fb++ = value;
		dst = (unsigned int *)((char *)dst + console->display.rowBytes);
	    }
	    break;
	}
    }
    return 0;
}

static void PutC(IOConsoleInfo *cso, char c)
// Write one character to screen. Cursor is 'on' on entry and exit.
{
    FBPutC((ConsolePtr)cso->priv, c);
}

static void GetSize(IOConsoleInfo *cso, struct ConsoleSize *s)
// Return the size of the screen in pixels
{
    ConsolePtr console = (ConsolePtr)cso->priv;
    s->cols = console->chars_per_row;
    s->rows = console->chars_per_column;
    s->pixel_width = console->display.width;
    s->pixel_height = console->display.height;
}

//
// END:		Implementation of IOConsoleInfo functions
//


//
// BEGIN:	Exported routines
//
IOConsoleInfo *FBAllocateConsole(IODisplayInfo *display)
{
    IOConsoleInfo *cso = (IOConsoleInfo *)IOMalloc(sizeof(IOConsoleInfo));
    
    if (cso == NIL)
        return NIL;
    cso->priv = (void *)IOMalloc(sizeof(ConsoleRep));
    if (cso->priv == NIL)
    {
        IOFree(cso, sizeof(IOConsoleInfo));
	return NIL;
    }
    cso->Free = Free;
    cso->Init = Init;
    cso->Restore = Restore;
    cso->DrawRect = DrawRect;
    cso->EraseRect = EraseRect;
    cso->PutC = PutC;
    cso->GetSize = GetSize;
    ((ConsolePtr)cso->priv)->display = *display;
    ((ConsolePtr)cso->priv)->window_type = SCM_UNINIT;
    return cso;
}

/*
 * plan 369: the VBE console (D024, written from the original bytes; no
 * reference text has these functions).  The boot loader leaves a VBE mode
 * description and the mapped frame buffer in its parameter block at
 * physical 0x11000 (no i386 kernBootStruct.h in any reference tree; local
 * definitions as D035): frame buffer at +0x1854 (0x12854), mode description
 * at +0x1858 (0x12858; width at 0x1285c).
 */
typedef struct {
	unsigned short	mode;			/* +0 */
	unsigned short	attributes;		/* +2 */
	unsigned short	width;			/* +4 */
	unsigned short	height;			/* +6 */
	unsigned short	rowBytes;		/* +8 */
	unsigned char	bitsPerPixel;		/* +10 */
	unsigned char	memoryModel;		/* +11 */
	unsigned char	redMaskSize;		/* +12 */
	unsigned char	redFieldPosition;	/* +13 */
	unsigned char	greenMaskSize;		/* +14 */
	unsigned char	greenFieldPosition;	/* +15 */
	unsigned char	blueMaskSize;		/* +16 */
	unsigned char	blueFieldPosition;	/* +17 */
	unsigned char	_reserved[2];		/* +18 */
	unsigned long	physBase;		/* +20 */
} VBEModeInfo;

typedef struct {
	char		_reserved0[0x1854];
	unsigned long	vbeFrameBuffer;		/* +0x1854 */
	VBEModeInfo	vbeModeInfo;		/* +0x1858 */
} KERNBOOTSTRUCT;
#define	KERNSTRUCT_ADDR	((KERNBOOTSTRUCT *) 0x11000)

void VBEModeInfo2IODisplayInfo(VBEModeInfo *vbe, IODisplayInfo *display);

IOConsoleInfo *FBAllocateVBEConsole(void)
{
    KERNBOOTSTRUCT *kernbootstruct = KERNSTRUCT_ADDR;
    IODisplayInfo display;

    if (kernbootstruct->vbeModeInfo.width == 0 ||
        kernbootstruct->vbeFrameBuffer == 0)
	return NIL;
    VBEModeInfo2IODisplayInfo(&kernbootstruct->vbeModeInfo, &display);
    display.frameBuffer = (void *)kernbootstruct->vbeFrameBuffer;
    return FBAllocateConsole(&display);
}

void VBEModeInfo2IODisplayInfo(VBEModeInfo *vbe, IODisplayInfo *display)
{
    int i, n;

    display->width = vbe->width;
    display->height = vbe->height;
    display->totalWidth = vbe->width;
    display->rowBytes = vbe->rowBytes;
    display->refreshRate = 0;
    display->frameBuffer = (void *)vbe->physBase;
    switch (vbe->bitsPerPixel) {
	case 2:
	    display->bitsPerPixel = IO_2BitsPerPixel;
	    break;
	case 8:
	    display->bitsPerPixel = IO_8BitsPerPixel;
	    break;
	case 12:
	    display->bitsPerPixel = IO_12BitsPerPixel;
	    break;
	case 15:
	case 16:
	    display->bitsPerPixel = IO_15BitsPerPixel;
	    break;
	case 24:
	case 32:
	    display->bitsPerPixel = IO_24BitsPerPixel;
	    break;
	default:
	    display->modeUnavailableFlag |= IO_DISPLAY_MODE_OTHER_INVALID;
	    return;
    }
    if (vbe->attributes & 8) {
	display->colorSpace = IO_RGBColorSpace;
	if (vbe->memoryModel == 4) {
	    for (i = 0; i < vbe->bitsPerPixel; i++)
		display->pixelEncoding[i] = 'P';
	} else {
	    for (i = 0; i < vbe->bitsPerPixel; i++)
		display->pixelEncoding[i] = '-';
	    n = vbe->bitsPerPixel - vbe->redFieldPosition - 1;
	    for (i = 0; i < vbe->redMaskSize; i++)
		display->pixelEncoding[n - i] = 'R';
	    n = vbe->bitsPerPixel - vbe->greenFieldPosition - 1;
	    for (i = 0; i < vbe->greenMaskSize; i++)
		display->pixelEncoding[n - i] = 'G';
	    n = vbe->bitsPerPixel - vbe->blueFieldPosition - 1;
	    for (i = 0; i < vbe->blueMaskSize; i++)
		display->pixelEncoding[n - i] = 'B';
	}
    } else {
	display->colorSpace = IO_OneIsWhiteColorSpace;
	for (i = 0; i < vbe->bitsPerPixel; i++)
	    display->pixelEncoding[i] = 'W';
    }
    display->flags = IO_DISPLAY_NEEDS_SOFTWARE_GAMMA_CORRECTION;
    display->parameters = (void *)vbe->mode;
    display->memorySize = vbe->height * vbe->rowBytes;
}
//
// END:		Exported routines
//
