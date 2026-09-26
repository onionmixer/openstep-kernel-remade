/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1542b0. */
int __cdecl msg_send_trap(int a1, char a2, int a3, int a4)
{
  int v4; // eax
  unsigned int v5; // ecx
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  __int16 v10; // ax
  int v11; // [esp-8h] [ebp-20h]
  int (*v12)(); // [esp-4h] [ebp-1Ch]
  vm_map_t target_task; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  int v15; // [esp+14h] [ebp-4h] BYREF

  v4 = *(_DWORD *)(active_threads + 12); /*0x1542c4*/
  v14 = *(_DWORD *)(v4 + 136); /*0x1542cd*/
  target_task = *(_DWORD *)(v4 + 12); /*0x1542d3*/
  v5 = a3 + 3; /*0x1542db*/
  LOBYTE(v5) = (a3 + 3) & 0xFC; /*0x1542dd*/
  if ( v5 > 0x2000 ) /*0x1542e8*/
    return -109; /*0x1542ef*/
  v7 = ipc_kmsg_get(a1, v5, a3 - v5, &v15); /*0x1542fe*/
  if ( v7 ) /*0x15430a*/
    return msg_return_translate(v7); /*0x154312*/
  v8 = ipc_kmsg_copyin_compat((_DWORD *)v15, v14, target_task); /*0x154335*/
  if ( v8 ) /*0x15433c*/
  {
    if ( *(int *)(v15 + 8) > 0 ) /*0x154346*/
      kfree(v15, *(_DWORD *)(v15 + 8)); /*0x15431a*/
    else
      ipc_kmsg_free(v15); /*0x154349*/
    return msg_return_translate(v8); /*0x154352*/
  }
  if ( (a2 & 2) != 0 ) /*0x154362*/
  {
    v9 = 0; /*0x154366*/
    if ( (a2 & 1) != 0 ) /*0x15436e*/
      v9 = a4; /*0x154370*/
    v8 = ipc_mqueue_send(v15, 16, v9, 0); /*0x154390*/
    if ( v8 == 268435460 ) /*0x15439b*/
    {
      v8 = ipc_marequest_create(v14, *(_DWORD *)(v15 + 28), 0, v15 + 12); /*0x1543b7*/
      if ( !v8 ) /*0x1543be*/
      {
        ipc_mqueue_send(v15, 0, 0, 0); /*0x1543cd*/
        return -105; /*0x1543d7*/
      }
      goto LABEL_22; /*0x1543be*/
    }
  }
  else
  {
    if ( (a2 & 0x20) != 0 ) /*0x1543e2*/
    {
      v12 = msg_send_switch_continue; /*0x1543e4*/
      v11 = a4; /*0x1543ec*/
      v10 = 0; /*0x1543ed*/
      if ( (a2 & 1) != 0 ) /*0x1543f8*/
        v10 = 16; /*0x1543fa*/
    }
    else
    {
      v12 = nullptr; /*0x154404*/
      v11 = a4; /*0x154409*/
      v10 = 0; /*0x15440a*/
      if ( (a2 & 1) != 0 ) /*0x154412*/
        v10 = 16; /*0x154414*/
    }
    v8 = ipc_mqueue_send(v15, v10, v11, v12); /*0x154423*/
  }
  if ( v8 ) /*0x15442a*/
LABEL_22:
    ipc_kmsg_destroy(v15); /*0x15442c*/
  return msg_return_translate(v8); /*0x154441*/
}
