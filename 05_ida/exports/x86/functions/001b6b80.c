/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6b80. */
int __cdecl -[IOAudio _analogInputSource](IOAudio *self, SEL a2)
{
  _BYTE *audioPrivate; // eax

  audioPrivate = self->_audioPrivate; /*0x1b6b86*/
  if ( audioPrivate[16] ) /*0x1b6b8c*/
    return 30; /*0x1b6b92*/
  if ( audioPrivate[17] || audioPrivate[18] || audioPrivate[19] ) /*0x1b6bb2*/
    return 33; /*0x1b6ba2*/
  if ( audioPrivate[20] ) /*0x1b6bb8*/
    return 34; /*0x1b6bc4*/
  return 0; /*0x1b6b99*/
}
