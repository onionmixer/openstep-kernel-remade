/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5d60. */
int __cdecl -[IODisk errnoFromReturn:](IODisk *self, SEL a2, int a3)
{
  objc_super v4; // [esp+0h] [ebp-8h] BYREF

  if ( a3 == -1101 ) /*0x1a5d6e*/
    return 22; /*0x1a5d94*/
  if ( a3 <= -1101 ) /*0x1a5d70*/
  {
    if ( a3 != -1102 ) /*0x1a5d77*/
      goto LABEL_8; /*0x1a5d77*/
    return 6; /*0x1a5d8b*/
  }
  if ( a3 == -1100 ) /*0x1a5d81*/
    return 6; /*0x1a5d81*/
LABEL_8:
  v4.receiver = self; /*0x1a5d98*/
  v4.super_class = (Class)stru_1FA104.super_class; /*0x1a5dac*/
  return -[IODevice errnoFromReturn:](&v4, sel_errnoFromReturn_, a3); /*0x1a5d88*/
}
