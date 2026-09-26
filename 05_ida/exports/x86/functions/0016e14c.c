/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e14c. */
void __cdecl sub_16E14C(int *a1, _DWORD *a2)
{
  host_t v2; // eax
  kern_return_t v3; // eax
  host_flavor_t v4; // [esp-Ch] [ebp-14h]
  mach_msg_type_number_t host_info_outCnt; // [esp+4h] [ebp-4h] BYREF

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0100 ) /*0x16e16c*/
  {
    host_info_outCnt = 1024; /*0x16e178*/
    v4 = a1[7]; /*0x16e18a*/
    v2 = convert_port_to_host(a1[2]); /*0x16e18f*/
    v3 = host_info(v2, v4, a2 + 11, &host_info_outCnt); /*0x16e198*/
    a2[7] = v3; /*0x16e19d*/
    if ( !v3 ) /*0x16e1a2*/
    {
      a2[8] = dword_1E0104; /*0x16e1aa*/
      a2[9] = off_1E0108; /*0x16e1b3*/
      a2[10] = dword_1E010C; /*0x16e1bc*/
      a2[10] = host_info_outCnt; /*0x16e1c2*/
      a2[1] = 4 * host_info_outCnt + 44; /*0x16e1d2*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e16e*/
  }
}
