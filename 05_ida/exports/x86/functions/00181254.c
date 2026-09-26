/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181254. */
id __cdecl -[KernDeviceDescription free](KernDeviceDescription *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->_stringTable, sel_freeKeys_values_, sub_181A08, sub_181A10); /*0x181273*/
  objc_msgSend(self->_stringTable, sel_free); /*0x181283*/
  objc_msgSend(self->_resourceTable, sel_freeKeys_values_, sub_181A08, sub_181A38); /*0x18129d*/
  objc_msgSend(self->_resourceTable, sel_free); /*0x1812b0*/
  objc_msgSend(self->_interruptList, sel_free); /*0x1812c0*/
  v3.receiver = self; /*0x1812cc*/
  v3.super_class = (Class)stru_1F9FC4.super_class; /*0x1812d5*/
  return -[Object free](&v3, sel_free); /*0x1812e1*/
}
