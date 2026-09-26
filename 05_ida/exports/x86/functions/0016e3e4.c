/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e3e4. */
void __cdecl sub_16E3E4(int *a1, _DWORD *a2)
{
  host_t v2; // eax
  kern_return_t v3; // eax
  processor_set_name_t new_name; // [esp+4h] [ebp-8h] BYREF
  processor_set_t new_set; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16e3fa*/
  {
    v2 = convert_port_to_host(a1[2]); /*0x16e414*/
    v3 = processor_set_create(v2, &new_set, &new_name); /*0x16e41d*/
    a2[7] = v3; /*0x16e422*/
    if ( !v3 ) /*0x16e42a*/
    {
      *a2 |= 0x80000000; /*0x16e42c*/
      a2[1] = 48; /*0x16e432*/
      a2[8] = dword_1E0128; /*0x16e43f*/
      a2[9] = convert_pset_to_port(new_set); /*0x16e44b*/
      a2[10] = dword_1E012C; /*0x16e454*/
      a2[11] = convert_pset_name_to_port(new_name); /*0x16e460*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e3fc*/
  }
}
