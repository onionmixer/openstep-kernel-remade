/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141e70. */
int __cdecl iflush(__int16 a1)
{
  int v1; // ecx
  int i; // edx

  v1 = 0; /*0x141e7a*/
  for ( i = inode_list; i; i = *(_DWORD *)(i + 8) ) /*0x141e84*/
  {
    if ( *(_WORD *)(i + 70) == a1 ) /*0x141e90*/
    {
      if ( (*(_BYTE *)(i + 69) & 1) != 0 ) /*0x141e96*/
      {
        v1 = -1; /*0x141e98*/
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)i + 4) = *(_DWORD *)(i + 4); /*0x141ea5*/
        **(_DWORD **)(i + 4) = *(_DWORD *)i; /*0x141ead*/
        *(_DWORD *)i = i; /*0x141eaf*/
        *(_DWORD *)(i + 4) = i; /*0x141eb1*/
      }
    }
    else if ( (*(_BYTE *)(i + 69) & 1) != 0 /*0x141ed6*/
           && (*(_WORD *)(i + 100) & 0xF000) == 0x6000
           && *(_DWORD *)(i + 140) == a1
           && v1 >= 0 )
    {
      ++v1; /*0x141ed8*/
    }
  }
  return v1; /*0x141ee5*/
}
