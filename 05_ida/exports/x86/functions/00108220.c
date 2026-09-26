/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108220. */
unsigned int __cdecl leavegroup(__int16 a1)
{
  int v1; // eax
  _WORD *v2; // edx
  unsigned int result; // eax

  v1 = *(_DWORD *)(active_u + 28); /*0x10822d*/
  v2 = (_WORD *)(v1 + 10); /*0x108230*/
  result = v1 + 42; /*0x108233*/
  if ( (unsigned int)v2 < result ) /*0x108238*/
  {
    while ( *v2 != a1 ) /*0x10823f*/
    {
      if ( (unsigned int)++v2 >= result ) /*0x108246*/
        return result; /*0x108246*/
    }
    while ( 1 ) /*0x10825e*/
    {
      result = *(_DWORD *)(active_u + 28) + 40; /*0x10825e*/
      if ( (unsigned int)v2 >= result ) /*0x108263*/
        break; /*0x108263*/
      *v2 = v2[1]; /*0x108250*/
      ++v2; /*0x108253*/
    }
    *v2 = -1; /*0x108265*/
  }
  return result; /*0x10826a*/
}
