/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5ccc. */
void __cdecl -[IODisk lockLogicalDisks](IODisk *self, SEL a2)
{
  objc_msgSend(self->_LogicalDiskLock, sel_lock); /*0x1a5ce0*/
}
