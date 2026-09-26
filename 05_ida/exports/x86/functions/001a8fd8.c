/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8fd8. */
NXLock *__cdecl -[NXLock init](NXLock *self, SEL a2)
{
  _DWORD **priv; // ebx
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  priv = (_DWORD **)self->_priv; /*0x1a8fe3*/
  v4.receiver = self; /*0x1a8fed*/
  v4.super_class = (Class)stru_1FA1F4.ext; /*0x1a8ff6*/
  -[Object init](&v4, sel_init); /*0x1a8ffd*/
  if ( !priv ) /*0x1a9007*/
  {
    priv = (_DWORD **)kalloc(4u); /*0x1a9010*/
    *priv = (_DWORD *)lock_alloc(); /*0x1a9017*/
    self->_priv = priv; /*0x1a9019*/
  }
  lock_init(*priv, 1); /*0x1a9024*/
  return self; /*0x1a902e*/
}
