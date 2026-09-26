/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c6cc. */
int __cdecl intr_change_ipl(unsigned int a1, int a2)
{
  __int16 v3; // kr00_2
  __int16 v4; // ax
  int v5; // ecx
  __int16 v6; // cx
  __int16 *v7; // [esp+Ch] [ebp-4h]

  if ( a1 > 0xF || a1 == 2 || (unsigned int)a2 > 7 || !dword_1E7624[3 * a1 + 1] ) /*0x18c6f8*/
    return 0; /*0x18c6ff*/
  v3 = __readeflags(); /*0x18c708*/
  _disable(); /*0x18c70a*/
  dword_1E7624[3 * a1 + 2] = a2; /*0x18c716*/
  v4 = 1 << a1; /*0x18c721*/
  v5 = 0; /*0x18c726*/
  v7 = word_1E76E4; /*0x18c728*/
  do /*0x18c74e*/
  {
    if ( v5 >= a2 ) /*0x18c736*/
      *v7 |= v4; /*0x18c743*/
    else
      *v7 &= ~v4; /*0x18c73b*/
    ++v5; /*0x18c746*/
    ++v7; /*0x18c747*/
  }
  while ( v5 <= 7 ); /*0x18c74e*/
  v6 = word_1E771E | word_1E76E4[dword_1E7718]; /*0x18c75d*/
  if ( word_1E771C != v6 ) /*0x18c76b*/
  {
    word_1E771C = word_1E771E | word_1E76E4[dword_1E7718]; /*0x18c76d*/
    __outbyte(0x21u, v6); /*0x18c77b*/
    _InterlockedIncrement(dword_1E7618); /*0x18c77c*/
    __outbyte(0xA1u, HIBYTE(v6)); /*0x18c78e*/
    _InterlockedIncrement(dword_1E7618); /*0x18c78f*/
  }
  __readeflags(); /*0x18c796*/
  if ( (v3 & 0x200) != 0 ) /*0x18c79a*/
    _enable(); /*0x18c79c*/
  else
    _disable(); /*0x18c7a0*/
  return 1; /*0x18c7a9*/
}
