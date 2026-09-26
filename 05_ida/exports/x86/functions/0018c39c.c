/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c39c. */
int __cdecl intr_register_irq(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  __int16 v7; // bx
  __int16 *v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]
  __int16 v10; // [esp+14h] [ebp-4h]

  if ( a1 > 0xF ) /*0x18c3ae*/
    return 0; /*0x18c3ae*/
  if ( a1 == 2 ) /*0x18c3b3*/
    return 0; /*0x18c3b3*/
  if ( (unsigned int)a4 > 7 ) /*0x18c3b8*/
    return 0; /*0x18c3b8*/
  v9 = 3 * a1; /*0x18c3c0*/
  if ( dword_1E7624[3 * a1 + 1] ) /*0x18c3c8*/
    return 0; /*0x18c3cf*/
  v5 = __readeflags(); /*0x18c3d8*/
  _disable(); /*0x18c3da*/
  dword_1E7624[3 * a1] = a3; /*0x18c3ea*/
  dword_1E7624[v9 + 1] = a2; /*0x18c3f8*/
  dword_1E7624[v9 + 2] = a4; /*0x18c3fc*/
  v10 = 1 << a1; /*0x18c40e*/
  v6 = 0; /*0x18c411*/
  v8 = word_1E76E4; /*0x18c413*/
  do /*0x18c442*/
  {
    if ( v6 >= a4 ) /*0x18c426*/
      *v8 |= v10; /*0x18c437*/
    else
      *v8 &= ~(unsigned __int16)(1 << a1); /*0x18c42b*/
    ++v6; /*0x18c43a*/
    ++v8; /*0x18c43b*/
  }
  while ( v6 <= 7 ); /*0x18c442*/
  word_1E771E |= v10; /*0x18c44f*/
  v7 = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c45d*/
  if ( word_1E771C != v7 ) /*0x18c46c*/
  {
    word_1E771C = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c46e*/
    __outbyte(0x21u, v7); /*0x18c47c*/
    _InterlockedIncrement(dword_1E7618); /*0x18c47d*/
    __outbyte(0xA1u, HIBYTE(v7)); /*0x18c48f*/
    _InterlockedIncrement(dword_1E7618); /*0x18c490*/
  }
  __readeflags(); /*0x18c497*/
  if ( ((v5 >> 9) & 1) != 0 ) /*0x18c49d*/
    _enable(); /*0x18c49f*/
  else
    _disable(); /*0x18c4a4*/
  return 1; /*0x18c4ad*/
}
