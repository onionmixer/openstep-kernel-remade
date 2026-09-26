/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c004. */
int __cdecl unix_pid(int a1, _DWORD *a2)
{
  int v3; // eax

  if ( a1 && (v3 = *(_DWORD *)(a1 + 60)) != 0 ) /*0x17c025*/
  {
    *a2 = *(__int16 *)(v3 + 48); /*0x17c02b*/
    return 0; /*0x17c02d*/
  }
  else
  {
    *a2 = -1; /*0x17c011*/
    return 5; /*0x17c017*/
  }
}
