/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cf98. */
int __cdecl exportfree(int a1)
{
  int v1; // eax
  int v2; // eax

  if ( *(_DWORD *)(a1 + 8) == 1 ) /*0x12cfa6*/
  {
    v1 = *(_DWORD *)(a1 + 12); /*0x12cfa8*/
    if ( v1 ) /*0x12cfad*/
      kfree(*(_DWORD *)(a1 + 16), 16 * v1); /*0x12cfb7*/
  }
  if ( (*(_BYTE *)a1 & 2) != 0 ) /*0x12cfc2*/
  {
    v2 = *(_DWORD *)(a1 + 24); /*0x12cfc4*/
    if ( v2 ) /*0x12cfc9*/
      kfree(*(_DWORD *)(a1 + 28), 16 * v2); /*0x12cfd3*/
  }
  kfree(*(_DWORD *)(a1 + 40), **(unsigned __int16 **)(a1 + 40) + 2); /*0x12cfe6*/
  return kfree(a1, 0x30u); /*0x12cff6*/
}
