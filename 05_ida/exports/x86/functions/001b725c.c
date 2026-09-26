/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b725c. */
id __cdecl -[IOAudio free](IOAudio *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  +[IOAudio _setInstance:](aIoaudio, sel__setInstance_, 0); /*0x1b7276*/
  IOFree((int)self->_audioPrivate, 28); /*0x1b7284*/
  v3.receiver = self; /*0x1b7290*/
  v3.super_class = (Class)stru_1FA474.super_class; /*0x1b7299*/
  return -[IODirectDevice free](&v3, sel_free); /*0x1b72a5*/
}
