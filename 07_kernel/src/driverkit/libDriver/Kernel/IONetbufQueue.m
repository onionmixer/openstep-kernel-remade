/*
 * IONetbufQueue.m (plan 300).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original module "Kernel/IONetbufQueue.m", methods 0x1a9968-0x1a9ad2).
 * The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/IONetbufQueue.m; kept as project-authored
 * under D027/D030, without Darwin's notices (license judgement: D017).
 */

#ifdef	KERNEL

#import <driverkit/IONetbufQueue.h>

@implementation IONetbufQueue

- init
{
    return [self initWithMaxCount:16];
}

- initWithMaxCount:(unsigned)maxCount
{
    [super init];

    _queueHead = _queueTail = 0;
    _queueCount = 0; _maxCount = maxCount;
    
    return self;
}

- free
{
    netbuf_t	nb;
    
    while (nb = [self dequeue])
    	nb_free(nb);
	
    return [super free];
}

- (unsigned)count
{
    return (_queueCount);
}

- (unsigned)maxCount
{
    return (_maxCount);
}

- (void)enqueue:(netbuf_t)nb
{
    struct _queueEntry	*qe = (struct _queueEntry *)nb;

    if (_queueCount < _maxCount) {
    	if (_queueCount++ > 0) {
	    _queueTail->_next = qe; _queueTail = qe;
	}
	else
	    _queueHead = _queueTail = qe;

    	qe->_next = 0;
    }
    else
    	nb_free(nb);
}

- (netbuf_t)dequeue
{
    struct _queueEntry	*qe;

    if (_queueCount > 0) {
    	qe = _queueHead; _queueHead = qe->_next;
	if (--_queueCount == 0)
	    _queueHead = _queueTail = 0;
	    
	qe->_next = 0;
    }
    else
    	qe = 0;
	
    return ((netbuf_t)qe);
}

@end

#endif	KERNEL
