/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c010. */
int __cdecl logioctl(int a1, int *a2)
{
  int v2; // eax
  int v3; // ebx

  if ( a1 == -2147191690 )
  {
    dword_1E97C8 = *a2; /*0x10c0ae*/
  }
  else if ( a1 > -2147191690 )
  {
    if ( a1 == 1074030207 )
    {
      v2 = splhigh(); /*0x10c04c*/
      v3 = *(_DWORD *)(pmsgbuf + 4) - *(_DWORD *)(pmsgbuf + 8); /*0x10c05b*/
      splx(v2); /*0x10c05f*/
      *a2 = v3 + (v3 < 0 ? 0xFF4 : 0);
    }
    else
    {
      if ( a1 != 1074033783 ) /*0x10c048*/
        return -1; /*0x10c048*/
      *a2 = dword_1E97C8; /*0x10c0be*/
    }
  }
  else if ( a1 == -2147195267 ) /*0x10c02d*/
  {
    if ( *a2 ) /*0x10c090*/
      LOBYTE(logsoftc) = logsoftc | 4; /*0x10c095*/
    else
      logsoftc &= ~4u; /*0x10c0a0*/
  }
  else
  {
    if ( a1 != -2147195266 ) /*0x10c034*/
      return -1; /*0x10c0c9*/
    if ( *a2 ) /*0x10c074*/
      LOBYTE(logsoftc) = logsoftc | 2; /*0x10c079*/
    else
      logsoftc &= ~2u; /*0x10c084*/
  }
  return 0; /*0x10c0d1*/
}
