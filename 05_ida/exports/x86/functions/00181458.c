/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181458. */
id __cdecl -[KernDeviceDescription setResources:forKey:](KernDeviceDescription *self, SEL a2, id a3, const char *a4)
{
  id v4; // eax
  void *v5; // ebx

  if ( !strcmp(a4, aIrqLevels_0) ) /*0x181472*/
  {
    objc_msgSend(self->_interruptList, sel_empty); /*0x181494*/
    objc_msgSend(self->_interruptList, sel_appendList_, a3); /*0x1814ab*/
  }
  v4 = objc_msgSend(self->_resourceTable, sel_insertKey_value_, a4, a3); /*0x1814c6*/
  v5 = v4; /*0x1814cb*/
  if ( v4 && a3 != v4 ) /*0x1814d7*/
  {
    objc_msgSend(v4, sel_freeObjects); /*0x1814e1*/
    objc_msgSend(v5, sel_free); /*0x1814ee*/
  }
  return self; /*0x1814f9*/
}
