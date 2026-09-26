/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15beb4. */
int __cdecl host_get_time(int a1, _DWORD *a2)
{
  _DWORD *v3; // edx

  if ( !a1 ) /*0x15bebf*/
    return 22; /*0x15bec1*/
  v3 = mtime; /*0x15bec8*/
  do /*0x15bedf*/
  {
    *a2 = *v3; /*0x15bed2*/
    a2[1] = v3[1]; /*0x15bed7*/
  }
  while ( *a2 != v3[2] ); /*0x15bedf*/
  return 0; /*0x15bee3*/
}
