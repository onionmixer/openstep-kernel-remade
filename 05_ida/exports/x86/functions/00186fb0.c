/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186fb0. */
// Alternative name is '_jump_label'
void __cdecl __noreturn longjmp(jmp_buf a1, int a2)
{
  int retaddr; // [esp+0h] [ebp+0h]

  retaddr = a1[5]; /*0x186fc6*/
  splx(a1[6]); /*0x186fcd*/
}
