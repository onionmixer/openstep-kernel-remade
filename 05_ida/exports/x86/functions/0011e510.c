/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11e510. */
int __cdecl vn_link(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  __int16 v7; // ax
  int v8; // ebx
  __int16 v9; // ax
  int v10; // [esp+Ch] [ebp-14h] BYREF
  int v11; // [esp+10h] [ebp-10h] BYREF
  int v12[3]; // [esp+14h] [ebp-Ch] BYREF

  v10 = 0; /*0x11e51c*/
  v11 = 0; /*0x11e523*/
  result = pn_get(a2, a3, v12); /*0x11e533*/
  if ( !result ) /*0x11e53f*/
  {
    v4 = lookupname(a1, a3, 1, 0, (int)&v11); /*0x11e55a*/
    if ( !v4 ) /*0x11e561*/
    {
      v4 = lookuppn((int)v12, 1, &v10, nullptr); /*0x11e571*/
      if ( !v4 ) /*0x11e578*/
      {
        v5 = *(_DWORD *)(v11 + 36); /*0x11e580*/
        if ( *(_DWORD *)(v10 + 36) == v5 ) /*0x11e586*/
        {
          if ( (*(_BYTE *)(v5 + 12) & 1) != 0 ) /*0x11e594*/
            v4 = 30; /*0x11e596*/
          else
            v4 = (*(int (__cdecl **)(int, int, int, _DWORD))(*(_DWORD *)(v10 + 28) + 44))( /*0x11e5b8*/
                   v11,
                   v10,
                   v12[1],
                   *(_DWORD *)(active_u + 28));
        }
        else
        {
          v4 = 18; /*0x11e588*/
        }
      }
    }
    pn_free(v12); /*0x11e5c1*/
    v6 = v11; /*0x11e5c9*/
    if ( v11 ) /*0x11e5ce*/
    {
      if ( !*(_WORD *)(v11 + 6) ) /*0x11e5d0*/
        panic(aVnRele); /*0x11e5dc*/
      v7 = *(_WORD *)(v11 + 6); /*0x11e5e4*/
      *(_WORD *)(v11 + 6) = v7 - 1; /*0x11e5ec*/
      if ( v7 == 1 ) /*0x11e5f4*/
        (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v6 + 28) + 76))(v6, *(_DWORD *)(active_u + 28)); /*0x11e607*/
    }
    v8 = v10; /*0x11e60c*/
    if ( v10 ) /*0x11e611*/
    {
      if ( !*(_WORD *)(v10 + 6) ) /*0x11e613*/
        panic(aVnRele); /*0x11e61f*/
      v9 = *(_WORD *)(v10 + 6); /*0x11e627*/
      *(_WORD *)(v10 + 6) = v9 - 1; /*0x11e62f*/
      if ( v9 == 1 ) /*0x11e637*/
        (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)(v8 + 28) + 76))(v8, *(_DWORD *)(active_u + 28)); /*0x11e64a*/
    }
    return v4; /*0x11e64c*/
  }
  return result; /*0x11e651*/
}
