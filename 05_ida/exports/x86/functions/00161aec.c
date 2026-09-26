/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161aec. */
kern_return_t __cdecl processor_set_policy_disable(processor_set_t processor_set, int policy, boolean_t change_threads)
{
  int v3; // ecx
  volatile __int32 *v5; // edx
  int v6; // edx
  thread_act_t i; // ebx
  mach_msg_type_number_t v8; // [esp+0h] [ebp-10h]
  boolean_t v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-4h]

  v3 = policy; /*0x161af8*/
  if ( !processor_set || policy == 1 || (unsigned int)(policy - 1) > 3 ) /*0x161b0a*/
    return 4; /*0x161b0c*/
  v5 = (volatile __int32 *)(processor_set + 344); /*0x161b14*/
  do /*0x161b2e*/
  {
    while ( *v5 ) /*0x161b1c*/
      ; /*0x161b1e*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x161b2e*/
  v6 = *(_DWORD *)(processor_set + 360); /*0x161b30*/
  if ( (v6 & policy) != 0 ) /*0x161b38*/
  {
    *(_DWORD *)(processor_set + 360) = ~policy & v6; /*0x161b40*/
    if ( change_threads ) /*0x161b4a*/
    {
      for ( i = *(_DWORD *)(processor_set + 312); processor_set + 312 != i; i = *(_DWORD *)(i + 24) ) /*0x161b5a*/
      {
        if ( *(_DWORD *)(i + 96) == v3 ) /*0x161b5f*/
        {
          v10 = v3; /*0x161b66*/
          thread_policy(i, 1, nullptr, v8, v9); /*0x161b69*/
          v3 = v10; /*0x161b71*/
        }
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)(processor_set + 344), 0); /*0x161b7d*/
  return 0; /*0x161b88*/
}
