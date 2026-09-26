/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8be4. */
id __cdecl +[HashTable newKeyDesc:valueDesc:capacity:](id a1, SEL a2, const char *a3, const char *a4, unsigned int a5)
{
  int v5; // eax
  id v6; // eax
  SEL v8; // [esp-10h] [ebp-14h]

  v5 = NXDefaultMallocZone(sel_initKeyDesc_valueDesc_capacity_, a3, a4, a5); /*0x1c8bfe*/
  v6 = objc_msgSend(a1, sel_allocFromZone_, v5); /*0x1c8c0c*/
  return objc_msgSend(v6, v8); /*0x1c8c1a*/
}
