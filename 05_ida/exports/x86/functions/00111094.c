/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111094. */
unsigned int __cdecl ttyecho(int a1, _BYTE *a2)
{
  unsigned __int8 v2; // bl
  int v3; // esi
  unsigned int result; // eax

  v2 = a1; /*0x11109a*/
  v3 = *(_DWORD *)a2; /*0x1110a0*/
  if ( (*(_BYTE *)(*(_DWORD *)a2 + 66) & 0x20) == 0 ) /*0x1110a6*/
    *(_DWORD *)(v3 + 60) &= ~0x800000u; /*0x1110a8*/
  result = *(_DWORD *)(v3 + 60); /*0x1110af*/
  if ( ((result & 8) != 0 || (a2[16] & 2) != 0 && a1 == 10) && (*(_BYTE *)(v3 + 66) & 0x40) == 0 ) /*0x1110c9*/
  {
    if ( (result & 0x10000000) != 0 /*0x1110e5*/
      && ((unsigned __int8)a1 <= 0x1Fu && (unsigned int)(a1 - 9) > 1 || (unsigned __int8)a1 == 127) )
    {
      ttyoutput(94, v3); /*0x1110ea*/
      if ( (unsigned __int8)a1 == 127 ) /*0x1110fb*/
      {
        v2 = 63; /*0x1110fd*/
      }
      else if ( (*(_BYTE *)(v3 + 60) & 4) != 0 ) /*0x111108*/
      {
        v2 = a1 + 96; /*0x11110a*/
      }
      else
      {
        v2 = a1 + 64; /*0x111110*/
      }
    }
    if ( v2 > 0x1Fu && ((*(_BYTE *)(v3 + 63) & 8) != 0 || (a2[18] & 0x40) != 0 || v2 <= 0x7Eu) ) /*0x11112d*/
      return ttyoutput(v2, v3); /*0x11112d*/
    result = v2 - 7; /*0x11112f*/
    if ( result <= 3 || v2 == 13 ) /*0x11113a*/
      return ttyoutput(v2, v3); /*0x11113e*/
  }
  return result; /*0x111146*/
}
