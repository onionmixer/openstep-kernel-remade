/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d4f8. */
int pcb_module_init()
{
  int result; // eax

  result = zinit(244, 124928, 0x3D00u, 0, (int)&unk_1E2478); /*0x18d511*/
  pcb_zone = result; /*0x18d516*/
  return result; /*0x18d51d*/
}
