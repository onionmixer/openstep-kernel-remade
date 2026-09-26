/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b28c4. */
id __cdecl -[EventDriver hideCursor](EventDriver *self, SEL a2)
{
  return -[EventDriver evDispatch:command:](self, sel_evDispatch_command_, self->currentScreen, 1); /*0x1b28e2*/
}
