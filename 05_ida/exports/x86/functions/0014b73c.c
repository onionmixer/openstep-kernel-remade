/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b73c. */
int __cdecl ipc_notify_msg_accepted_compat(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b747*/
  if ( v2 ) /*0x14b751*/
  {
    v2[2] = 52; /*0x14b76c*/
    v2[3] = 0; /*0x14b773*/
    v2[4] = 0; /*0x14b77a*/
    qmemcpy(v2 + 5, &ipc_notify_msg_accepted_template, 0x20u); /*0x14b78f*/
    v2[5] = 17; /*0x14b791*/
    v2[7] = a1; /*0x14b798*/
    v2[12] = a2; /*0x14b79e*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b7ab*/
  }
  else
  {
    printf("dropped msg-accepted-compat (0x%08x, 0x%x)\n", a1, a2); /*0x14b75d*/
    return ipc_port_release_send(a1); /*0x14b763*/
  }
}
