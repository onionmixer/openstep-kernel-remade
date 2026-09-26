/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bda94. */
const char *__cdecl check_label(unsigned int *a1, unsigned int a2)
{
  unsigned __int32 v2; // eax
  unsigned __int16 v3; // dx
  _WORD *v4; // edi
  unsigned int *v6; // ecx
  int v7; // edx
  unsigned int v8; // ebx
  int v9; // eax
  __int16 v10; // [esp+10h] [ebp-4h]

  v2 = _byteswap_ulong(*a1); /*0x1bdaa2*/
  if ( v2 == 1315264596 || v2 == 1684821554 ) /*0x1bdab0*/
  {
    v3 = 7240; /*0x1bdab2*/
    v4 = (_WORD *)a1 + 3619; /*0x1bdab7*/
  }
  else
  {
    if ( v2 != 1684821555 ) /*0x1bdac5*/
      return "Bad disk label magic number"; /*0x1bdacc*/
    v3 = 560; /*0x1bdad4*/
    v4 = (_WORD *)a1 + 279; /*0x1bdad9*/
  }
  if ( a2 != _byteswap_ulong(a1[1]) ) /*0x1bdaea*/
    return "Label in wrong location"; /*0x1bdaec*/
  a1[1] = _byteswap_ulong(0); /*0x1bdafc*/
  v10 = __ROR2__(*v4, 8); /*0x1bdb09*/
  *v4 = __ROR2__(0, 8); /*0x1bdb13*/
  v6 = a1; /*0x1bdb1b*/
  v7 = (v3 >> 1) & 0xF3C; /*0x1bdb1f*/
  v8 = 0; /*0x1bdb25*/
  while ( --v7 != -1 ) /*0x1bdb3d*/
  {
    v8 += (unsigned __int16)__ROR2__(*(_WORD *)v6, 8); /*0x1bdb38*/
    v6 = (unsigned int *)((char *)v6 + 2); /*0x1bdb3a*/
  }
  v9 = HIWORD(v8) + (unsigned __int16)v8; /*0x1bdb4b*/
  if ( v9 > 0xFFFF ) /*0x1bdb52*/
    LOWORD(v9) = v9 + 1; /*0x1bdb54*/
  if ( v10 != (_WORD)v9 ) /*0x1bdb5d*/
    return "Label checksum error"; /*0x1bdb7c*/
  a1[1] = _byteswap_ulong(a2); /*0x1bdb64*/
  *v4 = __ROR2__(v10, 8); /*0x1bdb72*/
  return nullptr; /*0x1bdb84*/
}
