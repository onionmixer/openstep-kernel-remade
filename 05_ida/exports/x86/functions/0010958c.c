/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10958c. */
int __cdecl kill(pid_t a1, int a2)
{
  int result; // eax
  int v3; // esi
  char *v4; // edx
  int v5; // eax
  _DWORD *posix_proc; // edi
  int v7; // edx
  __int16 v8; // ax
  __int16 v9; // bx
  __int16 v10; // di
  __int16 v11; // dx
  int v12; // ebx
  __int16 v13; // ax
  char v14; // al
  char v15; // dl
  int v16; // [esp+Ch] [ebp-4h]

  result = dword_1E875C; /*0x109595*/
  v3 = *(_DWORD *)(dword_1E875C + 36); /*0x10959a*/
  v4 = *(char **)(v3 + 4); /*0x10959d*/
  if ( (unsigned int)v4 > 0x20 ) /*0x1095a3*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1095a5*/
    return result; /*0x1095a9*/
  }
  v5 = *(_DWORD *)v3; /*0x1095b0*/
  if ( *(int *)v3 > 0 ) /*0x1095b4*/
  {
    v16 = pfind(*(_DWORD *)v3); /*0x1095c0*/
    if ( !v16 ) /*0x1095c8*/
    {
      result = dword_1E875C; /*0x1095ca*/
      *(_BYTE *)(dword_1E875C + 104) = 3; /*0x1095cf*/
      return result; /*0x1095d3*/
    }
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x1095e4*/
    {
      posix_proc = get_posix_proc(*(__int16 *)(v16 + 48)); /*0x1095f7*/
      if ( suser() /*0x109664*/
        || (v7 = *(_DWORD *)(active_u + 28), v8 = *(_WORD *)(v7 + 2), v9 = *((_WORD *)posix_proc + 2), v8 == v9)
        || (v10 = *((_WORD *)posix_proc + 3), v8 == v10)
        || (v11 = *(_WORD *)(v7 + 6), v11 == v9)
        || v11 == v10
        || *(_DWORD *)(v3 + 4) == 19
        && (v12 = get_posix_proc(*(__int16 *)(v16 + 48))[4],
            *(_DWORD *)(v12 + 8) == *(_DWORD *)(get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48))[4] + 8)) )
      {
        *(_BYTE *)(dword_1E875C + 104) = 0; /*0x10966b*/
LABEL_18:
        result = *(_DWORD *)(v3 + 4); /*0x109694*/
        if ( result ) /*0x109699*/
          psignal(v16, *(const char **)(v3 + 4)); /*0x1096a0*/
        return result; /*0x1096a5*/
      }
    }
    else
    {
      v13 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x109677*/
      if ( !v13 || *(_WORD *)(v16 + 44) == v13 ) /*0x109687*/
        goto LABEL_18; /*0x109687*/
    }
    result = dword_1E875C; /*0x109689*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x10968e*/
    return result; /*0x109692*/
  }
  if ( v5 == -1 ) /*0x1096ab*/
  {
    v14 = killpg1(v4, 0, 1); /*0x1096b9*/
  }
  else if ( v5 ) /*0x1096af*/
  {
    v14 = killpg1(*(char **)(v3 + 4), -*(_DWORD *)v3, 0); /*0x1096cf*/
  }
  else
  {
    v14 = killpg1(v4, 0, 0); /*0x1096c1*/
  }
  v15 = v14; /*0x1096d4*/
  result = dword_1E875C; /*0x1096d6*/
  *(_BYTE *)(dword_1E875C + 104) = v15; /*0x1096db*/
  return result; /*0x1096e1*/
}
