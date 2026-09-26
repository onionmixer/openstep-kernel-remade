/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9ecc. */
id __cdecl -[Object perform:](Object *self, SEL sel, SEL a3)
{
  const char *Name; // eax

  if ( a3 ) /*0x1c9ed8*/
    return objc_msgSend(self, a3); /*0x1c9f02*/
  Name = sel_getName(sel); /*0x1c9ee0*/
  return -[Object error:](self, sel_error_, "method %s given invalid selector %s", Name, 0); /*0x1c9f07*/
}
