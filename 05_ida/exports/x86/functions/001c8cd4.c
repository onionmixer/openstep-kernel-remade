/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8cd4. */
id __cdecl -[HashTable freeObjects](HashTable *self, SEL a2)
{
  void *v2; // edx
  void *v3; // edx
  void *v5; // [esp-4h] [ebp-8h]

  v2 = sub_1C8A78; /*0x1c8cde*/
  if ( *self->valueDesc == 64 ) /*0x1c8ce6*/
    v2 = sub_1C8A60; /*0x1c8ce8*/
  v5 = v2; /*0x1c8ced*/
  v3 = sub_1C8A78; /*0x1c8cf1*/
  if ( *self->keyDesc == 64 ) /*0x1c8cf9*/
    v3 = sub_1C8A60; /*0x1c8cfb*/
  return -[HashTable freeKeys:values:](self, sel_freeKeys_values_, v3, v5); /*0x1c8d0e*/
}
