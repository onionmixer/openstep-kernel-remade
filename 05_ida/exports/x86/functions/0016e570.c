/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e570. */
void __cdecl sub_16E570(int *a1, int a2)
{
  int v2; // esi
  processor_t v3; // eax
  int v4; // eax
  boolean_t v5; // [esp-8h] [ebp-14h]

  if ( a1[1] == 40 && *a1 < 0 && (a1[6] & 0x3FFFFFFF) == 0x10012011 && a1[8] == dword_1E0144 ) /*0x16e59e*/
  {
    v2 = convert_port_to_pset(a1[7]); /*0x16e5b5*/
    v5 = a1[9]; /*0x16e5ba*/
    v3 = convert_port_to_processor(a1[2]); /*0x16e5c0*/
    *(_DWORD *)(a2 + 28) = processor_assign(v3, v2, v5); /*0x16e5ce*/
    pset_deallocate(v2); /*0x16e5d2*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16e5da*/
    {
      v4 = a1[7]; /*0x16e5e0*/
      if ( v4 ) /*0x16e5e5*/
      {
        if ( v4 != -1 ) /*0x16e5ea*/
          ipc_port_release_send(a1[7]); /*0x16e5ed*/
      }
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e5a0*/
  }
}
