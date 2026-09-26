/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1437b0. */
int __cdecl sub_1437B0(int a1)
{
  int v1; // ebx
  int v2; // edi
  int v4; // esi
  int v5; // eax
  _BOOL4 v6; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 296); /*0x1437bc*/
  v2 = iflush(*(_WORD *)(v1 + 4)); /*0x1437cc*/
  if ( v2 < 0 ) /*0x1437d3*/
    return 16; /*0x1437df*/
  v4 = *(_DWORD *)(*(_DWORD *)(v1 + 12) + 32); /*0x1437ef*/
  v6 = *(_BYTE *)(v4 + 210) == 0; /*0x143801*/
  if ( !*(_BYTE *)(v4 + 210) && *(_BYTE *)(v4 + 209) == 2 ) /*0x14380f*/
  {
    *(_BYTE *)(v4 + 209) = 1; /*0x143811*/
    sbupdate(v1); /*0x143819*/
  }
  kfree(*(_DWORD *)(v4 + 728), *(_DWORD *)(v4 + 156)); /*0x14382f*/
  brelse(*(_DWORD *)(v1 + 12)); /*0x143838*/
  *(_DWORD *)(v1 + 12) = 0; /*0x14383d*/
  *(_WORD *)(v1 + 4) = 0; /*0x143844*/
  if ( !v2 ) /*0x14384f*/
  {
    (*(void (__cdecl **)(_DWORD, _BOOL4, int, _DWORD))(*(_DWORD *)(*(_DWORD *)(v1 + 8) + 28) + 4))( /*0x143870*/
      *(_DWORD *)(v1 + 8),
      v6,
      1,
      *(_DWORD *)(active_u + 28));
    binval(*(_DWORD *)(v1 + 8)); /*0x143876*/
    vn_rele(*(_DWORD *)(v1 + 8)); /*0x14387f*/
    *(_DWORD *)(v1 + 8) = 0; /*0x143884*/
    v5 = mounttab; /*0x14388b*/
    if ( v1 == mounttab ) /*0x143895*/
    {
      mounttab = *(_DWORD *)(v1 + 32); /*0x14389a*/
    }
    else
    {
      while ( v5 ) /*0x1438b4*/
      {
        if ( *(_DWORD *)(v5 + 32) == v1 ) /*0x1438a7*/
          *(_DWORD *)(v5 + 32) = *(_DWORD *)(v1 + 32); /*0x1438ac*/
        v5 = *(_DWORD *)(v5 + 32); /*0x1438af*/
      }
    }
    kfree(v1, 0x24u); /*0x1438b9*/
  }
  return 0; /*0x1438c3*/
}
