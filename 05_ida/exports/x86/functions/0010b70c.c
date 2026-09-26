/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b70c. */
int __cdecl setdomainname(const char *a1, int a2)
{
  _DWORD *v2; // ebx
  int result; // eax

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10b715*/
  result = suser(); /*0x10b718*/
  if ( result ) /*0x10b71f*/
  {
    if ( v2[1] <= 0xFFu ) /*0x10b729*/
    {
      domainnamelen = v2[1]; /*0x10b738*/
      *(_BYTE *)(dword_1E875C + 104) = copyin(*v2, domainname, v2[1]); /*0x10b755*/
      result = domainnamelen; /*0x10b758*/
      domainname[domainnamelen] = 0; /*0x10b75d*/
    }
    else
    {
      result = dword_1E875C; /*0x10b72b*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10b730*/
    }
  }
  return result; /*0x10b764*/
}
