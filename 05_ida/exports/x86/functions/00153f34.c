/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x153f34. */
int mach_msg_continue()
{
  int v0; // eax
  int v1; // edi
  int v2; // ebx
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // eax
  unsigned int v9; // [esp+Ch] [ebp-14h]
  int v10; // [esp+10h] [ebp-10h]
  vm_map_t target_task; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h] BYREF
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  v0 = *(_DWORD *)(active_threads + 12); /*0x153f43*/
  v1 = *(_DWORD *)(v0 + 136); /*0x153f46*/
  target_task = *(_DWORD *)(v0 + 12); /*0x153f4f*/
  v10 = *(_DWORD *)(active_threads + 196); /*0x153f58*/
  v9 = *(_DWORD *)(active_threads + 204); /*0x153f61*/
  v2 = *(_DWORD *)(active_threads + 216); /*0x153f64*/
  v3 = ipc_mqueue_receive( /*0x153f8b*/
         *(_DWORD *)(active_threads + 220),
         0,
         0xFFFFFFFF,
         0,
         1,
         (int)mach_msg_continue,
         (unsigned int *)&v13,
         &v12);
  ipc_object_release(v2); /*0x153f91*/
  if ( v3 ) /*0x153f9b*/
    thread_syscall_return(v3); /*0x153f9e*/
  v4 = (_DWORD *)v13; /*0x153fa6*/
  *(_DWORD *)(v13 + 36) = v12; /*0x153fac*/
  if ( v4[6] > v9 ) /*0x153fb5*/
  {
    ipc_kmsg_copyout_dest(v4, v1); /*0x153fb9*/
    ipc_kmsg_put(v10, v13, 24); /*0x153fc8*/
    thread_syscall_return(268451844); /*0x153fd2*/
  }
  v5 = ipc_kmsg_copyout((unsigned int *)v13, v1, target_task, 0); /*0x153fe5*/
  v6 = v5; /*0x153fea*/
  if ( v5 ) /*0x153ff1*/
  {
    BYTE1(v5) &= 0xC3u; /*0x153ff3*/
    if ( v5 == 268451852 ) /*0x153ffb*/
    {
      ipc_kmsg_put(v10, v13, *(_DWORD *)(v13 + 16) + *(_DWORD *)(v13 + 24)); /*0x15400c*/
    }
    else
    {
      ipc_kmsg_copyout_dest((_DWORD *)v13, v1); /*0x15401d*/
      ipc_kmsg_put(v10, v13, 24); /*0x15402c*/
    }
    thread_syscall_return(v6); /*0x154035*/
  }
  v7 = ipc_kmsg_put(v10, v13, *(_DWORD *)(v13 + 16) + *(_DWORD *)(v13 + 24)); /*0x15404c*/
  return thread_syscall_return(v7); /*0x15405c*/
}
