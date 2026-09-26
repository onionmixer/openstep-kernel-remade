/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e934. */
id __cdecl -[KernBusItemResource free](KernBusItemResource *self, SEL a2)
{
  void *items; // eax
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  if ( self->_itemCount > 0 ) /*0x17e942*/
    return self; /*0x17e944*/
  if ( self->_count ) /*0x17e948*/
  {
    items = self->_items; /*0x17e94e*/
    if ( items ) /*0x17e953*/
      IOFree((int)items, 4); /*0x17e958*/
  }
  v4.receiver = self; /*0x17e967*/
  v4.super_class = (Class)stru_1F9ED4.super_class; /*0x17e970*/
  return -[Object free](&v4, sel_free); /*0x17e97c*/
}
