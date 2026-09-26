/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e984. */
id __cdecl -[KernBusItemResource reserveItem:](KernBusItemResource *self, SEL a2, unsigned int a3)
{
  unsigned int base; // edx
  id *v4; // esi
  id v6; // eax
  id v7; // eax
  int itemCount; // eax

  base = self->_base; /*0x17e993*/
  if ( a3 < base ) /*0x17e998*/
    return nullptr; /*0x17e998*/
  if ( a3 >= self->_count + base ) /*0x17e9a1*/
    return nullptr; /*0x17e9a1*/
  v4 = (id *)((char *)self->_items + 4 * (a3 - base)); /*0x17e9a7*/
  if ( *v4 ) /*0x17e9aa*/
    return nullptr; /*0x17e9af*/
  v6 = objc_msgSend(self->_kind, sel_alloc); /*0x17e9ca*/
  v7 = objc_msgSend(v6, sel_initForResource_item_shareable_); /*0x17e9d3*/
  *v4 = v7; /*0x17e9d8*/
  if ( v7 ) /*0x17e9df*/
  {
    itemCount = self->_itemCount; /*0x17e9e1*/
    self->_itemCount = itemCount + 1; /*0x17e9e7*/
    if ( !itemCount ) /*0x17e9ec*/
      objc_msgSend(self->_owner, sel__resourceActive); /*0x17e9f9*/
  }
  return *v4; /*0x17ea03*/
}
