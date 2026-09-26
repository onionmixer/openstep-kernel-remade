/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cc28. */
int halt_thread()
{
  int savedregs; // [esp+0h] [ebp+0h]

  return boot(1, reboot_how, savedregs); /*0x18cc3b*/
}
