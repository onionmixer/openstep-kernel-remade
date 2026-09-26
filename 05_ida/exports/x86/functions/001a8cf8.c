/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8cf8. */
NXSpinLock *__cdecl -[NXSpinLock init](NXSpinLock *self, SEL a2)
{
  _DWORD *priv; // ebx
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  priv = self->_priv; /*0x1a8d03*/
  v4.receiver = self; /*0x1a8d0d*/
  v4.super_class = (Class)stru_1FA1A4.ext; /*0x1a8d16*/
  -[Object init](&v4, sel_init); /*0x1a8d1d*/
  if ( !priv ) /*0x1a8d27*/
  {
    priv = (_DWORD *)kalloc(4u); /*0x1a8d30*/
    *priv = simple_lock_alloc(); /*0x1a8d37*/
    self->_priv = priv; /*0x1a8d39*/
  }
  *(_DWORD *)*priv = 0; /*0x1a8d3e*/
  return self; /*0x1a8d49*/
}
