/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b6bc. */
int __cdecl ipc_notify_port_deleted_compat(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b6c7*/
  if ( v2 ) /*0x14b6d1*/
  {
    v2[2] = 52; /*0x14b6ec*/
    v2[3] = 0; /*0x14b6f3*/
    v2[4] = 0; /*0x14b6fa*/
    qmemcpy(v2 + 5, &ipc_notify_port_deleted_template, 0x20u); /*0x14b70f*/
    v2[5] = 17; /*0x14b711*/
    v2[7] = a1; /*0x14b718*/
    v2[12] = a2; /*0x14b71e*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b72b*/
  }
  else
  {
    printf("dropped port-deleted-compat (0x%08x, 0x%x)\n", a1, a2); /*0x14b6dd*/
    return ipc_port_release_send(a1); /*0x14b6e3*/
  }
}
