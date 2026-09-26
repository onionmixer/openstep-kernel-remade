/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157b7c. */
kern_return_t __cdecl host_kernel_version(host_t host, kernel_version_t kernel_version)
{
  if ( !host ) /*0x157b83*/
    return 4; /*0x157ba0*/
  strncpy(kernel_version, version, 0x200u); /*0x157b93*/
  return 0; /*0x157b9c*/
}
