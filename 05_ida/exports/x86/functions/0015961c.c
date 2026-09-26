/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15961c. */
int __cdecl ipc_thread_init(_DWORD *a1)
{
  _DWORD *v1; // eax
  int result; // eax
  int v3; // [esp+8h] [ebp-8h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-4h] BYREF

  v1 = ipc_port_alloc_special(ipc_space_kernel); /*0x15962e*/
  if ( !v1 ) /*0x15963a*/
    panic(aIpcThreadInit); /*0x159641*/
  a1[36] = a1; /*0x159649*/
  a1[37] = a1; /*0x15964f*/
  a1[41] = 0; /*0x159655*/
  a1[42] = 0; /*0x15965f*/
  a1[43] = v1; /*0x159669*/
  a1[44] = ipc_port_make_send((int)v1); /*0x159675*/
  a1[45] = 0; /*0x15967b*/
  a1[47] = 0; /*0x159685*/
  a1[48] = 0; /*0x15968f*/
  if ( ipc_port_alloc_compat(*(_DWORD *)(a1[3] + 136), &v4, &v3) ) /*0x1596ab*/
    panic(aIpcThreadInit_0); /*0x1596bc*/
  result = v3; /*0x1596c1*/
  ++*(_DWORD *)(v3 + 28); /*0x1596c4*/
  ++*(_DWORD *)(result + 4); /*0x1596c7*/
  _InterlockedExchange((volatile __int32 *)result, 0); /*0x1596cc*/
  a1[46] = result; /*0x1596ce*/
  return result; /*0x1596d7*/
}
