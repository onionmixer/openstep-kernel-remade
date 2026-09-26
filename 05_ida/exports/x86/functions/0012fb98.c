/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fb98. */
void __cdecl rflush(int a1)
{
  int *i; // esi
  int j; // ebx
  int v3; // eax

  for ( i = rtable; i < (int *)unixauthtab; ++i ) /*0x12fbac*/
  {
    for ( j = *i; j; j = *(_DWORD *)(j + 8) ) /*0x12fbb0*/
    {
      if ( *(char *)(j + 16) >= 0 ) /*0x12fbbf*/
      {
        v3 = *(_DWORD *)(j + 48); /*0x12fbc1*/
        if ( (*(_BYTE *)(v3 + 12) & 1) == 0 && (!a1 || v3 == a1) ) /*0x12fbd0*/
          sync_vp(j + 12); /*0x12fbd3*/
      }
    }
  }
}
