/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ddec. */
int __usercall forceclose@<eax>(int result@<eax>, __int16 a2)
{
  int i; // edx
  int v3; // ecx

  for ( i = file_list; (int *)i != &file_list; i = *(_DWORD *)i ) /*0x11de00*/
  {
    if ( *(_WORD *)(i + 14) ) /*0x11de04*/
    {
      if ( *(_WORD *)(i + 12) == 1 ) /*0x11de10*/
      {
        v3 = *(_DWORD *)(i + 24); /*0x11de12*/
        if ( v3 ) /*0x11de17*/
        {
          result = *(_DWORD *)(v3 + 40); /*0x11de19*/
          if ( (result == 4 || result == 9) && *(_WORD *)(v3 + 44) == a2 ) /*0x11de2a*/
            *(_DWORD *)(i + 8) &= 0xFFFFFFFC; /*0x11de2c*/
        }
      }
    }
  }
  return result; /*0x11de3a*/
}
