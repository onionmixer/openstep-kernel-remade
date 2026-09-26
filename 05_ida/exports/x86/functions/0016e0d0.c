/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e0d0. */
void __cdecl sub_16E0D0(int *a1, int a2)
{
  host_priv_t v2; // eax
  kern_return_t v3; // eax
  mach_msg_type_number_t out_processor_listCnt; // [esp+4h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e0e6*/
  {
    v2 = convert_port_to_host_priv(a1[2]); /*0x16e100*/
    v3 = host_processors(v2, (processor_array_t *)(a2 + 44), &out_processor_listCnt); /*0x16e109*/
    *(_DWORD *)(a2 + 28) = v3; /*0x16e10e*/
    if ( !v3 ) /*0x16e113*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16e115*/
      *(_DWORD *)(a2 + 4) = 48; /*0x16e11b*/
      *(_DWORD *)(a2 + 32) = dword_1E00F4; /*0x16e128*/
      *(_DWORD *)(a2 + 36) = off_1E00F8; /*0x16e131*/
      *(_DWORD *)(a2 + 40) = dword_1E00FC; /*0x16e13a*/
      *(_DWORD *)(a2 + 40) = out_processor_listCnt; /*0x16e140*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e0e8*/
  }
}
