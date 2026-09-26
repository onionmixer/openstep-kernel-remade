/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a58c0. */
void __cdecl -[IODisk addToBytesRead:totalTime:latentTime:](
        IODisk *self,
        SEL a2,
        unsigned int a3,
        unsigned __int64 a4,
        unsigned __int64 a5)
{
  ++self->_readOps; /*0x1a58cf*/
  self->_bytesRead += a3; /*0x1a58d8*/
  self->_readTotalTime += a4 / 0xF4240; /*0x1a58f5*/
  self->_readLatentTime += a5 / 0xF4240; /*0x1a5909*/
}
