/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9f10. */
id __cdecl -[Object perform:with:](Object *self, SEL sel, SEL a3, id a4)
{
  const char *Name; // eax

  if ( a3 ) /*0x1c9f1c*/
    return objc_msgSend(self, a3, a4); /*0x1c9f4a*/
  Name = sel_getName(sel); /*0x1c9f24*/
  return -[Object error:](self, sel_error_, "method %s given invalid selector %s", Name, 0); /*0x1c9f4f*/
}
