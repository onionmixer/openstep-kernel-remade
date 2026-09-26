/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a800. */
unsigned __int32 __cdecl fp_terminate(int a1)
{
  unsigned __int32 result; // eax

  result = dword_1E75F8; /*0x18a803*/
  if ( a1 == dword_1E75F8 ) /*0x18a80b*/
  {
    dword_1E75F8 = 0; /*0x18a80d*/
    result = __readcr0(); /*0x18a817*/
    LOBYTE(result) = result | 8; /*0x18a81a*/
    __writecr0(result); /*0x18a81c*/
  }
  return result; /*0x18a821*/
}
