/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e9dc. */
void __cdecl sub_16E9DC(int *a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax

  if ( a1[1] == 40 && *a1 < 0 && (a1[6] & 0x3FFFFFFF) == 0x10012011 && a1[8] == dword_1E0170 ) /*0x16ea07*/
  {
    v2 = convert_port_to_thread(a1[2]); /*0x16ea21*/
    v3 = convert_port_to_pset(a1[7]); /*0x16ea2c*/
    *(_DWORD *)(a2 + 28) = thread_max_priority(v2, v3, a1[9]); /*0x16ea3c*/
    pset_deallocate(v3); /*0x16ea40*/
    thread_deallocate(v2); /*0x16ea46*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16ea51*/
    {
      v4 = a1[7]; /*0x16ea57*/
      if ( v4 ) /*0x16ea5c*/
      {
        if ( v4 != -1 ) /*0x16ea61*/
          ipc_port_release_send(a1[7]); /*0x16ea64*/
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ea0c*/
  }
}
