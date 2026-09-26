/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9f58. */
id __cdecl -[Object perform:with:with:](Object *self, SEL sel, SEL a3, id a4, id a5)
{
  const char *Name; // eax

  if ( a3 ) /*0x1c9f64*/
    return objc_msgSend(self, a3, a4, a5); /*0x1c9f96*/
  Name = sel_getName(sel); /*0x1c9f6c*/
  return -[Object error:](self, sel_error_, "method %s given invalid selector %s", Name, 0); /*0x1c9f9b*/
}
