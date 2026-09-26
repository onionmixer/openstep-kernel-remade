/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c20d8. */
id __cdecl -[IOPCMCIADeviceDescription free](IOPCMCIADeviceDescription *self, SEL a2)
{
  unsigned int *pcmcia_private; // esi
  unsigned int i; // ebx
  objc_super v5; // [esp+Ch] [ebp-8h] BYREF

  pcmcia_private = (unsigned int *)self->_pcmcia_private; /*0x1c20e4*/
  if ( pcmcia_private[1] ) /*0x1c20e7*/
  {
    for ( i = 0; *pcmcia_private > i; ++i ) /*0x1c20ef*/
      objc_msgSend(*(id *)(pcmcia_private[1] + 4 * i), sel_free); /*0x1c2102*/
    IOFree(pcmcia_private[1], 4 * *pcmcia_private); /*0x1c211d*/
  }
  IOFree((int)pcmcia_private, 8); /*0x1c2128*/
  v5.receiver = self; /*0x1c2134*/
  v5.super_class = (Class)stru_1FA5B4.super_class; /*0x1c213d*/
  return -[IOEISADeviceDescription free](&v5, sel_free); /*0x1c214c*/
}
