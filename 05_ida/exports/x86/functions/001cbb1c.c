/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbb1c. */
uintptr_t __cdecl NXPtrHash(const void *info, const void *data)
{
  return (unsigned int)data ^ HIWORD(data); /*0x1cbb28*/
}
