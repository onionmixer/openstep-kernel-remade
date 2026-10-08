/*
 * SCSIGeneric.m (plan 307).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/SCSIGeneric.m", 0x1ae7c8-0x1af057).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/SCSIGeneric.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#import <driverkit/SCSIGeneric.h>
#import <driverkit/SCSIGenericPrivate.h>
#import <driverkit/scsiTypes.h>
#import <driverkit/return.h>
#import <driverkit/generalFuncs.h>
#import <driverkit/kernelDriver.h>
#import <machkit/NXLock.h>
#import <driverkit/xpr_mi.h>
#import <driverkit/align.h>

/*
 * Private method declarations.
 */
@interface SCSIGeneric(Private)

- (sc_status_t)getSense		: (esense_reply_t *)sense;
- (void)clearReservation;

@end

/* 
 * Public method implementation.
 */
@implementation SCSIGeneric

+ (IODeviceStyle)deviceStyle
{
	return IO_IndirectDevice;
}

/*
 * The protocol we need as an indirect device.
 */
static Protocol *protocols[] = {
	@protocol(IOSCSIControllerExported),
	nil
};

+ (Protocol **)requiredProtocols
{
	return protocols;
}



/* plan 307: Darwin's - registerLoudly (return nil) is not in the original method list */

+ (BOOL)probe : deviceDescription
{
	id sgId;
	int i;
	id controller = [deviceDescription directDevice];
	
        /*
         * We only bother attaching to controller 0 at probe time. 
         * Clients can specify other controllers later via
         * -setController:.
         */
        if([controller unit] != 0) {
                return NO;
        }
	for(i=0; i<NUM_SG_DEV; i++) {
		sgId = [self alloc];
		sgIdMap[i] = sgId;
		[sgId sgInit:i controller:controller];
	}
	return YES;
}

/*
 * One-time only init. Returns non-zero on error.
 */
- (int)sgInit : (unsigned)unitNum 
		controller : controller
{
	char name[20];
	
	_controller    = controller;
        _controllerNum = 0;
	_autoSense     = 0;
	_isReserved    = 0;
	_targLunValid  = 0;
	_openLock      = [NXLock new];
	_owner         = nil;
	sprintf(name, "sg%d", unitNum);
	[self setName:name];
	[self setDeviceKind:"SCSIGeneric"];
	[self setLocation:[controller name]];
	[self setUnit:unitNum];
	[self registerDevice];
	return 0;
}

- (unsigned char)target
{
	return (unsigned char)_target;
}

- (unsigned char)lun
{
	return (unsigned char)_lun;
}

- (unsigned long long)SCSI3_target
{
	return _target;
}

- (unsigned long long)SCSI3_lun
{
	return _lun;
}

/*
 * Acquire and release, to allow exclusive access to this device.
 * 
 * -acquire returns non-zero if device in use, else reserves device for
 * exclusive use by 'caller'.
 * -release returns non-zero if device not currently in use by 'caller'.
 */
- (int)acquire : caller
{
	int rtn;
	
	xpr_sdev("SCSIGeneric acquire\n", 1,2,3,4,5);
	[_openLock lock];
	if(_owner) {
		rtn = 1;
	}
	else {
		_autoSense = 0;
		_owner = caller;
		rtn = 0;
	}
	[_openLock unlock];
	return rtn;
}

- (int)release : caller
{
	int rtn;
	
	xpr_sdev("SCSIGeneric release\n", 1,2,3,4,5);
	[_openLock lock];
	if(caller != _owner) {
		IOLog("%s: bogus close call\n", [self name]);
		rtn = 1;
	}
	else {
		/*
		 * Clear possible pending reservation.
		 */
		[self clearReservation];
		_owner = nil;
	}
	[_openLock unlock];
}

/* 
 * ioctl equivalents.
 */
 
/*
 * Set target and lun. If isRoot is true, this will succeed even if specified
 * target/lun are currently reserved. otherwise, returns IO_R_BUSY if 
 * desired target/lun already reserved.
 */
- (IOReturn)setTarget		: (unsigned char)target
				  lun:(unsigned char)lun
				  isRoot:(BOOL)isRoot
{
	xpr_sdev("SCSIGeneric setTarget t %d l %d\n", target, lun, 3,4,5);
	if((target >= [_controller numberOfTargets]) || (lun > SCSI_NLUNS)) {
	 	return IO_R_INVALID_ARG;  
	}
	
	[self clearReservation];
	if([_controller reserveSCSI3Target:(unsigned long long)target 
			lun:(unsigned long long)lun
			forOwner:self]) {
		if(!isRoot) {
			return IO_R_BUSY;
		}		
		/*
		 * else: playing dangerously, but we'll do it...
		 */
	}
	else {
		_isReserved = 1;
	}
	_target = target;
	_lun = lun;
	_targLunValid = 1;
	return IO_R_SUCCESS;
}

- (IOReturn)setSCSI3Target	: (unsigned long long)target
				  lun:(unsigned long long)lun
				  isRoot:(BOOL)isRoot
{
	xpr_sdev("setSCSI3Target: t %x:%x l %x:%x\n",
		(unsigned)(target >> 32),
		(unsigned)target,
		(unsigned)(lun >> 32),
		(unsigned)lun, 5);
	if((target >= [_controller numberOfTargets]) || (lun > SCSI_NLUNS)) {
	 	return IO_R_INVALID_ARG;  
	}

	[self clearReservation];
	if([_controller reserveSCSI3Target:target 
			lun:lun
			forOwner:self]) {
		if(!isRoot) {
			return IO_R_BUSY;
		}		
		/*
		 * else: playing dangerously, but we'll do it...
		 */
	}
	else {
		_isReserved = 1;
	}
	_target = target;
	_lun = lun;
	_targLunValid = 1;
	return IO_R_SUCCESS;
}


/*
 * Select controller number. Clears pending reservation if controllerNum
 * is changing.
 */
- (IOReturn)setController : (unsigned)controllerNum
{
	char contrStr[10];
	IOReturn drtn;
	id newController;

	if(controllerNum == _controllerNum) {
		return IO_R_SUCCESS;
	}
	[self clearReservation];

	/* 
	 * Look up new controller.
	 */
	sprintf(contrStr, "sc%d", controllerNum);
	drtn = IOGetObjectForDeviceName(contrStr, &newController);
	if(drtn) {
		return IO_R_NO_DEVICE;
	}
	_controllerNum = controllerNum;
	_controller = newController;
	_targLunValid = 0;
	return IO_R_SUCCESS;
}

/*
 * Enable/disable 'autosense' mechanism.
 */
- (IOReturn)enableAutoSense
{
	_autoSense = 1;
	return IO_R_SUCCESS;
}

- (IOReturn)disableAutoSense
{
	_autoSense = 0;
	return IO_R_SUCCESS;
}

- (int)autoSense
{
	return _autoSense;
}


/*
 * Execute CDB. Buffer must be well aligned. 
 * *sense will contain sense data if autoSense is enabled and command 
 * resulted in Check status.
 */
- (sc_status_t)executeRequest	: (IOSCSIRequest *)scsiReq
			  	   buffer:(void *)buffer /* data destination */
				   client:(vm_task_t)client
				   senseBuf:(esense_reply_t *)senseBuf
{
	sc_status_t rtn;

	xpr_sdev("sg executeRequest; op %s\n", 
		IOFindNameForValue(scsiReq->cdb.cdb_opcode, 
			IOSCSIOpcodeStrings),2,3,4,5);
	if(!_targLunValid ||
	   ((unsigned long long)scsiReq->target != _target) || 
	   ((unsigned long long)scsiReq->lun != _lun)) {
		rtn = SR_IOST_CMDREJ;
		goto out;
	}
	rtn = [_controller executeRequest:scsiReq
		buffer:buffer
		client:client];
	
	/*
	 * The only thing we deal with is Check Status, for which we'll do
	 * a Request Sense if autoSense is enabled.
	 */
	if(rtn == SR_IOST_CHKSV) {
		/*
		 * Host adaptor already got us sense data.
		 */
		*senseBuf = scsiReq->senseData;
	}
	else if((rtn == SR_IOST_CHKSNV) && _autoSense) {
		rtn = [self getSense:senseBuf];
		if(rtn == SR_IOST_GOOD) {
			rtn = SR_IOST_CHKSV;
		}
		else {
			IOLog("%s: Request Sense on target %d lun %d "
				"failed (%s)\n",
				[self name], (unsigned)_target, (unsigned)_lun, 
				IOFindNameForValue(rtn, IOScStatusStrings));
			rtn = SR_IOST_CHKSNV;
		}
	}
out:
	xpr_sdev("sg executeRequest: returning %s\n", 
		IOFindNameForValue(rtn, IOScStatusStrings), 2,3,4,5);
	return rtn;
}				   
	
/*
 * Execute CDB, SCSI-3 style. Buffer must be well aligned. 
 * *sense will contain sense data if autoSense is enabled and command 
 * resulted in Check status.
 */
- (sc_status_t)executeSCSI3Request : (IOSCSI3Request *)scsiReq
			    buffer : (void *)buffer /* data destination */
			    client : (vm_task_t)client
			  senseBuf : (esense_reply_t *)senseBuf
{
	sc_status_t rtn;

	xpr_sdev("sg executeSCSI3Request; op %s\n", 
		IOFindNameForValue(scsiReq->cdb.cdb_opcode, 
			IOSCSIOpcodeStrings),2,3,4,5);
	if(!_targLunValid ||
	   (scsiReq->target != _target) || 
	   (scsiReq->lun != _lun)) {
		rtn = SR_IOST_CMDREJ;
		goto out;
	}
	rtn = [_controller executeSCSI3Request:scsiReq
		buffer:buffer
		client:client];
	
	/*
	 * The only thing we deal with is Check Status, for which we'll do
	 * a Request Sense if autoSense is enabled.
	 */
	if(rtn == SR_IOST_CHKSV) {
		/*
		 * Host adaptor already got us sense data.
		 */
		*senseBuf = scsiReq->senseData;
	}
	else if((rtn == SR_IOST_CHKSNV) && _autoSense) {
		rtn = [self getSense:senseBuf];
		if(rtn == SR_IOST_GOOD) {
			rtn = SR_IOST_CHKSV;
		}
		else {
			IOLog("%s: Request Sense on target %d lun %d "
				"failed (%s)\n",
				[self name], (unsigned)_target, (unsigned)_lun, 
				IOFindNameForValue(rtn, IOScStatusStrings));
			rtn = SR_IOST_CHKSNV;
		}
	}
out:
	xpr_sdev("sg executeSCSI3Request: returning %s\n", 
		IOFindNameForValue(rtn, IOScStatusStrings), 2,3,4,5);
	return rtn;
}				   
			  
/*
 * Reset SCSI bus. We can't authorize this; caller should ensure that 
 * client is root!
 */
- (sc_status_t) resetSCSIBus;
{
	return [_controller resetSCSIBus];
}

- controller
{
	return _controller;
}

@end /* of SCSIGeneric */

/*
 * Private methods.
 */
@implementation SCSIGeneric(Private)

/*
 * Get sense data from current target and lun. senseBuf does not have
 * to be well aligned.
 */
- (sc_status_t)getSense		: (esense_reply_t *)senseBuf
{
	IOSCSIRequest 	scsiReq;
	cdb_6_t 	*cdbp = &scsiReq.cdb.cdb_c6;
	esense_reply_t 	*alignedBuf;
	void 		*freePtr;
	int 		freeCnt;
	sc_status_t 	rtn;
	IODMAAlignment	dmaAlign;
	
	alignedBuf = [_controller allocateBufferOfLength:
					sizeof(esense_reply_t)
			actualStart:&freePtr
			actualLength:&freeCnt];
	bzero(&scsiReq, sizeof(IOSCSIRequest));
	[_controller getDMAAlignment:&dmaAlign];
	
	scsiReq.target 		= _target;
	scsiReq.lun 		= _lun;
	scsiReq.read		= YES;
	if(dmaAlign.readLength > 1) {
		scsiReq.maxTransfer = IOAlign(int, sizeof(esense_reply_t), 
					    dmaAlign.readLength);
	} else {
		scsiReq.maxTransfer = sizeof(esense_reply_t);
	}
	scsiReq.timeoutLength 	= 10;
	scsiReq.disconnect 	= 0;
	cdbp->c6_opcode 	= C6OP_REQSENSE;
	cdbp->c6_lun 		= _lun;
	cdbp->c6_len 		= sizeof(esense_reply_t);
	
	rtn = [_controller executeRequest:&scsiReq
		buffer:alignedBuf
		client:IOVmTaskSelf()];
	if(rtn == SR_IOST_GOOD) {
		*senseBuf = *alignedBuf;
	}
	IOFree(freePtr, freeCnt);
	return rtn;
}

/*
 * Clear possible pending reservation, whichever style was last used.
 */
- (void)clearReservation
{
	if(_isReserved) {
		if(_targLunValid) {
			[_controller releaseSCSI3Target:_target 
				lun:_lun
				forOwner:self];
			_targLunValid = 0;
		}
		else {
			IOLog("%s: clearReservation, no valid target\n", 
				[self name]);
		}
		_isReserved = 0;
	}
	
	/*
	 * Note _targLunValid could have been true on entry even if 
	 * _isReserved was false - that's the case where root set a target
	 * and LUN which was already reserved.
	 */
	_targLunValid = 0;
}


@end /* of SCSIGeneric(Private) */


