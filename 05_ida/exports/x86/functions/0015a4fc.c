/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a4fc. */
int __cdecl _event_port_by_tag(unsigned int a1)
{
  int v1; // esi
  int v3; // edx
  int v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  v1 = *(_DWORD *)(active_threads + 12); /*0x15a50c*/
  if ( !a1 && !suser() || a1 > 2 ) /*0x15a51e*/
    return 0; /*0x15a525*/
  v3 = ev_port_list[a1]; /*0x15a52c*/
  if ( !v3 ) /*0x15a535*/
    return 0; /*0x15a558*/
  v4 = ipc_port_copy_send(v3); /*0x15a540*/
  ipc_object_copyout(*(_DWORD *)(v1 + 136), v4, 17, 1, &v5); /*0x15a550*/
  return v5; /*0x15a565*/
}
