/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1babbc. */
id __cdecl -[AudioCommand free](AudioCommand *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->interLock, sel_free); /*0x1babd1*/
  v3.receiver = self; /*0x1babdd*/
  v3.super_class = (Class)stru_1FA514.ext; /*0x1babe6*/
  return -[Object free](&v3, sel_free); /*0x1babf2*/
}
