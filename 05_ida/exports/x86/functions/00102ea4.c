/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102ea4. */
int __cdecl lightning_bolt(int a1, int a2)
{
  int v2; // ebx
  __int64 v3; // rax

  v2 = a2; /*0x102ea8*/
  thread_wakeup_prim(&lbolt, 0, 0); /*0x102eb4*/
  if ( !a2 ) /*0x102ebe*/
    v2 = calloutEntryAllocate(lightning_bolt, 0); /*0x102ecc*/
  v3 = calloutDeadlineFromInterval(1000000000, 0); /*0x102ed8*/
  return calloutEntryDispatchDelayed(v2, v3, HIDWORD(v3)); /*0x102ee5*/
}
