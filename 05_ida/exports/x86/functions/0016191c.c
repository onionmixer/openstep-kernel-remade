/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16191c. */
kern_return_t __cdecl processor_set_info(
        processor_set_name_t set_name,
        int flavor,
        host_t *host,
        processor_set_info_t info_out,
        mach_msg_type_number_t *info_outCnt)
{
  volatile __int32 *v5; // edx
  volatile __int32 *v7; // edx

  if ( set_name ) /*0x161930*/
  {
    if ( flavor == 1 ) /*0x161939*/
    {
      if ( *info_outCnt > 4 ) /*0x16193e*/
      {
        v5 = (volatile __int32 *)(set_name + 344); /*0x161942*/
        do /*0x16195a*/
        {
          while ( *v5 ) /*0x161948*/
            ; /*0x16194a*/
        }
        while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16195a*/
        *info_out = *(_DWORD *)(set_name + 292); /*0x161962*/
        info_out[1] = *(_DWORD *)(set_name + 308); /*0x16196a*/
        info_out[2] = *(_DWORD *)(set_name + 320); /*0x161973*/
        info_out[4] = *(_DWORD *)(set_name + 368); /*0x16197c*/
        info_out[3] = *(_DWORD *)(set_name + 372); /*0x161985*/
        _InterlockedExchange((volatile __int32 *)(set_name + 344), 0); /*0x16198a*/
        *info_outCnt = 5; /*0x161990*/
LABEL_15:
        *host = (host_t)&realhost; /*0x1619e7*/
        return 0; /*0x1619f2*/
      }
      return 5; /*0x16193e*/
    }
    if ( flavor == 2 ) /*0x16199b*/
    {
      if ( *info_outCnt > 1 ) /*0x1619a0*/
      {
        v7 = (volatile __int32 *)(set_name + 344); /*0x1619ae*/
        do /*0x1619c6*/
        {
          while ( *v7 ) /*0x1619b4*/
            ; /*0x1619b6*/
        }
        while ( _InterlockedExchange(v7, 1) == 1 ); /*0x1619c6*/
        *info_out = *(_DWORD *)(set_name + 360); /*0x1619ce*/
        info_out[1] = *(_DWORD *)(set_name + 356); /*0x1619d6*/
        _InterlockedExchange((volatile __int32 *)(set_name + 344), 0); /*0x1619db*/
        *info_outCnt = 2; /*0x1619e1*/
        goto LABEL_15; /*0x1619e1*/
      }
      return 5; /*0x1619a7*/
    }
    *host = 0; /*0x1619f7*/
  }
  return 4; /*0x161a05*/
}
