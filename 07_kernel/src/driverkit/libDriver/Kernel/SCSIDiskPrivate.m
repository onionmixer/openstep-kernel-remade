/*
 * SCSIDiskPrivate.m (plan 312).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/SCSIDiskPrivate.m", methods 0x1acbc8-0x1ad8af).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/SCSIDiskPrivate.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#define MACH_USER_API	1	
#undef	KERNEL_PRIVATE

#import <sys/types.h>
#import <driverkit/SCSIDiskPrivate.h>
#import <driverkit/SCSIDiskTypes.h>
#import <driverkit/SCSIDiskThread.h>
#import <driverkit/SCSIDisk.h>
#import <driverkit/IODiskPartition.h>
#import <driverkit/scsiTypes.h>
#import <bsd/dev/scsireg.h>
#import <driverkit/xpr_mi.h>
#import <driverkit/return.h>
#import <driverkit/align.h>
#import <driverkit/generalFuncs.h>
#import <kernserv/prototypes.h>
#import <mach/mach_interface.h>
#import <machkit/NXLock.h>

static int moveString(char *inp, char *outp, int inlength, int outlength);

@implementation SCSIDisk(Private)

/*
 * One-time only initialization.
 */
- initResources
{
	/* plan 312: as in the original, one method; no initResourcesWithThreadCount: */
	int threadNum;

	queue_init(&_ioQueueDisk);
	queue_init(&_ioQueueNodisk);
	_ioQLock = [NXConditionLock alloc];
	[_ioQLock initWith:NO_WORK_AVAILABLE];
	
	/*
	 * This gets re-init'd per updateReadyState by IODiskPartitionProbe:.
	 */
	[self setLastReadyState:IO_NotReady];
	_ejectLock      = [NXConditionLock alloc];
	[_ejectLock initWith:0];
	_numDiskIos     = 0;
	_ejectPending   = NO;
	_isReserved     = 0;
	_isRegistered 	= 0;
	

	/*
	 * Start up some I/O threads to perform the actual work of this device.
	 * FIXME - there should only be one thread if target does not 
	 * implement command queueing, and more (at least two, max TBD)
	 * if target does implement command queueing.
	 */
	_numThreads = 0;
	for(threadNum=0; threadNum < NUM_SD_THREADS_MAX; threadNum++)	/* plan 312 */
	{
		_thread[threadNum] = IOForkThread((IOThreadFunc)sdIoThread, 
				self);
		_numThreads++;
	}
	return self;
}

/*
 * Device-specific initialization. We just do enough here to do some
 * I/O and to find out if the requested target/lun is a SCSI disk device.
 * This function is "reusable" for a given instance of SCSIDisk; initResources
 * must have been called exactly once prior to any use of this method.
 */

#define DRIVE_TYPE_LENGTH 80

- (sdInitReturn_t)SCSIDiskInit	:(int)iunit 	/* IODevice unit # */
	targetId : (u_char)Target
	lun : (u_char)Lun
	controller : controllerId
{
	inquiry_reply_t inquiryData;
	sc_status_t rtn;
	char driveType[DRIVE_TYPE_LENGTH];	/* name from Inquiry */
	char *outp;
	char deviceName[30];
	char location[IO_STRING_LENGTH];
	
	xpr_sd("SCSIDiskInit: iunit %d target %d lun %d\n", 
		iunit, Target, Lun, 4,5);
	
	/*
	 * init common instance variables.
	 */
	_controller = controllerId;
	_target = Target;
	_lun = Lun;
	[self setUnit:iunit];
	sprintf(deviceName, "sd%d", iunit);
	[self setName:deviceName];
	
	/*
	 * Try an Inquiry command.
	 */
	bzero(&inquiryData, sizeof(inquiry_reply_t));
	rtn = [self sdInquiry:&inquiryData];
	switch(rtn) {
	    case SR_IOST_GOOD:
	    	break;
	    case SR_IOST_SELTO:
	    	return(SDR_SELECTTO);
	    default:
	    	return(SDR_ERROR);
	}

	/*
	 * Is it a disk?
	 */
	if(inquiryData.ir_qual != DEVQUAL_OK) {
	    	return(SDR_NOTADISK);
	}
	switch(inquiryData.ir_devicetype) {
	    case DEVTYPE_DISK:
	    case DEVTYPE_WORM:
	    case DEVTYPE_OPTICAL:
	    case DEVTYPE_CDROM:
	    	break;
	    default:
	    	return(SDR_NOTADISK);
	}
	
	/*
	 * The top 3 bits (ir_qual) have to be 0, so throw 'em out.
	 */
	_inquiryDeviceType = inquiryData.ir_devicetype;
	if(inquiryData.ir_removable)
		[self setRemovable:1];
	
	/*
	 * Compress multiple blanks out of the vendor id and product ID. 
	 */
	outp = driveType;
	outp += moveString((char *)&inquiryData.ir_vendorid,
		outp, 
		8,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	if(*(outp - 1) != ' ')
		*outp++ = ' ';
	outp += moveString((char *)&inquiryData.ir_productid,
		outp, 
		16,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	if(*(outp - 1) != ' ')
		*outp++ = ' ';
	outp += moveString((char *)&inquiryData.ir_revision,
		outp, 
		4,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	*outp = '\0';
	[self setDriveName:driveType];
	sprintf(location,"Target %d LUN %d at %s", _target, _lun,
		[controllerId name]);
	[self setLocation:location];
	IOLog("%s: %s\n", deviceName, driveType);

	/*
	 * Do a Test Unit Ready to clear a possible Unit Attention condition.
	 * We don't care about the result.
	 */
	[self updateReadyState];

	/*
	 * Start up motor. We'll ignore errors on this one too.
	 */
	[self scsiStartStop:SS_START inhibitRetry:YES];
	
	/*
	 * Let's find out some more info. An error on the 
	 * updatePhysicalParameters could mean no disk present; that's OK...
	 */
	[self setFormattedInternal:0];		// until we do a successful r/w
	rtn = [self updatePhysicalParameters];
	if(rtn) {
		xpr_sd("SCSIDiskInit: updatePhysicalParameters failed; "
			"continuing\n", 
			1,2,3,4,5);
	}

	/*
	 * log device name. DiskObject will log block_size and capacity.
	 */
	 
	bzero(driveType, DRIVE_TYPE_LENGTH);
	
	/*
	 * Compress multiple blanks out of the vendor id and product ID. 
	 */
	outp = driveType;
	outp += moveString((char *)&inquiryData.ir_vendorid,
		outp, 
		8,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	if(*(outp - 1) != ' ')
		*outp++ = ' ';
	outp += moveString((char *)&inquiryData.ir_productid,
		outp, 
		16,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	if(*(outp - 1) != ' ')
		*outp++ = ' ';
	outp += moveString((char *)&inquiryData.ir_revision,
		outp, 
		32,
		&driveType[DRIVE_TYPE_LENGTH] - outp);
	*outp = '\0';
	[self setDriveName:driveType];
	sprintf(location,"Target %d LUN %d at %s", _target, _lun,
		[controllerId name]);
	[self setLocation:location];
	[super init];
	return(SDR_GOOD);
}

/*
 * Copy inp to outp for up to inlength input characters or outlength output
 * characters. Compress multiple spaces and eliminate nulls. Returns number
 * of characters copied to outp.
 */
static int moveString(char *inp, char *outp, int inlength, int outlength)
{
	int lastCharSpace = 0;
	char *outpStart = outp;
	
	while(inlength && outlength) {
		switch(*inp) {
		    case '\0':
		    	inp++;
			inlength--;
			continue;
		    case ' ':
			if(lastCharSpace) {
				inp++;
				inlength--;
				continue;
			}
			lastCharSpace = 1;
			goto copyit;
		    default:
		    	lastCharSpace = 0;
copyit:
			*outp++ = *inp++;
			inlength--;
			outlength--;
			break;
		}
	}
	return(outp - outpStart);
}

/*
 * Free up local resources. 
 */
- free
{
	int threadNum;
	sdBuf_t *sdBuf;
	
	xpr_sd("SCSIDisk free\n", 1,2,3,4,5);
	
	/* 
	 * Send a "thread abort" command to each thread.
	 */
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_ABORT_THREAD;
	sdBuf->needsDisk = 0;
	for(threadNum=0; threadNum<_numThreads; threadNum++) {
		[self enqueueSdBuf:sdBuf];
	}	
	[self freeSdBuf:sdBuf];
		
	/*
	 * Release our target/lun reservation if we have one.
	 */
	if(_isReserved) {
		/* plan 312: no releaseNonZeroLunsOnTarget: (not in the original) */
		[_controller releaseTarget:_target
			lun:_lun
			forOwner:self];
	}
	[_ioQLock free];
	return([super free]);
}

/* plan 312: no reacquireTarget, requestReleaseTarget or getCharValues:forParameter:count: (not in the original) */

/*
 * Internal I/O routines.
 */
 
/*
 * Inquiry. inquiryReply does not have to be well aligned.
 * Retries and error logging disabled.
 */
- (sc_status_t)sdInquiry : (inquiry_reply_t *)inquiryReply
{
	IOSCSIRequest 	scsiReq;
	cdb_6_t 	*cdbp = &scsiReq.cdb.cdb_c6;
	sdBuf_t 	*sdBuf;
	inquiry_reply_t *alignedReply;
	void 		*freep;
	int 		freecnt;
	sc_status_t 	rtn;
	IODMAAlignment 	dmaAlign;
	
	xpr_sd("sd%d sdInquiry\n", [self unit], 2,3,4,5);
	
	/*
	 * Get some well-aligned memory.
	 */
	alignedReply = [_controller allocateBufferOfLength:
					sizeof(inquiry_reply_t)
			actualStart:&freep
			actualLength:&freecnt];
	bzero(alignedReply, sizeof(inquiry_reply_t));
	bzero(&scsiReq, sizeof(IOSCSIRequest));
	scsiReq.target = _target;
	scsiReq.lun = _lun;
	scsiReq.read = YES;
	
	/*
	 * Get appropriate alignment from controller. 
	 */
	[_controller getDMAAlignment:&dmaAlign];
	if(dmaAlign.readLength > 1) {
		scsiReq.maxTransfer = IOAlign(int, sizeof(inquiry_reply_t), 
			dmaAlign.readLength);
	}
	else {
		scsiReq.maxTransfer = sizeof(inquiry_reply_t);
	}
	scsiReq.timeoutLength = SD_TIMEOUT_SIMPLE;
	scsiReq.disconnect = 1;
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_READ;
	sdBuf->scsiReq = &scsiReq;
	sdBuf->buf = alignedReply;
	sdBuf->client = IOVmTaskSelf();
	cdbp->c6_opcode = C6OP_INQUIRY;
	cdbp->c6_lun = _lun;
	cdbp->c6_len = sizeof(inquiry_reply_t);
	sdBuf->needsDisk = 0;
	sdBuf->retryDisable = 1;
	
	[self enqueueSdBuf:sdBuf];
	
	if(scsiReq.driverStatus == SR_IOST_GOOD) {
		unsigned required = (char *)(&alignedReply->ir_zero3) - 
				    (char *)(alignedReply);
		if(scsiReq.bytesTransferred < required) {
			IOLog("%s: bad DMA Transfer count (%d) on Inquiry\n", 
				[self name], scsiReq.bytesTransferred);
			rtn = SR_IOST_HW;
		}
		else {
			/*
		   	 * Copy data back to caller's struct. Zero the 
			 * portion of alignedReply which did not get valid
			 * data; the last flush out of the DMA pipe could
			 * have written trash to it (and our caller
			 * expects NULL data).
		   	 */
			unsigned zeroSize;
			
			zeroSize = sizeof(*alignedReply) - 
				scsiReq.bytesTransferred;
			if(zeroSize) {
				bzero((char *)alignedReply + 
					scsiReq.bytesTransferred,
					zeroSize);
			}
			*inquiryReply = *alignedReply;
			rtn = scsiReq.driverStatus;
		}
	}
	else {
		rtn = scsiReq.driverStatus;
	}
	IOFree(freep, freecnt);
	xpr_sd("sdInquiry: returning %s\n", 
		IOFindNameForValue(rtn, IOScStatusStrings),
		2,3,4,5);
	return rtn;
}

/*
 * Read Capacity. capacityReply does not have to be well aligned. Fails
 * if disk not ready.
 */
- (sc_status_t)sdReadCapacity 	: (capacity_reply_t *)capacityReply
{
	IOSCSIRequest 	scsiReq;
	cdb_10_t 	*cdbp = &scsiReq.cdb.cdb_c10;
	sdBuf_t 	*sdBuf;
	capacity_reply_t *alignedReply;
	void 		*freep;
	int 		freecnt;
	sc_status_t	rtn;
	IODMAAlignment 	dmaAlign;
	
	xpr_sd("sd%d sdReadCapacity\n", [self unit], 2,3,4,5);
	
	/*
	 * Get some well-aligned memory.
	 */
	alignedReply = [_controller allocateBufferOfLength:
					sizeof(capacity_reply_t)
			actualStart:&freep
			actualLength:&freecnt];

	bzero(&scsiReq, sizeof(IOSCSIRequest));
	scsiReq.target = _target;
	scsiReq.lun = _lun;
	scsiReq.read = YES;
	
	/*
	 * Get appropriate alignment from controller. 
	 */
	[_controller getDMAAlignment:&dmaAlign];
	if(dmaAlign.readLength > 1) {
		scsiReq.maxTransfer = IOAlign(int, sizeof(capacity_reply_t), 
			dmaAlign.readLength);
	}
	else {
		scsiReq.maxTransfer = sizeof(capacity_reply_t);
	}
	scsiReq.timeoutLength = SD_TIMEOUT_SIMPLE;
	scsiReq.disconnect = 1;
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_READ;
	sdBuf->scsiReq = &scsiReq;
	sdBuf->buf = alignedReply;
	sdBuf->client = IOVmTaskSelf();
	cdbp->c10_opcode = C10OP_READCAPACITY;
	cdbp->c10_lun = _lun;
	sdBuf->needsDisk = 0;
	
	[self enqueueSdBuf:sdBuf];
	
	if(scsiReq.driverStatus == SR_IOST_GOOD) {
#if	!i386
		if(scsiReq.bytesTransferred != sizeof(capacity_reply_t)) {
			IOLog("%s: bad DMA Transfer count (%d) on Read"
				" Capacity\n", 
				[self name], scsiReq.bytesTransferred);
			rtn = SR_IOST_HW;
		}
		else {
#else
		{
#endif
			/*
		   	 * Copy data back to caller's struct.
		   	 */
			*capacityReply = *alignedReply;
			rtn = scsiReq.driverStatus;
		}
	}
	else {
		rtn = scsiReq.driverStatus;
	}
	IOFree(freep, freecnt);
	xpr_sd("sdReadCapacity: returning %s\n", 
		IOFindNameForValue(rtn, IOScStatusStrings),
		2,3,4,5);
	return rtn;
}


/*
 * Mode Sense. 
 */
- (sc_status_t)sdModeSense 	: (mode_sel_data_t *)modeSenseReply
{
	IOSCSIRequest 	scsiReq;
	cdb_6_t 	*cdbp = &scsiReq.cdb.cdb_c6;
	sdBuf_t 	*sdBuf;
	mode_sel_data_t *alignedReply;
	void 		*freep;
	int 		freecnt;
	sc_status_t	rtn;
	IODMAAlignment 	dmaAlign;
	
	xpr_sd("sd%d sdModeSense\n", [self unit], 2,3,4,5);
	
	/*
	 * Get some well-aligned memory.
	 */
	alignedReply = [_controller allocateBufferOfLength:
					sizeof(mode_sel_data_t)
			actualStart:&freep
			actualLength:&freecnt];

	bzero(&scsiReq, sizeof(IOSCSIRequest));
	scsiReq.target = _target;
	scsiReq.lun = _lun;
	scsiReq.read = YES;
	
	/*
	 * Get appropriate alignment from controller. 
	 */
	[_controller getDMAAlignment:&dmaAlign];
	if(dmaAlign.readLength > 1) {
		scsiReq.maxTransfer = IOAlign(int, sizeof(mode_sel_data_t), 
			dmaAlign.readLength);
	}
	else {
		scsiReq.maxTransfer = sizeof(mode_sel_data_t);
	}
	scsiReq.timeoutLength = SD_TIMEOUT_SIMPLE;
	scsiReq.disconnect = 1;
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_CDB_READ;
	sdBuf->scsiReq = &scsiReq;
	sdBuf->buf = alignedReply;
	sdBuf->client = IOVmTaskSelf();
	cdbp->c6_opcode = C6OP_MODESENSE;
	cdbp->c6_lun = _lun;
	cdbp->c6_len = sizeof(mode_sel_data_t);
	sdBuf->needsDisk = 1;
	
	[self enqueueSdBuf:sdBuf];
	
	if(scsiReq.driverStatus == SR_IOST_GOOD) {

		/*
		 * Copy data back to caller's struct.
		 */
		*modeSenseReply = *alignedReply;
		rtn = scsiReq.driverStatus;
	}
	else {
		rtn = scsiReq.driverStatus;
	}

	IOFree(freep, freecnt);

	xpr_sd("sdModeSense: returning %s\n", 
		IOFindNameForValue(rtn, IOScStatusStrings),
		2,3,4,5);
	return rtn;
}

/*
 * Read data; retries and error reporting disabled. Assumes disk is present.
 */ 
- (IOReturn)sdRawRead		: (int)block
				  blockCnt:(int)blockCnt
				  buffer:(void *)buffer
{
	sdBuf_t *sdBuf;
	IOReturn rtn;
	
	xpr_sd("sdRawRead block %d cnt %d\n", block, blockCnt, 3,4,5);
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->command = SDOP_READ;
	sdBuf->block = block;
	sdBuf->blockCnt = blockCnt;
	sdBuf->buf = buffer;
	sdBuf->client = IOVmTaskSelf();
	sdBuf->needsDisk = 1;
	sdBuf->retryDisable = 1;
	rtn = [self enqueueSdBuf:sdBuf];
	[self freeSdBuf:sdBuf];
	xpr_sd("sdRawRead: returning %s\n", [self stringFromReturn:rtn], 
		2,3,4,5);
	return(rtn);
}

/*
 * Start, stop, eject.
 */
- (IOReturn)scsiStartStop : (startStop_t)cmd
			    inhibitRetry : (BOOL)inhibitRetry
{
	IOSCSIRequest scsiReq;
	sdBuf_t *sdBuf;
	cdb_6_t *cdbp = &scsiReq.cdb.cdb_c6;
	IOReturn rtn;
	
	xpr_sd("%s: scsiStartStop: cmd 0x%x\n", [self name], cmd,3,4,5);
	
	bzero(&scsiReq, sizeof(IOSCSIRequest));
	scsiReq.target = _target;
	scsiReq.lun = _lun;
	scsiReq.timeoutLength = SD_TIMEOUT_EJECT;
	scsiReq.disconnect = 1;
	
	sdBuf = [self allocSdBuf:NULL];
	sdBuf->scsiReq = &scsiReq;
	sdBuf->retryDisable = inhibitRetry ? 1 : 0;
	sdBuf->needsDisk = 1;
	
	cdbp->c6_opcode = C6OP_STARTSTOP;
	cdbp->c6_lun = _lun;

	switch(cmd) {
	    case SS_EJECT:
	    	cdbp->c6_len = C6S_SS_EJECT;
		sdBuf->command = SDOP_EJECT;
		break;
	    case SS_STOP:
	    	cdbp->c6_len = C6S_SS_STOP;
		sdBuf->command = SDOP_CDB_WRITE;
		break;
	    case SS_START:
	    	cdbp->c6_len = C6S_SS_START;
		sdBuf->command = SDOP_CDB_WRITE;
		break;
	}

	rtn = [self enqueueSdBuf:sdBuf];
	xpr_sd("%s scsiStartStop: returning %s\n", [self name], 
		[self stringFromReturn:rtn], 3,4,5);
	[self freeSdBuf:sdBuf];
	return(rtn);
}

/*
 * Common read/write routine.
 */
- (IOReturn) deviceRwCommon : (sdOp_t)command
		  block: (u_int) deviceBlock
		  length : (u_int)length 
		  buffer : (void *)buffer
		  client : (vm_task_t)client
		  pending : (void *)pending
		  actualLength : (u_int *)actualLength
{
	sdBuf_t *sdBuf;
	IOReturn rtn;
	u_int blocksReq;
	u_int block_size;
	u_int dev_size;
	
	/*
	 * Note we have to 'fault in' a possible non-present disk in 
	 * order to get its physical parameters...
	 */
	rtn = [self isDiskReady:YES];
	switch(rtn) {
	    case IO_R_SUCCESS:
	    	break;
	    case IO_R_NO_DISK:
		xpr_sd("%s deviceRwCommon: disk not present\n",
			[self name], 2,3,4,5);
		return(rtn);
	    default:
	    	IOLog("%s deviceRwCommon: bogus return from isDiskReady "
			"(%s)\n",
			[self name], [self stringFromReturn:rtn]);
		return(rtn);
	}

	if(![self isFormatted])
		return(IO_R_UNFORMATTED);
	block_size = [self blockSize];
	dev_size = [self diskSize];
	
	/*
	 * Verify access and legal parameters.
	 */
	if(length % block_size) {
	    	xpr_sd("deviceRwCommon: unaligned length\n", 1,2,3,4,5);
		return(IO_R_INVALID);
	}
	blocksReq = length / block_size;
	if((deviceBlock + blocksReq) > dev_size) {
		if(deviceBlock >= dev_size) {
			xpr_sd("deviceRwCommon: invalid "
				"deviceBlock/byte count\n", 1,2,3,4,5);
			return(IO_R_INVALID_ARG);
		}
		/*
		 * Truncate.
		 */
		blocksReq = dev_size - deviceBlock;
		xpr_sd("deviceRwCommon: truncating to %d blocks\n", blocksReq,
			2,3,4,5);
	}
	sdBuf = [self allocSdBuf:pending];
	sdBuf->command = command;
	sdBuf->block = deviceBlock;
	sdBuf->blockCnt = blocksReq;
	sdBuf->buf = buffer;
	sdBuf->client = client;
	sdBuf->needsDisk = 1;
	rtn = [self enqueueSdBuf:sdBuf];
	if(pending == NULL) {
		/* 
		 * Sync I/O.
		 */
		*actualLength = sdBuf->bytesXfr;
		[self freeSdBuf:sdBuf];
	}
	return(rtn);
}

/*
 * -- Enqueue an sdBuf on _ioQueue<Disk,Nodisk>
 * -- wake up one of the I/O threads
 * -- wait for I/O complete (if sdBuf->pending == NULL)
 */
- (IOReturn)enqueueSdBuf:(sdBuf_t *)sdBuf
{	
	queue_head_t *q;
	
#ifdef	DDM_DEBUG
	if(sdBuf->pending) {
		xpr_sd("enqueueSdBuf: sdBuf 0x%x, ASYNC\n", sdBuf, 2,3,4,5);
	}
	else {
		xpr_sd("enqueueSdBuf: sdBuf 0x%x, SYNC\n", sdBuf, 2,3,4,5);
	}
#endif	DDM_DEBUG

	sdBuf->status = IO_R_INVALID;
	[_ioQLock lock];
	/*
	 * TBD - sort by disk block eventually.
	 */
	if(sdBuf->needsDisk)
		q = &_ioQueueDisk;
	else
		q = &_ioQueueNodisk;
	queue_enter(q, sdBuf, sdBuf_t *, link);
	[_ioQLock unlockWith:WORK_AVAILABLE];
	if(sdBuf->pending != NULL)
		return(IO_R_SUCCESS);
	
	/*
	 * wait for I/O complete.
	 */
	[sdBuf->waitLock lockWhen:YES];
	[sdBuf->waitLock unlockWith:NO];	// for easy reuse
	xpr_sd("enqueueSdBuf: I/O Complete sdBuf 0x%x status %s\n",
		sdBuf, [self stringFromReturn:sdBuf->status], 3,4,5);
	return(sdBuf->status);
}

/*
 * Allocate and free sdBuf_t's.
 *
 * TBD - we might keep around a queue of free sdBuf_t's.
 */
- (sdBuf_t *)allocSdBuf : (void *)pending
{
	sdBuf_t *sdBuf = IOMalloc(sizeof(sdBuf_t));
	
	bzero(sdBuf, sizeof(sdBuf_t));
	if(pending == NULL) {
		sdBuf->waitLock = [NXConditionLock alloc];
		[sdBuf->waitLock initWith:NO];
	}
	else
		sdBuf->pending = pending;
	return(sdBuf);
}

- (void)freeSdBuf : (sdBuf_t *)sdBuf
{
	if(!sdBuf->pending) {
		[sdBuf->waitLock free];
	}
	IOFree(sdBuf, sizeof(sdBuf_t));
}

/* plan 312: no reserveNonZeroLunsOnTarget: or releaseNonZeroLunsOnTarget: (not in the original) */

@end



