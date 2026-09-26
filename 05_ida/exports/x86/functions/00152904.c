/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x152904. */
int mach_msg_receive_continue()
{
  int v0; // edx
  int v1; // edi
  int v2; // esi
  int v3; // edx
  int v4; // ebx
  int v5; // ebx
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp+Ch] [ebp-20h]
  unsigned int v14; // [esp+10h] [ebp-1Ch]
  unsigned int v15; // [esp+14h] [ebp-18h]
  int v16; // [esp+18h] [ebp-14h]
  vm_map_t target_task; // [esp+1Ch] [ebp-10h]
  int v18; // [esp+20h] [ebp-Ch] BYREF
  int v19; // [esp+24h] [ebp-8h] BYREF
  int v20; // [esp+28h] [ebp-4h] BYREF

  v0 = *(_DWORD *)(active_threads + 12); /*0x152912*/
  v1 = *(_DWORD *)(v0 + 136); /*0x152915*/
  target_task = *(_DWORD *)(v0 + 12); /*0x15291e*/
  v16 = *(_DWORD *)(active_threads + 196); /*0x152927*/
  v2 = *(_DWORD *)(active_threads + 200); /*0x15292a*/
  v15 = *(_DWORD *)(active_threads + 204); /*0x152936*/
  v3 = *(_DWORD *)(active_threads + 208); /*0x152939*/
  v14 = *(_DWORD *)(active_threads + 212); /*0x152945*/
  v13 = *(_DWORD *)(active_threads + 216); /*0x15294e*/
  v4 = *(_DWORD *)(active_threads + 220); /*0x152951*/
  if ( (v2 & 0x800) != 0 ) /*0x15295d*/
  {
    v5 = ipc_mqueue_receive(v4, v2 & 0x100, v15, v3, 1, (int)mach_msg_receive_continue, (unsigned int *)&v20, &v19); /*0x152981*/
    ipc_object_release(v13); /*0x15298a*/
    if ( v5 ) /*0x152994*/
    {
      if ( v5 == 268451844 ) /*0x15299c*/
      {
        v18 = v20; /*0x1529a1*/
        copyout(&v18, v16 + 4, 4); /*0x1529b1*/
      }
      thread_syscall_return(v5); /*0x1529ba*/
    }
    *(_DWORD *)(v20 + 36) = v19; /*0x1529c8*/
  }
  else
  {
    v6 = ipc_mqueue_receive( /*0x1529f0*/
           v4,
           v2 & 0x100,
           0xFFFFFFFF,
           v3,
           1,
           (int)mach_msg_receive_continue,
           (unsigned int *)&v20,
           &v19);
    ipc_object_release(v13); /*0x1529f9*/
    if ( v6 ) /*0x152a03*/
      thread_syscall_return(v6); /*0x152a06*/
    v7 = (_DWORD *)v20; /*0x152a0e*/
    *(_DWORD *)(v20 + 36) = v19; /*0x152a14*/
    if ( v7[6] > v15 ) /*0x152a1d*/
    {
      ipc_kmsg_copyout_dest(v7, v1); /*0x152a21*/
      ipc_kmsg_put(v16, v20, 24); /*0x152a30*/
      thread_syscall_return(268451844); /*0x152a3a*/
    }
  }
  if ( (v2 & 0x200) == 0 ) /*0x152a48*/
  {
    v9 = ipc_kmsg_copyout((unsigned int *)v20, v1, target_task, 0); /*0x152a6b*/
LABEL_16:
    v8 = v9; /*0x152a70*/
    if ( !v9 ) /*0x152a77*/
      goto LABEL_21; /*0x152a77*/
    goto LABEL_17; /*0x152a77*/
  }
  if ( v14 ) /*0x152a4e*/
  {
    v9 = ipc_kmsg_copyout((unsigned int *)v20, v1, target_task, v14); /*0x152a5c*/
    goto LABEL_16; /*0x152a5c*/
  }
  v8 = 268451847; /*0x152a50*/
LABEL_17:
  v10 = v8; /*0x152a79*/
  BYTE1(v10) = BYTE1(v8) & 0xC3; /*0x152a7b*/
  if ( v10 == 268451852 ) /*0x152a83*/
  {
    ipc_kmsg_put(v16, v20, *(_DWORD *)(v20 + 16) + *(_DWORD *)(v20 + 24)); /*0x152a94*/
  }
  else
  {
    ipc_kmsg_copyout_dest((_DWORD *)v20, v1); /*0x152aa5*/
    ipc_kmsg_put(v16, v20, 24); /*0x152ab4*/
  }
  thread_syscall_return(v8); /*0x152abd*/
LABEL_21:
  v11 = ipc_kmsg_put(v16, v20, *(_DWORD *)(v20 + 16) + *(_DWORD *)(v20 + 24)); /*0x152ac5*/
  return thread_syscall_return(v11); /*0x152ae4*/
}
