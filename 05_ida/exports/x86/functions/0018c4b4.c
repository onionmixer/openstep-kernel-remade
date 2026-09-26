/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c4b4. */
int __cdecl intr_unregister_irq(unsigned int a1)
{
  __int16 v2; // kr00_2
  __int16 *v3; // edi
  __int16 v4; // di
  int v5; // [esp+Ch] [ebp-4h]

  if ( a1 > 0xF || a1 == 2 || !dword_1E7628[3 * a1] ) /*0x18c4d4*/
    return 0; /*0x18c4dd*/
  v2 = __readeflags(); /*0x18c4e4*/
  _disable(); /*0x18c4e6*/
  dword_1E7624[3 * a1] = 0; /*0x18c4ef*/
  dword_1E7628[3 * a1] = 0; /*0x18c4f9*/
  dword_1E762C[3 * a1] = 0; /*0x18c503*/
  v5 = 0; /*0x18c51b*/
  v3 = word_1E76E4; /*0x18c522*/
  do /*0x18c535*/
  {
    *v3 |= 1 << a1; /*0x18c528*/
    ++v5; /*0x18c52b*/
    ++v3; /*0x18c52e*/
  }
  while ( v5 <= 7 ); /*0x18c535*/
  v4 = word_1E771E | word_1E76E4[dword_1E7718]; /*0x18c544*/
  if ( word_1E771C != v4 ) /*0x18c552*/
  {
    word_1E771C = word_1E771E | word_1E76E4[dword_1E7718]; /*0x18c554*/
    __outbyte(0x21u, v4); /*0x18c564*/
    _InterlockedIncrement(dword_1E7618); /*0x18c565*/
    __outbyte(0xA1u, HIBYTE(v4)); /*0x18c577*/
    _InterlockedIncrement(dword_1E7618); /*0x18c578*/
  }
  __readeflags(); /*0x18c57f*/
  if ( (v2 & 0x200) != 0 ) /*0x18c583*/
    _enable(); /*0x18c585*/
  else
    _disable(); /*0x18c588*/
  intr_change_mode(a1, 0); /*0x18c58c*/
  return 1; /*0x18c599*/
}
