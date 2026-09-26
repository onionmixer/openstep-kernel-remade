/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11203c. */
int __cdecl ptcwakeup(int a1, char a2)
{
  __int16 v2; // dx
  int result; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int v6; // edx
  int v7; // esi
  int v8; // edx

  v2 = *(_WORD *)(a1 + 56); /*0x112045*/
  result = 16 * (unsigned __int8)v2; /*0x11204c*/
  v4 = *(_DWORD **)((char *)dword_1E56D4 + result); /*0x11204f*/
  if ( v2 ) /*0x112058*/
  {
    if ( (a2 & 1) != 0 ) /*0x112064*/
    {
      v5 = spltty(); /*0x11206b*/
      v6 = v4[1]; /*0x11206d*/
      if ( v6 ) /*0x112072*/
      {
        selwakeup(v6, *v4 & 1); /*0x11207b*/
        selthreadclear(v4 + 1); /*0x112084*/
        *v4 &= ~1u; /*0x112089*/
      }
      splx(v5); /*0x112090*/
      result = wakeup(a1 + 28); /*0x112099*/
    }
    if ( (a2 & 2) != 0 ) /*0x1120a7*/
    {
      v7 = spltty(); /*0x1120ae*/
      v8 = v4[2]; /*0x1120b0*/
      if ( v8 ) /*0x1120b5*/
      {
        selwakeup(v8, *v4 & 2); /*0x1120be*/
        selthreadclear(v4 + 2); /*0x1120c7*/
        *v4 &= ~2u; /*0x1120cc*/
      }
      splx(v7); /*0x1120d3*/
      return wakeup(a1 + 4); /*0x1120dc*/
    }
  }
  return result; /*0x1120e4*/
}
