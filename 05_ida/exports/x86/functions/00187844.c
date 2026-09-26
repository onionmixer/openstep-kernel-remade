/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187844. */
int __cdecl system_timer_dispatch(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // [esp+8h] [ebp-Ch] BYREF
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  qword_1E75D0 += 10000000; /*0x187852*/
  word_1E75D8 = word_1E75DA; /*0x18786a*/
  if ( a2 ) /*0x187873*/
  {
    v4 = *(_DWORD *)(a2 + 56); /*0x187878*/
    if ( (*(_BYTE *)(a2 + 66) & 2) != 0 ) /*0x18787f*/
      v5 = 3; /*0x18788c*/
    else
      v5 = *(_BYTE *)(a2 + 60) & 3; /*0x187887*/
  }
  else
  {
    v4 = 0; /*0x187898*/
    v5 = 0; /*0x18789f*/
  }
  v6 = a3; /*0x1878a6*/
  if ( dword_1E75E8 ) /*0x1878b0*/
    result = sub_187938(&v4); /*0x1878b6*/
  if ( dword_1E75E4 ) /*0x1878c6*/
  {
    result = qword_1E75DC; /*0x1878c8*/
    if ( qword_1E75DC ) /*0x1878cf*/
    {
      if ( qword_1E75D0 >= (unsigned __int64)qword_1E75DC ) /*0x1878f2*/
      {
        qword_1E75DC = 0; /*0x1878f4*/
        return dword_1E75E4(0, 0, 0); /*0x18790e*/
      }
    }
  }
  return result; /*0x187913*/
}
