/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158534. */
mach_msg_return_t __cdecl mach_msg(
        mach_msg_header_t *msg,
        mach_msg_option_t option,
        mach_msg_size_t send_size,
        mach_msg_size_t rcv_size,
        mach_port_name_t rcv_name,
        mach_msg_timeout_t timeout,
        mach_port_name_t notify)
{
  int v7; // eax
  int v8; // esi
  mach_msg_return_t v9; // ebx
  unsigned int *v11; // eax
  int v12; // eax
  int v13; // [esp-8h] [ebp-28h]
  size_t v14; // [esp-4h] [ebp-24h]
  vm_map_t target_task; // [esp+Ch] [ebp-14h]
  int v16; // [esp+10h] [ebp-10h] BYREF
  int v17; // [esp+14h] [ebp-Ch] BYREF
  volatile __int32 *v18; // [esp+18h] [ebp-8h] BYREF
  int v19; // [esp+1Ch] [ebp-4h] BYREF

  v7 = *(_DWORD *)(active_threads + 12); /*0x158545*/
  v8 = *(_DWORD *)(v7 + 136); /*0x158548*/
  target_task = *(_DWORD *)(v7 + 12); /*0x158551*/
  if ( (option & 1) != 0 ) /*0x15855a*/
  {
    if ( ipc_kmsg_get_from_kernel(msg, send_size, 0, &v19) ) /*0x158567*/
      panic(aMachMsg); /*0x15857a*/
    v9 = ipc_kmsg_copyin((_DWORD *)v19, v8, target_task, 0); /*0x158592*/
    if ( v9 ) /*0x158599*/
    {
      if ( *(int *)(v19 + 8) > 0 ) /*0x1585a3*/
        kfree(v19, *(_DWORD *)(v19 + 8)); /*0x1585b2*/
      else
        ipc_kmsg_free(v19); /*0x1585a6*/
      return v9; /*0x158639*/
    }
    while ( ipc_mqueue_send(v19, 0, 0, 0) == 268435463 ) /*0x1585d6*/
      ; /*0x1585bc*/
  }
  if ( (option & 2) != 0 ) /*0x1585de*/
  {
    while ( 1 ) /*0x1585f6*/
    {
      v9 = ipc_mqueue_copyin(v8, rcv_name, &v18, &v17); /*0x1585f6*/
      if ( v9 ) /*0x1585fd*/
        break; /*0x1585fd*/
      v9 = ipc_mqueue_receive((int)v18, 0, 0xFFFFFFFF, 0, 0, 0, (unsigned int *)&v19, &v16); /*0x15861a*/
      ipc_object_release(v17); /*0x158623*/
      if ( v9 != 268451845 ) /*0x158631*/
      {
        if ( v9 ) /*0x158635*/
          return v9; /*0x158635*/
        v11 = (unsigned int *)v19; /*0x158640*/
        *(_DWORD *)(v19 + 36) = v16; /*0x158646*/
        if ( v11[6] > rcv_size ) /*0x15864f*/
        {
          ipc_kmsg_copyout_dest(v11, v8); /*0x158653*/
          ipc_kmsg_put_to_kernel(msg, v19, 0x18u); /*0x15865f*/
          return 268451844; /*0x158669*/
        }
        v12 = ipc_kmsg_copyout(v11, v8, target_task, 0); /*0x158674*/
        v9 = v12; /*0x158679*/
        if ( !v12 ) /*0x158680*/
        {
          ipc_kmsg_put_to_kernel(msg, v19, *(_DWORD *)(v19 + 16) + *(_DWORD *)(v19 + 24)); /*0x1586c0*/
          return 0; /*0x1586c0*/
        }
        BYTE1(v12) &= 0xC3u; /*0x158682*/
        if ( v12 == 268451852 ) /*0x15868a*/
        {
          ipc_kmsg_put_to_kernel(msg, v19, *(_DWORD *)(v19 + 16) + *(_DWORD *)(v19 + 24)); /*0x158697*/
        }
        else
        {
          ipc_kmsg_copyout_dest((_DWORD *)v19, v8); /*0x1586a1*/
          ipc_kmsg_put_to_kernel(msg, v13, v14); /*0x1586ad*/
        }
        return v9; /*0x158697*/
      }
    }
    return v9; /*0x1585fd*/
  }
  return 0; /*0x1586ca*/
}
