/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5cec. */
void __cdecl -[IODisk unlockLogicalDisks](IODisk *self, SEL a2)
{
  objc_msgSend(self->_LogicalDiskLock, sel_unlock); /*0x1a5d00*/
}
