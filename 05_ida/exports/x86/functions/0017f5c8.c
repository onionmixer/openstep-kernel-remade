/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f5c8. */
id __cdecl -[KernBus allocateResourcesForDeviceDescription:](KernBus *self, SEL a2, id a3)
{
  const char **v3; // ebx

  v3 = -[KernBus resourceNames](self, sel_resourceNames); /*0x17f5e0*/
  if ( v3 ) /*0x17f5e7*/
  {
    while ( *v3 ) /*0x17f5f0*/
    {
      if ( !objc_msgSend(a3, sel_allocateResourcesForKey_, *v3) ) /*0x17f5fb*/
        return nullptr; /*0x17f609*/
      if ( !++v3 ) /*0x17f60f*/
        return a3; /*0x17f60f*/
    }
  }
  return a3; /*0x17f616*/
}
