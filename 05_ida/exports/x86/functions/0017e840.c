/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e840. */
KernBusItemResource *__cdecl -[KernBusItemResource initWithItemCount:itemBase:itemKind:owner:](
        KernBusItemResource *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        id a5,
        id a6)
{
  objc_super v7; // [esp+Ch] [ebp-8h] BYREF

  v7.receiver = self; /*0x17e859*/
  v7.super_class = (Class)stru_1F9ED4.super_class; /*0x17e862*/
  -[Object init](&v7, sel_init); /*0x17e869*/
  if ( a3 > 0x400 || a4 >= a3 + a4 ) /*0x17e881*/
    return (KernBusItemResource *)-[KernBusItemResource free](self, sel_free); /*0x17e88b*/
  self->_owner = a6; /*0x17e897*/
  if ( a5 ) /*0x17e89c*/
    self->_kind = a5; /*0x17e89e*/
  else
    self->_kind = objc_msgSend(&aKernbusitem, sel_class); /*0x17e8ba*/
  self->_items = (void *)IOMalloc(4 * a3); /*0x17e8ca*/
  self->_itemCount = 0; /*0x17e8cd*/
  bzero(self->_items, 4 * a3); /*0x17e8d9*/
  self->_count = a3; /*0x17e8de*/
  self->_base = a4; /*0x17e8e4*/
  return self; /*0x17e8ec*/
}
