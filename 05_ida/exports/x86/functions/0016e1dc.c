/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e1dc. */
void __cdecl sub_16E1DC(int *a1, _DWORD *a2)
{
  processor_t v2; // eax
  kern_return_t v3; // eax
  processor_flavor_t v4; // [esp-10h] [ebp-1Ch]
  mach_msg_type_number_t processor_info_outCnt; // [esp+4h] [ebp-8h] BYREF
  host_t host; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0110 ) /*0x16e1fc*/
  {
    processor_info_outCnt = 1024; /*0x16e20c*/
    v4 = a1[7]; /*0x16e222*/
    v2 = convert_port_to_processor(a1[2]); /*0x16e227*/
    v3 = processor_info(v2, v4, &host, a2 + 13, &processor_info_outCnt); /*0x16e230*/
    a2[7] = v3; /*0x16e235*/
    if ( !v3 ) /*0x16e23d*/
    {
      *a2 |= 0x80000000; /*0x16e23f*/
      a2[8] = dword_1E0114; /*0x16e24b*/
      a2[9] = convert_host_to_port((int *)host); /*0x16e257*/
      a2[10] = dword_1E0118; /*0x16e260*/
      a2[11] = off_1E011C; /*0x16e269*/
      a2[12] = dword_1E0120; /*0x16e272*/
      a2[12] = processor_info_outCnt; /*0x16e278*/
      a2[1] = 4 * processor_info_outCnt + 52; /*0x16e288*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e1fe*/
  }
}
