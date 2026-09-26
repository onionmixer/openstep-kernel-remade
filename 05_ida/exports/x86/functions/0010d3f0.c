/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d3f0. */
int selcont()
{
  int v0; // ebx
  _DWORD *v1; // edi
  _DWORD *v2; // esi
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // ebx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  _DWORD v14[2]; // [esp+14h] [ebp-8h] BYREF

  v0 = dword_1E875C; /*0x10d3f9*/
  v1 = *(_DWORD **)(dword_1E875C + 36); /*0x10d3ff*/
  v2 = (_DWORD *)(dword_1E875C + 136); /*0x10d402*/
  if ( *(int *)(dword_1E875C + 340) < 0 ) /*0x10d40f*/
  {
    if ( (unsigned int)(thread_wait_result() - 2) > 1 ) /*0x10d41c*/
      *(_DWORD *)(v0 + 340) = 0; /*0x10d42c*/
    else
      *(_DWORD *)(v0 + 340) = 4; /*0x10d41e*/
  }
  if ( (int)v2[51] <= 0 ) /*0x10d43d*/
  {
    while ( 1 ) /*0x10d449*/
    {
      v12 = nselcoll; /*0x10d449*/
      v3 = *(_DWORD *)active_u; /*0x10d451*/
      *(_DWORD *)(*(_DWORD *)active_u + 40) |= 0x400000u; /*0x10d453*/
      *(_DWORD *)(dword_1E875C + 96) = selscan(v2, v2 + 24, *v1); /*0x10d46e*/
      v4 = *(char *)(dword_1E875C + 104); /*0x10d476*/
      v2[51] = v4; /*0x10d47a*/
      if ( v4 || *(_DWORD *)(dword_1E875C + 96) || v2[50] ) /*0x10d49a*/
        break; /*0x10d49a*/
      v13 = splhigh(); /*0x10d4ac*/
      if ( v1[4] ) /*0x10d4af*/
      {
        getthetime(v14); /*0x10d4b9*/
        v5 = v2[48]; /*0x10d4c1*/
        if ( v14[0] > v5 || v14[0] == v5 && v14[1] >= v2[49] ) /*0x10d4d9*/
        {
          splx(v13); /*0x10d4df*/
          break; /*0x10d4e7*/
        }
      }
      v6 = *(_DWORD *)(v3 + 40); /*0x10d4ec*/
      if ( (v6 & 0x400000) != 0 && nselcoll == v12 ) /*0x10d4ff*/
      {
        *(_DWORD *)(v3 + 40) = v6 & 0xFFBFFFFF; /*0x10d521*/
        v2[51] = -1; /*0x10d524*/
        if ( v1[4] ) /*0x10d52e*/
          sleep_with_continuation_and_deadline((int)&selwait, 26, (int)selcont, v2 + 48); /*0x10d547*/
        else
          sleep_with_continuation((int)&selwait, 26, (int)selcont); /*0x10d560*/
        break; /*0x10d54f*/
      }
      *(_DWORD *)(v3 + 40) = v6 & 0xFFBFFFFF; /*0x10d506*/
      splx(v13); /*0x10d50d*/
    }
  }
  v7 = (unsigned int)(*v1 + 31) >> 5; /*0x10d568*/
  if ( v2[51] ) /*0x10d572*/
    goto LABEL_28; /*0x10d572*/
  v8 = v1[1]; /*0x10d57b*/
  if ( v8 ) /*0x10d580*/
    v2[51] = copyout(v2 + 24, v8, 4 * v7); /*0x10d594*/
  v9 = v1[2]; /*0x10d59d*/
  if ( v9 ) /*0x10d5a2*/
    v2[51] = copyout(v2 + 32, v9, 4 * v7); /*0x10d5b9*/
  v10 = v1[3]; /*0x10d5c2*/
  if ( v10 ) /*0x10d5c7*/
    v2[51] = copyout(v2 + 40, v10, 4 * v7); /*0x10d5de*/
  if ( v2[51] ) /*0x10d5e7*/
LABEL_28:
    *(_BYTE *)(dword_1E875C + 104) = *((_BYTE *)v2 + 204); /*0x10d5fb*/
  return unix_syscall_return(v2[51]); /*0x10d60d*/
}
