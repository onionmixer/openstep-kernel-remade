/* Module driverServer */

#define EXPORT_BOOLEAN
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/mig_support.h>
#include <ipc/ipc_port.h>

#ifndef	mig_internal
#define	mig_internal	static
#endif

#ifndef	mig_external
#define mig_external
#endif

#ifndef	TypeCheck
#define	TypeCheck 1
#endif

#ifndef	UseExternRCSId
#define	UseExternRCSId		1
#endif

#define msgh_request_port	msgh_remote_port
#define MACH_MSGH_BITS_REQUEST(bits)	MACH_MSGH_BITS_REMOTE(bits)
#define msgh_reply_port		msgh_local_port
#define MACH_MSGH_BITS_REPLY(bits)	MACH_MSGH_BITS_LOCAL(bits)

#include <mach/std_types.h>
#include <kern/ipc_kobject.h>
#include <kern/ipc_tt.h>
#include <kern/ipc_host.h>
#include <kern/task.h>
#include <kern/thread.h>
#include <kern/host.h>
#include <kern/processor.h>
#include <vm/vm_object.h>
#include <vm/vm_map.h>
#include <ipc/ipc_space.h>
#include <mach/mach_types.h>
#include <driverkit/driverTypes.h>
#include <driverkit/driverTypesPrivate.h>
#include <driverkit/driverServerXXX.h>

/* Routine _IOLookupByObjectNumber */
mig_internal void _X_IOLookupByObjectNumber
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t deviceKindType;
		IOString deviceKind;
		mach_msg_type_t deviceNameType;
		IOString deviceName;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOLookupByObjectNumber
		(host_t device_master, IOObjectNumber objectNumber, IOString deviceKind, IOString deviceName);

	static mach_msg_type_t objectNumberCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t deviceKindType = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		80,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t deviceNameType = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		80,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->objectNumberType != * (int *) &objectNumberCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOLookupByObjectNumber(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->objectNumber, OutP->deviceKind, OutP->deviceName);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 200;

	OutP->deviceKindType = deviceKindType;

	OutP->deviceNameType = deviceNameType;
}

/* Routine _IOLookupByDeviceName */
mig_internal void _X_IOLookupByDeviceName
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t deviceNameType;
		IOString deviceName;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
		mach_msg_type_t deviceKindType;
		IOString deviceKind;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOLookupByDeviceName
		(host_t device_master, IOString deviceName, IOObjectNumber *objectNumber, IOString deviceKind);

	static mach_msg_type_t deviceNameCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		80,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t objectNumberType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t deviceKindType = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		80,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 108) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->deviceNameType != * (int *) &deviceNameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOLookupByDeviceName(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->deviceName, &OutP->objectNumber, OutP->deviceKind);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 124;

	OutP->objectNumberType = objectNumberType;

	OutP->deviceKindType = deviceKindType;
}

/* Routine _IOGetIntValues */
mig_internal void _X_IOGetIntValues
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
		mach_msg_type_t parameterNameType;
		IOParameterName parameterName;
		mach_msg_type_t maxCountType;
		unsigned maxCount;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t parameterArrayType;
		int parameterArray[512];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOGetIntValues
		(host_t device_master, IOObjectNumber objectNumber, IOParameterName parameterName, unsigned maxCount, IOIntParameter parameterArray, mach_msg_type_number_t *parameterArrayCnt);

	static mach_msg_type_t objectNumberCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterNameCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		64,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t maxCountCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterArrayType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		512,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	mach_msg_type_number_t parameterArrayCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 108) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->objectNumberType != * (int *) &objectNumberCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->maxCountType != * (int *) &maxCountCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	parameterArrayCnt = 512;

	OutP->RetCode = kern_IOGetIntValues(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->objectNumber, In0P->parameterName, In0P->maxCount, OutP->parameterArray, &parameterArrayCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->parameterArrayType = parameterArrayType;

	OutP->parameterArrayType.msgt_number = parameterArrayCnt;
	OutP->Head.msgh_size = 36 + (4 * parameterArrayCnt);
}

/* Routine _IOGetCharValues */
mig_internal void _X_IOGetCharValues
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
		mach_msg_type_t parameterNameType;
		IOParameterName parameterName;
		mach_msg_type_t maxCountType;
		unsigned maxCount;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t parameterArrayType;
		char parameterArray[512];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOGetCharValues
		(host_t device_master, IOObjectNumber objectNumber, IOParameterName parameterName, unsigned maxCount, IOCharParameter parameterArray, mach_msg_type_number_t *parameterArrayCnt);

	static mach_msg_type_t objectNumberCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterNameCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		64,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t maxCountCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterArrayType = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		512,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	mach_msg_type_number_t parameterArrayCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 108) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->objectNumberType != * (int *) &objectNumberCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->maxCountType != * (int *) &maxCountCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	parameterArrayCnt = 512;

	OutP->RetCode = kern_IOGetCharValues(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->objectNumber, In0P->parameterName, In0P->maxCount, OutP->parameterArray, &parameterArrayCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->parameterArrayType = parameterArrayType;

	OutP->parameterArrayType.msgt_number = parameterArrayCnt;
	OutP->Head.msgh_size = 36 + ((parameterArrayCnt + 3) & ~3);
}

/* Routine _IOSetIntValues */
mig_internal void _X_IOSetIntValues
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
		mach_msg_type_t parameterNameType;
		IOParameterName parameterName;
		mach_msg_type_t parameterArrayType;
		int parameterArray[512];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOSetIntValues
		(host_t device_master, IOObjectNumber objectNumber, IOParameterName parameterName, IOIntParameter parameterArray, mach_msg_type_number_t parameterArrayCnt);

	unsigned int msgh_size;

	static mach_msg_type_t objectNumberCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterNameCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		64,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 104) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->objectNumberType != * (int *) &objectNumberCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->parameterArrayType.msgt_inline != TRUE) ||
	    (In0P->parameterArrayType.msgt_longform != FALSE) ||
	    (In0P->parameterArrayType.msgt_name != 2) ||
	    (In0P->parameterArrayType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 104 + (4 * In0P->parameterArrayType.msgt_number))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOSetIntValues(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), In0P->objectNumber, In0P->parameterName, In0P->parameterArray, In0P->parameterArrayType.msgt_number);
}

/* Routine _IOSetCharValues */
mig_internal void _X_IOSetCharValues
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t objectNumberType;
		IOObjectNumber objectNumber;
		mach_msg_type_t parameterNameType;
		IOParameterName parameterName;
		mach_msg_type_t parameterArrayType;
		char parameterArray[512];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOSetCharValues
		(host_t device_master, IOObjectNumber objectNumber, IOParameterName parameterName, IOCharParameter parameterArray, mach_msg_type_number_t parameterArrayCnt);

	unsigned int msgh_size;

	static mach_msg_type_t objectNumberCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t parameterNameCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		64,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 104) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->objectNumberType != * (int *) &objectNumberCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->parameterNameType != * (int *) &parameterNameCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->parameterArrayType.msgt_inline != TRUE) ||
	    (In0P->parameterArrayType.msgt_longform != FALSE) ||
	    (In0P->parameterArrayType.msgt_name != 8) ||
	    (In0P->parameterArrayType.msgt_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 104 + ((In0P->parameterArrayType.msgt_number + 3) & ~3))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOSetCharValues(convert_port_to_host_priv((ipc_port_t) In0P->Head.msgh_request_port), In0P->objectNumber, In0P->parameterName, In0P->parameterArray, In0P->parameterArrayType.msgt_number);
}

/* Routine _IOGetEISADeviceConfig */
mig_internal void _X_IOGetEISADeviceConfig
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t intr_confType;
		IOEISAInterrupt intr_conf[7];
		mach_msg_type_t dma_confType;
		IOEISADMAChannel dma_conf[4];
		mach_msg_type_t io_confType;
		IOEISAPortRange io_conf[20];
		mach_msg_type_t phys_confType;
		IOEISAMemoryRange phys_conf[9];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOGetEISADeviceConfig
		(kernDevice_p device, IOEISAInterruptList intr_conf, mach_msg_type_number_t *intr_confCnt, IOEISADMAChannelList dma_conf, mach_msg_type_number_t *dma_confCnt, IOEISAPortMap io_conf, mach_msg_type_number_t *io_confCnt, IOEISAMemoryMap phys_conf, mach_msg_type_number_t *phys_confCnt);

	unsigned int msgh_size;
	unsigned int msgh_size_delta;

	static mach_msg_type_t intr_confType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		7,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t dma_confType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		4,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t io_confType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		40,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t phys_confType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		18,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	mach_msg_type_number_t intr_confCnt;
	IOEISADMAChannel dma_conf[4];
	mach_msg_type_number_t dma_confCnt;
	IOEISAPortRange io_conf[20];
	mach_msg_type_number_t io_confCnt;
	IOEISAMemoryRange phys_conf[9];
	mach_msg_type_number_t phys_confCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	intr_confCnt = 7;

	dma_confCnt = 4;

	io_confCnt = 20;

	phys_confCnt = 9;

	OutP->RetCode = kern_IOGetEISADeviceConfig(convert_port_to_dev((ipc_port_t) In0P->Head.msgh_request_port), OutP->intr_conf, &intr_confCnt, dma_conf, &dma_confCnt, io_conf, &io_confCnt, phys_conf, &phys_confCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->intr_confType = intr_confType;

	OutP->intr_confType.msgt_number = intr_confCnt;
	msgh_size_delta = 4 * intr_confCnt;
	msgh_size = 48 + msgh_size_delta;
	OutP = (Reply *) ((char *) OutP + msgh_size_delta - 28);

	OutP->dma_confType = dma_confType;

	memcpy(OutP->dma_conf, dma_conf, 4 * dma_confCnt);

	OutP->dma_confType.msgt_number = dma_confCnt;
	msgh_size_delta = 4 * dma_confCnt;
	msgh_size += msgh_size_delta;
	OutP = (Reply *) ((char *) OutP + msgh_size_delta - 16);

	OutP->io_confType = io_confType;

	memcpy(OutP->io_conf, io_conf, 8 * io_confCnt);

	OutP->io_confType.msgt_number = 2 * io_confCnt;
	msgh_size_delta = 8 * io_confCnt;
	msgh_size += msgh_size_delta;
	OutP = (Reply *) ((char *) OutP + msgh_size_delta - 160);

	OutP->phys_confType = phys_confType;

	memcpy(OutP->phys_conf, phys_conf, 8 * phys_confCnt);

	OutP->phys_confType.msgt_number = 2 * phys_confCnt;
	msgh_size += 8 * phys_confCnt;

	OutP = (Reply *) OutHeadP;
	OutP->Head.msgh_size = msgh_size;
}

/* Routine _IOMapEISADevicePorts */
mig_internal void _X_IOMapEISADevicePorts
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t threadType;
		ipc_port_t thread;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOMapEISADevicePorts
		(kernDevice_p device, thread_t thread);

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->threadType.msgt_inline != TRUE) ||
	    (In0P->threadType.msgt_longform != FALSE) ||
	    (In0P->threadType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->threadType.msgt_number != 1) ||
	    (In0P->threadType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread(In0P->thread);

	OutP->RetCode = kern_IOMapEISADevicePorts(convert_port_to_dev((ipc_port_t) In0P->Head.msgh_request_port), thread);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->thread))
		ipc_port_release_send(In0P->thread);
}

/* Routine _IOUnMapEISADevicePorts */
mig_internal void _X_IOUnMapEISADevicePorts
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t threadType;
		ipc_port_t thread;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOUnMapEISADevicePorts
		(kernDevice_p device, thread_t thread);

	thread_t thread;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->threadType.msgt_inline != TRUE) ||
	    (In0P->threadType.msgt_longform != FALSE) ||
	    (In0P->threadType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->threadType.msgt_number != 1) ||
	    (In0P->threadType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	thread = convert_port_to_thread(In0P->thread);

	OutP->RetCode = kern_IOUnMapEISADevicePorts(convert_port_to_dev((ipc_port_t) In0P->Head.msgh_request_port), thread);
	thread_deallocate(thread);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->thread))
		ipc_port_release_send(In0P->thread);
}

/* Routine _IOMapEISADeviceMemory */
mig_internal void _X_IOMapEISADeviceMemory
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t target_taskType;
		ipc_port_t target_task;
		mach_msg_type_t physType;
		vm_offset_t phys;
		mach_msg_type_t lengthType;
		vm_size_t length;
		mach_msg_type_t addrType;
		vm_offset_t addr;
		mach_msg_type_t anywhereType;
		BOOL anywhere;
		char anywherePad[3];
		mach_msg_type_t cacheType;
		IOCache cache;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t addrType;
		vm_offset_t addr;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOMapEISADeviceMemory
		(kernDevice_p device, task_t target_task, vm_offset_t phys, vm_size_t length, vm_offset_t *addr, BOOL anywhere, IOCache cache);

	static mach_msg_type_t physCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t lengthCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t addrCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t anywhereCheck = {
		/* msgt_name = */		8,
		/* msgt_size = */		8,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t cacheCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t addrType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	task_t target_task;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 72) ||
	    !(In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->target_taskType.msgt_inline != TRUE) ||
	    (In0P->target_taskType.msgt_longform != FALSE) ||
	    (In0P->target_taskType.msgt_name != MACH_MSG_TYPE_PORT_SEND) ||
	    (In0P->target_taskType.msgt_number != 1) ||
	    (In0P->target_taskType.msgt_size != 32))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->physType != * (int *) &physCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->lengthType != * (int *) &lengthCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->addrType != * (int *) &addrCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->anywhereType != * (int *) &anywhereCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->cacheType != * (int *) &cacheCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	target_task = convert_port_to_task(In0P->target_task);

	OutP->RetCode = kern_IOMapEISADeviceMemory(convert_port_to_dev((ipc_port_t) In0P->Head.msgh_request_port), target_task, In0P->phys, In0P->length, &In0P->addr, In0P->anywhere, In0P->cache);
	task_deallocate(target_task);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	if (IP_VALID(In0P->target_task))
		ipc_port_release_send(In0P->target_task);

	OutP->Head.msgh_size = 40;

	OutP->addrType = addrType;

	OutP->addr = In0P->addr;
}

/* Routine _IOProbeDriver */
mig_internal void _X_IOProbeDriver
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_long_t configTableType;
		char configTable[4096];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOProbeDriver
		(host_t device_master, IOConfigData configTable, mach_msg_type_number_t configTableCnt);

	unsigned int msgh_size;

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 36) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->configTableType.msgtl_header.msgt_inline != TRUE) ||
	    (In0P->configTableType.msgtl_header.msgt_longform != TRUE) ||
	    (In0P->configTableType.msgtl_name != 8) ||
	    (In0P->configTableType.msgtl_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 36 + ((In0P->configTableType.msgtl_number + 3) & ~3))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOProbeDriver(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->configTable, In0P->configTableType.msgtl_number);
}

/* Routine _IOGetSystemConfig */
mig_internal void _X_IOGetSystemConfig
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t maxDataSizeType;
		unsigned maxDataSize;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t configTableType;
		char configTable[4096];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOGetSystemConfig
		(host_t device_master, unsigned maxDataSize, IOConfigData configTable, mach_msg_type_number_t *configTableCnt);

	static mach_msg_type_t maxDataSizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t configTableType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	8,
		/* msgtl_size = */	8,
		/* msgtl_number = */	4096,
	};

	mach_msg_type_number_t configTableCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 32) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->maxDataSizeType != * (int *) &maxDataSizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	configTableCnt = 4096;

	OutP->RetCode = kern_IOGetSystemConfig(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->maxDataSize, OutP->configTable, &configTableCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->configTableType = configTableType;

	OutP->configTableType.msgtl_number = configTableCnt;
	OutP->Head.msgh_size = 44 + ((configTableCnt + 3) & ~3);
}

/* Routine _IOUnloadDriver */
mig_internal void _X_IOUnloadDriver
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_long_t configTableType;
		char configTable[4096];
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOUnloadDriver
		(host_t device_master, IOConfigData configTable, mach_msg_type_number_t configTableCnt);

	unsigned int msgh_size;

#if	TypeCheck
	msgh_size = In0P->Head.msgh_size;
	if ((msgh_size < 36) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if ((In0P->configTableType.msgtl_header.msgt_inline != TRUE) ||
	    (In0P->configTableType.msgtl_header.msgt_longform != TRUE) ||
	    (In0P->configTableType.msgtl_name != 8) ||
	    (In0P->configTableType.msgtl_size != 8))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (msgh_size != 36 + ((In0P->configTableType.msgtl_number + 3) & ~3))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_IOUnloadDriver(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->configTable, In0P->configTableType.msgtl_number);
}

/* Routine _IOGetDriverConfig */
mig_internal void _X_IOGetDriverConfig
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t driverNumType;
		unsigned driverNum;
		mach_msg_type_t maxDataSizeType;
		unsigned maxDataSize;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_long_t configTableType;
		char configTable[4096];
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_IOGetDriverConfig
		(host_t device_master, unsigned driverNum, unsigned maxDataSize, IOConfigData configTable, mach_msg_type_number_t *configTableCnt);

	static mach_msg_type_t driverNumCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t maxDataSizeCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_long_t configTableType = {
	{
		/* msgt_name = */		0,
		/* msgt_size = */		0,
		/* msgt_number = */		0,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		TRUE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	},
		/* msgtl_name = */	8,
		/* msgtl_size = */	8,
		/* msgtl_number = */	4096,
	};

	mach_msg_type_number_t configTableCnt;

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->driverNumType != * (int *) &driverNumCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->maxDataSizeType != * (int *) &maxDataSizeCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	configTableCnt = 4096;

	OutP->RetCode = kern_IOGetDriverConfig(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->driverNum, In0P->maxDataSize, OutP->configTable, &configTableCnt);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->configTableType = configTableType;

	OutP->configTableType.msgtl_number = configTableCnt;
	OutP->Head.msgh_size = 44 + ((configTableCnt + 3) & ~3);
}
#include <kern/power.h>

/* Routine _PMSetPowerState */
mig_internal void _X_PMSetPowerState
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t deviceType;
		PMDeviceID device;
		mach_msg_type_t stateType;
		PMPowerState state;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_PMSetPowerState
		(host_t host, PMDeviceID device, PMPowerState state);

	static mach_msg_type_t deviceCheck = {
		/* msgt_name = */		1,
		/* msgt_size = */		16,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t stateCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->deviceType != * (int *) &deviceCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->stateType != * (int *) &stateCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_PMSetPowerState(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->device, In0P->state);
}

/* Routine _PMGetPowerEvent */
mig_internal void _X_PMGetPowerEvent
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t eventType;
		PMPowerEvent event;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_PMGetPowerEvent
		(host_t host, PMPowerEvent *event);

	static mach_msg_type_t eventType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_PMGetPowerEvent(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &OutP->event);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 40;

	OutP->eventType = eventType;
}

/* Routine _PMGetPowerStatus */
mig_internal void _X_PMGetPowerStatus
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
		mach_msg_type_t statusType;
		PMPowerStatus status;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_PMGetPowerStatus
		(host_t host, PMPowerStatus *status);

	static mach_msg_type_t statusType = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		3,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_PMGetPowerStatus(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), &OutP->status);
	if (OutP->RetCode != KERN_SUCCESS)
		return;

	OutP->Head.msgh_size = 48;

	OutP->statusType = statusType;
}

/* Routine _PMSetPowerManagement */
mig_internal void _X_PMSetPowerManagement
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t deviceType;
		PMDeviceID device;
		mach_msg_type_t stateType;
		PMPowerManagementState state;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_PMSetPowerManagement
		(host_t host, PMDeviceID device, PMPowerManagementState state);

	static mach_msg_type_t deviceCheck = {
		/* msgt_name = */		1,
		/* msgt_size = */		16,
		/* msgt_number = */		2,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	static mach_msg_type_t stateCheck = {
		/* msgt_name = */		2,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

#if	TypeCheck
	if ((In0P->Head.msgh_size != 40) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->deviceType != * (int *) &deviceCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

#if	TypeCheck
	if (* (int *) &In0P->stateType != * (int *) &stateCheck)
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_PMSetPowerManagement(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port), In0P->device, In0P->state);
}

/* Routine _PMRestoreDefaults */
mig_internal void _X_PMRestoreDefaults
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	typedef struct {
		mach_msg_header_t Head;
	} Request;

	typedef struct {
		mach_msg_header_t Head;
		mach_msg_type_t RetCodeType;
		kern_return_t RetCode;
	} Reply;

	register Request *In0P = (Request *) InHeadP;
	register Reply *OutP = (Reply *) OutHeadP;
	mig_external kern_return_t kern_PMRestoreDefaults
		(host_t host);

#if	TypeCheck
	if ((In0P->Head.msgh_size != 24) ||
	    (In0P->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX))
		{ OutP->RetCode = MIG_BAD_ARGUMENTS; return; }
#endif	/* TypeCheck */

	OutP->RetCode = kern_PMRestoreDefaults(convert_port_to_host((ipc_port_t) In0P->Head.msgh_request_port));
}

static mig_routine_t driverServer_server_routines[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		_X_IOLookupByObjectNumber,
		_X_IOLookupByDeviceName,
		_X_IOGetIntValues,
		_X_IOGetCharValues,
		_X_IOSetIntValues,
		_X_IOSetCharValues,
		_X_IOGetEISADeviceConfig,
		_X_IOMapEISADevicePorts,
		_X_IOUnMapEISADevicePorts,
		_X_IOMapEISADeviceMemory,
		0,
		0,
		_X_IOProbeDriver,
		_X_IOGetSystemConfig,
		_X_IOUnloadDriver,
		_X_IOGetDriverConfig,
		_X_PMSetPowerState,
		_X_PMGetPowerEvent,
		_X_PMGetPowerStatus,
		_X_PMSetPowerManagement,
		_X_PMRestoreDefaults,
};

mig_external boolean_t driverServer_server
	(mach_msg_header_t *InHeadP, mach_msg_header_t *OutHeadP)
{
	register mach_msg_header_t *InP =  InHeadP;
	register mig_reply_header_t *OutP = (mig_reply_header_t *) OutHeadP;

	static mach_msg_type_t RetCodeType = {
		/* msgt_name = */		MACH_MSG_TYPE_INTEGER_32,
		/* msgt_size = */		32,
		/* msgt_number = */		1,
		/* msgt_inline = */		TRUE,
		/* msgt_longform = */		FALSE,
		/* msgt_deallocate = */		FALSE,
		/* msgt_unused = */		0
	};

	register mig_routine_t routine;

	OutP->Head.msgh_bits = MACH_MSGH_BITS(MACH_MSGH_BITS_REPLY(InP->msgh_bits), 0);
	OutP->Head.msgh_size = sizeof *OutP;
	OutP->Head.msgh_remote_port = InP->msgh_reply_port;
	OutP->Head.msgh_local_port = MACH_PORT_NULL;
	OutP->Head.msgh_seqno = 0;
	OutP->Head.msgh_id = InP->msgh_id + 100;

	OutP->RetCodeType = RetCodeType;

	if ((InP->msgh_id > 2738) || (InP->msgh_id < 2700) ||
	    ((routine = driverServer_server_routines[InP->msgh_id - 2700]) == 0)) {
		OutP->RetCode = MIG_BAD_ID;
		return FALSE;
	}
	(*routine) (InP, &OutP->Head);
	return TRUE;
}

mig_external mig_routine_t driverServer_server_routine
	(const mach_msg_header_t *InHeadP)
{
	register int msgh_id;

	msgh_id = InHeadP->msgh_id - 2700;

	if ((msgh_id > 38) || (msgh_id < 0))
		return 0;

	return driverServer_server_routines[msgh_id];
}

