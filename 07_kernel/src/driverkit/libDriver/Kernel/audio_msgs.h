/*
 * libDriver/Kernel/audio_msgs.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_msgs.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>
#import <mach/message.h>

#define AUDIO_SERVER_NAME "audio0"

#define AUDIO_MSG_GET_PORTS	0
#define	AUDIO_MSG_RET_PORTS	1

typedef struct {
    msg_header_t	header;
    msg_type_t		privType;
    port_t		priv;
    msg_type_t		resetType;
    boolean_t		reset;
} audio_get_ports_t;

typedef struct {
    msg_header_t	header;
    msg_type_t		portsType;
    port_t		inputPort;
    port_t		outputPort;
    port_t		sndPort;
} audio_ret_ports_t;
