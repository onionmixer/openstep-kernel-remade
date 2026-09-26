/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0ac4. */
id __cdecl -[IODirectDevice freeEISA](IODirectDevice *self, SEL a2)
{
  IOFree((int)self->_busPrivate, 4); /*0x1c0ad4*/
  return self; /*0x1c0adb*/
}
