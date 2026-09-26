/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bab5c. */
id __cdecl -[AudioCommand initPort:](AudioCommand *self, SEL a2, int a3)
{
  NXConditionLock *v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1bab71*/
  v5.super_class = (Class)stru_1FA514.ext; /*0x1bab7a*/
  -[Object init](&v5, sel_init); /*0x1bab81*/
  v3 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1bab9d*/
  self->interLock = -[NXConditionLock initWith:](v3, sel_initWith_); /*0x1babab*/
  self->driverPort_kern = a3; /*0x1babae*/
  return self; /*0x1babb6*/
}
