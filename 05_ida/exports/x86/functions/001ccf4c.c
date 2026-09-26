/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccf4c. */
int __cdecl sub_1CCF4C(int a1)
{
  int zone; // eax
  int result; // eax

  if ( !dword_1E55B0 ) /*0x1ccf5a*/
  {
    zone = _objc_create_zone(); /*0x1ccf5c*/
    dword_1E55B0 = (int)NXCreateMapTableFromZone( /*0x1ccf85*/
                          NXStrValueMapPrototype,
                          (int)_mapStrIsEqual,
                          (int)_mapNoFree,
                          0,
                          8u,
                          zone);
  }
  result = NXMapGet((_DWORD *)dword_1E55B0, *(_DWORD *)(a1 + 8)); /*0x1ccf98*/
  if ( !result ) /*0x1ccfa2*/
    return NXMapInsert((_DWORD *)dword_1E55B0, *(_DWORD *)(a1 + 8), a1); /*0x1ccfb0*/
  return result; /*0x1ccfb5*/
}
