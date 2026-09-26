/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a4d8. */
int __cdecl uwritec(int *a1)
{
  unsigned __int8 **v1; // ebx
  int v2; // eax
  int v3; // eax
  int v4; // esi

  if ( a1[5] <= 0 ) /*0x10a4e5*/
    return -1; /*0x10a4e5*/
  while ( 1 ) /*0x10a4eb*/
  {
    if ( a1[1] <= 0 ) /*0x10a4ef*/
      panic(aUwritec); /*0x10a4f6*/
    v1 = (unsigned __int8 **)*a1; /*0x10a4fe*/
    if ( *(_DWORD *)(*a1 + 4) ) /*0x10a500*/
      break; /*0x10a500*/
    *a1 = (int)(v1 + 2); /*0x10a509*/
    v2 = a1[1]; /*0x10a50b*/
    a1[1] = v2 - 1; /*0x10a511*/
    if ( v2 == 1 ) /*0x10a517*/
      return -1; /*0x10a517*/
  }
  v3 = a1[3]; /*0x10a51c*/
  if ( v3 == 1 ) /*0x10a522*/
  {
    v4 = **v1; /*0x10a542*/
  }
  else if ( v3 > 1 ) /*0x10a524*/
  {
    if ( v3 != 2 ) /*0x10a52f*/
LABEL_16:
      panic(aUwritecBogusUi); /*0x10a554*/
    v4 = fuibyte(*v1); /*0x10a550*/
  }
  else
  {
    if ( v3 ) /*0x10a528*/
      goto LABEL_16; /*0x10a528*/
    v4 = fubyte(*v1); /*0x10a53c*/
  }
  if ( v4 < 0 ) /*0x10a562*/
    return -1; /*0x10a578*/
  ++*v1; /*0x10a564*/
  --v1[1]; /*0x10a566*/
  --a1[5]; /*0x10a569*/
  ++a1[2]; /*0x10a56c*/
  return (unsigned __int8)v4; /*0x10a580*/
}
