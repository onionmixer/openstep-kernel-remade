/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b81c. */
int __cdecl sub_19B81C(int a1)
{
  int v1; // ebx

  v1 = *(_DWORD *)(a1 + 28); /*0x19b824*/
  if ( *(_DWORD *)(v1 + 256) ) /*0x19b827*/
    IOFree(*(_DWORD *)(v1 + 196), 196608); /*0x19b83c*/
  IOFree(v1, 260); /*0x19b84a*/
  return IOFree(a1, 32); /*0x19b85a*/
}
