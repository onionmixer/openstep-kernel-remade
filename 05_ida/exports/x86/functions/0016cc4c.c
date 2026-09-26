/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cc4c. */
int __cdecl kern_serv_port_death_proc(int a1, int a2)
{
  *(_DWORD *)(*(_DWORD *)a1 + 1208) = a2; /*0x16cc57*/
  return 0; /*0x16cc61*/
}
