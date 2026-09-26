/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9f98. */
id __cdecl -[DriverCmd initPort:](DriverCmd *self, SEL a2, int a3)
{
  NXConditionLock *v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1a9fad*/
  v5.super_class = (Class)stru_1FA2E4.super_class; /*0x1a9fb6*/
  -[Object init](&v5, sel_init); /*0x1a9fbd*/
  v3 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1a9fd9*/
  self->_interLock = -[NXConditionLock initWith:](v3, sel_initWith_); /*0x1a9fe7*/
  self->_driverPort_kern = IOGetKernPort(a3); /*0x1a9ff0*/
  return self; /*0x1a9ff8*/
}
