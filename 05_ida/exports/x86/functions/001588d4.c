/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1588d4. */
int __cdecl msg_receive(_DWORD *a1, __int16 a2, int a3)
{
  int v3; // eax
  int v4; // edi
  unsigned int v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  size_t v9; // ecx
  int v11; // [esp-4h] [ebp-2Ch]
  int v12; // [esp+10h] [ebp-18h]
  vm_map_t target_task; // [esp+14h] [ebp-14h]
  _BYTE v14[4]; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h] BYREF
  int v17; // [esp+24h] [ebp-4h] BYREF

  v3 = *(_DWORD *)(active_threads + 12); /*0x1588e2*/
  v4 = *(_DWORD *)(v3 + 136); /*0x1588e5*/
  target_task = *(_DWORD *)(v3 + 12); /*0x1588ee*/
  v12 = a1[3]; /*0x1588f7*/
  v5 = a1[1]; /*0x1588fd*/
  while ( 1 ) /*0x158912*/
  {
    v6 = ipc_mqueue_copyin(v4, v12, &v17, &v16); /*0x158912*/
    if ( v6 ) /*0x158919*/
      break; /*0x158919*/
    v7 = -1; /*0x15892f*/
    if ( (a2 & 0x1000) != 0 ) /*0x158938*/
      v7 = v5; /*0x15893a*/
    v6 = ipc_mqueue_receive(v17, a2 & 0x100, v7, a3, 0, 0, &v15, v14); /*0x15894f*/
    ipc_object_release(v16); /*0x158958*/
    if ( v6 == 268451845 ) /*0x158966*/
    {
      while ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x158982*/
        thread_halt_self_with_continuation(0); /*0x15896e*/
      if ( (a2 & 0x400) == 0 ) /*0x158988*/
        continue; /*0x158988*/
    }
    if ( v6 ) /*0x158998*/
    {
      if ( v6 == 268451844 ) /*0x1589a0*/
        a1[1] = v15; /*0x1589a8*/
    }
    else
    {
      if ( *(_DWORD *)(v15 + 24) > v5 ) /*0x1589b6*/
      {
        ipc_kmsg_destroy(v15); /*0x1589b9*/
        return msg_return_translate(v11); /*0x1589c3*/
      }
      v6 = ipc_kmsg_copyout_compat(v15, v4, target_task); /*0x1589d3*/
      v8 = v15; /*0x1589d5*/
      v9 = *(_DWORD *)(v15 + 16) + *(_DWORD *)(v15 + 24); /*0x1589db*/
      *(_DWORD *)(v15 + 24) = v9; /*0x1589de*/
      ipc_kmsg_put_to_kernel(a1, v8, v9); /*0x1589e7*/
    }
    break; /*0x1589ab*/
  }
  v11 = v6; /*0x1589ec*/
  return msg_return_translate(v11); /*0x1589f5*/
}
