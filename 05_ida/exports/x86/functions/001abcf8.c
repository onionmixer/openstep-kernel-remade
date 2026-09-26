/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abcf8. */
int __cdecl -[IOSCSIController reserveTarget:lun:forOwner:](
        IOSCSIController *self,
        SEL a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        id a5)
{
  return -[IOSCSIController reserveSCSI3Target:lun:forOwner:]( /*0x1abd20*/
           self,
           sel_reserveSCSI3Target_lun_forOwner_,
           a3,
           0,
           a4,
           0,
           a5);
}
