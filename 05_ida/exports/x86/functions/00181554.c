/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181554. */
char __cdecl -[KernDeviceDescription removeResourcesForKey:](KernDeviceDescription *self, SEL a2, const char *a3)
{
  unsigned int i; // ebx
  id v4; // eax
  id v6; // [esp+Ch] [ebp-4h]

  v6 = objc_msgSend(self->_resourceTable, sel_removeKey_, a3); /*0x181574*/
  if ( v6 ) /*0x18157c*/
  {
    if ( !strcmp(a3, aIrqLevels_0) ) /*0x18158f*/
    {
      for ( i = 0; i < (unsigned int)objc_msgSend(v6, sel_count); ++i ) /*0x1815a2*/
      {
        v4 = objc_msgSend(v6, sel_objectAt_, i); /*0x1815c7*/
        objc_msgSend(self->_interruptList, sel_removeObject_, v4); /*0x1815db*/
      }
    }
    objc_msgSend(v6, sel_freeObjects); /*0x1815f3*/
    objc_msgSend(v6, sel_free); /*0x181603*/
  }
  return 0; /*0x18160d*/
}
