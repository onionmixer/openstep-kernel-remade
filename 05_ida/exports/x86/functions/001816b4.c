/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1816b4. */
id __cdecl -[KernDeviceDescription allocateResourcesForKey:](KernDeviceDescription *self, SEL a2, const char *a3)
{
  const char *v3; // eax
  const char *v4; // ebx
  id v6; // eax

  v3 = -[KernDeviceDescription stringForKey:](self, sel_stringForKey_, a3); /*0x1816c9*/
  v4 = v3; /*0x1816ce*/
  if ( !v3 ) /*0x1816d5*/
    return self; /*0x1816d7*/
  if ( strchr(v3, 45) ) /*0x1816df*/
    v6 = -[KernDeviceDescription _parseRangeResourceByKey:value:](self, sel__parseRangeResourceByKey_value_, a3, v4); /*0x1816f3*/
  else
    v6 = -[KernDeviceDescription _parseItemResourceByKey:value:](self, sel__parseItemResourceByKey_value_, a3, v4); /*0x181702*/
  if ( !v6 ) /*0x18170c*/
    return nullptr; /*0x181724*/
  -[KernDeviceDescription setResources:forKey:](self, sel_setResources_forKey_, v6, a3); /*0x181718*/
  return self; /*0x181729*/
}
