/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fbc4. */
id __cdecl -[KernBusInterrupt initForResource:item:withHandler:shareable:](
        KernBusInterrupt *self,
        SEL a2,
        id a3,
        unsigned int a4,
        void *a5,
        char a6)
{
  List *v6; // eax
  KernLock *v7; // eax
  KernLock *v8; // eax
  int (__cdecl *v9)(int, int); // eax
  objc_super v11; // [esp+8h] [ebp-8h] BYREF

  v11.receiver = self; /*0x17fbe5*/
  v11.super_class = (Class)stru_1F9F24.ext; /*0x17fbee*/
  -[KernBusItem initForResource:item:shareable:](&v11, sel_initForResource_item_shareable_, a3, a4, a6); /*0x17fbf5*/
  v6 = +[Object alloc](aList, sel_alloc); /*0x17fc0f*/
  self->_attachedInterrupts = -[List init](v6, sel_init); /*0x17fc1d*/
  v7 = +[Object alloc](aKernlock, sel_alloc); /*0x17fc35*/
  self->_interruptLock = -[KernLock init](v7, sel_init); /*0x17fc43*/
  v8 = +[Object alloc](aKernlock, sel_alloc); /*0x17fc5e*/
  self->_suspendLock = -[KernLock init](v8, sel_init); /*0x17fc6c*/
  self->_deviceHandler = a5; /*0x17fc72*/
  if ( !a5 ) /*0x17fc77*/
  {
    v9 = KernDeviceInterruptDispatch; /*0x17fc79*/
    if ( a6 ) /*0x17fc80*/
      v9 = KernDeviceInterruptDispatchShared; /*0x17fc82*/
    self->_deviceHandler = v9; /*0x17fc87*/
  }
  return self; /*0x17fc8f*/
}
