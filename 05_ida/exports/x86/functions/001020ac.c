/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1020ac. */
int rpause()
{
  _DWORD *v0; // ecx
  int v1; // eax
  int result; // eax
  char v3; // [esp+Ch] [ebp-4h]

  v0 = *(_DWORD **)(dword_1E875C + 36); /*0x1020ba*/
  if ( *v0 != 28 || v0[1] != 0x7FFFFFFF ) /*0x1020c9*/
    goto LABEL_10; /*0x1020c9*/
  v3 = *(_BYTE *)(active_u + 608); /*0x1020dc*/
  v1 = v0[2]; /*0x1020e6*/
  if ( v1 == 1 ) /*0x1020ec*/
  {
    *(_BYTE *)(active_u + 608) = v3 & 0xF7; /*0x102113*/
  }
  else if ( v1 > 1 ) /*0x1020ee*/
  {
    if ( v1 != 2 ) /*0x1020fb*/
    {
LABEL_10:
      result = dword_1E875C; /*0x10211c*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x102121*/
      return result; /*0x102125*/
    }
    *(_BYTE *)(active_u + 608) = v3 | 8; /*0x102102*/
  }
  else if ( v1 ) /*0x1020f2*/
  {
    goto LABEL_10; /*0x1020f2*/
  }
  result = dword_1E875C; /*0x102128*/
  if ( (v3 & 8) != 0 ) /*0x10212f*/
    *(_DWORD *)(dword_1E875C + 96) = 0x7FFFFFFF; /*0x102131*/
  else
    *(_DWORD *)(dword_1E875C + 96) = 0; /*0x10213c*/
  return result; /*0x102146*/
}
