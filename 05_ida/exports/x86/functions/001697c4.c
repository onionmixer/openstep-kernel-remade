/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1697c4. */
int __cdecl calloutEntryFree(int a1)
{
  int v1; // esi

  v1 = splsched(); /*0x1697d1*/
  do /*0x1697ed*/
  {
    while ( dword_1E7244 ) /*0x1697db*/
      ; /*0x1697d9*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x1697ed*/
  if ( *(_DWORD *)(a1 + 28) ) /*0x1697ef*/
  {
    _InterlockedExchange(&dword_1E7244, 0); /*0x1697f7*/
    panic(aCalloutentryfr); /*0x169802*/
  }
  _InterlockedExchange(&dword_1E7244, 0); /*0x16980c*/
  splx(v1); /*0x169813*/
  return kfree(a1, 0x20u); /*0x169823*/
}
