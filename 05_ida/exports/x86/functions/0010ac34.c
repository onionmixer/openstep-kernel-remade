/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ac34. */
int __cdecl setthetime(_DWORD *a1)
{
  int result; // eax
  int v2; // [esp+Ch] [ebp-8h] BYREF

  result = suser(); /*0x10ac40*/
  if ( result ) /*0x10ac47*/
  {
    getthetime(&v2); /*0x10ac4d*/
    boottime += *a1 - v2; /*0x10ac57*/
    dword_1E97AC = 0; /*0x10ac5d*/
    return host_set_time(dword_1E97B4, *a1, a1[1]); /*0x10ac75*/
  }
  return result; /*0x10ac7d*/
}
