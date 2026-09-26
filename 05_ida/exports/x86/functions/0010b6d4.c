/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b6d4. */
int __cdecl getdomainname(char *a1, int a2)
{
  _DWORD *v2; // ecx
  unsigned int v3; // eax
  char v4; // dl
  int result; // eax

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10b6dc*/
  v3 = v2[1]; /*0x10b6df*/
  if ( v3 > domainnamelen + 1 ) /*0x10b6eb*/
    v3 = domainnamelen + 1; /*0x10b6ed*/
  v4 = copyout(&domainname, *v2, v3); /*0x10b6fd*/
  result = dword_1E875C; /*0x10b6ff*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x10b704*/
  return result; /*0x10b709*/
}
