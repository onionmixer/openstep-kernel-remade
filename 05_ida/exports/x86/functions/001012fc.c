/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1012fc. */
int __cdecl bcmp(const void *a1, const void *a2, size_t a3)
{
  bool v6; // zf
  int result; // eax

  result = 0; /*0x10130b*/
  v6 = 1; /*0x10130b*/
  do /*0x10130d*/
  {
    if ( !a3 ) /*0x10130d*/
      break; /*0x10130d*/
    v6 = *(_BYTE *)a1 == *(_BYTE *)a2; /*0x10130d*/
    a1 = (char *)a1 + 1; /*0x10130d*/
    a2 = (char *)a2 + 1; /*0x10130d*/
    --a3; /*0x10130d*/
  }
  while ( v6 ); /*0x10130d*/
  if ( !v6 ) /*0x10130f*/
    return (unsigned __int8)*((char *)a1 - 1) - (unsigned __int8)*((char *)a2 - 1); /*0x101319*/
  return result; /*0x10131e*/
}
