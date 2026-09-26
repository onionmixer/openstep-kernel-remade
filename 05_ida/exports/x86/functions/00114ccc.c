/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114ccc. */
int __cdecl solisten(int a1, int a2)
{
  int v2; // edi
  int v3; // esi
  __int16 v5; // ax
  int v6; // [esp+Ch] [ebp-4h]

  v2 = a2; /*0x114cd8*/
  v6 = splnet(); /*0x114ce0*/
  v3 = (*(int (__cdecl **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 3, 0, 0, 0); /*0x114cf4*/
  if ( v3 ) /*0x114cfb*/
  {
    splx(v6); /*0x114d01*/
    return v3; /*0x114d06*/
  }
  else
  {
    if ( !*(_DWORD *)(a1 + 28) ) /*0x114d0c*/
    {
      *(_DWORD *)(a1 + 28) = a1; /*0x114d12*/
      *(_DWORD *)(a1 + 20) = a1; /*0x114d15*/
      *(_BYTE *)(a1 + 2) |= 2u; /*0x114d18*/
    }
    if ( a2 < 0 ) /*0x114d1e*/
      v2 = 0; /*0x114d20*/
    v5 = v2; /*0x114d22*/
    if ( v2 > 128 ) /*0x114d29*/
      v5 = 128; /*0x114d2b*/
    *(_WORD *)(a1 + 34) = v5; /*0x114d30*/
    splx(v6); /*0x114d38*/
    return 0; /*0x114d3d*/
  }
}
