/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8ae8. */
id __cdecl +[HashTable _newBare:::](id a1, SEL a2, const char *a3, const char *a4, unsigned int a5)
{
  int v5; // eax
  id v6; // eax
  SEL v8; // [esp-10h] [ebp-14h]

  v5 = NXDefaultMallocZone(sel__initBare_::, a3, a4, a5); /*0x1c8b02*/
  v6 = objc_msgSend(a1, sel_allocFromZone_, v5); /*0x1c8b10*/
  return objc_msgSend(v6, v8); /*0x1c8b1e*/
}
