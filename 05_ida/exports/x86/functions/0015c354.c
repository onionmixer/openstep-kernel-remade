/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c354. */
char *__cdecl getsectdatafromheader(const mach_header *mhp, const char *segname, const char *sectname, uint32_t *size)
{
  const section *v4; // eax

  v4 = getsectbynamefromheader(mhp, segname, sectname); /*0x15c367*/
  if ( v4 ) /*0x15c36e*/
  {
    *size = v4->size; /*0x15c373*/
    return (char *)v4->addr; /*0x15c375*/
  }
  else
  {
    *size = 0; /*0x15c37c*/
    return nullptr; /*0x15c382*/
  }
}
