/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1618c0. */
kern_return_t __cdecl processor_get_assignment(processor_t processor, processor_set_name_t *assigned_set)
{
  int v2; // eax
  processor_set_name_t v4; // ecx
  volatile __int32 *v5; // edx

  v2 = *(_DWORD *)(processor + 276); /*0x1618c9*/
  if ( v2 == 5 || !v2 ) /*0x1618d6*/
    return 5; /*0x1618d8*/
  *assigned_set = *(_DWORD *)(processor + 300); /*0x1618ea*/
  v4 = *assigned_set; /*0x1618ec*/
  v5 = (volatile __int32 *)(*assigned_set + 328); /*0x1618ee*/
  do /*0x161906*/
  {
    while ( *v5 ) /*0x1618f4*/
      ; /*0x1618f6*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x161906*/
  ++*(_DWORD *)(v4 + 324); /*0x161908*/
  _InterlockedExchange((volatile __int32 *)(v4 + 328), 0); /*0x161910*/
  return 0; /*0x1618df*/
}
