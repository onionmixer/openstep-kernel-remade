/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174848. */
int __cdecl vm_map_insert(_DWORD *a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  int v6; // esi
  _DWORD *v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-4h] BYREF

  if ( a1[5] > a4 || a1[6] < a5 || a4 >= a5 ) /*0x174867*/
    return 1; /*0x174869*/
  if ( vm_map_lookup_entry(a1, a4, &v12) ) /*0x17487d*/
    return 3; /*0x17487d*/
  v6 = v12; /*0x174889*/
  v7 = *(_DWORD **)(v12 + 4); /*0x17488f*/
  if ( v7 != a1 + 3 && v7[2] < a5 ) /*0x17489c*/
    return 3; /*0x17489e*/
  if ( !a2 /*0x1748f5*/
    && (_DWORD *)v12 != a1 + 3
    && *(_DWORD *)(v12 + 12) == a4
    && (*(_BYTE *)(v12 + 24) & 5) == 0
    && *(_DWORD *)(v12 + 36) == 1
    && *(_DWORD *)(v12 + 28) == 3
    && *(_DWORD *)(v12 + 32) == 7
    && !*(_WORD *)(v12 + 40)
    && vm_object_coalesce(*(_DWORD *)(v12 + 16), 0, *(_DWORD *)(v12 + 20), 0, a4 - *(_DWORD *)(v12 + 8), a5 - a4) )
  {
    a1[10] += a5 - *(_DWORD *)(v6 + 12); /*0x174907*/
    *(_DWORD *)(v6 + 12) = a5; /*0x17490d*/
  }
  else
  {
    if ( a1[8] ) /*0x174918*/
      v8 = vm_map_entry_zone; /*0x17491e*/
    else
      v8 = vm_map_kentry_zone; /*0x174928*/
    v9 = zalloc(v8); /*0x17492e*/
    v10 = v9; /*0x174933*/
    if ( !v9 ) /*0x17493a*/
      panic(aVmMapEntryCrea); /*0x174941*/
    *(_DWORD *)(v9 + 8) = a4; /*0x17494b*/
    *(_DWORD *)(v9 + 12) = a5; /*0x174951*/
    *(_BYTE *)(v9 + 24) &= 0xFAu; /*0x174954*/
    *(_DWORD *)(v9 + 16) = a2; /*0x17495b*/
    *(_DWORD *)(v9 + 20) = a3; /*0x174961*/
    *(_BYTE *)(v9 + 24) &= 0xB7u; /*0x174964*/
    if ( a1[11] ) /*0x174968*/
    {
      *(_DWORD *)(v9 + 36) = 1; /*0x17496e*/
      *(_DWORD *)(v9 + 28) = 3; /*0x174975*/
      *(_DWORD *)(v9 + 32) = 7; /*0x17497c*/
      *(_WORD *)(v9 + 40) = 0; /*0x174983*/
    }
    ++a1[7]; /*0x174989*/
    *(_DWORD *)v9 = v6; /*0x17498c*/
    *(_DWORD *)(v9 + 4) = *(_DWORD *)(v6 + 4); /*0x174991*/
    v11 = *(_DWORD *)v9; /*0x174994*/
    **(_DWORD **)(v10 + 4) = v10; /*0x174999*/
    *(_DWORD *)(v11 + 4) = v10; /*0x17499b*/
    a1[10] += *(_DWORD *)(v10 + 12) - *(_DWORD *)(v10 + 8); /*0x1749a4*/
    if ( a1[16] == v6 && *(_DWORD *)(v6 + 12) >= *(_DWORD *)(v10 + 8) ) /*0x1749b2*/
      a1[16] = v10; /*0x1749b4*/
  }
  return 0; /*0x1749bc*/
}
