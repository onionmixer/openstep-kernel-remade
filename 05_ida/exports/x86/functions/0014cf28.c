/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cf28. */
int __cdecl ipc_port_lookup_notify(_DWORD *a1, unsigned int a2)
{
  int *v2; // eax
  int v4; // edx

  v2 = ipc_entry_lookup(a1, a2); /*0x14cf33*/
  if ( !v2 || (*((_BYTE *)v2 + 2) & 2) == 0 ) /*0x14cf48*/
    return 0; /*0x14cf3c*/
  v4 = v2[1]; /*0x14cf4a*/
  do /*0x14cf62*/
  {
    while ( *(_DWORD *)v4 ) /*0x14cf50*/
      ; /*0x14cf52*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x14cf62*/
  ++*(_DWORD *)(v4 + 4); /*0x14cf64*/
  ++*(_DWORD *)(v4 + 32); /*0x14cf67*/
  _InterlockedExchange((volatile __int32 *)v4, 0); /*0x14cf6c*/
  return v4; /*0x14cf40*/
}
