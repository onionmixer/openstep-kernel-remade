/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a949c. */
int __cdecl -[IOBufDevice releaseUnit:](IOBufDevice *self, SEL a2, unsigned int a3)
{
  $56D1BF522F95260DED69B470E8535AF1 *v3; // ebx

  v3 = &self->unitInfo[a3]; /*0x1a94b0*/
  if ( !v3->callbackId ) /*0x1a94b7*/
    return -801; /*0x1a94d8*/
  -[IOBufDevice shutdownUnit:](self, sel_shutdownUnit_, a3); /*0x1a94c5*/
  v3->callbackId = nullptr; /*0x1a94ca*/
  self->unitInfo[a3].ownerName[0] = 0; /*0x1a94d0*/
  return 0; /*0x1a94e0*/
}
