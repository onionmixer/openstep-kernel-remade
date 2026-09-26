/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbef8. */
char *__cdecl NXCopyStringBuffer(const char *buffer)
{
  void *v1; // eax
  int v3; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v1 = (void *)NXDefaultMallocZone(v3, savedregs); /*0x1cbeff*/
  return NXCopyStringBufferFromZone(buffer, v1); /*0x1cbf0b*/
}
