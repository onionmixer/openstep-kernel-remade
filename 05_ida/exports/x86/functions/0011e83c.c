/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11e83c. */
int __cdecl vn_remove(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  __int16 v6; // ax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  __int16 v10; // ax
  int v11; // ebx
  __int16 v12; // ax
  int v13; // [esp+Ch] [ebp-14h] BYREF
  int v14; // [esp+10h] [ebp-10h] BYREF
  _BYTE v15[4]; // [esp+14h] [ebp-Ch] BYREF
  int v16; // [esp+18h] [ebp-8h]

  result = pn_get(a1, a2, v15); /*0x11e851*/
  if ( !result ) /*0x11e85d*/
  {
    v13 = 0; /*0x11e863*/
    v4 = lookuppn((int)v15, 0, &v14, &v13); /*0x11e87a*/
    if ( v4 ) /*0x11e881*/
    {
      pn_free(v15); /*0x11e884*/
      return v4; /*0x11ea50*/
    }
    if ( v13 ) /*0x11e895*/
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v13 + 36) + 12) & 1) != 0 ) /*0x11e8ab*/
      {
        v4 = 30; /*0x11e8ad*/
      }
      else
      {
        if ( (*(_BYTE *)(v13 + 4) & 1) == 0 ) /*0x11e8bc*/
        {
          vnode_uncache(v13); /*0x11e8c9*/
          v5 = v13; /*0x11e8ce*/
          if ( *(_DWORD *)(v13 + 40) == 2 ) /*0x11e8d8*/
          {
            if ( a3 != 1 ) /*0x11e8de*/
            {
              v4 = 1; /*0x11e94c*/
              goto LABEL_28; /*0x11e951*/
            }
            if ( *(_DWORD *)(v13 + 16) ) /*0x11e8e0*/
            {
              v4 = 66; /*0x11e8e6*/
              goto LABEL_28; /*0x11e8eb*/
            }
            if ( !*(_WORD *)(v13 + 6) ) /*0x11e8f0*/
              panic(aVnRele); /*0x11e8fc*/
            v6 = *(_WORD *)(v13 + 6); /*0x11e904*/
            *(_WORD *)(v13 + 6) = v6 - 1; /*0x11e90c*/
            if ( v6 == 1 ) /*0x11e914*/
              (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v5 + 28) + 76))(v5, *(_DWORD *)(active_u + 28)); /*0x11e927*/
            v13 = 0; /*0x11e92c*/
            v7 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v14 + 28) + 56))( /*0x11e94a*/
                   v14,
                   v16,
                   *(_DWORD *)(active_u + 28));
          }
          else
          {
            if ( a3 ) /*0x11e958*/
            {
              v4 = 20; /*0x11e9c0*/
              goto LABEL_28; /*0x11e9c0*/
            }
            if ( !*(_WORD *)(v13 + 6) ) /*0x11e95a*/
              panic(aVnRele); /*0x11e966*/
            v8 = *(_WORD *)(v13 + 6); /*0x11e96e*/
            *(_WORD *)(v13 + 6) = v8 - 1; /*0x11e976*/
            if ( v8 == 1 ) /*0x11e97e*/
              (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v5 + 28) + 76))(v5, *(_DWORD *)(active_u + 28)); /*0x11e991*/
            v13 = 0; /*0x11e996*/
            v7 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v14 + 28) + 40))( /*0x11e9b4*/
                   v14,
                   v16,
                   *(_DWORD *)(active_u + 28));
          }
          v4 = v7; /*0x11e9b6*/
          goto LABEL_28; /*0x11e9bb*/
        }
        v4 = 16; /*0x11e8be*/
      }
    }
    else
    {
      v4 = 2; /*0x11e897*/
    }
LABEL_28:
    pn_free(v15); /*0x11e9c5*/
    v9 = v13; /*0x11e9d1*/
    if ( v13 ) /*0x11e9d6*/
    {
      if ( !*(_WORD *)(v13 + 6) ) /*0x11e9d8*/
        panic(aVnRele); /*0x11e9e4*/
      v10 = *(_WORD *)(v13 + 6); /*0x11e9ec*/
      *(_WORD *)(v13 + 6) = v10 - 1; /*0x11e9f4*/
      if ( v10 == 1 ) /*0x11e9fc*/
        (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v9 + 28) + 76))(v9, *(_DWORD *)(active_u + 28)); /*0x11ea0f*/
    }
    v11 = v14; /*0x11ea14*/
    if ( !*(_WORD *)(v14 + 6) ) /*0x11ea17*/
      panic(aVnRele); /*0x11ea23*/
    v12 = *(_WORD *)(v14 + 6); /*0x11ea2b*/
    *(_WORD *)(v14 + 6) = v12 - 1; /*0x11ea33*/
    if ( v12 == 1 ) /*0x11ea3b*/
      (*(void (__stdcall **)(int))(*(_DWORD *)(v11 + 28) + 76))(v11); /*0x11ea4e*/
    return v4; /*0x11ea4e*/
  }
  return result; /*0x11ea55*/
}
