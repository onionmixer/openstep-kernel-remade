/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162e7c. */
int __cdecl thread_set_timeout(int a1)
{
  thread_act_t v1; // ebx
  int v2; // esi
  volatile __int32 *v3; // edx

  v1 = active_threads; /*0x162e81*/
  v2 = splsched(); /*0x162e8c*/
  v3 = (volatile __int32 *)(v1 + 32); /*0x162e8e*/
  do /*0x162ea6*/
  {
    while ( *v3 ) /*0x162e94*/
      ; /*0x162e96*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x162ea6*/
  if ( (*(_BYTE *)(v1 + 76) & 1) != 0 ) /*0x162eac*/
    set_timeout(v1 + 280, a1); /*0x162eb9*/
  _InterlockedExchange((volatile __int32 *)(v1 + 32), 0); /*0x162ec3*/
  return splx(v2); /*0x162ecf*/
}
