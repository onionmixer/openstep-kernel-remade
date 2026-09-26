/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1788. */
char __cdecl -[IODirectDevice isPCIPresent](IODirectDevice *self, SEL a2)
{
  id v2; // eax

  v2 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c17a0*/
  if ( v2 ) /*0x1c17aa*/
    return (unsigned __int8)objc_msgSend(v2, sel_isPCIPresent); /*0x1c17b4*/
  else
    return 0; /*0x1c17c0*/
}
