/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155fac. */
int __cdecl port_allocate(int a1, unsigned int *a2)
{
  int v3; // eax
  int v4; // ecx
  volatile __int32 *v5; // [esp+4h] [ebp-4h] BYREF

  if ( !a1 ) /*0x155fb8*/
    return 4; /*0x155fba*/
  v3 = ipc_port_alloc_compat(a1, a2, (int *)&v5); /*0x155fcd*/
  v4 = v3; /*0x155fd2*/
  if ( v3 ) /*0x155fd6*/
  {
    if ( v3 != 6 ) /*0x155fe7*/
      return 4; /*0x155fe9*/
  }
  else
  {
    _InterlockedExchange(v5, 0); /*0x155fdd*/
  }
  return v4; /*0x155ff0*/
}
