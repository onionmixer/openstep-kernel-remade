/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108274. */
int __cdecl entergroup(__int16 a1)
{
  int v1; // eax
  _WORD *i; // edx

  v1 = *(_DWORD *)(active_u + 28); /*0x108280*/
  for ( i = (_WORD *)(v1 + 10); (unsigned int)i < v1 + 42; ++i ) /*0x108283*/
  {
    if ( *i == a1 ) /*0x10828e*/
      return 0; /*0x108295*/
    if ( *i == 0xFFFF ) /*0x10829c*/
    {
      *i = a1; /*0x10829e*/
      return 0; /*0x1082a6*/
    }
    v1 = *(_DWORD *)(active_u + 28); /*0x1082b0*/
  }
  return -1; /*0x108294*/
}
