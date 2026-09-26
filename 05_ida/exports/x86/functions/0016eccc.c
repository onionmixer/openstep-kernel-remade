/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16eccc. */
void __cdecl sub_16ECCC(int *a1, int a2)
{
  int v2; // esi
  mach_msg_type_number_t thread_listCnt; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16ece3*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16ecf9*/
    *(_DWORD *)(a2 + 28) = processor_set_threads(v2, (thread_act_array_t *)(a2 + 44), &thread_listCnt); /*0x16ed09*/
    pset_deallocate(v2); /*0x16ed0d*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16ed12*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16ed18*/
      *(_DWORD *)(a2 + 4) = 48; /*0x16ed1e*/
      *(_DWORD *)(a2 + 32) = dword_1E01A4; /*0x16ed2b*/
      *(_DWORD *)(a2 + 36) = off_1E01A8; /*0x16ed34*/
      *(_DWORD *)(a2 + 40) = dword_1E01AC; /*0x16ed3d*/
      *(_DWORD *)(a2 + 40) = thread_listCnt; /*0x16ed43*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ece5*/
  }
}
