/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114a48. */
int __cdecl mclput(int a1)
{
  __int16 v1; // ax
  _DWORD *v2; // ecx
  int result; // eax
  char v4; // dl

  v1 = *(_WORD *)(a1 + 12); /*0x114a4f*/
  if ( v1 == 1 ) /*0x114a57*/
  {
    v2 = (_DWORD *)((*(_DWORD *)(a1 + 4) + a1) & 0xFFFFFC00); /*0x114a6b*/
    result = ((int)v2 - mbutl) >> 10; /*0x114a79*/
    v4 = mclrefcnt[result]; /*0x114a7c*/
    mclrefcnt[result] = v4 - 1; /*0x114a86*/
    if ( v4 == 1 ) /*0x114a8f*/
    {
      *v2 = mclfree; /*0x114a97*/
      mclfree = (int)v2; /*0x114a99*/
      ++dword_1E916C; /*0x114a9f*/
    }
  }
  else
  {
    if ( v1 != 2 ) /*0x114a5d*/
      panic(aMclput); /*0x114ab9*/
    return (*(int (__stdcall **)(_DWORD))(a1 + 16))(*(_DWORD *)(a1 + 20)); /*0x114aaf*/
  }
  return result; /*0x114abe*/
}
