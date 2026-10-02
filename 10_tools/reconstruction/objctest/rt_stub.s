# rt_stub.s -- stand-ins for the ObjC runtime symbols the T-ObjC objects use.
	.text
	.globl	_objc_msgSend
_objc_msgSend:
	ret
	.data
	.globl	.objc_class_name_Object
.objc_class_name_Object:
	.long	0
