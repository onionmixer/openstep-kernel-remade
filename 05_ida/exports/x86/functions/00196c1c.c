/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196c1c. */
void __cdecl -[kmDevice powerOffRequest](kmDevice *self, SEL a2)
{
  char v2[100]; // [esp+0h] [ebp-64h] BYREF

  printf("\nReally Shut down (y/n)? "); /*0x196c27*/
  gets(v2); /*0x196c31*/
  if ( v2[0] == 121 ) /*0x196c3d*/
    boot(1, 589824, (int)&unk_1E3E68); /*0x196c5c*/
  else
    printf("...aborting shutdown\n"); /*0x196c44*/
}
