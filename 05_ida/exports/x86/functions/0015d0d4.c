/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d0d4. */
int __cdecl sub_15D0D4(int a1, int a2)
{
  thread_act_t v2; // edi
  int result; // eax
  int v4; // ebx

  v2 = active_threads; /*0x15d0dd*/
  if ( *(_DWORD *)(a2 + 12) ) /*0x15d0e3*/
    return 4; /*0x15d0e9*/
  v4 = a1 + 8; /*0x15d101*/
  result = sub_15D270(active_threads, a1 + 8, *(_DWORD *)(a1 + 4) - 8, a2 + 8); /*0x15d106*/
  if ( !result ) /*0x15d110*/
  {
    result = sub_15D2D4(v2, v4, *(_DWORD *)(a1 + 4) - 8, a2 + 4); /*0x15d122*/
    if ( !result ) /*0x15d12c*/
    {
      result = sub_15D21C(v2, v4, *(_DWORD *)(a1 + 4) - 8); /*0x15d13a*/
      if ( !result ) /*0x15d141*/
      {
        *(_BYTE *)(a2 + 16) |= 1u; /*0x15d143*/
        ++*(_DWORD *)(a2 + 12); /*0x15d147*/
        return 0; /*0x15d14a*/
      }
    }
  }
  return result; /*0x15d14f*/
}
