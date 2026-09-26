/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c5a0. */
int __cdecl intr_enable_irq(unsigned int a1)
{
  __int16 v2; // kr00_2
  __int16 v3; // cx

  if ( a1 > 0xF || a1 == 2 ) /*0x18c5af*/
    return 0; /*0x18c5b1*/
  v2 = __readeflags(); /*0x18c5b8*/
  _disable(); /*0x18c5ba*/
  word_1E771E &= __ROL4__(-2, a1); /*0x18c5d4*/
  v3 = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c5e2*/
  if ( word_1E771C != v3 ) /*0x18c5f1*/
  {
    word_1E771C = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c5f3*/
    __outbyte(0x21u, v3); /*0x18c601*/
    _InterlockedIncrement(dword_1E7618); /*0x18c602*/
    __outbyte(0xA1u, HIBYTE(v3)); /*0x18c614*/
    _InterlockedIncrement(dword_1E7618); /*0x18c615*/
  }
  __readeflags(); /*0x18c61c*/
  if ( (v2 & 0x200) != 0 ) /*0x18c620*/
    _enable(); /*0x18c622*/
  else
    _disable(); /*0x18c628*/
  return 1; /*0x18c62e*/
}
