/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1746a0. */
_DWORD *__cdecl vm_map_create(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // ebx

  v4 = (_DWORD *)zalloc(vm_map_zone); /*0x1746b0*/
  if ( !v4 ) /*0x1746b7*/
    panic(aVmMapCreate); /*0x1746be*/
  v4[4] = v4 + 3; /*0x1746c9*/
  v4[3] = v4 + 3; /*0x1746cc*/
  v4[7] = 0; /*0x1746cf*/
  v4[8] = a4; /*0x1746d9*/
  v4[10] = 0; /*0x1746dc*/
  v4[12] = 1; /*0x1746e3*/
  v4[9] = a1; /*0x1746ed*/
  v4[11] = 1; /*0x1746f0*/
  v4[5] = a2; /*0x1746fa*/
  v4[6] = a3; /*0x174700*/
  v4[18] = 0; /*0x174703*/
  v4[17] = 0; /*0x17470a*/
  v4[16] = v4 + 3; /*0x174711*/
  v4[14] = v4 + 3; /*0x174714*/
  v4[19] = 0; /*0x174717*/
  lock_init(v4, 1); /*0x174721*/
  v4[19] = 0; /*0x174726*/
  v4[13] = 0; /*0x17472d*/
  v4[15] = 0; /*0x174734*/
  return v4; /*0x17473d*/
}
