/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9568. */
int __cdecl -[IOBufDevice errnoFromReturn:](IOBufDevice *self, SEL a2, int a3)
{
  objc_super v4; // [esp+0h] [ebp-8h] BYREF

  if ( a3 == -801 ) /*0x1a9576*/
    return 1; /*0x1a9588*/
  if ( a3 == -800 ) /*0x1a957d*/
    return 58; /*0x1a957f*/
  v4.receiver = self; /*0x1a959f*/
  v4.super_class = (Class)stru_1FA244.super_class; /*0x1a95a8*/
  return -[IODevice errnoFromReturn:](&v4, sel_errnoFromReturn_, a3); /*0x1a9584*/
}
