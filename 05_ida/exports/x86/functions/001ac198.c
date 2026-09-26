/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac198. */
int __cdecl -[IOSCSIController setIntValues:forParameter:count:](
        IOSCSIController *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  objc_super v6; // [esp+Ch] [ebp-8h] BYREF

  if ( !strcmp(a4, "IOSCSIControllerStatistics") ) /*0x1ac1b6*/
  {
    -[IOSCSIController resetStats](self, sel_resetStats); /*0x1ac1c2*/
    return 0; /*0x1ac1c7*/
  }
  else
  {
    v6.receiver = self; /*0x1ac1dc*/
    v6.super_class = (Class)stru_1FA334.ext; /*0x1ac1e5*/
    return -[IODevice setIntValues:forParameter:count:](&v6, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1ac1ec*/
  }
}
