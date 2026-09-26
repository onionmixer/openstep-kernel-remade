/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139894. */
int __cdecl sunsave(int a1)
{
  _DWORD *v1; // ebx
  int result; // eax
  int v3; // ecx

  v1 = nullptr; /*0x13989c*/
  result = (*(_BYTE *)(a1 + 66) + *(_BYTE *)(a1 + 67)) & 0xF; /*0x1398a8*/
  v3 = stable[result]; /*0x1398ab*/
  if ( v3 ) /*0x1398b4*/
  {
    while ( v3 != a1 ) /*0x1398ba*/
    {
      v1 = (_DWORD *)v3; /*0x1398e0*/
      v3 = *(_DWORD *)v3; /*0x1398e2*/
      if ( !v3 ) /*0x1398e6*/
        return result; /*0x1398e6*/
    }
    if ( v1 ) /*0x1398be*/
    {
      *v1 = *(_DWORD *)v3; /*0x1398da*/
    }
    else
    {
      result = (*(_BYTE *)(v3 + 66) + *(_BYTE *)(v3 + 67)) & 0xF; /*0x1398ca*/
      stable[result] = *(_DWORD *)v3; /*0x1398cf*/
    }
  }
  return result; /*0x1398eb*/
}
