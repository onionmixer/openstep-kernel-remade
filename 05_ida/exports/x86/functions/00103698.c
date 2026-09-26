/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103698. */
int __cdecl hzto(_DWORD *a1)
{
  int v1; // ecx
  int v3; // [esp+Ch] [ebp-10h]
  _DWORD v4[2]; // [esp+14h] [ebp-8h] BYREF

  getthetime(v4); /*0x1036a8*/
  v1 = *a1 - v4[0]; /*0x1036af*/
  if ( v1 <= 2146483 ) /*0x1036b8*/
    return ((a1[1] - v4[1]) / 1000 + 1000 * v1) / (tick / 1000); /*0x1036f6*/
  v3 = 0x7FFFFFFF; /*0x10370e*/
  if ( v1 <= 0x7FFFFFFF / hz ) /*0x103717*/
    return hz * v1; /*0x10371c*/
  return v3; /*0x103725*/
}
