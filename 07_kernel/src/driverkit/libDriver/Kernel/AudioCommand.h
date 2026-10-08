/*
 * libDriver/Kernel/AudioCommand.h - kernel-private header (plan 342, D030).
 *
 * Needed by the libDriver audio modules (Kernel/*.m), whose objects
 * match the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/AudioCommand.h; kept as project-authored under D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <mach/mach_types.h>
#import <mach/message.h>

//#import "audio_types.h"		

/*
 * Valid DriverCommand commands
 */
typedef enum {
    setDeviceInputGainLeft,
    setDeviceInputGainRight,
    setDeviceOutputMute,
    setDeviceOutputAttenuationLeft,
    setDeviceOutputAttenuationRight,
    setDeviceLoudness,
    abortInputChannel,
    abortOutputChannel,
    
    setDeviceInputMicEnable,
    setDeviceInputMicDisable,
    setDeviceInputLineEnable,
    setDeviceInputLineDisable,
    setDeviceInputCDEnable,
    setDeviceInputCDDisable,
    setDeviceInputAux1Enable,
    setDeviceInputAux1Disable,
    setDeviceInputAux2Enable,
    setDeviceInputAux2Disable,
    
    setDeviceOutputLineEnable,
    setDeviceOutputLineDisable,
    setDeviceOutputSpeakerEnable,
    setDeviceOutputSpeakerDisable,
    setDeviceOutputCDEnable,
    setDeviceOutputCDDisable,
    setDeviceOutputAux1Enable,
    setDeviceOutputAux1Disable,
    setDeviceOutputAux2Enable,
    setDeviceOutputAux2Disable,
    
} ADCommand;

#import <machkit/NXLock.h>
#import <driverkit/generalFuncs.h>

@interface AudioCommand:Object
{
    port_t	driverPort_kern;
    id		interLock;
#define AUDIO_COMMAND_DONE		1
#define AUDIO_COMMAND_BUSY		2
#define AUDIO_COMMAND_IDLE		3
    ADCommand	command;
    int		ret;
}


- initPort:(port_t)port;
- free;
- (ADCommand)command;
- (void)done:(int)_ret;
- (int)send:(ADCommand)_command;

@end

