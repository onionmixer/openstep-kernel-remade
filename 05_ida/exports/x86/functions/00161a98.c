/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161a98. */
kern_return_t __cdecl processor_set_policy_enable(processor_set_t processor_set, int policy)
{
  volatile __int32 *v3; // edx

  if ( !processor_set || (unsigned int)(policy - 1) > 3 ) /*0x161aac*/
    return 4; /*0x161aae*/
  v3 = (volatile __int32 *)(processor_set + 344); /*0x161ab8*/
  do /*0x161ad2*/
  {
    while ( *v3 ) /*0x161ac0*/
      ; /*0x161ac2*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x161ad2*/
  *(_DWORD *)(processor_set + 360) |= policy; /*0x161ad4*/
  _InterlockedExchange((volatile __int32 *)(processor_set + 344), 0); /*0x161adc*/
  return 0; /*0x161ae4*/
}
