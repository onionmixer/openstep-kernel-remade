/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ead0. */
id __cdecl -[KernBusItemResource _destroyItem:](KernBusItemResource *self, SEL a2, id a3)
{
  char *items; // esi
  char *v4; // eax
  int itemCount; // eax

  items = (char *)self->_items; /*0x17eadc*/
  if ( !(unsigned __int8)objc_msgSend(a3, sel_isKindOf_, self->_kind) ) /*0x17eaeb*/
    return nullptr; /*0x17eaeb*/
  v4 = &items[4 * (*((_DWORD *)a3 + 2) - self->_base)]; /*0x17eafd*/
  if ( !*(_DWORD *)v4 ) /*0x17eb00*/
    return nullptr; /*0x17eb05*/
  *(_DWORD *)v4 = 0; /*0x17eb0c*/
  itemCount = self->_itemCount; /*0x17eb12*/
  self->_itemCount = itemCount - 1; /*0x17eb18*/
  if ( itemCount == 1 ) /*0x17eb1e*/
    objc_msgSend(self->_owner, sel__resourceInactive); /*0x17eb2b*/
  return objc_msgSend(a3, sel_dealloc); /*0x17eb43*/
}
