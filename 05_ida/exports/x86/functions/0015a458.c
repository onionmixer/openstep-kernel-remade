/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a458. */
unsigned int __cdecl _lookupd_port(unsigned int a1)
{
  unsigned int v1; // ebx
  int v2; // esi
  int v3; // eax
  int v5; // [esp+8h] [ebp-8h] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v1 = a1; /*0x15a460*/
  v2 = *(_DWORD *)(active_threads + 12); /*0x15a468*/
  if ( a1 ) /*0x15a46d*/
  {
    if ( !suser() || ipc_object_copyin(*(_DWORD *)(v2 + 136), a1, 20, (int)&v6) ) /*0x15a48a*/
    {
      return 0; /*0x15a478*/
    }
    else
    {
      if ( lookupd_port ) /*0x15a49d*/
        ipc_port_release_send(lookupd_port); /*0x15a4a0*/
      lookupd_port = v6; /*0x15a4a8*/
    }
  }
  else
  {
    v6 = lookupd_port; /*0x15a4b6*/
    if ( !lookupd_port ) /*0x15a4c1*/
      return 0; /*0x15a4e4*/
    v3 = ipc_port_copy_send(lookupd_port); /*0x15a4cc*/
    ipc_object_copyout(*(_DWORD *)(v2 + 136), v3, 17, 1, &v5); /*0x15a4dc*/
    return v5; /*0x15a4eb*/
  }
  return v1; /*0x15a4f3*/
}
