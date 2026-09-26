/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b464. */
int __cdecl ipc_notify_msg_accepted(int a1, int a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)kalloc(0x34u); /*0x14b46f*/
  if ( v2 ) /*0x14b479*/
  {
    v2[2] = 52; /*0x14b494*/
    v2[3] = 0; /*0x14b49b*/
    v2[4] = 0; /*0x14b4a2*/
    qmemcpy(v2 + 5, &ipc_notify_msg_accepted_template, 0x20u); /*0x14b4b7*/
    v2[7] = a1; /*0x14b4b9*/
    v2[12] = a2; /*0x14b4bf*/
    return ipc_mqueue_send((int)v2, 0x10000, 0, 0); /*0x14b4cc*/
  }
  else
  {
    printf(aDroppedMsgAcce_0, a1, a2); /*0x14b485*/
    return ipc_port_release_sonce(a1); /*0x14b48b*/
  }
}
