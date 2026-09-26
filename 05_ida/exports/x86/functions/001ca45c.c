/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca45c. */
id __cdecl -[Object shouldNotImplement:](Object *self, SEL a2, SEL sel)
{
  const char *Name; // eax

  Name = sel_getName(sel); /*0x1ca467*/
  return -[Object error:](self, sel_error_, "should NOT have implemented the '%s' method.", Name); /*0x1ca47f*/
}
