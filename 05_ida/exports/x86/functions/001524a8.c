/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1524a8. */
kern_return_t __cdecl mach_port_dnrequest_info(
        ipc_space_t task,
        mach_port_name_t name,
        unsigned int *dnr_total,
        unsigned int *dnr_used)
{
  kern_return_t result; // eax
  int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // edx
  volatile __int32 *v10; // [esp+Ch] [ebp-4h] BYREF

  if ( !task ) /*0x1524b9*/
    return 16; /*0x1524bb*/
  result = ipc_object_translate(task, name, 1, &v10); /*0x1524cf*/
  if ( !result ) /*0x1524d6*/
  {
    v5 = *((_DWORD *)v10 + 11); /*0x1524db*/
    if ( v5 ) /*0x1524e0*/
    {
      v6 = **(_DWORD **)(v5 + 4); /*0x1524eb*/
      v8 = 1; /*0x1524ed*/
      v7 = 0; /*0x1524f2*/
      if ( v6 > 1 ) /*0x1524f6*/
      {
        v9 = v5 + 8; /*0x1524f8*/
        do /*0x152509*/
        {
          if ( *(_DWORD *)(v9 + 4) ) /*0x1524fc*/
            ++v7; /*0x152502*/
          v9 += 8; /*0x152503*/
          ++v8; /*0x152506*/
        }
        while ( v8 < v6 ); /*0x152509*/
      }
    }
    else
    {
      v6 = 0; /*0x1524e2*/
      v7 = 0; /*0x1524e4*/
    }
    _InterlockedExchange(v10, 0); /*0x152510*/
    *dnr_total = v6; /*0x152515*/
    *dnr_used = v7; /*0x152517*/
    return 0; /*0x152519*/
  }
  return result; /*0x15251e*/
}
