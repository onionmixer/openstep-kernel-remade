/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192ba0. */
int __cdecl _i386_backtrace(_DWORD *a1, int a2)
{
  int v3; // esi
  int result; // eax

  v3 = 0; /*0x192bac*/
  if ( a2 > 0 ) /*0x192bb0*/
  {
    while ( (unsigned int)a1 <= 0x40000000 ) /*0x192bba*/
    {
      safe_prf("frame %x called by %x ", a1, a1[1]); /*0x192bc6*/
      safe_prf("args %x %x %x %x\n", a1[2], a1[3], a1[4], a1[5]); /*0x192be0*/
      if ( *a1 < (unsigned int)a1 ) /*0x192bec*/
        break; /*0x192bec*/
      result = (*a1 - (int)a1) >> 3; /*0x192bf2*/
      if ( result > 0x10000 ) /*0x192bfa*/
        break; /*0x192bfa*/
      a1 = (_DWORD *)*a1; /*0x192bfc*/
      if ( ++v3 >= a2 ) /*0x192c01*/
        return result; /*0x192c01*/
    }
    return (int)safe_prf("invalid frame pointer %x\n", *a1); /*0x192c10*/
  }
  return result; /*0x192c18*/
}
