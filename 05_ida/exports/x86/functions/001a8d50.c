/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8d50. */
id __cdecl -[NXSpinLock free](NXSpinLock *self, SEL a2)
{
  int *priv; // ebx
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  priv = (int *)self->_priv; /*0x1a8d5b*/
  if ( priv ) /*0x1a8d60*/
  {
    simple_lock_free(*priv); /*0x1a8d65*/
    kfree((int)priv, 4u); /*0x1a8d6d*/
  }
  v4.receiver = self; /*0x1a8d7c*/
  v4.super_class = (Class)stru_1FA1A4.ext; /*0x1a8d85*/
  return -[Object free](&v4, sel_free); /*0x1a8d94*/
}
