/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154a18. */
int msg_receive_continue()
{
  int v0; // ecx
  unsigned int v1; // edi
  unsigned int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch] BYREF
  int v13; // [esp+18h] [ebp-8h] BYREF
  int v14; // [esp+1Ch] [ebp-4h] BYREF

  v11 = *(_DWORD *)(active_threads + 196); /*0x154a2c*/
  v0 = *(_DWORD *)(active_threads + 200); /*0x154a2f*/
  v1 = *(_DWORD *)(active_threads + 204); /*0x154a35*/
  v10 = *(_DWORD *)(active_threads + 216); /*0x154a41*/
  v2 = -1; /*0x154a60*/
  if ( (v0 & 0x1000) != 0 ) /*0x154a68*/
    v2 = *(_DWORD *)(active_threads + 204); /*0x154a6a*/
  v3 = ipc_mqueue_receive( /*0x154a7b*/
         *(_DWORD *)(active_threads + 220),
         v0 & 0x100,
         v2,
         *(_DWORD *)(active_threads + 208),
         1,
         (int)msg_receive_continue,
         (unsigned int *)&v14,
         &v13);
  ipc_object_release(v10); /*0x154a84*/
  if ( v3 ) /*0x154a8e*/
  {
    if ( v3 == 268451844 ) /*0x154a96*/
    {
      v12 = v14; /*0x154a9b*/
      copyout(&v12, v11 + 4, 4); /*0x154aab*/
    }
    v4 = msg_return_translate(v3); /*0x154ab4*/
    thread_syscall_return(v4); /*0x154aba*/
  }
  if ( *(_DWORD *)(v14 + 24) > v1 ) /*0x154ac8*/
  {
    ipc_kmsg_destroy((_DWORD *)v14); /*0x154acb*/
    thread_syscall_return(-204); /*0x154ad5*/
  }
  ipc_kmsg_copyout_compat( /*0x154af4*/
    (_DWORD *)v14,
    *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136),
    *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12));
  v5 = v14; /*0x154af9*/
  v6 = *(_DWORD *)(v14 + 16) + *(_DWORD *)(v14 + 24); /*0x154aff*/
  *(_DWORD *)(v14 + 24) = v6; /*0x154b02*/
  v7 = ipc_kmsg_put(v11, v5, v6); /*0x154b0b*/
  v8 = msg_return_translate(v7); /*0x154b13*/
  return thread_syscall_return(v8); /*0x154b21*/
}
