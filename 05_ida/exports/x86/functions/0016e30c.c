/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e30c. */
void __cdecl sub_16E30C(int a1, int a2)
{
  unsigned int v2; // ebx
  processor_t v3; // eax
  mach_msg_type_number_t v4; // [esp-4h] [ebp-Ch]

  v2 = *(_DWORD *)(a1 + 4); /*0x16e317*/
  if ( v2 > 0x23 /*0x16e342*/
    && *(int *)a1 >= 0
    && (*(_BYTE *)(a1 + 27) & 0x30) == 0x30
    && *(char **)(a1 + 28) == a62i
    && v2 == 4 * *(_DWORD *)(a1 + 32) + 36 )
  {
    v4 = *(_DWORD *)(a1 + 32); /*0x16e350*/
    v3 = convert_port_to_processor(*(_DWORD *)(a1 + 8)); /*0x16e359*/
    *(_DWORD *)(a2 + 28) = processor_control(v3, (processor_info_t)(a1 + 36), v4); /*0x16e367*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16e344*/
  }
}
