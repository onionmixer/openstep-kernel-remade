/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1765ac. */
int __cdecl vm_map_remove(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int v5; // ebx

  v3 = a2; /*0x1765b5*/
  v4 = a3; /*0x1765b8*/
  lock_write((int)a1); /*0x1765bc*/
  ++a1[19]; /*0x1765c1*/
  if ( a2 < a1[5] ) /*0x1765cc*/
    v3 = a1[5]; /*0x1765ce*/
  if ( a3 > a1[6] ) /*0x1765d5*/
    v4 = a1[6]; /*0x1765d7*/
  if ( v3 > v4 ) /*0x1765db*/
    v3 = v4; /*0x1765dd*/
  v5 = vm_map_delete((int)a1, v3, v4); /*0x1765e7*/
  lock_done((int)a1); /*0x1765ea*/
  return v5; /*0x1765f4*/
}
