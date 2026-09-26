/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x152708. */
mach_msg_return_t __cdecl mach_msg_receive(mach_msg_header_t *a1)
{
  _DWORD *v1; // ebx
  int v2; // eax
  int v3; // edi
  mach_msg_return_t result; // eax
  mach_msg_return_t v5; // esi
  _DWORD *v6; // eax
  int v7; // eax
  mach_msg_return_t v8; // eax
  int v9; // [esp-8h] [ebp-2Ch]
  int v10; // [esp-4h] [ebp-28h]
  vm_map_t target_task; // [esp+Ch] [ebp-18h]
  int v12; // [esp+10h] [ebp-14h] BYREF
  int v13; // [esp+14h] [ebp-10h] BYREF
  int v14; // [esp+18h] [ebp-Ch] BYREF
  int v15; // [esp+1Ch] [ebp-8h] BYREF
  volatile __int32 *v16; // [esp+20h] [ebp-4h] BYREF
  int v17; // [esp+30h] [ebp+Ch]
  unsigned int v18; // [esp+34h] [ebp+10h]
  unsigned int v19; // [esp+38h] [ebp+14h]
  int v20; // [esp+3Ch] [ebp+18h]
  unsigned int v21; // [esp+40h] [ebp+1Ch]

  v1 = (_DWORD *)active_threads; /*0x152711*/
  v2 = *(_DWORD *)(active_threads + 12); /*0x152717*/
  v3 = *(_DWORD *)(v2 + 136); /*0x15271a*/
  target_task = *(_DWORD *)(v2 + 12); /*0x152723*/
  result = ipc_mqueue_copyin(v3, v19, &v16, &v15); /*0x152733*/
  if ( !result ) /*0x15273f*/
  {
    v1[49] = a1; /*0x152748*/
    v1[50] = v17; /*0x152751*/
    v1[51] = v18; /*0x15275a*/
    v1[52] = v20; /*0x152763*/
    v1[53] = v21; /*0x15276c*/
    v1[54] = v15; /*0x152775*/
    v1[55] = v16; /*0x15277e*/
    if ( (v17 & 0x800) != 0 ) /*0x15278a*/
    {
      v5 = ipc_mqueue_receive( /*0x1527b5*/
             (int)v16,
             v17 & 0x100,
             v18,
             v20,
             0,
             (int)mach_msg_receive_continue,
             (unsigned int *)&v14,
             &v13);
      ipc_object_release(v15); /*0x1527be*/
      if ( v5 ) /*0x1527c8*/
      {
        if ( v5 == 268451844 ) /*0x1527d0*/
        {
          v12 = v14; /*0x1527d5*/
          copyout(&v12, &a1->msgh_size, 4); /*0x1527e5*/
        }
        return v5; /*0x1527ea*/
      }
      *(_DWORD *)(v14 + 36) = v13; /*0x1527f2*/
    }
    else
    {
      v5 = ipc_mqueue_receive( /*0x15281f*/
             (int)v16,
             v17 & 0x100,
             0xFFFFFFFF,
             v20,
             0,
             (int)mach_msg_receive_continue,
             (unsigned int *)&v14,
             &v13);
      ipc_object_release(v15); /*0x152828*/
      if ( v5 ) /*0x152832*/
        return v5; /*0x152836*/
      v6 = (_DWORD *)v14; /*0x15283c*/
      *(_DWORD *)(v14 + 36) = v13; /*0x152842*/
      if ( v6[6] > v18 ) /*0x15284b*/
      {
        ipc_kmsg_copyout_dest(v6, v3); /*0x15284f*/
        ipc_kmsg_put((int)a1, v14, 24); /*0x15285e*/
        return 268451844; /*0x152868*/
      }
    }
    if ( (v17 & 0x200) != 0 ) /*0x152876*/
    {
      if ( !v21 ) /*0x15287c*/
      {
        v5 = 268451847; /*0x15287e*/
LABEL_17:
        v8 = v5; /*0x1528a9*/
        BYTE1(v8) = BYTE1(v5) & 0xC3; /*0x1528ab*/
        if ( v8 == 268451852 ) /*0x1528b3*/
        {
          v10 = *(_DWORD *)(v14 + 16) + *(_DWORD *)(v14 + 24); /*0x1528be*/
          v9 = v14; /*0x1528bf*/
        }
        else
        {
          ipc_kmsg_copyout_dest((_DWORD *)v14, v3); /*0x1528c9*/
        }
        ipc_kmsg_put((int)a1, v9, v10); /*0x1528d8*/
        return v5; /*0x1528dd*/
      }
      v7 = ipc_kmsg_copyout((unsigned int *)v14, v3, target_task, v21); /*0x15288c*/
    }
    else
    {
      v7 = ipc_kmsg_copyout((unsigned int *)v14, v3, target_task, 0); /*0x15289b*/
    }
    v5 = v7; /*0x1528a0*/
    if ( v7 ) /*0x1528a7*/
      goto LABEL_17; /*0x1528a7*/
    return ipc_kmsg_put((int)a1, v14, *(_DWORD *)(v14 + 16) + *(_DWORD *)(v14 + 24)); /*0x1528f3*/
  }
  return result; /*0x1528fb*/
}
