/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11e658. */
int __cdecl vn_rename(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  __int16 v7; // ax
  int v8; // ebx
  __int16 v9; // ax
  int v10; // ebx
  __int16 v11; // ax
  int v12; // [esp+10h] [ebp-24h] BYREF
  int v13; // [esp+14h] [ebp-20h] BYREF
  int v14; // [esp+18h] [ebp-1Ch] BYREF
  _BYTE v15[4]; // [esp+1Ch] [ebp-18h] BYREF
  int v16; // [esp+20h] [ebp-14h]
  _BYTE v17[4]; // [esp+28h] [ebp-Ch] BYREF
  int v18; // [esp+2Ch] [ebp-8h]

  v13 = 0; /*0x11e661*/
  v12 = 0; /*0x11e668*/
  v14 = 0; /*0x11e66f*/
  result = pn_get(a1, a3, v17); /*0x11e682*/
  if ( !result ) /*0x11e68e*/
  {
    v4 = pn_get(a2, a3, v15); /*0x11e6a5*/
    if ( v4 ) /*0x11e6ac*/
    {
      pn_free(v17); /*0x11e6af*/
    }
    else
    {
      v4 = lookuppn((int)v17, 0, &v14, &v13); /*0x11e6cc*/
      if ( !v4 ) /*0x11e6d3*/
      {
        if ( v13 ) /*0x11e6d9*/
        {
          v4 = lookuppn((int)v15, 0, &v12, nullptr); /*0x11e6f2*/
          if ( !v4 ) /*0x11e6f9*/
          {
            v5 = *(_DWORD *)(v13 + 36); /*0x11e701*/
            if ( *(_DWORD *)(v12 + 36) == v5 ) /*0x11e707*/
            {
              if ( (*(_BYTE *)(v5 + 12) & 1) != 0 ) /*0x11e714*/
              {
                v4 = 30; /*0x11e716*/
              }
              else
              {
                vnode_uncache(v12); /*0x11e721*/
                v4 = (*(int (__cdecl **)(int, int, int, int, _DWORD))(*(_DWORD *)(v14 + 28) + 48))( /*0x11e74d*/
                       v14,
                       v18,
                       v12,
                       v16,
                       *(_DWORD *)(active_u + 28));
              }
            }
            else
            {
              v4 = 18; /*0x11e709*/
            }
          }
        }
        else
        {
          v4 = 2; /*0x11e6db*/
        }
      }
      pn_free(v17); /*0x11e756*/
      pn_free(v15); /*0x11e75f*/
      v6 = v13; /*0x11e767*/
      if ( v13 ) /*0x11e76c*/
      {
        if ( !*(_WORD *)(v13 + 6) ) /*0x11e76e*/
          panic(aVnRele); /*0x11e77a*/
        v7 = *(_WORD *)(v13 + 6); /*0x11e782*/
        *(_WORD *)(v13 + 6) = v7 - 1; /*0x11e78a*/
        if ( v7 == 1 ) /*0x11e792*/
          (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v6 + 28) + 76))(v6, *(_DWORD *)(active_u + 28)); /*0x11e7a5*/
      }
      v8 = v14; /*0x11e7aa*/
      if ( v14 ) /*0x11e7af*/
      {
        if ( !*(_WORD *)(v14 + 6) ) /*0x11e7b1*/
          panic(aVnRele); /*0x11e7bd*/
        v9 = *(_WORD *)(v14 + 6); /*0x11e7c5*/
        *(_WORD *)(v14 + 6) = v9 - 1; /*0x11e7cd*/
        if ( v9 == 1 ) /*0x11e7d5*/
          (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v8 + 28) + 76))(v8, *(_DWORD *)(active_u + 28)); /*0x11e7e8*/
      }
      v10 = v12; /*0x11e7ed*/
      if ( v12 ) /*0x11e7f2*/
      {
        if ( !*(_WORD *)(v12 + 6) ) /*0x11e7f4*/
          panic(aVnRele); /*0x11e800*/
        v11 = *(_WORD *)(v12 + 6); /*0x11e808*/
        *(_WORD *)(v12 + 6) = v11 - 1; /*0x11e810*/
        if ( v11 == 1 ) /*0x11e818*/
          (*(void (__stdcall **)(int))(*(_DWORD *)(v10 + 28) + 76))(v10); /*0x11e82b*/
      }
    }
    return v4; /*0x11e82d*/
  }
  return result; /*0x11e832*/
}
