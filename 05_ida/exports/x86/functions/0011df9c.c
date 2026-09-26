/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11df9c. */
int __cdecl vn_open(int a1, int a2, unsigned int a3, __int16 a4, _DWORD *a5)
{
  unsigned int v5; // esi
  int result; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // esi
  __int16 v10; // ax
  int v11; // [esp+10h] [ebp-8Ch]
  _BYTE v12[24]; // [esp+18h] [ebp-84h] BYREF
  int v13; // [esp+30h] [ebp-6Ch]
  int v14; // [esp+58h] [ebp-44h] BYREF
  int v15; // [esp+5Ch] [ebp-40h] BYREF
  __int16 v16; // [esp+60h] [ebp-3Ch]
  int v17; // [esp+74h] [ebp-28h]

  v5 = a3; /*0x11dfa8*/
  v11 = 0; /*0x11dfab*/
  if ( (a3 & 1) != 0 ) /*0x11dfbb*/
    v11 = 256; /*0x11dfbd*/
  if ( (a3 & 0x402) != 0 ) /*0x11dfd5*/
    LOBYTE(v11) = v11 | 0x80; /*0x11dfd7*/
  if ( (a3 & 0x200) == 0 ) /*0x11dfe4*/
  {
    result = lookupname(a1, a2, 1, 0, (int)&v14); /*0x11e060*/
    if ( result ) /*0x11e06c*/
      return result; /*0x11e06c*/
    if ( (a3 & 0x402) != 0 ) /*0x11e079*/
    {
      v7 = *(_DWORD *)(v14 + 40); /*0x11e07e*/
      if ( v7 == 2 ) /*0x11e084*/
      {
        v8 = 21; /*0x11e086*/
        goto LABEL_34; /*0x11e08b*/
      }
      if ( (*(_BYTE *)(*(_DWORD *)(v14 + 36) + 12) & 1) != 0 && (unsigned int)(v7 - 3) > 1 ) /*0x11e09f*/
      {
        v8 = 30; /*0x11e0a1*/
        goto LABEL_34; /*0x11e0a6*/
      }
      if ( (*(_BYTE *)(v14 + 4) & 2) != 0 ) /*0x11e0b3*/
      {
        vnode_uncache(v14); /*0x11e0b6*/
        if ( (*(_BYTE *)(v14 + 4) & 2) != 0 ) /*0x11e0c5*/
        {
          v8 = 26; /*0x11e0c7*/
          goto LABEL_34; /*0x11e0cc*/
        }
      }
    }
    v8 = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v14 + 28) + 28))(v14, v11, *(_DWORD *)(active_u + 28)); /*0x11e0f0*/
    if ( v8 ) /*0x11e0f7*/
      goto LABEL_34; /*0x11e0f7*/
    if ( (*(_BYTE *)(*(_DWORD *)(v14 + 36) + 12) & 8) != 0 && (unsigned int)(*(_DWORD *)(v14 + 40) - 3) <= 1 ) /*0x11e112*/
    {
      v8 = 1; /*0x11e114*/
      goto LABEL_34; /*0x11e119*/
    }
LABEL_24:
    if ( *(_DWORD *)(v14 + 40) == 6 ) /*0x11e127*/
    {
      v8 = 45; /*0x11e129*/
    }
    else
    {
      v8 = (**(int (__cdecl ***)(int *, unsigned int, _DWORD))(v14 + 28))(&v14, v5, *(_DWORD *)(active_u + 28)); /*0x11e145*/
      if ( !v8 ) /*0x11e14c*/
      {
        if ( (v5 & 0x400) != 0 ) /*0x11e154*/
        {
          v5 &= ~0x400u; /*0x11e156*/
          vattr_null(v12); /*0x11e163*/
          v13 = 0; /*0x11e168*/
          v8 = (*(int (__cdecl **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v14 + 28) + 24))( /*0x11e185*/
                 v14,
                 v12,
                 *(_DWORD *)(active_u + 28));
        }
        if ( !v8 ) /*0x11e18c*/
        {
          if ( (v5 & 0x40000000) == 0 && *(_DWORD *)(v14 + 40) == 1 ) /*0x11e19d*/
            map_vnode(v14); /*0x11e1a0*/
          *a5 = v14; /*0x11e1f2*/
          return v8; /*0x11e1a8*/
        }
      }
    }
LABEL_34:
    v9 = v14; /*0x11e1ac*/
    if ( !*(_WORD *)(v14 + 6) ) /*0x11e1af*/
      panic(aVnRele); /*0x11e1bb*/
    v10 = *(_WORD *)(v14 + 6); /*0x11e1c3*/
    *(_WORD *)(v14 + 6) = v10 - 1; /*0x11e1cb*/
    if ( v10 == 1 ) /*0x11e1d3*/
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)(v9 + 28) + 76))(v9, *(_DWORD *)(active_u + 28)); /*0x11e1e6*/
    return v8; /*0x11e1f4*/
  }
  vattr_null(&v15); /*0x11dfea*/
  v15 = 1; /*0x11dfef*/
  v16 = a4; /*0x11dffa*/
  if ( (a3 & 0x400) != 0 ) /*0x11e007*/
    v17 = 0; /*0x11e009*/
  v5 = a3 & 0xFFFFF1FF; /*0x11e01b*/
  result = vn_create(a1, a2, &v15, (a3 & 0x800) != 0, v11, &v14); /*0x11e036*/
  if ( !result ) /*0x11e042*/
    goto LABEL_24; /*0x11e042*/
  return result; /*0x11e1fc*/
}
