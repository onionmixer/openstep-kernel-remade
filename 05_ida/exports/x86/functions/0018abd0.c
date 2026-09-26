/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18abd0. */
const segment_command *sub_18ABD0()
{
  const segment_command *result; // eax
  int v1; // esi
  int i; // ebx

  result = getsegbyname(segname); /*0x18abda*/
  v1 = (int)result; /*0x18abdf*/
  if ( result ) /*0x18abe6*/
  {
    result = (const segment_command *)firstsect((int)result); /*0x18abe9*/
    for ( i = (int)result; result; i = (int)result ) /*0x18abf5*/
    {
      if ( (*(_BYTE *)(i + 56) & 1) != 0 ) /*0x18abfc*/
        bzero(*(void **)(i + 32), *(_DWORD *)(i + 36)); /*0x18ac06*/
      result = (const segment_command *)nextsect(v1, i); /*0x18ac10*/
    }
  }
  return result; /*0x18ac21*/
}
