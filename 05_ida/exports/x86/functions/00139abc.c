/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139abc. */
int __cdecl smark(int a1, __int16 a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h]

  result = microtime(&v6); /*0x139ace*/
  *(_WORD *)(a1 + 64) |= a2; /*0x139ad3*/
  if ( (a2 & 4) != 0 ) /*0x139ada*/
  {
    v3 = v7; /*0x139adf*/
    *(_DWORD *)(a1 + 76) = v6; /*0x139ae2*/
    *(_DWORD *)(a1 + 80) = v3; /*0x139ae5*/
  }
  if ( (a2 & 2) != 0 ) /*0x139aeb*/
  {
    v4 = v7; /*0x139af0*/
    *(_DWORD *)(a1 + 84) = v6; /*0x139af3*/
    *(_DWORD *)(a1 + 88) = v4; /*0x139af6*/
  }
  if ( (a2 & 0x40) != 0 ) /*0x139afc*/
  {
    v5 = v7; /*0x139b01*/
    *(_DWORD *)(a1 + 92) = v6; /*0x139b04*/
    *(_DWORD *)(a1 + 96) = v5; /*0x139b07*/
  }
  return result; /*0x139b0d*/
}
