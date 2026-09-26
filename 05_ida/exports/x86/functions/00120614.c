/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120614. */
int __cdecl vtrip_config(int a1, int a2, int a3, int a4)
{
  _DWORD v5[4]; // [esp+4h] [ebp-10h] BYREF

  v5[0] = a1; /*0x120627*/
  v5[1] = a2; /*0x12062a*/
  v5[2] = a3; /*0x12062d*/
  v5[3] = a4; /*0x120630*/
  return if_registervirtual(sub_120458, v5); /*0x120641*/
}
