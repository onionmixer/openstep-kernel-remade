/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c8ec. */
__int16 exportfs()
{
  int v0; // eax
  int v1; // ebx
  _DWORD *v2; // esi
  int *v3; // ebx
  _WORD *v4; // edx
  int v5; // eax
  unsigned __int16 *v7; // [esp+Ch] [ebp-10h]
  int *v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h] BYREF

  v8 = *(int **)(dword_1E875C + 36); /*0x12c8fd*/
  if ( !suser() ) /*0x12c900*/
  {
    LOWORD(v0) = dword_1E875C; /*0x12c909*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x12c90e*/
    return v0; /*0x12c912*/
  }
  *(_BYTE *)(dword_1E875C + 104) = lookupname(*v8, 0, 1, 0, (int)&v10); /*0x12c934*/
  LOWORD(v0) = dword_1E875C; /*0x12c937*/
  if ( !*(_BYTE *)(dword_1E875C + 104) )
  {
    *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, int *))(*(_DWORD *)(v10 + 28) + 100))(v10, &v9); /*0x12c960*/
    v1 = *(_DWORD *)(v10 + 36); /*0x12c966*/
    vn_rele(v10); /*0x12c96a*/
    LOWORD(v0) = dword_1E875C; /*0x12c96f*/
    if ( !*(_BYTE *)(dword_1E875C + 104) )
    {
      if ( !v8[1] ) /*0x12c984*/
      {
        *(_BYTE *)(dword_1E875C + 104) = unexport((void *)(v1 + 20), v9); /*0x12c99e*/
        LOWORD(v0) = kfree(v9, *(unsigned __int16 *)v9 + 2); /*0x12c9ac*/
        return v0; /*0x12c9ac*/
      }
      v2 = (_DWORD *)kalloc(0x30u); /*0x12c9bb*/
      v2[8] = *(_DWORD *)(v1 + 20); /*0x12c9c0*/
      v2[9] = *(_DWORD *)(v1 + 24); /*0x12c9c6*/
      v2[10] = v9; /*0x12c9cc*/
      *(_BYTE *)(dword_1E875C + 104) = copyin(v8[1], v2, 32); /*0x12c9e5*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x12c9f1*/
      {
LABEL_24:
        kfree(v2[10], *(unsigned __int16 *)v2[10] + 2); /*0x12caf4*/
        LOWORD(v0) = kfree((int)v2, 0x30u); /*0x12cb07*/
        return v0; /*0x12cb07*/
      }
      if ( (*v2 & 0xFFFFFFFC) != 0 ) /*0x12ca02*/
      {
        *(_BYTE *)(dword_1E875C + 104) = 22; /*0x12ca04*/
        goto LABEL_24; /*0x12ca08*/
      }
      if ( (*v2 & 2) != 0 ) /*0x12ca12*/
      {
        *(_BYTE *)(dword_1E875C + 104) = loadaddrs(v2 + 6); /*0x12ca24*/
        if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x12ca2f*/
          goto LABEL_24; /*0x12ca2f*/
      }
      *(_BYTE *)(dword_1E875C + 104) = v2[2] == 1 ? (unsigned __int8)loadaddrs(v2 + 3) : 22;
      LOWORD(v0) = dword_1E875C; /*0x12ca61*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x12ca66*/
        goto LABEL_24; /*0x12ca6a*/
      v3 = &exported; /*0x12ca70*/
      if ( exported ) /*0x12ca7c*/
      {
        do /*0x12cae1*/
        {
          v0 = bcmp((const void *)(*v3 + 32), v2 + 8, 8u); /*0x12ca8c*/
          if ( v0 /*0x12cac6*/
            || (v7 = *(unsigned __int16 **)(*v3 + 40), v4 = (_WORD *)v2[10], LOWORD(v0) = *v7, *v4 != *v7)
            || (v0 = bcmp(v7 + 1, v4 + 1, *v7)) != 0 )
          {
            v3 = (int *)(*v3 + 44); /*0x12cade*/
          }
          else
          {
            v5 = *v3; /*0x12cac8*/
            *v3 = *(_DWORD *)(*v3 + 44); /*0x12cacd*/
            LOWORD(v0) = exportfree(v5); /*0x12cad0*/
          }
        }
        while ( *v3 ); /*0x12cae1*/
      }
      v2[11] = 0; /*0x12cae6*/
      *v3 = (int)v2; /*0x12caed*/
    }
  }
  return v0; /*0x12cb0f*/
}
