/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180648. */
KernDeviceInterrupt *__cdecl -[KernDeviceInterrupt initWithInterruptPort:](KernDeviceInterrupt *self, SEL a2, void *a3)
{
  KernLock *v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v5.receiver = self; /*0x18065d*/
  v5.super_class = (Class)stru_1F9F74.super_class; /*0x180666*/
  -[Object init](&v5, sel_init); /*0x18066d*/
  v3 = +[Object alloc](aKernlock, sel_alloc); /*0x180689*/
  self->_lock = -[KernLock initWithLevel:](v3, sel_initWithLevel_); /*0x180697*/
  self->_ipcMessage = sub_17FFD8((int)a3); /*0x1806a0*/
  return self; /*0x1806a8*/
}
