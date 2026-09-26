/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d690. */
int __cdecl access(const char *a1, int a2)
{
  int *v2; // esi
  int result; // eax
  _WORD *v4; // eax
  __int16 v5; // di
  unsigned __int16 v6; // bx
  int v7; // eax
  __int16 v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *(int **)(dword_1E875C + 36); /*0x11d69e*/
  *(_BYTE *)(dword_1E875C + 104) = lookupname(*v2, 0, 1, 0, (int)&v9); /*0x11d6ba*/
  result = dword_1E875C; /*0x11d6bd*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d6c5*/
  {
    v4 = *(_WORD **)(active_u + 28); /*0x11d6d4*/
    v5 = v4[1]; /*0x11d6d7*/
    v8 = v4[2]; /*0x11d6df*/
    v4[1] = v4[3]; /*0x11d6e6*/
    *(_WORD *)(*(_DWORD *)(active_u + 28) + 4) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x11d6f6*/
    v6 = 0; /*0x11d6fa*/
    v7 = v2[1]; /*0x11d6fc*/
    if ( v7 ) /*0x11d701*/
    {
      if ( (v7 & 4) != 0 ) /*0x11d705*/
        v6 = 256; /*0x11d707*/
      if ( (v7 & 2) != 0 ) /*0x11d70e*/
      {
        if ( isrofile(v9) ) /*0x11d714*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 30; /*0x11d725*/
          goto LABEL_12; /*0x11d729*/
        }
        LOBYTE(v6) = v6 | 0x80; /*0x11d72c*/
      }
      if ( (v2[1] & 1) != 0 ) /*0x11d733*/
        LOBYTE(v6) = v6 | 0x40; /*0x11d735*/
      *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, _DWORD, _DWORD))(*(_DWORD *)(v9 + 28) + 28))( /*0x11d758*/
                                         v9,
                                         v6,
                                         *(_DWORD *)(active_u + 28));
    }
LABEL_12:
    vn_rele(v9); /*0x11d75e*/
    *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) = v5; /*0x11d76f*/
    result = *(_DWORD *)(active_u + 28); /*0x11d778*/
    *(_WORD *)(result + 4) = v8; /*0x11d77f*/
  }
  return result; /*0x11d786*/
}
