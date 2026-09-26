/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac934. */
int __cdecl -[SCSIDisk ejectPhysical](SCSIDisk *self, SEL a2)
{
  return -[SCSIDisk scsiStartStop:inhibitRetry:](self, sel_scsiStartStop_inhibitRetry_, 2, 0); /*0x1ac94d*/
}
