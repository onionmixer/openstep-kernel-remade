/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1514. */
void sub_1A1514()
{
  thread_act_t v0; // esi
  int v1; // eax
  int v2; // edi
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // eax
  _DWORD *v7; // ebx

  v0 = active_threads; /*0x1a151a*/
  v1 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x1a1523*/
  if ( v1 ) /*0x1a1528*/
    v2 = v1 + 132; /*0x1a152a*/
  else
    v2 = thread_user_state(active_threads); /*0x1a153d*/
  v3 = *(int **)(*(_DWORD *)(v0 + 40) + 236); /*0x1a1542*/
  v4 = 0; /*0x1a1548*/
  if ( v3 ) /*0x1a154c*/
    v4 = *v3; /*0x1a154e*/
  if ( v4 ) /*0x1a1552*/
  {
    v5 = *(_DWORD *)(v4 + 132); /*0x1a1554*/
    if ( v5 > 7 ) /*0x1a155d*/
      v6 = 0; /*0x1a1570*/
    else
      v6 = v4 + 132 * v5 + 136; /*0x1a1566*/
    v7 = (_DWORD *)v6; /*0x1a1572*/
  }
  else
  {
    v7 = nullptr; /*0x1a1578*/
  }
  if ( v7[21] ) /*0x1a157a*/
  {
    v7[22] = 1; /*0x1a1580*/
    PCcallMonitor(v0, v2); /*0x1a1589*/
  }
  if ( !v7[22] && (v7[29] || PCtimersPending(v7)) ) /*0x1a159e*/
    PCcallMonitor(v0, v2); /*0x1a15ac*/
  thread_exception_return(); /*0x1a15b4*/
}
