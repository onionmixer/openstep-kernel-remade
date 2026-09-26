/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178400. */
int __cdecl vm_map_machine_attribute(_DWORD *a1, unsigned int a2, int a3, int a4, int a5)
{
  int v6; // esi

  if ( a1[5] > a2 || a1[6] < a3 + a2 ) /*0x17841a*/
    return 4; /*0x17841c*/
  lock_write((int)a1); /*0x178425*/
  ++a1[19]; /*0x17842a*/
  v6 = pmap_attribute(a1[9], a2, a3, a4, a5); /*0x178443*/
  lock_done((int)a1); /*0x178446*/
  return v6; /*0x178450*/
}
