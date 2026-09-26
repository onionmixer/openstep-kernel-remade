/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1659ac. */
mach_msg_type_number_t __cdecl kernel_task_create(task_t target_task, int a2)
{
  int v2; // edx
  mach_msg_type_number_t result; // eax
  boolean_t v4; // [esp+0h] [ebp-10h]
  task_t *v5; // [esp+4h] [ebp-Ch] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-8h] BYREF
  mach_msg_type_number_t ledgersCnt; // [esp+Ch] [ebp-4h] BYREF

  task_create(target_task, nullptr, (mach_msg_type_number_t)&ledgersCnt, v4, v5); /*0x1659c0*/
  task_deallocate(ledgersCnt); /*0x1659c9*/
  vm_map_deallocate(*(_DWORD *)(ledgersCnt + 12)); /*0x1659d5*/
  if ( a2 ) /*0x1659df*/
  {
    v2 = kmem_suballoc(kernel_map, v6, &v5, a2, 0); /*0x165a07*/
    *(_DWORD *)(ledgersCnt + 12) = v2; /*0x165a0c*/
  }
  else
  {
    *(_DWORD *)(ledgersCnt + 12) = kernel_map; /*0x1659ea*/
  }
  result = ledgersCnt; /*0x165a0f*/
  *(_DWORD *)(ledgersCnt + 80) = 1; /*0x165a12*/
  return result; /*0x165a19*/
}
