/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cfb8. */
id __usercall md_shutdown_devices@<eax>(int a1@<ebx>)
{
  return _io_setDriverPowerState(a1, 3); /*0x18cfc4*/
}
