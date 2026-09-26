/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11db6c. */
int __cdecl truncate(const char *a1, off_t a2)
{
  int result; // eax
  _DWORD *v3; // esi
  char v4; // dl
  _BYTE v5[24]; // [esp+8h] [ebp-40h] BYREF
  int v6; // [esp+20h] [ebp-28h]

  result = dword_1E875C; /*0x11db74*/
  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x11db79*/
  if ( (int)v3[1] >= 0 ) /*0x11db80*/
  {
    vattr_null(v5); /*0x11db8c*/
    v6 = v3[1]; /*0x11db94*/
    v4 = namesetattr(*v3, 1, v5); /*0x11dba2*/
    result = dword_1E875C; /*0x11dba4*/
    *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11dba9*/
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11db82*/
  }
  return result; /*0x11dbaf*/
}
