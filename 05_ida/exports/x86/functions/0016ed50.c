/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ed50. */
void __cdecl sub_16ED50(int *a1, int a2)
{
  host_priv_t v2; // eax
  kern_return_t v3; // eax
  mach_msg_type_number_t processor_setsCnt; // [esp+4h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16ed66*/
  {
    v2 = convert_port_to_host(a1[2]); /*0x16ed80*/
    v3 = host_processor_sets(v2, (processor_set_name_array_t *)(a2 + 44), &processor_setsCnt); /*0x16ed89*/
    *(_DWORD *)(a2 + 28) = v3; /*0x16ed8e*/
    if ( !v3 ) /*0x16ed93*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16ed95*/
      *(_DWORD *)(a2 + 4) = 48; /*0x16ed9b*/
      *(_DWORD *)(a2 + 32) = dword_1E01B0; /*0x16eda8*/
      *(_DWORD *)(a2 + 36) = off_1E01B4; /*0x16edb1*/
      *(_DWORD *)(a2 + 40) = dword_1E01B8; /*0x16edba*/
      *(_DWORD *)(a2 + 40) = processor_setsCnt; /*0x16edc0*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ed68*/
  }
}
