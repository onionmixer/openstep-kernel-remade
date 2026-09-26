/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca0fc. */
id __cdecl -[Object performv::](Object *self, SEL a2, SEL op, void *a4)
{
  id v5; // eax

  if ( !self ) /*0x1ca109*/
    return nullptr; /*0x1ca10b*/
  v5 = -[Object methodArgSize:](self, sel_methodArgSize_, op); /*0x1ca119*/
  if ( v5 ) /*0x1ca123*/
    return objc_msgSendv(self, op, (size_t)v5, a4); /*0x1ca12c*/
  else
    return -[Object doesNotRecognize:](self, sel_doesNotRecognize_, op); /*0x1ca13d*/
}
