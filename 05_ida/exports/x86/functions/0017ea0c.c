/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ea0c. */
id __cdecl -[KernBusItemResource shareItem:](KernBusItemResource *self, SEL a2, unsigned int a3)
{
  unsigned int base; // edx
  id *v5; // esi
  id v6; // eax
  id v7; // eax
  int itemCount; // eax

  base = self->_base; /*0x17ea1b*/
  if ( a3 < base || a3 >= self->_count + base ) /*0x17ea29*/
    return nullptr; /*0x17ea2b*/
  v5 = (id *)((char *)self->_items + 4 * (a3 - base)); /*0x17ea34*/
  if ( *v5 ) /*0x17ea37*/
    return objc_msgSend(*v5, sel_share); /*0x17ea45*/
  v6 = objc_msgSend(self->_kind, sel_alloc); /*0x17ea62*/
  v7 = objc_msgSend(v6, sel_initForResource_item_shareable_); /*0x17ea6b*/
  *v5 = v7; /*0x17ea70*/
  if ( v7 ) /*0x17ea77*/
  {
    itemCount = self->_itemCount; /*0x17ea79*/
    self->_itemCount = itemCount + 1; /*0x17ea7f*/
    if ( !itemCount ) /*0x17ea84*/
      objc_msgSend(self->_owner, sel__resourceActive); /*0x17ea91*/
  }
  return *v5; /*0x17ea9b*/
}
