/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1581a8. */
_DWORD *__cdecl ipc_kobject_server(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ebx
  void (__cdecl *v4)(int, _DWORD *); // edx
  int v5; // eax
  int v6; // esi
  int v7; // eax

  v1 = (_DWORD *)kalloc(0x800u); /*0x1581b6*/
  v2 = v1; /*0x1581bb*/
  if ( v1 )
  {
    v1[2] = 2048; /*0x1581dc*/
    v1[3] = 0; /*0x1581e3*/
    v1[4] = 0; /*0x1581ea*/
    v1[5] = *(unsigned __int8 *)(a1 + 21); /*0x1581f5*/
    v1[6] = 32; /*0x1581f8*/
    v1[7] = *(_DWORD *)(a1 + 32); /*0x158202*/
    v1[8] = 0; /*0x158205*/
    v1[9] = 0; /*0x15820c*/
    v1[10] = *(_DWORD *)(a1 + 40) + 100; /*0x158219*/
    v1[11] = dword_1DEC14; /*0x158222*/
    if ( netipc_msg_send(a1) ) /*0x158226*/
    {
      v2[12] = -305; /*0x158232*/
    }
    else
    {
      v4 = (void (__cdecl *)(int, _DWORD *))mach_server_routine(a1 + 20); /*0x158245*/
      if ( v4 /*0x158288*/
        || (v4 = (void (__cdecl *)(int, _DWORD *))mach_port_server_routine(a1 + 20)) != nullptr
        || (v4 = (void (__cdecl *)(int, _DWORD *))mach_host_server_routine(a1 + 20)) != nullptr
        || (v4 = (void (__cdecl *)(int, _DWORD *))mach_debug_server_routine(a1 + 20)) != nullptr
        || (v4 = (void (__cdecl *)(int, _DWORD *))driverServer_server_routine(a1 + 20)) != nullptr )
      {
        v4(a1 + 20, v2 + 5); /*0x158292*/
      }
      else if ( !ipc_kobject_notify(a1 + 20, v2 + 5) ) /*0x1582a1*/
      {
        v2[12] = -303; /*0x1582ad*/
      }
    }
    v5 = *(unsigned __int8 *)(a1 + 20); /*0x1582b7*/
    if ( v5 == 17 ) /*0x1582be*/
    {
      ipc_port_release_send(*(_DWORD *)(a1 + 28)); /*0x1582cc*/
    }
    else
    {
      if ( v5 != 18 ) /*0x1582c3*/
        panic(aIpcObjectDestr); /*0x1582e5*/
      ipc_port_release_sonce(*(_DWORD *)(a1 + 28)); /*0x1582d8*/
    }
    *(_DWORD *)(a1 + 28) = 0; /*0x1582ed*/
    v6 = v2[12]; /*0x1582f3*/
    if ( v6 && v6 != -305 ) /*0x158300*/
    {
      *(_DWORD *)(a1 + 32) = 0; /*0x15834c*/
      ipc_kmsg_destroy((_DWORD *)a1); /*0x158354*/
    }
    else
    {
      *(_DWORD *)(a1 + 16) = 0; /*0x158302*/
      if ( *(_DWORD *)(a1 + 8) != 256 || ipc_kmsg_cache ) /*0x158319*/
      {
        if ( *(int *)(a1 + 8) > 0 ) /*0x158329*/
          kfree(a1, *(_DWORD *)(a1 + 8)); /*0x158336*/
        else
          ipc_kmsg_free(a1); /*0x15832c*/
      }
      else
      {
        ipc_kmsg_cache = a1; /*0x15831b*/
      }
    }
    if ( v6 == -305 ) /*0x158362*/
    {
      if ( (int)v2[2] > 0 ) /*0x158369*/
        kfree((int)v2, v2[2]); /*0x158342*/
      else
        ipc_kmsg_free((int)v2); /*0x15836c*/
      return nullptr; /*0x158371*/
    }
    else
    {
      v7 = v2[7]; /*0x158378*/
      if ( v7 && v7 != -1 ) /*0x158382*/
      {
        return v2; /*0x158390*/
      }
      else
      {
        ipc_kmsg_destroy(v2); /*0x158385*/
        return nullptr; /*0x15838a*/
      }
    }
  }
  else
  {
    printf("ipc_kobject_server: dropping request\n");
    ipc_kmsg_destroy((_DWORD *)a1); /*0x1581cf*/
    return nullptr; /*0x1581d4*/
  }
}
