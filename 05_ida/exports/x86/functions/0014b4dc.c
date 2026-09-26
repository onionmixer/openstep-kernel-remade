/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b4dc. */
int __cdecl ipc_notify_port_destroyed(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b4e7*/
  if ( v2 ) /*0x14b4f1*/
  {
    v2[2] = 52; /*0x14b514*/
    v2[3] = 0; /*0x14b51b*/
    v2[4] = 0; /*0x14b522*/
    qmemcpy(v2 + 5, &ipc_notify_port_destroyed_template, 0x20u); /*0x14b537*/
    v2[7] = a1; /*0x14b539*/
    v2[12] = a2; /*0x14b53f*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b54c*/
  }
  else
  {
    printf("dropped port-destroyed (0x%08x, 0x%08x)\n", a1, a2); /*0x14b4fd*/
    ipc_port_release_sonce(a1); /*0x14b503*/
    return ipc_port_release_receive(a2); /*0x14b50c*/
  }
}
