/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c638. */
int __cdecl intr_disable_irq(unsigned int a1)
{
  __int16 v2; // kr00_2
  __int16 v3; // cx

  if ( a1 > 0xF || a1 == 2 ) /*0x18c647*/
    return 0; /*0x18c649*/
  v2 = __readeflags(); /*0x18c650*/
  _disable(); /*0x18c652*/
  word_1E771E |= 1 << a1; /*0x18c66b*/
  v3 = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c679*/
  if ( word_1E771C != v3 ) /*0x18c688*/
  {
    word_1E771C = word_1E76E4[dword_1E7718] | word_1E771E; /*0x18c68a*/
    __outbyte(0x21u, v3); /*0x18c698*/
    _InterlockedIncrement(dword_1E7618); /*0x18c699*/
    __outbyte(0xA1u, HIBYTE(v3)); /*0x18c6ab*/
    _InterlockedIncrement(dword_1E7618); /*0x18c6ac*/
  }
  __readeflags(); /*0x18c6b3*/
  if ( (v2 & 0x200) != 0 ) /*0x18c6b7*/
    _enable(); /*0x18c6b9*/
  else
    _disable(); /*0x18c6bc*/
  return 1; /*0x18c6c2*/
}
