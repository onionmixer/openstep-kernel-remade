/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: matrox snapshot; requested VA: 0x1c1748. */
char __cdecl +[IODirectDevice isPCIPresent](id a1, SEL a2)
{
  id v2; // eax

  v2 = +[KernBus lookupBusInstanceWithName:busId:](aKernbus, sel_lookupBusInstanceWithName_busId_, "PCI", 0); /*0x1c1760*/
  if ( v2 ) /*0x1c176a*/
    return (unsigned __int8)objc_msgSend(v2, sel_isPCIPresent); /*0x1c1774*/
  else
    return 0; /*0x1c1780*/
}
