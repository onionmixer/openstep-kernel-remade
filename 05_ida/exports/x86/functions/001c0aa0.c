/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0aa0. */
id __cdecl -[IODirectDevice initEISA](IODirectDevice *self, SEL a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)IOMalloc(4u); /*0x1c0aa9*/
  self->_busPrivate = v2; /*0x1c0aae*/
  *v2 = 1; /*0x1c0ab4*/
  return self; /*0x1c0abc*/
}
