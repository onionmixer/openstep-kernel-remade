/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9fd0. */
id __cdecl -[Object notImplemented:](Object *self, SEL a2, SEL sel)
{
  const char *Name; // eax

  Name = sel_getName(sel); /*0x1c9fdb*/
  return -[Object error:](self, sel_error_, "method '%s' not implemented", Name); /*0x1c9ff3*/
}
