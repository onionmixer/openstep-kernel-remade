/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15bdc4. */
int __cdecl set_timeout(int a1, int a2)
{
  int v2; // ebx
  __int64 v3; // rax
  __int64 v4; // rax

  v2 = splsched(); /*0x15bdd1*/
  do /*0x15bdee*/
  {
    while ( dword_1E5BA8 ) /*0x15bddc*/
      ; /*0x15bdda*/
  }
  while ( _InterlockedExchange(&dword_1E5BA8, 1) == 1 ); /*0x15bdee*/
  v3 = ticks_to_ns_time(a2); /*0x15bdf4*/
  v4 = calloutDeadlineFromInterval(v3, HIDWORD(v3)); /*0x15bdfb*/
  calloutEntryDispatchDelayed(a1, v4, HIDWORD(v4)); /*0x15be03*/
  *(_DWORD *)(a1 + 44) = 1; /*0x15be08*/
  _InterlockedExchange(&dword_1E5BA8, 0); /*0x15be14*/
  return splx(v2); /*0x15be23*/
}
