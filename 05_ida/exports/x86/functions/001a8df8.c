/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8df8. */
NXConditionLock *__cdecl -[NXConditionLock initWith:](NXConditionLock *self, SEL a2, int a3)
{
  _DWORD *priv; // ebx
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  priv = self->_priv; /*0x1a8e03*/
  v5.receiver = self; /*0x1a8e0d*/
  v5.super_class = (Class)stru_1FA1F4.super_class; /*0x1a8e16*/
  -[Object init](&v5, sel_init); /*0x1a8e1d*/
  if ( !priv ) /*0x1a8e27*/
  {
    priv = (_DWORD *)kalloc(0xCu); /*0x1a8e30*/
    *priv = simple_lock_alloc(); /*0x1a8e37*/
    priv[1] = lock_alloc(); /*0x1a8e3e*/
    self->_priv = priv; /*0x1a8e41*/
  }
  *(_DWORD *)*priv = 0; /*0x1a8e49*/
  lock_init((_DWORD *)priv[1], 1); /*0x1a8e55*/
  priv[2] = a3; /*0x1a8e5d*/
  return self; /*0x1a8e65*/
}
