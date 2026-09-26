/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c454. */
int ipc_port_timestamp()
{
  int v0; // edx

  do /*0x14c471*/
  {
    while ( ipc_port_timestamp_lock_data ) /*0x14c45f*/
      ; /*0x14c45d*/
  }
  while ( _InterlockedExchange(&ipc_port_timestamp_lock_data, 1) == 1 ); /*0x14c471*/
  v0 = ipc_port_timestamp_data++; /*0x14c473*/
  _InterlockedExchange(&ipc_port_timestamp_lock_data, 0); /*0x14c481*/
  return v0; /*0x14c48b*/
}
