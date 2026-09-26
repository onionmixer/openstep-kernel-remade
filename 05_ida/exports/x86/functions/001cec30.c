/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cec30. */
char *__cdecl getsectdatafromheaderinfo(int a1, char *segname, char *sectname, uint32_t *size)
{
  char *result; // eax

  result = getsectdatafromheader(*(const mach_header **)a1, segname, sectname, size); /*0x1cec46*/
  if ( result ) /*0x1cec4d*/
    result += *(_DWORD *)(a1 + 16); /*0x1cec4f*/
  return result; /*0x1cec52*/
}
