/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184b84. */
char *__cdecl IOCopyString(char *__src)
{
  char *v1; // edi

  v1 = (char *)IOMalloc(strlen(__src) + 1); /*0x184ba2*/
  strcpy(v1, __src); /*0x184ba6*/
  return v1; /*0x184bb0*/
}
