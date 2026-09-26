/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5e9c. */
int __cdecl -[IOLogicalDisk readAsyncAt:length:buffer:pending:client:](
        IOLogicalDisk *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        char *a5,
        void *a6,
        unsigned int a7)
{
  int result; // eax
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h] BYREF

  result = -[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]( /*0x1a5ebe*/
             self,
             sel__diskParamCommon_length_deviceOffset_bytesToMove_,
             a3,
             a4,
             &v9,
             &v8);
  if ( !result ) /*0x1a5ec8*/
    return (int)objc_msgSend(self->_physicalDisk, sel_readAsyncAt_length_buffer_pending_client_, v9, v8, a5, a6, a7); /*0x1a5eec*/
  return result; /*0x1a5ef1*/
}
