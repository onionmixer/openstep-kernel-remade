/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9658. */
id __cdecl -[List freeObjects](List *self, SEL a2)
{
  id v2; // eax

  while ( 1 ) /*0x1c9668*/
  {
    v2 = -[List removeLastObject](self, sel_removeLastObject); /*0x1c9668*/
    if ( !v2 ) /*0x1c9672*/
      break; /*0x1c9672*/
    objc_msgSend(v2, sel_free); /*0x1c967c*/
  }
  return self; /*0x1c968a*/
}
