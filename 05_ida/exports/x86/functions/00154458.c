/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x154458. */
int __cdecl msg_receive_trap(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v5; // eax
  int v6; // ebx
  _DWORD *v7; // eax
  unsigned int v8; // eax
  int v10; // eax
  int v11; // edx
  vm_map_t target_task; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+14h] [ebp-14h] BYREF
  int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h] BYREF
  volatile __int32 *v18; // [esp+24h] [ebp-4h] BYREF

  v5 = *(_DWORD *)(active_threads + 12); /*0x15446c*/
  v13 = *(_DWORD *)(v5 + 136); /*0x154475*/
  target_task = *(_DWORD *)(v5 + 12); /*0x15447b*/
  v6 = ipc_mqueue_copyin(v13, a4, &v18, &v17); /*0x154493*/
  if ( !v6 ) /*0x15449a*/
  {
    v7 = (_DWORD *)active_threads; /*0x1544a0*/
    *(_DWORD *)(active_threads + 196) = a1; /*0x1544a8*/
    v7[50] = a2; /*0x1544ae*/
    v7[51] = a3; /*0x1544b4*/
    v7[52] = a5; /*0x1544bd*/
    v7[54] = v17; /*0x1544c6*/
    v7[55] = v18; /*0x1544cf*/
    v8 = -1; /*0x1544e8*/
    if ( (a2 & 0x1000) != 0 ) /*0x1544f3*/
      v8 = a3; /*0x1544f5*/
    v6 = ipc_mqueue_receive((int)v18, a2 & 0x100, v8, a5, 0, (int)msg_receive_continue, (unsigned int *)&v16, &v15); /*0x154509*/
    ipc_object_release(v17); /*0x154512*/
    if ( v6 ) /*0x15451c*/
    {
      if ( v6 == 268451844 ) /*0x154524*/
      {
        v14 = v16; /*0x154529*/
        copyout(&v14, a1 + 4, 4); /*0x154539*/
      }
    }
    else
    {
      if ( *(_DWORD *)(v16 + 24) > a3 ) /*0x15454a*/
      {
        ipc_kmsg_destroy((_DWORD *)v16); /*0x15454d*/
        return -204; /*0x154557*/
      }
      ipc_kmsg_copyout_compat((_DWORD *)v16, v13, target_task); /*0x154565*/
      v10 = v16; /*0x15456a*/
      v11 = *(_DWORD *)(v16 + 16) + *(_DWORD *)(v16 + 24); /*0x154570*/
      *(_DWORD *)(v16 + 24) = v11; /*0x154573*/
      v6 = ipc_kmsg_put(a1, v10, v11); /*0x154581*/
    }
  }
  return msg_return_translate(v6); /*0x15458c*/
}
