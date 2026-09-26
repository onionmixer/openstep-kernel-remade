/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181d28. */
int __cdecl destroy_dev_port(int a1)
{
  int result; // eax
  volatile __int32 *v2; // edx

  result = a1; /*0x181d2b*/
  if ( a1 ) /*0x181d30*/
  {
    v2 = (volatile __int32 *)IOConvertPort(a1, 1, 0); /*0x181d3c*/
    do /*0x181d56*/
    {
      while ( *v2 ) /*0x181d44*/
        ; /*0x181d46*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x181d56*/
    return ipc_port_destroy((int)v2); /*0x181d59*/
  }
  return result; /*0x181d60*/
}
