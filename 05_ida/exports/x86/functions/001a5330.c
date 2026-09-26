/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5330. */
id __cdecl -[IOConfigTable free](IOConfigTable *self, SEL a2)
{
  void *v2; // edx
  objc_super v4; // [esp+Ch] [ebp-8h] BYREF

  v2 = self->_private; /*0x1a533c*/
  if ( v2 ) /*0x1a5341*/
    IOFree((int)v2, strlen((const char *)self->_private) + 1); /*0x1a5355*/
  v4.receiver = self; /*0x1a5364*/
  v4.super_class = (Class)stru_1FA0B4.ext; /*0x1a536d*/
  return -[Object free](&v4, sel_free); /*0x1a537c*/
}
