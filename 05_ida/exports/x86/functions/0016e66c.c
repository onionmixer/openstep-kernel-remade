/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e66c. */
void __cdecl sub_16E66C(int *a1, int a2)
{
  int v2; // esi
  int v3; // ebx
  int v4; // eax

  if ( a1[1] == 32 && *a1 < 0 && (a1[6] & 0x3FFFFFFF) == 0x10012011 ) /*0x16e68d*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16e6a5*/
    v3 = convert_port_to_pset(a1[7]); /*0x16e6b0*/
    *(_DWORD *)(a2 + 28) = thread_assign(v2, v3); /*0x16e6bc*/
    pset_deallocate(v3); /*0x16e6c0*/
    thread_deallocate(v2); /*0x16e6c6*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16e6d1*/
    {
      v4 = a1[7]; /*0x16e6d7*/
      if ( v4 ) /*0x16e6dc*/
      {
        if ( v4 != -1 ) /*0x16e6e1*/
          ipc_port_release_send(a1[7]); /*0x16e6e4*/
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e692*/
  }
}
