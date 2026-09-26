/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0d20. */
void *__cdecl -[IODirectDevice createDMABufferFor:length:read:needsLowMemory:limitSize:](
        IODirectDevice *self,
        SEL a2,
        unsigned int *a3,
        unsigned int a4,
        char a5,
        char a6,
        char a7)
{
  int v7; // eax
  void *v8; // ebx

  v7 = IOMalloc(0x18u); /*0x1c0d3f*/
  v8 = (void *)v7; /*0x1c0d44*/
  if ( !v7 ) /*0x1c0d4b*/
    return nullptr; /*0x1c0d4d*/
  *(_DWORD *)v7 = *a3; /*0x1c0d56*/
  *(_DWORD *)(v7 + 4) = a4; /*0x1c0d5b*/
  *(_BYTE *)(v7 + 20) = (32 * (a7 & 1)) | (16 * (a6 & 1)) & 0xDD | (8 * (a5 & 1)) & 0xCD | *(_BYTE *)(v7 + 20) & 0xC5; /*0x1c0d8a*/
  if ( dma_xfer(v7, a3) ) /*0x1c0d8f*/
    return v8; /*0x1c0da8*/
  IOFree((int)v8, 24); /*0x1c0d9e*/
  return nullptr; /*0x1c0dad*/
}
