/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157a28. */
kern_return_t __cdecl host_info(
        host_t host,
        host_flavor_t flavor,
        host_info_t host_info_out,
        mach_msg_type_number_t *host_info_outCnt)
{
  int v4; // ecx
  host_info_t v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax

  if ( !host ) /*0x157a3b*/
    return 4; /*0x157a3b*/
  if ( flavor != 2 ) /*0x157a44*/
  {
    if ( flavor > 2 ) /*0x157a4a*/
    {
      if ( flavor == 3 ) /*0x157a5b*/
      {
        if ( *host_info_outCnt > 1 ) /*0x157b17*/
        {
          v9 = tick / 1000; /*0x157b24*/
          *host_info_out = tick / 1000; /*0x157b26*/
          host_info_out[1] = v9; /*0x157b28*/
          *host_info_outCnt = 2; /*0x157b2b*/
          return 0; /*0x157b33*/
        }
      }
      else
      {
        if ( flavor != 4 ) /*0x157a64*/
          return 4; /*0x157a64*/
        if ( *host_info_outCnt > 5 ) /*0x157b3b*/
        {
          bcopy(&avenrun, host_info_out, 0xCu); /*0x157b4c*/
          bcopy(&mach_factor, host_info_out + 3, 0xCu); /*0x157b5c*/
          *host_info_outCnt = 6; /*0x157b61*/
          return 0; /*0x157b69*/
        }
      }
    }
    else
    {
      if ( flavor != 1 ) /*0x157a4f*/
        return 4; /*0x157b6c*/
      if ( *host_info_outCnt > 4 ) /*0x157a73*/
      {
        *host_info_out = dword_1F6348; /*0x157a7f*/
        host_info_out[1] = dword_1F634C; /*0x157a87*/
        host_info_out[2] = dword_1F6350; /*0x157a90*/
        v4 = master_processor; /*0x157a93*/
        host_info_out[3] = machine_slot[8 * *(_DWORD *)(master_processor + 324) + 1]; /*0x157aab*/
        host_info_out[4] = machine_slot[8 * *(_DWORD *)(v4 + 324) + 2]; /*0x157abb*/
        *host_info_outCnt = 5; /*0x157abe*/
        return 0; /*0x157ac6*/
      }
    }
    return 5; /*0x157b42*/
  }
  if ( !*host_info_outCnt ) /*0x157acc*/
    return 4; /*0x157ad6*/
  v6 = host_info_out; /*0x157adc*/
  *host_info_outCnt = 0; /*0x157ade*/
  v7 = 0; /*0x157ae4*/
  v8 = 0; /*0x157aeb*/
  do /*0x157b0d*/
  {
    if ( machine_slot[v8] ) /*0x157af0*/
    {
      if ( machine_slot[v8 + 3] ) /*0x157af9*/
      {
        *v6++ = v7; /*0x157b00*/
        ++*host_info_outCnt; /*0x157b05*/
      }
    }
    v8 += 8; /*0x157b07*/
    ++v7; /*0x157b0a*/
  }
  while ( v7 <= 0 ); /*0x157b0d*/
  return 0; /*0x157b74*/
}
