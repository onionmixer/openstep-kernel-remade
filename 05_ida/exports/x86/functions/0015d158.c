/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d158. */
int __cdecl sub_15D158(int a1, int a2)
{
  int result; // eax
  thread_act_t child_act; // [esp+Ch] [ebp-4h] BYREF

  if ( *(_DWORD *)(a2 + 12) ) /*0x15d167*/
  {
    if ( thread_create(*(_DWORD *)(active_threads + 12), &child_act) ) /*0x15d185*/
      return 7; /*0x15d196*/
    thread_deallocate(child_act); /*0x15d19c*/
  }
  else
  {
    child_act = active_threads; /*0x15d173*/
  }
  result = sub_15D21C(child_act, a1 + 8, *(_DWORD *)(a1 + 4) - 8); /*0x15d1b3*/
  if ( !result ) /*0x15d1bd*/
  {
    if ( *(_DWORD *)(a2 + 12) ) /*0x15d1bf*/
    {
      thread_resume(child_act); /*0x15d208*/
    }
    else
    {
      result = sub_15D270(active_threads, a1 + 8, *(_DWORD *)(a1 + 4) - 8, a2 + 8); /*0x15d1d8*/
      if ( result ) /*0x15d1e2*/
        return result; /*0x15d1e2*/
      result = sub_15D2D4(active_threads, a1 + 8, *(_DWORD *)(a1 + 4) - 8, a2 + 4); /*0x15d1f7*/
      if ( result ) /*0x15d1fe*/
        return result; /*0x15d1fe*/
    }
    ++*(_DWORD *)(a2 + 12); /*0x15d20d*/
    return 0; /*0x15d210*/
  }
  return result; /*0x15d215*/
}
