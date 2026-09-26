/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a38c. */
kern_return_t fp_extension_fault()
{
  int v0; // ebx
  kern_return_t result; // eax

  v0 = dword_1E75F8; /*0x18a390*/
  result = sub_18A428(); /*0x18a396*/
  if ( active_threads == v0 ) /*0x18a3a1*/
    return exception(3, (exception_data_t)0x10, 0); /*0x18a3a9*/
  *(_DWORD *)(v0 + 380) |= 0x40000000u; /*0x18a3b0*/
  return result; /*0x18a3ba*/
}
