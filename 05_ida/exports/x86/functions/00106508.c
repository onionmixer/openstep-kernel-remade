/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106508. */
int waitpgrp()
{
  int v0; // ebx
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char v11; // al
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h] BYREF

  v13 = *(_DWORD *)(dword_1E875C + 36); /*0x106519*/
  v12 = 0; /*0x10651c*/
  while ( 1 ) /*0x10652a*/
  {
    v0 = *(_DWORD *)(*(_DWORD *)active_u + 72); /*0x10652a*/
    if ( v0 ) /*0x10652f*/
      break; /*0x10652f*/
LABEL_31:
    if ( !v12 ) /*0x1066f7*/
    {
      *(_BYTE *)(dword_1E875C + 104) = 10; /*0x1066fe*/
      return 0; /*0x106702*/
    }
    if ( (*(_BYTE *)(v13 + 8) & 1) != 0 ) /*0x10670f*/
    {
      v14 = 0; /*0x106716*/
      *(_DWORD *)(dword_1E875C + 96) = 0; /*0x10671d*/
      v11 = copyout(&v14, *(_DWORD *)(v13 + 4), 4); /*0x10672a*/
LABEL_29:
      *(_BYTE *)(dword_1E875C + 104) = v11; /*0x1066d9*/
      return 0; /*0x106794*/
    }
    if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x106735*/
    {
      if ( ((*(int *)(active_u + 320) >> (*(_BYTE *)(*(_DWORD *)active_u + 23) - 1)) & 1) != 0 ) /*0x106759*/
        *(_BYTE *)(dword_1E875C + 104) = 4; /*0x106760*/
      else
        *(_BYTE *)(dword_1E875C + 105) = 2; /*0x106771*/
      return 0; /*0x106764*/
    }
    sleep(*(_DWORD *)active_u); /*0x106786*/
  }
  while ( 1 ) /*0x106538*/
  {
    if ( *(_DWORD *)v13 != *(__int16 *)(v0 + 46) ) /*0x106541*/
      goto LABEL_30; /*0x106541*/
    ++v12; /*0x106547*/
    v1 = *(_DWORD *)(v0 + 104); /*0x10654a*/
    if ( !v1 ) /*0x10654f*/
      break; /*0x10654f*/
    if ( *(int *)(v1 + 68) > 0 && *(_BYTE *)(v0 + 19) == 6 ) /*0x10667e*/
    {
      v7 = *(_DWORD *)(v0 + 40); /*0x106680*/
      if ( (v7 & 0x20) == 0 && ((v7 & 0x10) != 0 || (*(_BYTE *)(v13 + 8) & 2) != 0) ) /*0x106691*/
      {
        v8 = *(_DWORD *)(v0 + 124); /*0x106693*/
        if ( !v8 || v8 == *(_DWORD *)active_u ) /*0x10669c*/
        {
          LOBYTE(v7) = v7 | 0x20; /*0x10669e*/
          *(_DWORD *)(v0 + 40) = v7; /*0x1066a1*/
          *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v0 + 48); /*0x1066ad*/
          LOBYTE(v9) = *(_BYTE *)(v0 + 23); /*0x1066b0*/
          if ( (_BYTE)v9 ) /*0x1066b5*/
            v9 = (char)v9; /*0x1066bc*/
          else
            v9 = *(_DWORD *)(v0 + 60); /*0x1066b7*/
          v10 = v9 << 8; /*0x1066bf*/
          LOBYTE(v10) = v10 | 0x7F; /*0x1066c2*/
          v14 = v10; /*0x1066c4*/
          v11 = copyout(&v14, *(_DWORD *)(v13 + 4), 4); /*0x1066d4*/
          goto LABEL_29; /*0x1066d4*/
        }
      }
    }
LABEL_30:
    v0 = *(_DWORD *)(v0 + 76); /*0x1066e8*/
    if ( !v0 ) /*0x1066ed*/
      goto LABEL_31; /*0x1066ed*/
  }
  *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v0 + 48); /*0x10655e*/
  *(_BYTE *)(dword_1E875C + 104) = copyout(v0 + 52, *(_DWORD *)(v13 + 4), 4); /*0x106577*/
  if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x106582*/
    return 0; /*0x106586*/
  *(_WORD *)(v0 + 52) = 0; /*0x10658c*/
  if ( *(_DWORD *)(v0 + 56) ) /*0x106592*/
  {
    ruadd(active_u + 440, *(_DWORD *)(v0 + 56)); /*0x1065a5*/
    kfree(*(_DWORD *)(v0 + 56), 0x48u); /*0x1065b0*/
    *(_DWORD *)(v0 + 56) = 0; /*0x1065b5*/
  }
  leavepgrp(v0); /*0x1065c0*/
  delete_posix_proc(v0); /*0x1065c6*/
  *(_BYTE *)(v0 + 19) = 0; /*0x1065cb*/
  *(_WORD *)(v0 + 48) = 0; /*0x1065cf*/
  *(_WORD *)(v0 + 50) = 0; /*0x1065d5*/
  v2 = *(_DWORD *)(v0 + 8); /*0x1065de*/
  **(_DWORD **)(v0 + 12) = v2; /*0x1065e1*/
  if ( v2 ) /*0x1065e5*/
    *(_DWORD *)(*(_DWORD *)(v0 + 8) + 12) = *(_DWORD *)(v0 + 12); /*0x1065ed*/
  *(_DWORD *)(v0 + 8) = freeproc; /*0x1065f6*/
  freeproc = v0; /*0x1065f9*/
  v3 = *(_DWORD *)(v0 + 80); /*0x1065ff*/
  if ( v3 ) /*0x106604*/
    *(_DWORD *)(v3 + 76) = *(_DWORD *)(v0 + 76); /*0x106609*/
  v4 = *(_DWORD *)(v0 + 76); /*0x10660c*/
  if ( v4 ) /*0x106611*/
    *(_DWORD *)(v4 + 80) = *(_DWORD *)(v0 + 80); /*0x106616*/
  v5 = *(_DWORD *)(v0 + 68); /*0x106619*/
  if ( *(_DWORD *)(v5 + 72) == v0 ) /*0x10661f*/
    *(_DWORD *)(v5 + 72) = *(_DWORD *)(v0 + 76); /*0x106624*/
  *(_DWORD *)(v0 + 68) = 0; /*0x106627*/
  *(_DWORD *)(v0 + 80) = 0; /*0x10662e*/
  *(_DWORD *)(v0 + 76) = 0; /*0x106635*/
  *(_DWORD *)(v0 + 72) = 0; /*0x10663c*/
  *(_DWORD *)(v0 + 24) = 0; /*0x106643*/
  *(_DWORD *)(v0 + 36) = 0; /*0x10664a*/
  *(_DWORD *)(v0 + 32) = 0; /*0x106651*/
  *(_DWORD *)(v0 + 28) = 0; /*0x106658*/
  *(_DWORD *)(v0 + 40) = 0; /*0x10665f*/
  *(_BYTE *)(v0 + 23) = 0; /*0x106666*/
  return 0; /*0x106799*/
}
