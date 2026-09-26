/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181360. */
const char *__cdecl -[KernDeviceDescription stringForKey:](KernDeviceDescription *self, SEL a2, const char *a3)
{
  const char *v3; // ebx
  const char *v4; // eax

  v3 = (const char *)objc_msgSend(self->_stringTable, sel_valueForKey_, a3); /*0x18137d*/
  if ( !v3 ) /*0x181384*/
  {
    v4 = (const char *)objc_msgSend(self->_configTable, sel_valueForStringKey_, a3); /*0x181392*/
    v3 = v4; /*0x181397*/
    if ( v4 ) /*0x18139e*/
      objc_msgSend(self->_stringTable, sel_insertKey_value_, a3, v4); /*0x1813ad*/
  }
  return v3; /*0x1813b7*/
}
