/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ceac. */
int __cdecl rwuio(int *a1, int a2)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v4; // eax
  int result; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  bool v9; // sf
  int v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  v14 = 0; /*0x10ceb4*/
  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10cec0*/
  if ( *(_DWORD *)(active_u + 348) <= *v2 ) /*0x10ced1*/
    goto LABEL_8; /*0x10ced1*/
  v3 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *v2); /*0x10ced9*/
  v10 = v3; /*0x10cedc*/
  if ( !v3 || v3 == -65536 ) /*0x10cee9*/
    goto LABEL_8; /*0x10cee9*/
  v4 = *(_DWORD *)(v3 + 8); /*0x10ceee*/
  if ( a2 ) /*0x10cef5*/
  {
    if ( (v4 & 2) == 0 ) /*0x10cf02*/
    {
LABEL_8:
      result = dword_1E875C; /*0x10cf04*/
      *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10cf09*/
      return result; /*0x10cf0d*/
    }
  }
  else if ( (v4 & 1) == 0 ) /*0x10cef9*/
  {
    goto LABEL_8; /*0x10cef9*/
  }
  a1[5] = 0; /*0x10cf17*/
  a1[3] = 0; /*0x10cf1e*/
  v6 = *a1; /*0x10cf25*/
  v13 = 0; /*0x10cf27*/
  if ( a1[1] <= 0 ) /*0x10cf33*/
  {
LABEL_14:
    v12 = a1[5]; /*0x10cf5c*/
    do /*0x10d040*/
    {
      v11 = a1[5]; /*0x10cf6b*/
      a1[2] = *(_DWORD *)(v10 + 28); /*0x10cf77*/
      if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x10cf83*/
      {
        if ( a1[5] == v12 ) /*0x10cf95*/
        {
          if ( ((*(int *)(active_u + 320) >> (*(_BYTE *)(*(_DWORD *)active_u + 23) - 1)) & 1) != 0 ) /*0x10cfb0*/
            *(_BYTE *)(dword_1E875C + 104) = 4; /*0x10cfb7*/
          else
            *(_BYTE *)(dword_1E875C + 105) = 2; /*0x10cfc5*/
        }
      }
      else
      {
        ++v14; /*0x10cfdc*/
        *(_BYTE *)(dword_1E875C + 104) = (**(int (__cdecl ***)(int, int, int *))(v10 + 20))(v10, a2, a1); /*0x10cfff*/
      }
      *(_DWORD *)(dword_1E875C + 96) = v12 - a1[5]; /*0x10d013*/
      *(_DWORD *)(v10 + 28) += v11 - a1[5]; /*0x10d01f*/
      result = dword_1E875C; /*0x10d022*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10d027*/
        break; /*0x10d02b*/
      result = fspause(*(_DWORD *)(v10 + 8) & 0x1000); /*0x10d036*/
    }
    while ( result ); /*0x10d040*/
  }
  else
  {
    v7 = a1[1]; /*0x10cf35*/
    while ( 1 ) /*0x10cf38*/
    {
      v8 = *(_DWORD *)(v6 + 4); /*0x10cf38*/
      if ( v8 < 0 ) /*0x10cf3d*/
        break; /*0x10cf3d*/
      v9 = a1[5] + v8 < 0; /*0x10cf46*/
      a1[5] += v8; /*0x10cf49*/
      if ( v9 ) /*0x10cf4c*/
        break; /*0x10cf4c*/
      v6 += 8; /*0x10cf4e*/
      if ( ++v13 >= v7 ) /*0x10cf5a*/
        goto LABEL_14; /*0x10cf5a*/
    }
    result = dword_1E875C; /*0x10cfcc*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10cfd1*/
  }
  return result; /*0x10d049*/
}
