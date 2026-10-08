/*
 * bsd/dev/i386/kbd_entries.m (plan 363).
 *
 * Keyboard entry registration (keyboard_reboot, StealKeyEvent,
 * steal_keyboard_event, register_keyboard_entries) of the OPENSTEP 4.2
 * kernel, text 0x1a0d90-0x1a0e46, data 0x1e4b78-0x1e4b80.  The text is
 * nearly the same as Darwin 0.1 kernel/bsd/dev/i386/kbd_entries.m (body
 * verbatim, head comment replaced); kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import "kbd_entries.h"

static struct keyboard_entries function_list = {
    NULL,
    NULL
};

/*
 * Brute force reboot.
 */
 
#define K_STATUS 	0x64		// keybd status (read-only)
#define K_IBUF_FUL 	0x02		// input (to keybd) buffer full
#define K_CMD	 	0x64		// keybd ctlr command (write-only)
#define	KC_REBOOT	0xfe		// cause a reboot to occur

static void kdreboot(void)
// Description:	Sends a "magic" sequence to the keyboard controller
//		which causes it to send a signal back to the system which
//		causes the system to reboot.
{
    // Wait for room in the buffer
    while (inb(K_STATUS) & K_IBUF_FUL)
	continue;
    outb(K_CMD, KC_REBOOT);	// Send the command
    return;
}

void keyboard_reboot()
{
    if (function_list.keyboard_reboot)
	function_list.keyboard_reboot();
    kdreboot();
    return;
}

PCKeyboardEvent *StealKeyEvent()
{
    /*
     * Fill up a little code space here so that
     * the old keyboard driver has enough room to patch this function.
     */
    volatile int i;
    i = 1; i = 2; i = 3; i = 4; i = 5;
    
    return NULL;
}

PCKeyboardEvent *steal_keyboard_event()
{
    PCKeyboardEvent *event = NULL;
    if ((event = StealKeyEvent()) == NULL) {
	if (function_list.steal_keyboard_event)
	    event = (PCKeyboardEvent *)function_list.steal_keyboard_event();
    }
    return event;
}

void register_keyboard_entries(struct keyboard_entries *list)
{
    function_list = *list;
}

