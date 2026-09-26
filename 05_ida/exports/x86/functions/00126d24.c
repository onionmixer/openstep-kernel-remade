/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126d24. */
unsigned int __cdecl save_rte(unsigned __int8 *a1, int a2)
{
  unsigned int result; // eax
  unsigned int v3; // ebx

  result = (unsigned int)a1; /*0x126d28*/
  v3 = a1[1]; /*0x126d2b*/
  if ( v3 <= 0xA3 )
  {
    bcopy(a1, (char *)&dword_1E5908 + 1, a1[1]); /*0x126d57*/
    result = (v3 - 3) >> 2; /*0x126d5f*/
    ip_nhops = result; /*0x126d62*/
    dword_1E590C[result] = a2; /*0x126d6a*/
    ++ip_nhops; /*0x126d71*/
  }
  else if ( ipprintfs )
  {
    return printf("save_rte: olen %d\n", a1[1]);
  }
  return result; /*0x126d77*/
}
