/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d048. */
int __cdecl symlink(const char *a1, const char *a2)
{
  int *v2; // edi
  int result; // eax
  int v4; // [esp+10h] [ebp-5Ch] BYREF
  int v5[3]; // [esp+14h] [ebp-58h] BYREF
  int v6[3]; // [esp+20h] [ebp-4Ch] BYREF
  _BYTE v7[4]; // [esp+2Ch] [ebp-40h] BYREF
  __int16 v8; // [esp+30h] [ebp-3Ch]

  v2 = *(int **)(dword_1E875C + 36); /*0x11d056*/
  *(_BYTE *)(dword_1E875C + 104) = pn_get(v2[1], 0, v5); /*0x11d06f*/
  result = dword_1E875C; /*0x11d072*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d07a*/
  {
    *(_BYTE *)(dword_1E875C + 104) = lookuppn((int)v5, 0, &v4, nullptr); /*0x11d099*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x11d0a5*/
    {
      return pn_free(v5); /*0x11d0ac*/
    }
    else
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v4 + 36) + 12) & 1) != 0 ) /*0x11d0c2*/
      {
        *(_BYTE *)(dword_1E875C + 104) = 30; /*0x11d0c4*/
      }
      else
      {
        *(_BYTE *)(dword_1E875C + 104) = pn_get(*v2, 0, v6); /*0x11d0e1*/
        vattr_null(v7); /*0x11d0e8*/
        v8 = 511; /*0x11d0ed*/
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11d0fb*/
        {
          *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, int, _BYTE *, int, _DWORD))(*(_DWORD *)(v4 + 28) + 64))( /*0x11d12c*/
                                             v4,
                                             v5[1],
                                             v7,
                                             v6[1],
                                             *(_DWORD *)(active_u + 28));
          pn_free(v6); /*0x11d130*/
        }
      }
      pn_free(v5); /*0x11d13c*/
      LOWORD(result) = vn_rele(v4); /*0x11d145*/
    }
  }
  return result; /*0x11d14d*/
}
