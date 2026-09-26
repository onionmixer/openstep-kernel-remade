/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b7cc. */
int __cdecl ptrace(int _request, pid_t _pid, caddr_t _addr, int _data)
{
  int result; // eax
  int v5; // eax
  unsigned int v6; // edx
  int v7; // ecx
  int v8; // ecx
  __int16 v9; // ax
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // [esp+Ch] [ebp-10h]
  int *v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-8h]
  task_t target_task; // [esp+18h] [ebp-4h]

  v17 = *(int **)(dword_1E875C + 36); /*0x10b7dd*/
  if ( *v17 <= 0 ) /*0x10b7e3*/
  {
    *(_BYTE *)(*(_DWORD *)active_u + 40) |= 0x10u; /*0x10b7ec*/
    *(_DWORD *)(*(_DWORD *)active_u + 124) = *(_DWORD *)(*(_DWORD *)active_u + 68); /*0x10b7fa*/
    result = *(_DWORD *)(*(_DWORD *)active_u + 68); /*0x10b804*/
    *(_DWORD *)(result + 128) = *(_DWORD *)active_u; /*0x10b807*/
    return result; /*0x10b80d*/
  }
  v5 = pfind(v17[1]); /*0x10b81b*/
  v6 = v5; /*0x10b820*/
  if ( !v5 ) /*0x10b827*/
    goto LABEL_4; /*0x10b827*/
  target_task = *(_DWORD *)(v5 + 104); /*0x10b83b*/
  v7 = *v17; /*0x10b841*/
  if ( *v17 == 10 ) /*0x10b846*/
  {
    v8 = *(_DWORD *)active_u; /*0x10b84d*/
    v9 = *(_WORD *)(*(_DWORD *)active_u + 44); /*0x10b84f*/
    if ( !v9 || *(_WORD *)(v6 + 44) == v9 ) /*0x10b85c*/
    {
      v10 = *(_DWORD *)(v6 + 40); /*0x10b85e*/
      if ( (v10 & 0x10) == 0 && !*(_DWORD *)(v8 + 128) ) /*0x10b865*/
      {
        LOBYTE(v10) = v10 | 0x10; /*0x10b86e*/
        *(_DWORD *)(v6 + 40) = v10; /*0x10b870*/
        *(_DWORD *)(v6 + 124) = *(_DWORD *)active_u; /*0x10b87a*/
        *(_DWORD *)(v8 + 128) = v6; /*0x10b87d*/
        psignal(v6, (const char *)0x11); /*0x10b886*/
        return result; /*0x10b88b*/
      }
    }
LABEL_4:
    result = dword_1E875C; /*0x10b829*/
    *(_BYTE *)(dword_1E875C + 104) = 3; /*0x10b82e*/
    return result; /*0x10b832*/
  }
  if ( !*(_DWORD *)(target_task + 68) ) /*0x10b893*/
    goto LABEL_4; /*0x10b893*/
  if ( *(_BYTE *)(v5 + 19) != 6 ) /*0x10b89d*/
    goto LABEL_4; /*0x10b89d*/
  v11 = *(_DWORD *)(v5 + 124); /*0x10b8a4*/
  if ( *(_DWORD *)active_u != v11 || (*(_BYTE *)(v5 + 40) & 0x10) == 0 ) /*0x10b8b3*/
    goto LABEL_4; /*0x10b8b3*/
  if ( v7 == 8 ) /*0x10b8bc*/
  {
    *(_BYTE *)(v5 + 23) += 32; /*0x10b910*/
    goto LABEL_34; /*0x10b914*/
  }
  if ( v7 <= 8 ) /*0x10b8be*/
  {
    if ( v7 != 7 ) /*0x10b8c3*/
      goto LABEL_38; /*0x10b8c3*/
    goto LABEL_25; /*0x10b8c3*/
  }
  if ( v7 == 9 ) /*0x10b8cf*/
  {
LABEL_25:
    v16 = *(_DWORD *)(target_task + 28); /*0x10b91c*/
    v18 = **(_DWORD **)(v16 + 132); /*0x10b92d*/
    v13 = v17[2]; /*0x10b933*/
    if ( v13 != 1 ) /*0x10b939*/
      *(_DWORD *)(v18 + 56) = v13; /*0x10b93e*/
    if ( (unsigned int)v17[3] > 0x20 ) /*0x10b948*/
      goto LABEL_38; /*0x10b948*/
    if ( ((7928 >> (*(_BYTE *)(v6 + 23) - 1)) & 1) != 0 ) /*0x10b95e*/
      *(_BYTE *)(*(_DWORD *)(v16 + 132) + 120) = 0; /*0x10b969*/
    *(_BYTE *)(v6 + 23) = *((_BYTE *)v17 + 12); /*0x10b973*/
    v14 = v17[3]; /*0x10b979*/
    if ( ((7928 >> (v14 - 1)) & 1) != 0 ) /*0x10b988*/
      *(_BYTE *)(*(_DWORD *)(v16 + 132) + 120) = v14; /*0x10b995*/
    if ( *v17 == 9 ) /*0x10b99e*/
      *(_DWORD *)(v18 + 64) |= 0x100u; /*0x10b9a3*/
    goto LABEL_34; /*0x10b9a3*/
  }
  if ( v7 != 11 ) /*0x10b8d4*/
  {
LABEL_38:
    result = dword_1E875C; /*0x10b9d4*/
    *(_BYTE *)(dword_1E875C + 104) = 5; /*0x10b9d9*/
    return result; /*0x10b9d9*/
  }
  v12 = *(_DWORD *)(v11 + 128); /*0x10b8da*/
  if ( !v12 ) /*0x10b8e2*/
  {
    result = dword_1E875C; /*0x10b8e4*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10b8e9*/
    return result; /*0x10b8ed*/
  }
  *(_DWORD *)(v12 + 40) &= ~0x10u; /*0x10b8f4*/
  *(_DWORD *)(v12 + 124) = 0; /*0x10b8f8*/
  *(_DWORD *)(v11 + 128) = 0; /*0x10b8ff*/
LABEL_34:
  *(_BYTE *)(v6 + 19) = 3; /*0x10b9aa*/
  v15 = *(_DWORD *)(v6 + 108); /*0x10b9ae*/
  if ( v15 && *(_BYTE *)(v6 + 23) ) /*0x10b9b5*/
    clear_wait(v15, 2, 1); /*0x10b9c0*/
  return task_resume(target_task); /*0x10b9e0*/
}
