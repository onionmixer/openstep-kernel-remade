/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161780. */
kern_return_t __cdecl processor_info(
        processor_t processor,
        processor_flavor_t flavor,
        host_t *host,
        processor_info_t processor_info_out,
        mach_msg_type_number_t *processor_info_outCnt)
{
  int v6; // eax
  integer_t v7; // [esp+Ch] [ebp-8h]

  if ( !processor ) /*0x161791*/
    return 4; /*0x161793*/
  if ( flavor != 1 || *processor_info_outCnt <= 4 ) /*0x1617a9*/
    return 5; /*0x1617ab*/
  v7 = *(_DWORD *)(processor + 324); /*0x1617bd*/
  *processor_info_out = machine_slot[8 * v7 + 1]; /*0x1617cc*/
  processor_info_out[1] = machine_slot[8 * v7 + 2]; /*0x1617d2*/
  v6 = *(_DWORD *)(processor + 276); /*0x1617d5*/
  processor_info_out[2] = v6 != 5 && v6; /*0x1617f0*/
  processor_info_out[3] = v7; /*0x1617fa*/
  processor_info_out[4] = master_processor == processor; /*0x161805*/
  *processor_info_outCnt = 5; /*0x161817*/
  *host = (host_t)&realhost; /*0x161820*/
  return 0; /*0x16182b*/
}
