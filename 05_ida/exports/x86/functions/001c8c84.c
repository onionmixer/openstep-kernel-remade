/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8c84. */
id __cdecl -[HashTable free](HashTable *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[HashTable freeKeys:values:](self, sel_freeKeys_values_, sub_1C8A78, sub_1C8A78); /*0x1c8ca0*/
  free(self->_buckets); /*0x1c8ca9*/
  v3.receiver = self; /*0x1c8cb5*/
  v3.super_class = (Class)stru_1FA654.ext; /*0x1c8cbe*/
  return -[Object free](&v3, sel_free); /*0x1c8cca*/
}
