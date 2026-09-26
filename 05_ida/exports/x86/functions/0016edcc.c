/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16edcc. */
void __cdecl sub_16EDCC(int *a1, _DWORD *a2)
{
  int v2; // esi
  host_priv_t v3; // eax
  int v4; // eax
  processor_set_t set; // [esp+Ch] [ebp-4h] BYREF

  if ( a1[1] == 32 && *a1 < 0 && (a1[6] & 0x3FFFFFFF) == 0x10012011 ) /*0x16edf3*/
  {
    v2 = convert_port_to_pset_name(a1[7]); /*0x16ee09*/
    v3 = convert_port_to_host_priv(a1[2]); /*0x16ee14*/
    a2[7] = host_processor_set_priv(v3, v2, &set); /*0x16ee22*/
    pset_deallocate(v2); /*0x16ee26*/
    if ( !a2[7] ) /*0x16ee2e*/
    {
      v4 = a1[7]; /*0x16ee34*/
      if ( v4 ) /*0x16ee39*/
      {
        if ( v4 != -1 ) /*0x16ee3e*/
          ipc_port_release_send(a1[7]); /*0x16ee41*/
      }
      *a2 |= 0x80000000; /*0x16ee49*/
      a2[1] = 40; /*0x16ee4f*/
      a2[8] = dword_1E01BC; /*0x16ee5c*/
      a2[9] = convert_pset_to_port(set); /*0x16ee68*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16edf5*/
  }
}
