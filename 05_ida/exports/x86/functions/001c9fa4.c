/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9fa4. */
id __cdecl -[Object subclassResponsibility:](Object *self, SEL a2, SEL sel)
{
  const char *Name; // eax

  Name = sel_getName(sel); /*0x1c9faf*/
  return -[Object error:](self, sel_error_, "should have implemented the '%s' method.", Name); /*0x1c9fc7*/
}
