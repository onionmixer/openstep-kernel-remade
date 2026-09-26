/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cf7c. */
int __cdecl mkdir(const char *a1, mode_t a2)
{
  int v2; // esi
  __int16 v3; // dx
  int result; // eax
  int v5; // [esp+8h] [ebp-44h] BYREF
  int v6; // [esp+Ch] [ebp-40h] BYREF
  __int16 v7; // [esp+10h] [ebp-3Ch]

  v2 = *(_DWORD *)(dword_1E875C + 36); /*0x11cf89*/
  vattr_null(&v6); /*0x11cf90*/
  v6 = 2; /*0x11cf95*/
  v3 = *(_WORD *)(v2 + 4); /*0x11cf9c*/
  HIBYTE(v3) &= 1u; /*0x11cfa0*/
  v7 = ~*(_WORD *)(active_u + 366) & v3; /*0x11cfb5*/
  *(_BYTE *)(dword_1E875C + 104) = vn_create(*(_DWORD *)v2, 0, &v6, 1, 0, &v5); /*0x11cfd3*/
  result = dword_1E875C; /*0x11cfd6*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11cfde*/
    LOWORD(result) = vn_rele(v5); /*0x11cfe8*/
  return result; /*0x11cff0*/
}
