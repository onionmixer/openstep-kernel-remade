/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16df30. */
int __cdecl exc_server(_DWORD *a1, int a2)
{
  *(_BYTE *)(a2 + 3) = 1; /*0x16df3a*/
  *(_DWORD *)(a2 + 4) = 32; /*0x16df3e*/
  *(_DWORD *)(a2 + 8) = a1[2]; /*0x16df48*/
  *(_DWORD *)(a2 + 12) = 0; /*0x16df4b*/
  *(_DWORD *)(a2 + 16) = a1[4]; /*0x16df55*/
  *(_DWORD *)(a2 + 20) = a1[5] + 100; /*0x16df5e*/
  *(_DWORD *)(a2 + 24) = 268509186; /*0x16df67*/
  *(_DWORD *)(a2 + 28) = -303; /*0x16df6a*/
  if ( a1[5] != 2400 || !sub_16DF98 ) /*0x16df82*/
    return 0; /*0x16df84*/
  sub_16DF98(a1, a2); /*0x16df8a*/
  return 1; /*0x16df91*/
}
