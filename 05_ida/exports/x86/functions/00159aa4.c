/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159aa4. */
int __cdecl retrieve_task_notify(int a1)
{
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // ebx

  v1 = *(_DWORD *)(a1 + 136); /*0x159aac*/
  v2 = (volatile __int32 *)(v1 + 8); /*0x159ab2*/
  do /*0x159aca*/
  {
    while ( *v2 ) /*0x159ab8*/
      ; /*0x159aba*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x159aca*/
  if ( *(_DWORD *)(v1 + 12) ) /*0x159acc*/
  {
    v3 = *(_DWORD *)(v1 + 68); /*0x159ad2*/
    if ( v3 && v3 != -1 ) /*0x159adc*/
      ipc_object_reference(*(_DWORD *)(v1 + 68)); /*0x159adf*/
  }
  else
  {
    v3 = 0; /*0x159ae8*/
  }
  _InterlockedExchange((volatile __int32 *)(v1 + 8), 0); /*0x159aec*/
  return v3; /*0x159af4*/
}
