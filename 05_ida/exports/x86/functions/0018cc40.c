/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cc40. */
void __cdecl reboot_mach(int a1)
{
  int v1; // eax
  int savedregs; // [esp+0h] [ebp+0h]

  v1 = a1; /*0x18cc43*/
  if ( kernel_task ) /*0x18cc4d*/
  {
    reboot_how = a1; /*0x18cc4f*/
    calloutDispatch((int)halt_thread, 0); /*0x18cc5b*/
  }
  else
  {
    LOBYTE(v1) = a1 | 4; /*0x18cc64*/
    boot(1, v1, savedregs); /*0x18cc69*/
  }
}
