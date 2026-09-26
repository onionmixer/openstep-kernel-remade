/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f358. */
id __cdecl +[KernBus initialize](id a1, SEL a2)
{
  HashTable *v2; // eax
  HashTable *v3; // eax

  if ( !dword_1E731C ) /*0x17f362*/
  {
    v2 = +[Object alloc](aHashtable, sel_alloc); /*0x17f37e*/
    dword_1E731C = -[HashTable initKeyDesc:](v2, sel_initKeyDesc_); /*0x17f38c*/
  }
  if ( !dword_1E7320 ) /*0x17f39b*/
  {
    v3 = +[Object alloc](aHashtable, sel_alloc); /*0x17f3b7*/
    dword_1E7320 = -[HashTable initKeyDesc:](v3, sel_initKeyDesc_); /*0x17f3c5*/
  }
  return a1; /*0x17f3cf*/
}
