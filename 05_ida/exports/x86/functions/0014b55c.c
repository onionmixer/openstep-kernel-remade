/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b55c. */
int __cdecl ipc_notify_no_senders(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b567*/
  if ( v2 ) /*0x14b571*/
  {
    v2[2] = 52; /*0x14b58c*/
    v2[3] = 0; /*0x14b593*/
    v2[4] = 0; /*0x14b59a*/
    qmemcpy(v2 + 5, &ipc_notify_no_senders_template, 0x20u); /*0x14b5af*/
    v2[7] = a1; /*0x14b5b1*/
    v2[12] = a2; /*0x14b5b7*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b5c4*/
  }
  else
  {
    printf("dropped no-senders (0x%08x, %u)\n", a1, a2); /*0x14b57d*/
    return ipc_port_release_sonce(a1); /*0x14b583*/
  }
}
