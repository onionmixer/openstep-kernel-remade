/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9704. */
id __cdecl -[IONetwork free](IONetwork *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  if_detach((int)self->_netif); /*0x1a9712*/
  v3.receiver = self; /*0x1a971e*/
  v3.super_class = (Class)stru_1FA244.ext; /*0x1a9727*/
  return -[Object free](&v3, sel_free); /*0x1a9733*/
}
