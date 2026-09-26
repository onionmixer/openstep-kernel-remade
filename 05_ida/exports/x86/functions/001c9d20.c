/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: matrox snapshot; requested VA: 0x1c9d20. */
$3D27A55567FB06BC0E416B979767FD15 *__cdecl -[Object zone](Object *self, SEL a2)
{
  $3D27A55567FB06BC0E416B979767FD15 *result; // eax

  result = ($3D27A55567FB06BC0E416B979767FD15 *)NXZoneFromPtr(self); /*0x1c9d27*/
  if ( !result ) /*0x1c9d31*/
    return NXDefaultMallocZone(); /*0x1c9d33*/
  return result; /*0x1c9d3a*/
}
