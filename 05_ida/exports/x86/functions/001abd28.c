/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1abd28. */
void __cdecl -[IOSCSIController releaseTarget:lun:forOwner:](
        IOSCSIController *self,
        SEL a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        id a5)
{
  -[IOSCSIController releaseSCSI3Target:lun:forOwner:](self, sel_releaseSCSI3Target_lun_forOwner_, a3, 0, a4, 0, a5); /*0x1abd49*/
}
