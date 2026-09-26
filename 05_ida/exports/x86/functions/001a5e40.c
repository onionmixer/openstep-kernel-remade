/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5e40. */
int __cdecl -[IOLogicalDisk readAt:length:buffer:actualLength:client:](
        IOLogicalDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        unsigned int *a6,
        unsigned int a7)
{
  int result; // eax
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  result = -[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]( /*0x1a5e62*/
             self,
             sel__diskParamCommon_length_deviceOffset_bytesToMove_,
             a3,
             a4,
             &v9,
             &v8);
  if ( !result ) /*0x1a5e6c*/
    return (int)objc_msgSend(self->_physicalDisk, sel_readAt_length_buffer_actualLength_client_, v9, v8, a5, a6, a7); /*0x1a5e90*/
  return result; /*0x1a5e95*/
}
