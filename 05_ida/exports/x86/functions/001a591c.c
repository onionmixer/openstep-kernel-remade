/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a591c. */
void __cdecl -[IODisk addToBytesWritten:totalTime:latentTime:](
        IODisk *self,
        SEL a2,
        unsigned int a3,
        unsigned __int64 a4,
        unsigned __int64 a5)
{
  ++self->_writeOps; /*0x1a592b*/
  self->_bytesWritten += a3; /*0x1a5934*/
  self->_writeTotalTime += a4 / 0xF4240; /*0x1a5951*/
  self->_writeLatentTime += a5 / 0xF4240; /*0x1a5965*/
}
