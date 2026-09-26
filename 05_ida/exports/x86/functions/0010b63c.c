/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b63c. */
int __cdecl gethostname(char *a1, size_t a2)
{
  _DWORD *v2; // ecx
  size_t v3; // eax
  char v4; // dl
  int result; // eax

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10b644*/
  v3 = v2[1]; /*0x10b647*/
  if ( v3 > hostnamelen + 1 ) /*0x10b653*/
    v3 = hostnamelen + 1; /*0x10b655*/
  v4 = copyout(&hostname, *v2, v3); /*0x10b665*/
  result = dword_1E875C; /*0x10b667*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x10b66c*/
  return result; /*0x10b671*/
}
