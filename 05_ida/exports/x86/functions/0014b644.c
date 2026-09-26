/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b644. */
int __cdecl ipc_notify_dead_name(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b64f*/
  if ( v2 ) /*0x14b659*/
  {
    v2[2] = 52; /*0x14b674*/
    v2[3] = 0; /*0x14b67b*/
    v2[4] = 0; /*0x14b682*/
    qmemcpy(v2 + 5, &ipc_notify_dead_name_template, 0x20u); /*0x14b697*/
    v2[7] = a1; /*0x14b699*/
    v2[12] = a2; /*0x14b69f*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b6ac*/
  }
  else
  {
    printf("dropped dead-name (0x%08x, 0x%x)\n", a1, a2); /*0x14b665*/
    return ipc_port_release_sonce(a1); /*0x14b66b*/
  }
}
