/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b184. */
int __cdecl locate_idt(int a1)
{
  int result; // eax

  result = a1; /*0x18b187*/
  idt_base = a1; /*0x18b18a*/
  idt_limit = 2047; /*0x18b18f*/
  __lidt(&idt_limit); /*0x18b198*/
  return result; /*0x18b1a1*/
}
