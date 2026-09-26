/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1860dc. */
void start()
{
  MEMORY[0x472] = 4660; /*0x1860e0*/
  gdt_init(); /*0x1860e7*/
  idt_init(); /*0x1860ec*/
  JUMPOUT(0x186578); /*0x186578*/
}
