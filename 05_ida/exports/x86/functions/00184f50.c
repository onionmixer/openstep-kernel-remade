/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184f50. */
__int32 __cdecl vol_notify_cancel(__int16 a1)
{
  __int16 v1; // si
  _DWORD *v2; // ecx
  _UNKNOWN **v3; // ebx
  _UNKNOWN **v4; // eax

  v1 = a1 & 0xFFF8; /*0x184f59*/
  if ( !byte_1E7589 ) /*0x184f65*/
  {
    lock_init(dword_1E758C, 1); /*0x184f6e*/
    byte_1E7589 = 1; /*0x184f73*/
  }
  lock_write((int)dword_1E758C); /*0x184f82*/
  v2 = off_1E13FC; /*0x184f87*/
  if ( off_1E13FC != (_UNKNOWN *)&off_1E13FC ) /*0x184f96*/
  {
    do /*0x184fe5*/
    {
      v3 = (_UNKNOWN **)*v2; /*0x184f98*/
      if ( *((_WORD *)v2 + 6) == v1 || *((_WORD *)v2 + 7) == v1 ) /*0x184fa4*/
      {
        v4 = (_UNKNOWN **)v2[1]; /*0x184fa8*/
        if ( v3 == &off_1E13FC ) /*0x184fb1*/
          off_1E1400[0] = *((_UNKNOWN ***)v2 + 1); /*0x184fb3*/
        else
          v3[1] = v4; /*0x184fbc*/
        if ( v4 == &off_1E13FC ) /*0x184fc4*/
          off_1E13FC = v3; /*0x184fc6*/
        else
          *v4 = v3; /*0x184fd0*/
        kfree((int)v2, 0x64u); /*0x184fd5*/
      }
      v2 = v3; /*0x184fdd*/
    }
    while ( v3 != &off_1E13FC ); /*0x184fe5*/
  }
  return lock_done((int)dword_1E758C); /*0x184ff4*/
}
