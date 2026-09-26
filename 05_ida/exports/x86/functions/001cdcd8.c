/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdcd8. */
int _objc_create_zone()
{
  int v1; // [esp-Ch] [ebp-Ch]
  int v2; // [esp-8h] [ebp-8h]
  int v3; // [esp-4h] [ebp-4h]

  if ( !dword_1E55B4 ) /*0x1cdce2*/
  {
    dword_1E55B4 = NXCreateZone(0x2000, 0x2000, 1); /*0x1cdcf5*/
    NXNameZone(dword_1E55B4, "ObjC", v1, v2, v3); /*0x1cdd00*/
  }
  return dword_1E55B4; /*0x1cdd0c*/
}
