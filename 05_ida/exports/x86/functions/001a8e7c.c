/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8e7c. */
id __cdecl -[NXConditionLock free](NXConditionLock *self, SEL a2)
{
  int *priv; // ebx
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  priv = (int *)self->_priv; /*0x1a8e87*/
  if ( priv ) /*0x1a8e8c*/
  {
    lock_free(priv[1]); /*0x1a8e92*/
    simple_lock_free(*priv); /*0x1a8e9a*/
    kfree((int)priv, 0xCu); /*0x1a8ea2*/
  }
  v4.receiver = self; /*0x1a8eb1*/
  v4.super_class = (Class)stru_1FA1F4.super_class; /*0x1a8eba*/
  return -[Object free](&v4, sel_free); /*0x1a8ec9*/
}
