/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ec48. */
void __cdecl sub_16EC48(int *a1, int a2)
{
  int v2; // esi
  mach_msg_type_number_t task_listCnt; // [esp+8h] [ebp-4h] BYREF

  if ( a1[1] == 24 && *a1 >= 0 ) /*0x16ec5f*/
  {
    v2 = convert_port_to_pset(a1[2]); /*0x16ec75*/
    *(_DWORD *)(a2 + 28) = processor_set_tasks(v2, (task_array_t *)(a2 + 44), &task_listCnt); /*0x16ec85*/
    pset_deallocate(v2); /*0x16ec89*/
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16ec8e*/
    {
      *(_DWORD *)a2 |= 0x80000000; /*0x16ec94*/
      *(_DWORD *)(a2 + 4) = 48; /*0x16ec9a*/
      *(_DWORD *)(a2 + 32) = dword_1E0198; /*0x16eca7*/
      *(_DWORD *)(a2 + 36) = off_1E019C; /*0x16ecb0*/
      *(_DWORD *)(a2 + 40) = dword_1E01A0; /*0x16ecb9*/
      *(_DWORD *)(a2 + 40) = task_listCnt; /*0x16ecbf*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16ec61*/
  }
}
