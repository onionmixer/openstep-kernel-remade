/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16e4b0. */
void __cdecl sub_16E4B0(int *a1, _DWORD *a2)
{
  int v2; // edi
  mach_msg_type_number_t info_outCnt; // [esp+Ch] [ebp-8h] BYREF
  host_t host; // [esp+10h] [ebp-4h] BYREF

  if ( a1[1] == 32 && *a1 >= 0 && a1[6] == dword_1E0130 ) /*0x16e4d2*/
  {
    v2 = convert_port_to_pset_name(a1[2]); /*0x16e4e9*/
    info_outCnt = 1024; /*0x16e4eb*/
    a2[7] = processor_set_info(v2, a1[7], &host, a2 + 13, &info_outCnt); /*0x16e508*/
    pset_deallocate(v2); /*0x16e50c*/
    if ( !a2[7] ) /*0x16e514*/
    {
      *a2 |= 0x80000000; /*0x16e51a*/
      a2[8] = dword_1E0134; /*0x16e526*/
      a2[9] = convert_host_to_port((int *)host); /*0x16e532*/
      a2[10] = dword_1E0138; /*0x16e53b*/
      a2[11] = off_1E013C; /*0x16e544*/
      a2[12] = dword_1E0140; /*0x16e54d*/
      a2[12] = info_outCnt; /*0x16e553*/
      a2[1] = 4 * info_outCnt + 52; /*0x16e563*/
    }
  }
  else
  {
    a2[7] = -304; /*0x16e4d4*/
  }
}
