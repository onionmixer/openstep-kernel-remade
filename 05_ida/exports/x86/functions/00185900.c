/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185900. */
char vol_start_thread()
{
  int v0; // eax
  char result; // al
  int v2; // [esp+0h] [ebp-4h] BYREF

  v0 = ipc_port_alloc(*(_DWORD *)(kernel_task + 136), &v2, &dword_1E13F4); /*0x18591b*/
  if ( v0 )
    return printf("vol_start_thread: port_alloc returned %d\n", v0);
  dword_1E13F8 = *(_DWORD *)(dword_1E13F4 + 16); /*0x185940*/
  _InterlockedExchange((volatile __int32 *)dword_1E13F4, 0); /*0x185948*/
  result = kernel_thread(kernel_task, (int)sub_1859DC, 0); /*0x185958*/
  off_1E1408 = &off_1E1404; /*0x18595d*/
  off_1E1404 = &off_1E1404; /*0x185967*/
  dword_1E140C = 1; /*0x185971*/
  if ( !byte_1E7589 ) /*0x185985*/
  {
    result = lock_init(dword_1E758C, 1); /*0x18598e*/
    byte_1E7589 = 1; /*0x185993*/
  }
  return result; /*0x185932*/
}
