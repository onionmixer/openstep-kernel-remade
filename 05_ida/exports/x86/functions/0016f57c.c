/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16f57c. */
void __cdecl sub_16F57C(int *a1, int a2)
{
  int v2; // edi
  mach_msg_type_number_t membersCnt; // [esp+Ch] [ebp-4h] BYREF

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E02EC ) /*0x16f59e*/
  {
    v2 = convert_port_to_space(a1[2]); /*0x16f5b5*/
    *(_DWORD *)(a2 + 28) = mach_port_get_set_status(v2, a1[7], (mach_port_name_array_t *)(a2 + 44), &membersCnt); /*0x16f5c9*/
    space_deallocate(v2); /*0x16f5cd*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16f5d2*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16f5d8*/
      *(_DWORD *)(a2 + 4) = 48; /*0x16f5de*/
      *(_DWORD *)(a2 + 32) = dword_1E02F0; /*0x16f5eb*/
      *(_DWORD *)(a2 + 36) = off_1E02F4; /*0x16f5f4*/
      *(_DWORD *)(a2 + 40) = dword_1E02F8; /*0x16f5fd*/
      *(_DWORD *)(a2 + 40) = membersCnt; /*0x16f603*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16f5a0*/
  }
}
