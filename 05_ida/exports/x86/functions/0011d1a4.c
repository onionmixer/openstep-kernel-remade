/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d1a4. */
int __cdecl getdirentries(int a1, char *a2, int a3, __int32 *a4)
{
  _DWORD *v4; // esi
  char v5; // dl
  int result; // eax
  _DWORD v7[2]; // [esp+Ch] [ebp-24h] BYREF
  int v8; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD v9[2]; // [esp+18h] [ebp-18h] BYREF
  int v10; // [esp+20h] [ebp-10h]
  int v11; // [esp+24h] [ebp-Ch]
  int v12; // [esp+2Ch] [ebp-4h]

  v4 = *(_DWORD **)(dword_1E875C + 36); /*0x11d1b2*/
  v5 = getvnodefp(*v4, &v8); /*0x11d1c1*/
  result = dword_1E875C; /*0x11d1c3*/
  *(_BYTE *)(dword_1E875C + 104) = v5; /*0x11d1c8*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d1d4*/
  {
    result = v8; /*0x11d1de*/
    if ( (*(_BYTE *)(v8 + 8) & 1) != 0 ) /*0x11d1e5*/
    {
      while ( 1 ) /*0x11d1f3*/
      {
        v7[0] = v4[1]; /*0x11d1f3*/
        v7[1] = v4[2]; /*0x11d1f9*/
        v9[0] = v7; /*0x11d1ff*/
        v9[1] = 1; /*0x11d202*/
        v10 = *(_DWORD *)(v8 + 28); /*0x11d20f*/
        v11 = 0; /*0x11d212*/
        v12 = v4[2]; /*0x11d21c*/
        if ( v10 < 0 ) /*0x11d223*/
          break; /*0x11d223*/
        *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(_DWORD, _DWORD *, _DWORD))(*(_DWORD *)(*(_DWORD *)(v8 + 24) /*0x11d240*/
                                                                                                  + 28)
                                                                                      + 60))(
                                           *(_DWORD *)(v8 + 24),
                                           v9,
                                           *(_DWORD *)(v8 + 32));
        if ( v4[2] != v12 ) /*0x11d24c*/
          goto LABEL_8; /*0x11d24c*/
        *(_DWORD *)(v8 + 28) = -1024; /*0x11d251*/
      }
      *(_BYTE *)(dword_1E875C + 104) = getfakedirentries(*(_DWORD *)(v8 + 24), v9); /*0x11d274*/
LABEL_8:
      result = dword_1E875C; /*0x11d27a*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d27f*/
      {
        *(_BYTE *)(dword_1E875C + 104) = copyout(v8 + 28, v4[3], 4); /*0x11d29e*/
        *(_DWORD *)(dword_1E875C + 96) = v4[2] - v12; /*0x11d2ac*/
        result = v8; /*0x11d2af*/
        *(_DWORD *)(v8 + 28) = v10; /*0x11d2b5*/
      }
    }
    else
    {
      *(_BYTE *)(dword_1E875C + 104) = 9; /*0x11d1e7*/
    }
  }
  return result; /*0x11d2bb*/
}
