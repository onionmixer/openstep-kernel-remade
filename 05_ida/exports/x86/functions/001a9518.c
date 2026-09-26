/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9518. */
const char *__cdecl -[IOBufDevice stringFromReturn:](IOBufDevice *self, SEL a2, int a3)
{
  objc_super v4; // [esp+0h] [ebp-8h] BYREF

  if ( a3 == -801 ) /*0x1a9526*/
    return "Not Owner"; /*0x1a9538*/
  if ( a3 == -800 ) /*0x1a952d*/
    return "Buffer Flushed"; /*0x1a952f*/
  v4.receiver = self; /*0x1a954f*/
  v4.super_class = (Class)stru_1FA244.super_class; /*0x1a9558*/
  return -[IODevice stringFromReturn:](&v4, sel_stringFromReturn_, a3); /*0x1a9534*/
}
