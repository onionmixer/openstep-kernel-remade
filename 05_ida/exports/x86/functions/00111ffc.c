/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111ffc. */
int __cdecl ptsstart(int a1)
{
  __int16 v1; // dx
  int result; // eax
  int v3; // ecx
  int v4; // eax

  v1 = *(_WORD *)(a1 + 56); /*0x112003*/
  result = 4 * (unsigned __int8)v1; /*0x11200a*/
  v3 = dword_1E56D4[result]; /*0x11200d*/
  if ( v1 && (*(_BYTE *)(a1 + 65) & 1) == 0 ) /*0x11201c*/
  {
    v4 = *(_DWORD *)v3; /*0x11201e*/
    if ( (*(_DWORD *)v3 & 0x10) != 0 ) /*0x112022*/
    {
      LOBYTE(v4) = v4 & 0xEF; /*0x112024*/
      *(_DWORD *)v3 = v4; /*0x112026*/
      *(_BYTE *)(v3 + 12) = 8; /*0x112028*/
    }
    return ptcwakeup(a1, 1); /*0x11202f*/
  }
  return result * 4; /*0x112034*/
}
