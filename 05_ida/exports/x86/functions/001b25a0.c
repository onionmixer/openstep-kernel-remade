/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b25a0. */
void __cdecl -[EventDriver changeCursor:](EventDriver *self, SEL a2, int a3)
{
  int v3; // eax

  v3 = 1; /*0x1b25b1*/
  if ( a3 <= 3 ) /*0x1b25b9*/
    v3 = a3; /*0x1b25bb*/
  *((_DWORD *)self->evg + 7) = v3; /*0x1b25bd*/
  -[EventDriver moveCursor](self, sel_moveCursor); /*0x1b25c8*/
}
