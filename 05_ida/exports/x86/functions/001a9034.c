/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9034. */
id __cdecl -[NXLock free](NXLock *self, SEL a2)
{
  int *priv; // ebx
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  priv = (int *)self->_priv; /*0x1a903f*/
  if ( priv ) /*0x1a9044*/
  {
    lock_free(*priv); /*0x1a9049*/
    kfree((int)priv, 4u); /*0x1a9051*/
  }
  v4.receiver = self; /*0x1a9060*/
  v4.super_class = (Class)stru_1FA1F4.ext; /*0x1a9069*/
  return -[Object free](&v4, sel_free); /*0x1a9078*/
}
