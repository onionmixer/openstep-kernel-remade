/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135dbc. */
char *__cdecl clnt_sperrno(clnt_stat a1)
{
  unsigned int v1; // edx
  int v2; // eax

  v1 = 0; /*0x135dc3*/
  v2 = 0; /*0x135dca*/
  do /*0x135de3*/
  {
    if ( dword_1DCE88[v2] == a1 ) /*0x135dd2*/
      return (char *)dword_1DCE88[v2 + 1]; /*0x135dd8*/
    v2 += 2; /*0x135ddc*/
    ++v1; /*0x135ddf*/
  }
  while ( v1 <= 0x10 ); /*0x135de3*/
  return aRpcUnknownErro; /*0x135dea*/
}
