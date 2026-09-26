/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1525a8. */
mach_msg_return_t __cdecl mach_msg_send(mach_msg_header_t *a1)
{
  int v1; // eax
  unsigned int v2; // esi
  mach_msg_return_t result; // eax
  mach_msg_return_t v4; // ebx
  int v5; // eax
  int v6; // eax
  vm_map_t target_task; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h] BYREF
  char v9; // [esp+20h] [ebp+Ch]
  unsigned int v10; // [esp+24h] [ebp+10h]
  int v11; // [esp+28h] [ebp+14h]
  unsigned int v12; // [esp+2Ch] [ebp+18h]

  v1 = *(_DWORD *)(active_threads + 12); /*0x1525b9*/
  v2 = *(_DWORD *)(v1 + 136); /*0x1525bc*/
  target_task = *(_DWORD *)(v1 + 12); /*0x1525c5*/
  result = ipc_kmsg_get((int)a1, v10, 0, (unsigned int **)&v8); /*0x1525d6*/
  if ( !result ) /*0x1525e2*/
  {
    if ( v9 >= 0 ) /*0x1525ec*/
    {
      v5 = ipc_kmsg_copyin((_DWORD *)v8, v2, target_task, 0); /*0x15261b*/
    }
    else
    {
      if ( !v12 ) /*0x1525f2*/
      {
        v4 = 268435467; /*0x1525f4*/
        goto LABEL_9; /*0x1525f9*/
      }
      v5 = ipc_kmsg_copyin((_DWORD *)v8, v2, target_task, v12); /*0x152600*/
    }
    v4 = v5; /*0x152620*/
    if ( v5 ) /*0x152627*/
    {
LABEL_9:
      if ( *(int *)(v8 + 8) > 0 ) /*0x152631*/
        kfree(v8, *(_DWORD *)(v8 + 8)); /*0x152606*/
      else
        ipc_kmsg_free(v8); /*0x152634*/
      return v4; /*0x152639*/
    }
    if ( (v9 & 0x20) != 0 ) /*0x152646*/
    {
      v6 = 0; /*0x15264a*/
      if ( (v9 & 0x10) != 0 ) /*0x152652*/
        v6 = v11; /*0x152654*/
      v4 = ipc_mqueue_send(v8, 16, v6, 0); /*0x152663*/
      if ( v4 == 268435460 ) /*0x15266e*/
      {
        if ( v12 ) /*0x15267a*/
        {
          v4 = ipc_marequest_create(v2, *(volatile __int32 **)(v8 + 28), v12, (unsigned int **)(v8 + 12)); /*0x15268b*/
          if ( !v4 ) /*0x152692*/
          {
            ipc_mqueue_send(v8, 0x10000, 0, 0); /*0x1526a1*/
            return 268435461; /*0x1526ab*/
          }
        }
        else
        {
          v4 = 268435467; /*0x1526b0*/
        }
        goto LABEL_21; /*0x152692*/
      }
    }
    else
    {
      v4 = ipc_mqueue_send(v8, v9 & 0x10, v11, 0); /*0x1526cd*/
    }
    if ( !v4 ) /*0x1526d4*/
      return v4; /*0x1526fa*/
LABEL_21:
    v4 |= ipc_kmsg_copyout_pseudo((_DWORD *)v8, v2, target_task); /*0x1526d6*/
    ipc_kmsg_put((int)a1, v8, *(_DWORD *)(v8 + 16) + *(_DWORD *)(v8 + 24)); /*0x1526f5*/
    return v4; /*0x1526f5*/
  }
  return result; /*0x1526ff*/
}
