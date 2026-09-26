/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5ef8. */
int __cdecl -[IOLogicalDisk writeAt:length:buffer:actualLength:client:](
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

  if ( -[IODisk isWriteProtected](self, sel_isWriteProtected) ) /*0x1a5f0a*/
    return -719; /*0x1a5f16*/
  result = -[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]( /*0x1a5f38*/
             self,
             sel__diskParamCommon_length_deviceOffset_bytesToMove_,
             a3,
             a4,
             &v9,
             &v8);
  if ( !result ) /*0x1a5f42*/
    return (int)objc_msgSend(self->_physicalDisk, sel_writeAt_length_buffer_actualLength_client_, v9, v8, a5, a6, a7); /*0x1a5f66*/
  return result; /*0x1a5f6b*/
}
