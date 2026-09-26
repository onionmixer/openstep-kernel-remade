/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cd18. */
int __cdecl findexivp(_DWORD *a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3; /*0x12cd24*/
  ++*(_WORD *)(a3 + 6); /*0x12cd27*/
  if ( a2 ) /*0x12cd30*/
    ++*(_WORD *)(a2 + 6); /*0x12cd32*/
  while ( 1 ) /*0x12cd45*/
  {
    v4 = (*(int (__cdecl **)(int, int *))(*(_DWORD *)(v3 + 28) + 100))(v3, &v6); /*0x12cd45*/
    if ( v4 ) /*0x12cd4c*/
      break; /*0x12cd4c*/
    *a1 = findexport((void *)(*(_DWORD *)(v3 + 36) + 20), v6); /*0x12cd62*/
    kfree(v6, *(unsigned __int16 *)v6 + 2); /*0x12cd6f*/
    if ( *a1 ) /*0x12cd77*/
      break; /*0x12cd77*/
    if ( (*(_BYTE *)(v3 + 4) & 1) != 0 ) /*0x12cd80*/
    {
      v4 = 22; /*0x12cd82*/
      break; /*0x12cd87*/
    }
    if ( !a2 ) /*0x12cd90*/
    {
      v4 = (*(int (__cdecl **)(int, void *, int *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(v3 + 28) + 32))( /*0x12cdb1*/
             v3,
             &unk_1DBF5C,
             &a2,
             *(_DWORD *)(active_u + 28),
             0,
             0);
      if ( v4 ) /*0x12cdb8*/
        break; /*0x12cdb8*/
    }
    vn_rele(v3); /*0x12cdbb*/
    v3 = a2; /*0x12cdc0*/
    a2 = 0; /*0x12cdc3*/
  }
  vn_rele(v3); /*0x12cdd4*/
  if ( a2 ) /*0x12cde2*/
    vn_rele(a2); /*0x12cde5*/
  return v4; /*0x12cdef*/
}
