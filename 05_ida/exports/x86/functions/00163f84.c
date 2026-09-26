/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163f84. */
__int32 __cdecl run_queue_enqueue(int a1, _DWORD *a2)
{
  unsigned int v2; // ecx
  volatile __int32 *v3; // edx
  int v4; // edx

  v2 = a2[22]; /*0x163f90*/
  if ( v2 > 0x1F )
  {
    printf("run_queue_enqueue: pri too high (%d)\n", a2[22]);
    v2 = 31; /*0x163fa3*/
  }
  v3 = (volatile __int32 *)(a1 + 256); /*0x163fa8*/
  do /*0x163fc2*/
  {
    while ( *v3 ) /*0x163fb0*/
      ; /*0x163fb2*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x163fc2*/
  v4 = a1 + 8 * v2; /*0x163fc4*/
  *a2 = v4; /*0x163fc7*/
  a2[1] = *(_DWORD *)(v4 + 4); /*0x163fcc*/
  *(_DWORD *)a2[1] = a2; /*0x163fd2*/
  *(_DWORD *)(v4 + 4) = a2; /*0x163fd4*/
  if ( *(_DWORD *)(a1 + 260) < v2 || !*(_DWORD *)(a1 + 264) ) /*0x163fdf*/
    *(_DWORD *)(a1 + 260) = v2; /*0x163fe8*/
  ++*(_DWORD *)(a1 + 264); /*0x163fee*/
  a2[2] = a1; /*0x163ff4*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 256), 0); /*0x164002*/
}
