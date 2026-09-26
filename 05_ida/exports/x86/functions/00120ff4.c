/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120ff4. */
int (__cdecl **__cdecl if_registervirtual(int (__cdecl *a1)(int, int), int (__cdecl *a2)(int, int)))(int, int)
{
  int *v2; // ebx
  int (__cdecl **result)(int, int); // eax
  int (__cdecl **v4)(int, int); // edx
  int i; // ebx

  v2 = &dword_1E58D8; /*0x121000*/
  result = (int (__cdecl **)(int, int))kalloc(0xCu); /*0x121007*/
  v4 = result; /*0x12100c*/
  *result = a1; /*0x12100e*/
  result[1] = a2; /*0x121010*/
  result[2] = nullptr; /*0x121013*/
  if ( dword_1E58D8 ) /*0x121024*/
  {
    do /*0x12102d*/
    {
      result = (int (__cdecl **)(int, int))*v2; /*0x121028*/
      v2 = (int *)(result + 2); /*0x12102a*/
    }
    while ( result[2] ); /*0x12102d*/
  }
  *v2 = (int)v4; /*0x121033*/
  for ( i = ifnet; i; i = *(_DWORD *)(i + 92) ) /*0x12103d*/
  {
    if ( !*(_DWORD *)(i + 20) ) /*0x121040*/
      result = (int (__cdecl **)(int, int))a1((int)a2, i); /*0x121048*/
  }
  return result; /*0x121057*/
}
