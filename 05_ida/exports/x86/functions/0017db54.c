/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17db54. */
__int32 __cdecl vnode_pager_truncate(unsigned int a1)
{
  __int32 result; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-48h]
  _DWORD *v9; // [esp+10h] [ebp-44h]
  _BYTE v10[24]; // [esp+14h] [ebp-40h] BYREF
  int v11; // [esp+2Ch] [ebp-28h]

  result = (unsigned __int8)a1; /*0x17db60*/
  v2 = dword_1E7294[(unsigned __int8)a1]; /*0x17db63*/
  v9 = *(_DWORD **)(v2 + 8); /*0x17db6d*/
  if ( *(_DWORD *)(v2 + 32) <= (signed int)(a1 >> 8) && !swapfs_enabled )
  {
    lock_write(v2 + 52); /*0x17db8f*/
    v3 = (a1 >> 8) - 1; /*0x17db94*/
    if ( v3 >= 0 ) /*0x17db9a*/
    {
      while ( 1 ) /*0x17dbad*/
      {
        v4 = *(char *)(v3 / 8 + *(_DWORD *)(v2 + 16)); /*0x17dbad*/
        if ( _bittest(&v4, v3 % 8) ) /*0x17dbbb*/
          break; /*0x17dbbb*/
        if ( --v3 < 0 ) /*0x17dbbe*/
          goto LABEL_6; /*0x17dbbe*/
      }
      *(_DWORD *)(v2 + 32) = v3; /*0x17dbf4*/
    }
LABEL_6:
    v5 = *(_DWORD *)(v2 + 32) + 1; /*0x17dbc0*/
    v6 = *(_DWORD *)(v2 + 28); /*0x17dbc7*/
    if ( v6 && v5 > v6 && *(_DWORD *)(*v9 + 20) >= (unsigned int)(v5 << page_shift) )
    {
      vattr_null(v10); /*0x17dc00*/
      v11 = v5 << page_shift; /*0x17dc11*/
      v8 = *(_DWORD *)(active_u + 28); /*0x17dc1d*/
      *(_DWORD *)(active_u + 28) = *(_DWORD *)(*v9 + 48); /*0x17dc28*/
      v7 = (*(int (__cdecl **)(_DWORD *, _BYTE *, _DWORD))(v9[7] + 24))(v9, v10, *(_DWORD *)(*v9 + 48)); /*0x17dc39*/
      if ( v7 )
        printf("vnode_deallocpage: error truncating %s, error = %d\n", *(const char **)(v2 + 40), v7);
      *(_DWORD *)(active_u + 28) = v8; /*0x17dc5c*/
    }
    return lock_done(v2 + 52); /*0x17dc63*/
  }
  return result; /*0x17dc6b*/
}
