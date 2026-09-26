/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x102934. */
void __cdecl task_name(const char *a1)
{
  unsigned int v1; // ecx
  size_t v2; // edx

  v1 = strlen(a1) + 1; /*0x102946*/
  v2 = 17; /*0x10294d*/
  if ( v1 - 1 <= 0x10 ) /*0x102955*/
    v2 = v1; /*0x102957*/
  bcopy(a1, (void *)(active_u + 8), v2); /*0x102964*/
}
