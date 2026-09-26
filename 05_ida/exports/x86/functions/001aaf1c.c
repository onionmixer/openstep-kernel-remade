/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aaf1c. */
id __cdecl -[DriverCmdtr initPort:](DriverCmdtr *self, SEL a2, int a3)
{
  NXConditionLock *v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1aaf31*/
  v5.super_class = (Class)stru_1FA334.super_class; /*0x1aaf3a*/
  -[Object init](&v5, sel_init); /*0x1aaf41*/
  v3 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1aaf5d*/
  self->_interLock = -[NXConditionLock initWith:](v3, sel_initWith_); /*0x1aaf6b*/
  self->_driverPort_kern = IOGetKernPort(a3); /*0x1aaf74*/
  return self; /*0x1aaf7c*/
}
