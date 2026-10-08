/*
 * SCSIDisk.m (plan 314).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/SCSIDisk.m", methods 0x1ac3d8-0x1acbc8).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/SCSIDisk.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define MACH_USER_API	1
#undef	KERNEL_PRIVATE

#import <bsd/sys/types.h>
#import <driverkit/return.h>
#import <driverkit/IODisk.h>
#import <driverkit/SCSIDiskPrivate.h>
#import <driverkit/SCSIDiskTypes.h>
#import <driverkit/SCSIDisk.h>	
#import <driverkit/SCSIDiskKern.h>
#import <driverkit/SCSIStructInlines.h>
#import <bsd/dev/scsireg.h>	
#import <driverkit/xpr_mi.h>
#import <kernserv/prototypes.h>
#import <mach/mach_interface.h>
#import <driverkit/kernelDiskMethods.h>
#import <machkit/NXLock.h>

#ifdef	DEBUG
#define SCSI_SA_TEST	0
#else	DEBUG
#define SCSI_SA_TEST	0
#endif	DEBUG

/*
 * FIXME - ensure that diskUnit doesn't exceed NUM_SD_DEV.
 */
static int diskUnit = 0;

@implementation SCSIDisk

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


+ initialize
{
	if(self == [SCSIDisk class]) {
		sd_init_idmap();
	}
	return [super initialize];
}  

/*
 * probe is invoked at load time. It determines what devices are on the
 * bus and alloc's and init:'s an instance of this class for each one.
 */
+ (BOOL)probe : deviceDescription;
{
	char Target, Lun;
	sdInitReturn_t irtn = SDR_ERROR;
	SCSIDisk *diskId = nil;
	IODevAndIdInfo *idMap = sd_idmap();
	id controllerId = [deviceDescription directDevice];
	BOOL brtn = NO;
	SCSIDisk *diskIdArray[SCSI_NLUNS];
	int nLuns;
	/* plan 314: no Radar 2005639 thread-count query in the original */
	
/* asm volatile("int3");  */

#if hppa
	/* search from the top down on hp since that was done before */
	for(Target=[controllerId numberOfTargets]-1; Target>=0; Target--)
#else
	for(Target=0; Target<[controllerId numberOfTargets]; Target++)
#endif
	{

		/* plan 314: all LUNs, as in the original (no Radar Fix #2260508) */
		for(Lun=nLuns=0; Lun<SCSI_NLUNS; Lun++) {
			if(diskId == nil) {
				/*
				 * Create an instance, do some basic 
				 * initialization. Set up a default 
				 * device name for error reporting during
				 * initialization.
				 */
				diskId = [SCSIDisk alloc];
				[diskId setName:"SCSIDisk"];
				[diskId initResources];	/* plan 314 */
				[diskId setDevAndIdInfo:&(idMap[diskUnit])];
			}
			if([controllerId reserveTarget:Target
			    lun:Lun
			    forOwner:diskId]) {
			 	/*
				 * Someone already has this one.
				 */
				continue;   
			}
			/* plan 314: _isReserved is set when registering (below), as in the original */
			/* plan 314: no Radar Fix #2260508 (non-zero LUN reservation) in the original */
			irtn = [diskId SCSIDiskInit:(int)diskUnit
				targetId:Target
				lun:Lun
				controller:controllerId];
			/* plan 314: no setDeviceDescription: here in the original */
			switch(irtn) {
			    case SDR_GOOD:
				/*
				 * Postpone registering this device
				 * until we have looked at all other LUNs.
				 * This prevents I/O to multiple LUNs
				 * while we are probing, which is not handled
				 * well by some devices.
				 */
				diskIdArray[nLuns++] = diskId;
				diskUnit++;
				diskId = nil;
				brtn = YES;
				break;				
				
			    default:
			/* plan 314: no Radar Fix #2260508 (non-zero LUN reservation) in the original */
			        [controllerId releaseTarget:Target
			    		lun:Lun
			    		forOwner:diskId];
				/* plan 314: _isReserved is not cleared here in the original */

				if(irtn == SDR_SELECTTO) {
					/*
					 * Skip the rest of the luns on 
					 * this target.
					 */
					goto nextTarget;
				}
				/* 
				 * else try next lun.
				 */
			}
		}	/* for lun */
nextTarget:
		/* Now we have looked at all luns. */
		for (Lun=0; Lun < nLuns; Lun++) {
			SCSIDisk *thisId = diskIdArray[Lun];
			thisId->_isReserved = 1;	/* plan 314 */
			/*
			 * All right! Have IODisk superclass take 
			 * care of the rest.
			 */
			[thisId setDeviceKind:"SCSIDisk"];
			[thisId setIsPhysical:YES];
			[thisId registerDevice];
			thisId->_isRegistered = 1;
		}
		continue;
	}		/* for target */
	
	/*
	 * Free up leftover owner and id. At this point, diskId does NOT have
	 * a target/lun reserved.
	 */
	if(diskId) {
		[diskId free];
	}
	
#if	SCSI_SA_TEST
	diskTest("sd0");
#endif	SCSI_SA_TEST
	return brtn;
}

/*
 * IODiskReadingAndWriting protocol methods.
 */ 
- (IOReturn) readAt		: (unsigned)offset 
				  length : (unsigned)length 
				  buffer : (unsigned char *)buffer
				  actualLength : (unsigned *)actualLength 
				  client : (vm_task_t)client
{
	IOReturn rtn;
	
	xpr_sd("%s read: offset 0x%x length 0x%x\n",
		[self name], offset, length, 4,5);
	rtn = [self deviceRwCommon : SDOP_READ
		  block : offset
		  length : length 
		  buffer : buffer
		  client: client
		  pending : NULL
		  actualLength : actualLength];
	xpr_sd("%s read: RETURNING %s\n", [self name],
		[self stringFromReturn:rtn], 3,4,5);
	return(rtn);
}

- (IOReturn) readAsyncAt	: (unsigned)offset 
				  length : (unsigned)length 
				  buffer : (unsigned char *)buffer
				  pending : (void *)pending
				  client : (vm_task_t)client
{
	IOReturn rtn;
	
	xpr_sd("%s readAsync: offset 0x%x length 0x%x\n",
		[self name], offset, length, 4,5);
	rtn = [self deviceRwCommon : SDOP_READ
		  block : offset
		  length : length 
		  buffer : buffer
		  client : client
		  pending : (void *)pending
		  actualLength : NULL];
	xpr_sd("%s readAsync: RETURNING %s\n", [self name],
		[self stringFromReturn:rtn], 3,4,5);
	return(rtn);
}	

- (IOReturn) writeAt		: (unsigned)offset 
				  length : (unsigned)length 
				  buffer : (unsigned char *)buffer
				  actualLength : (unsigned *)actualLength 
				  client : (vm_task_t)client
{
	IOReturn rtn;
	
	xpr_sd("%s write: offset 0x%x length 0x%x\n",
		[self name], offset, length, 4,5);
	rtn = [self deviceRwCommon : SDOP_WRITE
		  block : offset
		  length : length 
		  buffer : buffer
		  client: client
		  pending : NULL
		  actualLength : actualLength];
	xpr_sd("%s deviceWrite: RETURNING %s\n", [self name],
		[self stringFromReturn:rtn], 3,4,5);
	return(rtn);
}				  	

- (IOReturn) writeAsyncAt	: (unsigned)offset 
				  length : (unsigned)length 
				  buffer : (unsigned char *)buffer
				  pending : (void *)pending
				  client : (vm_task_t)client
{
	IOReturn rtn;
	
	xpr_sd("%s writeAsync: offset 0x%x length 0x%x\n",
		[self name], offset, length, 4,5);
	rtn = [self deviceRwCommon : SDOP_WRITE
		  block : offset
		  length : length 
		  buffer : buffer
		  client : client
		  pending : (void *)pending
		  actualLength : NULL];
	xpr_sd("%s writeAsync: RETURNING %s\n", [self name],
		[self stringFromReturn:rtn], 3,4,5);
	return(rtn);
}


/* plan 314: no synchronizeCache (not in the original) */

- (IODiskReadyState)updateReadyState
{
	IOSCSIRequest scsiReq;
	cdb_6_t *cdbp = &scsiReq.cdb.cdb_c6;
	sdBuf_t *sdBuf;
	IODiskReadyState readyState;
	esense_reply_t senseReply;
	
	xpr_sd("%s updateReadyState\n", [self name], 2,3,4,5);
	/* plan 314: no _isReserved check here in the original */

	bzero(&scsiReq, sizeof(IOSCSIRequest));
	scsiReq.target = _target;
	scsiReq.lun = _lun;
	scsiReq.timeoutLength = SD_TIMEOUT_SIMPLE;
	scsiReq.disconnect = 1;
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_WRITE;
	sdBuf->scsiReq = &scsiReq;
	sdBuf->retryDisable = 1;
	sdBuf->needsDisk = 0;
	
	cdbp->c6_opcode = C6OP_TESTRDY;
	cdbp->c6_lun = _lun;
	
	[self enqueueSdBuf:sdBuf];

	/*
	 * FIXME - how to distinguish not ready from no disk???
	 */
	switch(scsiReq.driverStatus) {
	    case SR_IOST_GOOD:
	    	readyState = IO_Ready;
		break;
	    default:
	    	readyState = IO_NotReady;
		break;
		
	}
	xpr_sd("%s updateReadyState: DONE; state = %s\n", 
		[self name], 
		IOFindNameForValue(readyState, readyStateValues), 3,4,5);
	[self freeSdBuf:sdBuf];
	return(readyState);
}

/*
 * IOPhysicalDiskMethods protocol methods.
 */
- (IOReturn) ejectPhysical
{
	return [self scsiStartStop:SS_EJECT inhibitRetry:NO];
}


/*
 * Get physical parameters (dev_size, block_size, etc.) from new disk.
 */
- (IOReturn)updatePhysicalParameters
{
	capacity_reply_t capacityData;
	mode_sel_data_t	 modeData;
	sc_status_t rtn;
	int block;
	void *dataBuf;
	void *freePtr;
	unsigned freeCnt;
	u_int block_size;
	BOOL wp = NO;
	int i;
	
	rtn = [self updateReadyState];
	if(rtn) {
		return IO_R_NOT_READY;
	}
	rtn = [self sdReadCapacity:&capacityData];
	if(rtn) {
		return(IO_R_IO);
	}
	[self setDiskSize:scsi_lastlba(&capacityData) + 1];
	[self setBlockSize:scsi_blklen(&capacityData)];
	
	/*
	 * Try reading a block to see if disk is formatted.
	 */
	block_size = [self blockSize];
	dataBuf = [_controller allocateBufferOfLength:block_size
			actualStart:&freePtr
			actualLength:&freeCnt];
	block = 10;
	for(i=0; i<5; i++) {
		rtn = [self sdRawRead:block blockCnt:1 buffer:dataBuf];
		if(rtn == IO_R_SUCCESS) {
			break;
		}
		block += 10;
	}
	if(rtn == IO_R_SUCCESS) 
		[self setFormattedInternal:1];
	else
		[self setFormattedInternal:0];

	IOFree(freePtr, freeCnt);
	
	/*
	 * Mark CD-ROMs as write-protected; use a mode sense for the others.
	 */

	if(_inquiryDeviceType == DEVTYPE_CDROM)
		wp = YES;
	else {
		bzero(&modeData, sizeof(mode_sel_data_t));
		rtn = [self sdModeSense:&modeData];

		if (modeData.msd_header.msh_wp)
			wp = YES;
	}

	[self setWriteProtected: wp];

	return(IO_R_SUCCESS);
}

/*
 * Called by volCheck thread when WS has told us that a requested disk is
 * not present. Pending I/Os which require a disk to be present must be 
 * aborted.
 */
- (void)abortRequest
{
	sdBuf_t *sdBuf;
	
	xpr_sd("%s: abortRequest\n", [self name], 2,3,4,5);
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_ABORT;
	sdBuf->needsDisk = 0;
	[self enqueueSdBuf:sdBuf];
	xpr_sd("%s abortRequest: done %s\n", [self name], 2,3,4,5);
	[self freeSdBuf:sdBuf];
	return;
}

/*
 * Called by the volCheck thread when a transition to "ready" is detected.
 * Pending I/Os which require a disk may proceed. All we have to do is 
 * wakeup the I/O threads which are waiting for something to show up 
 * in an I/O queue.
 */
- (void)diskBecameReady
{
	xpr_sd("diskBecameReady: %s\n", [self name], 2,3,4,5);
	[_ioQLock lock];
	[_ioQLock unlockWith:WORK_AVAILABLE];
}

/*
 * Inquire if disk is present; if not, and 'prompt' is YES, ask for it. 
 * Returns IO_R_NO_DISK if:
 *    prompt YES, disk not present, and user cancels request for disk.
 *    prompt NO, disk not present.
 * Else returns IO_R_SUCCESS.
 */
- (IOReturn)isDiskReady	: (BOOL)prompt
{
	sdBuf_t *sdBuf;
	IOReturn rtn;
	
	xpr_sd("%s: diskBecameReady\n", [self name], 2,3,4,5);

	/* plan 314: no _isReserved check here in the original */

	if([self lastReadyState] == IO_Ready) {
		/*
		 * This one's easy...
		 */
		return(IO_R_SUCCESS);
	}
	if(!prompt) {
		return(IO_R_NO_DISK);
	}
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_PROBEDISK;
	sdBuf->needsDisk = 1;
	rtn = [self enqueueSdBuf:sdBuf];
	xpr_sd("%s diskBecameReady: returning %s\n", [self name], 
		[self stringFromReturn:rtn], 3,4,5);
	[self freeSdBuf:sdBuf];
	return(rtn);
}	

/*
 * We have to override IODisk's setLastReadyState: so we know when to 
 * clear our local ejectPending flag.
 */
 - (void)setLastReadyState : (IODiskReadyState)readyState
 {
 	xpr_sd("sd setLastReadyState\n", 1,2,3,4,5);
 	if(_ejectPending && (readyState != IO_Ejecting))
		_ejectPending = 0;
	[super setLastReadyState:readyState];
 }

/*
 * Exported methods unique to the SCSIDisk class.
 * Note caller must provide well-aligned DMA buffers.
 */
- (IOReturn) sdCdbRead 		: (IOSCSIRequest *)scsiReq	 /* SCSI parameters */
			  	   buffer:(void *)buffer /* data destination */
				   client:(vm_task_t)client;
{
	sdBuf_t *sdBuf;
	IOReturn rtn;
	
	xpr_sd("sd%d sdCdbRead: opcode = 0x%x\n", [self unit],
		scsiReq->cdb.cdb_opcode, 3,4,5);
		
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_READ;
	sdBuf->scsiReq = scsiReq;
	sdBuf->buf = buffer;
	sdBuf->client = client;
	sdBuf->pending = NULL;
	sdBuf->needsDisk = 0;
	rtn = [self enqueueSdBuf:sdBuf];
	xpr_sd("sd%d sdCdbRead: returning %s\n", [self unit],
		[self stringFromReturn:rtn], 3,4,5);
	[self freeSdBuf:sdBuf];
	return(rtn);
}

- (IOReturn) sdCdbWrite		: (IOSCSIRequest *)scsiReq	 /* SCSI parameters */
			  	   buffer:(void *)buffer /* data destination */
				   client:(vm_task_t)client
{
	sdBuf_t *sdBuf;
	IOReturn rtn;
	
	xpr_sd("sd%d sdCdbWrite: opcode = 0x%x\n", [self unit],
		scsiReq->cdb.cdb_opcode, 3,4,5);
		
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_WRITE;
	sdBuf->scsiReq = scsiReq;
	sdBuf->buf = buffer;
	sdBuf->client = client;
	sdBuf->pending = NULL;
	sdBuf->needsDisk = 0;
	rtn = [self enqueueSdBuf:sdBuf];
	xpr_sd("sd%d sdCdbWrite: returning %s\n", [self unit],
		[self stringFromReturn:rtn], 3,4,5);
	[self freeSdBuf:sdBuf];
	return(rtn);	
}

- (int)target
{
	return _target;
}

- (int)lun
{
	return _lun;
}

/*
 * This is mainly here for the convenience of 486 CDROM boot. It's cheap so
 * we'll leave it in for other platforms too.
 */
- (unsigned char)inquiryDeviceType
{	
	return _inquiryDeviceType;
}

- controller
{
	return _controller;
}

/* plan 314: no getDevicePath:maxLength:useAlias:, matchDevicePath:, property_IOUnit:length: or property_IODeviceType:length: (not in the original) */

@end
