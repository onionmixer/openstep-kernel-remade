/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a3c4. */
int fp_kernel_extension_fault()
{
  int v0; // ebx
  int result; // eax
  int v2; // edx

  v0 = dword_1E75F8; /*0x18a3c8*/
  result = sub_18A428(); /*0x18a3ce*/
  v2 = *(_DWORD *)(v0 + 380) | 0x40000000; /*0x18a3d9*/
  *(_DWORD *)(v0 + 380) = v2; /*0x18a3df*/
  if ( active_threads == v0 ) /*0x18a3eb*/
  {
    need_ast[0] |= v2; /*0x18a3f4*/
    return need_ast[0]; /*0x18a3f9*/
  }
  return result; /*0x18a3fe*/
}
