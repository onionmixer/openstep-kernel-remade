/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e7b0. */
void __cdecl sub_16E7B0(int *a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax

  if ( a1[1] == 40 && *a1 < 0 && (a1[6] & 0x3FFFFFFF) == 0x10012011 && a1[8] == dword_1E0150 ) /*0x16e7db*/
  {
    v2 = convert_port_to_task(a1[2]); /*0x16e7f5*/
    v3 = convert_port_to_pset(a1[7]); /*0x16e800*/
    *(_DWORD *)(a2 + 28) = task_assign(v2, v3, a1[9]); /*0x16e810*/
    pset_deallocate(v3); /*0x16e814*/
    task_deallocate(v2); /*0x16e81a*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16e825*/
    {
      v4 = a1[7]; /*0x16e82b*/
      if ( v4 ) /*0x16e830*/
      {
        if ( v4 != -1 ) /*0x16e835*/
          ipc_port_release_send(a1[7]); /*0x16e838*/
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e7e0*/
  }
}
