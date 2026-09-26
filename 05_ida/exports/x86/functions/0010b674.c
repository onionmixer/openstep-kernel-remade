/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b674. */
int __cdecl sethostname(const char *a1, int a2)
{
  _DWORD *v2; // ebx
  int result; // eax

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10b67d*/
  result = suser(); /*0x10b680*/
  if ( result ) /*0x10b687*/
  {
    if ( v2[1] <= 0xFFu ) /*0x10b691*/
    {
      hostnamelen = v2[1]; /*0x10b6a0*/
      *(_BYTE *)(dword_1E875C + 104) = copyin(*v2, hostname, v2[1]); /*0x10b6bd*/
      result = hostnamelen; /*0x10b6c0*/
      hostname[hostnamelen] = 0; /*0x10b6c5*/
    }
    else
    {
      result = dword_1E875C; /*0x10b693*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x10b698*/
    }
  }
  return result; /*0x10b6cc*/
}
