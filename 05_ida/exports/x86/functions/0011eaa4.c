/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11eaa4. */
int ustat()
{
  unsigned __int16 *v0; // esi
  int result; // eax
  int v2; // eax
  char v3; // dl
  int v4; // [esp+Ch] [ebp-58h] BYREF
  _DWORD v5[5]; // [esp+10h] [ebp-54h] BYREF
  _BYTE v6[4]; // [esp+24h] [ebp-40h] BYREF
  int v7; // [esp+28h] [ebp-3Ch]
  int v8; // [esp+34h] [ebp-30h]
  int v9; // [esp+3Ch] [ebp-28h]

  v0 = *(unsigned __int16 **)(dword_1E875C + 36); /*0x11eab2*/
  *(_BYTE *)(dword_1E875C + 104) = vafsidtovfs(*v0, &v4); /*0x11eac9*/
  result = dword_1E875C; /*0x11eacc*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11ead4*/
  {
    *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, _BYTE *))(*(_DWORD *)(v4 + 4) + 12))(v4, v6); /*0x11eaf1*/
    result = dword_1E875C; /*0x11eaf4*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11eafc*/
    {
      bzero(v5, 0x14u); /*0x11eb08*/
      v2 = v7 * v8 + 511; /*0x11eb14*/
      if ( v2 < 0 ) /*0x11eb1c*/
        v2 = v7 * v8 + 1022; /*0x11eb1e*/
      v5[0] = v2 >> 9; /*0x11eb27*/
      v5[1] = v9; /*0x11eb2d*/
      v3 = copyout(v5, *((_DWORD *)v0 + 1), 20); /*0x11eb3c*/
      result = dword_1E875C; /*0x11eb3e*/
      *(_BYTE *)(dword_1E875C + 104) = v3; /*0x11eb43*/
    }
  }
  return result; /*0x11eb49*/
}
