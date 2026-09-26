/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a384. */
int __cdecl spec_fsync(vnop_fsync_args *a1)
{
  int v1; // ebx
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // edx
  int v10; // edx
  int v11; // ecx
  int v12; // [esp-8h] [ebp-1Ch]
  int v13; // [esp-4h] [ebp-18h]
  int v14; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]
  int v16; // [esp+20h] [ebp+Ch]

  v1 = *((_DWORD *)a1 + 12); /*0x13a390*/
  if ( (*(_BYTE *)(v1 + 64) & 0x46) == 0 && *((_DWORD *)a1 + 10) != 3 ) /*0x13a39d*/
    return 0; /*0x13a39d*/
  v15 = *(_DWORD *)(v1 + 56); /*0x13a3a2*/
  if ( !v15 ) /*0x13a3a7*/
    return 0; /*0x13a3a9*/
  v3 = (_DWORD *)kalloc(0x40u); /*0x13a3b7*/
  if ( !(*(int (__cdecl **)(_DWORD, _DWORD *, int))(*(_DWORD *)(*(_DWORD *)(v1 + 56) + 28) + 20))( /*0x13a3c8*/
          *(_DWORD *)(v1 + 56),
          v3,
          v16) )
  {
    v14 = kalloc(0x40u); /*0x13a3dc*/
    vattr_null((_BYTE *)v14); /*0x13a3e0*/
    v4 = v3[8]; /*0x13a3e8*/
    v5 = *(_DWORD *)(v1 + 76); /*0x13a3eb*/
    if ( v4 > v5 || v4 == v5 && v3[9] > *(_DWORD *)(v1 + 80) ) /*0x13a3fa*/
    {
      v6 = v3[8]; /*0x13a3fc*/
      v7 = v3[9]; /*0x13a3ff*/
    }
    else
    {
      v6 = *(_DWORD *)(v1 + 76); /*0x13a404*/
      v7 = *(_DWORD *)(v1 + 80); /*0x13a407*/
    }
    *(_DWORD *)(v14 + 32) = v6; /*0x13a40d*/
    *(_DWORD *)(v14 + 36) = v7; /*0x13a410*/
    v8 = v3[10]; /*0x13a413*/
    v9 = *(_DWORD *)(v1 + 84); /*0x13a416*/
    if ( v8 > v9 || v8 == v9 && v3[11] > *(_DWORD *)(v1 + 88) ) /*0x13a425*/
    {
      v10 = v3[10]; /*0x13a427*/
      v11 = v3[11]; /*0x13a42a*/
    }
    else
    {
      v10 = *(_DWORD *)(v1 + 84); /*0x13a430*/
      v11 = *(_DWORD *)(v1 + 88); /*0x13a433*/
    }
    *(_DWORD *)(v14 + 40) = v10; /*0x13a439*/
    *(_DWORD *)(v14 + 44) = v11; /*0x13a43c*/
    (*(void (__cdecl **)(int, int, int))(*(_DWORD *)(v15 + 28) + 24))(v15, v14, v16); /*0x13a454*/
    kfree(v14, 0x40u); /*0x13a45c*/
  }
  kfree((int)v3, 0x40u); /*0x13a467*/
  (*(void (__stdcall **)(int, int, int, int))(*(_DWORD *)(v15 + 28) + 72))(v15, v16, v12, v13); /*0x13a47d*/
  return 0; /*0x13a484*/
}
