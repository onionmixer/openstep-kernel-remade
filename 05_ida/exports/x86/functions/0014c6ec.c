/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c6ec. */
unsigned int __cdecl ipc_port_set_qlimit(int a1, unsigned int a2)
{
  unsigned int result; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebx

  result = *(_DWORD *)(a1 + 60); /*0x14c6f5*/
  if ( a2 > result ) /*0x14c6fb*/
  {
    v3 = a2 - result; /*0x14c700*/
    v4 = 0; /*0x14c702*/
    if ( a2 != result ) /*0x14c706*/
    {
      do /*0x14c733*/
      {
        result = ipc_thread_dequeue(a1 + 76); /*0x14c711*/
        if ( !result ) /*0x14c71b*/
          break; /*0x14c71b*/
        *(_DWORD *)(result + 152) = 0; /*0x14c71d*/
        result = thread_go(result); /*0x14c728*/
        ++v4; /*0x14c730*/
      }
      while ( v4 < v3 ); /*0x14c733*/
    }
  }
  *(_DWORD *)(a1 + 60) = a2; /*0x14c73b*/
  return result; /*0x14c741*/
}
