/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161a0c. */
kern_return_t __cdecl processor_set_max_priority(
        processor_set_t processor_set,
        int max_priority,
        boolean_t change_threads)
{
  int v3; // ecx
  volatile __int32 *v5; // edx
  int i; // ebx
  int v7; // [esp+Ch] [ebp-4h]

  v3 = max_priority; /*0x161a18*/
  if ( !processor_set || (unsigned int)max_priority > 0x1F ) /*0x161a22*/
    return 4; /*0x161a24*/
  v5 = (volatile __int32 *)(processor_set + 344); /*0x161a2c*/
  do /*0x161a46*/
  {
    while ( *v5 ) /*0x161a34*/
      ; /*0x161a36*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x161a46*/
  *(_DWORD *)(processor_set + 356) = max_priority; /*0x161a48*/
  if ( change_threads ) /*0x161a52*/
  {
    for ( i = *(_DWORD *)(processor_set + 312); processor_set + 312 != i; i = *(_DWORD *)(i + 24) ) /*0x161a62*/
    {
      if ( *(_DWORD *)(i + 84) < v3 ) /*0x161a67*/
      {
        v7 = v3; /*0x161a6c*/
        thread_max_priority(i, processor_set, v3); /*0x161a6f*/
        v3 = v7; /*0x161a77*/
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)(processor_set + 344), 0); /*0x161a83*/
  return 0; /*0x161a8e*/
}
