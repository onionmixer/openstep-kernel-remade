/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b3ec. */
int __cdecl ipc_notify_port_deleted(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b3f7*/
  if ( v2 ) /*0x14b401*/
  {
    v2[2] = 52; /*0x14b41c*/
    v2[3] = 0; /*0x14b423*/
    v2[4] = 0; /*0x14b42a*/
    qmemcpy(v2 + 5, &ipc_notify_port_deleted_template, 0x20u); /*0x14b43f*/
    v2[7] = a1; /*0x14b441*/
    v2[12] = a2; /*0x14b447*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b454*/
  }
  else
  {
    printf("dropped port-deleted (0x%08x, 0x%x)\n", a1, a2); /*0x14b40d*/
    return ipc_port_release_sonce(a1); /*0x14b413*/
  }
}
