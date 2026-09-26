/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11e204. */
int __cdecl vn_create(int a1, int a2, _DWORD *a3, int a4, int a5, int *a6)
{
  int result; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  __int16 v10; // ax
  int v11; // ebx
  __int16 v12; // ax
  int v13; // ebx
  __int16 v14; // ax
  int v15; // ebx
  __int16 v16; // ax
  int v17; // [esp+10h] [ebp-10h] BYREF
  int v18; // [esp+14h] [ebp-Ch] BYREF
  int v19; // [esp+18h] [ebp-8h]

  v17 = 0; /*0x11e210*/
  *a6 = 0; /*0x11e217*/
  result = pn_get(a1, a2, &v18); /*0x11e229*/
  if ( !result ) /*0x11e235*/
  {
    if ( a4 != 1 || *a3 == 2 ) /*0x11e247*/
      v7 = lookuppn((int)&v18, 1, &v17, a6); /*0x11e25f*/
    else
      v7 = lookuppn((int)&v18, 0, &v17, nullptr); /*0x11e252*/
    v8 = v7; /*0x11e264*/
    if ( v7 ) /*0x11e26b*/
    {
      pn_free(&v18); /*0x11e271*/
      return v8; /*0x11e465*/
    }
    if ( *a6 && *(_DWORD *)(*a6 + 40) == 6 ) /*0x11e286*/
      return 45; /*0x11e28d*/
    if ( (*(_BYTE *)(*(_DWORD *)(v17 + 36) + 12) & 1) != 0 ) /*0x11e29e*/
    {
      v9 = *a6; /*0x11e2a0*/
      if ( !*a6 ) /*0x11e2a4*/
      {
LABEL_18:
        v8 = 30; /*0x11e2ed*/
LABEL_39:
        pn_free(&v18); /*0x11e41d*/
        v15 = v17; /*0x11e426*/
        if ( !*(_WORD *)(v17 + 6) ) /*0x11e42c*/
          panic(aVnRele); /*0x11e438*/
        v16 = *(_WORD *)(v17 + 6); /*0x11e440*/
        *(_WORD *)(v17 + 6) = v16 - 1; /*0x11e448*/
        if ( v16 == 1 ) /*0x11e450*/
          (*(void (__stdcall **)(int))(*(_DWORD *)(v15 + 28) + 76))(v15); /*0x11e463*/
        return v8; /*0x11e463*/
      }
      if ( (unsigned int)(*(_DWORD *)(v9 + 40) - 3) > 1 ) /*0x11e2af*/
      {
        if ( !*(_WORD *)(v9 + 6) ) /*0x11e2b1*/
          panic(aVnRele); /*0x11e2bd*/
        v10 = *(_WORD *)(v9 + 6); /*0x11e2c5*/
        *(_WORD *)(v9 + 6) = v10 - 1; /*0x11e2cd*/
        if ( v10 == 1 ) /*0x11e2d5*/
          (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v9 + 28) + 76))(v9, *(_DWORD *)(active_u + 28)); /*0x11e2e8*/
        goto LABEL_18; /*0x11e2e8*/
      }
    }
    if ( !a4 && *a6 ) /*0x11e2fe*/
    {
      if ( (a5 & 0x80u) != 0 && (*(_BYTE *)(*a6 + 4) & 2) != 0 ) /*0x11e30e*/
      {
        vnode_uncache(*a6); /*0x11e311*/
        if ( (*(_BYTE *)(*a6 + 4) & 2) != 0 ) /*0x11e31f*/
          v8 = 26; /*0x11e321*/
      }
      v11 = *a6; /*0x11e326*/
      if ( !*(_WORD *)(*a6 + 6) ) /*0x11e328*/
        panic(aVnRele); /*0x11e334*/
      v12 = *(_WORD *)(v11 + 6); /*0x11e33c*/
      *(_WORD *)(v11 + 6) = v12 - 1; /*0x11e344*/
      if ( v12 == 1 ) /*0x11e34c*/
        (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v11 + 28) + 76))(v11, *(_DWORD *)(active_u + 28)); /*0x11e35f*/
    }
    if ( !v8 ) /*0x11e366*/
    {
      if ( *a3 == 2 ) /*0x11e372*/
      {
        v13 = *a6; /*0x11e374*/
        if ( *a6 ) /*0x11e374*/
        {
          if ( !*(_WORD *)(v13 + 6) ) /*0x11e37a*/
            panic(aVnRele); /*0x11e386*/
          v14 = *(_WORD *)(v13 + 6); /*0x11e38e*/
          *(_WORD *)(v13 + 6) = v14 - 1; /*0x11e396*/
          if ( v14 == 1 ) /*0x11e39e*/
            (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)(v13 + 28) + 76))(v13, *(_DWORD *)(active_u + 28)); /*0x11e3b1*/
          v8 = 17; /*0x11e3b6*/
        }
        else
        {
          v8 = (*(int (__cdecl **)(int, int, _DWORD *, int *, _DWORD))(*(_DWORD *)(v17 + 28) + 52))( /*0x11e3e4*/
                 v17,
                 v19,
                 a3,
                 a6,
                 *(_DWORD *)(active_u + 28));
        }
      }
      else
      {
        v8 = (*(int (__cdecl **)(int, int, _DWORD *, int, int, int *, _DWORD))(*(_DWORD *)(v17 + 28) + 36))( /*0x11e418*/
               v17,
               v19,
               a3,
               a4,
               a5,
               a6,
               *(_DWORD *)(active_u + 28));
      }
    }
    goto LABEL_39; /*0x11e3bb*/
  }
  return result; /*0x11e46a*/
}
