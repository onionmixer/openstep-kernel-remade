/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a904. */
int __cdecl locate_gdt(int a1)
{
  int result; // eax

  result = a1; /*0x18a907*/
  gdt_base = a1; /*0x18a90a*/
  gdt_limit = 255; /*0x18a90f*/
  __lgdt(&gdt_limit); /*0x18a918*/
  return result; /*0x18a921*/
}
