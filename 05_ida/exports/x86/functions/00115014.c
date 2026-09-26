/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115014. */
int __cdecl sodisconnect(int a1)
{
  int v1; // esi
  __int16 v2; // ax
  int v3; // ebx

  v1 = splnet(); /*0x115021*/
  v2 = *(_WORD *)(a1 + 6); /*0x115023*/
  if ( (v2 & 2) != 0 ) /*0x115029*/
  {
    if ( (v2 & 8) != 0 ) /*0x115036*/
      v3 = 37; /*0x115038*/
    else
      v3 = (*(int (__cdecl **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 6, 0, 0, 0); /*0x115051*/
  }
  else
  {
    v3 = 57; /*0x11502b*/
  }
  splx(v1); /*0x115057*/
  return v3; /*0x115061*/
}
