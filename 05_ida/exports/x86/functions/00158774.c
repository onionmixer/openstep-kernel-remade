/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158774. */
int __cdecl msg_send(_DWORD *a1, char a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // ecx
  int v8; // eax
  int v9; // ebx
  __int16 v10; // ax
  int v11; // [esp-8h] [ebp-20h]
  vm_map_t target_task; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(active_threads + 12); /*0x158788*/
  v13 = *(_DWORD *)(v3 + 136); /*0x158791*/
  target_task = *(_DWORD *)(v3 + 12); /*0x158797*/
  v4 = a1[1]; /*0x15879d*/
  v5 = v4 + 3; /*0x1587a2*/
  LOBYTE(v5) = (v4 + 3) & 0xFC; /*0x1587a4*/
  v6 = v4 - v5; /*0x1587a7*/
  if ( v5 > 0x2000 ) /*0x1587af*/
    return -109; /*0x1587b1*/
  v8 = ipc_kmsg_get_from_kernel(a1, v5, v6, (int)&v14); /*0x1587c3*/
  if ( v8 ) /*0x1587cf*/
    return msg_return_translate(v8); /*0x1587d2*/
  v9 = ipc_kmsg_copyin_compat(v14, v13, target_task); /*0x1587f9*/
  if ( v9 ) /*0x158800*/
  {
    if ( *(int *)(v14 + 8) > 0 ) /*0x15880a*/
      kfree(v14, *(_DWORD *)(v14 + 8)); /*0x1587de*/
    else
      ipc_kmsg_free(v14); /*0x15880d*/
  }
  else
  {
    if ( (a2 & 2) != 0 ) /*0x158826*/
      panic(aMsgSendNotify); /*0x15882d*/
    do /*0x1588aa*/
    {
      if ( (a2 & 0x20) != 0 ) /*0x15883e*/
      {
        v11 = a3; /*0x158845*/
        v10 = 0; /*0x158846*/
        if ( (a2 & 1) != 0 ) /*0x158851*/
          v10 = 16; /*0x158853*/
      }
      else
      {
        v11 = a3; /*0x158861*/
        v10 = 0; /*0x158862*/
        if ( (a2 & 1) != 0 ) /*0x15886a*/
          v10 = 16; /*0x15886c*/
      }
      v9 = ipc_mqueue_send(v14, v10, v11, 0); /*0x15887b*/
      if ( v9 != 268435463 ) /*0x158886*/
        break; /*0x158886*/
      while ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x1588a2*/
        thread_halt_self_with_continuation(0); /*0x15888e*/
    }
    while ( (a2 & 4) == 0 ); /*0x1588aa*/
    if ( v9 ) /*0x1588b6*/
      ipc_kmsg_destroy(v14); /*0x1588bc*/
  }
  return msg_return_translate(v9); /*0x1588cd*/
}
