/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174120. */
int __cdecl copyoutmap(int a1, void *a2, void *a3, size_t a4)
{
  if ( *(_DWORD *)(a1 + 36) == kernel_pmap ) /*0x174139*/
  {
    bcopy(a2, a3, a4); /*0x17413e*/
    return 0; /*0x174143*/
  }
  else if ( *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12) == a1 ) /*0x174153*/
  {
    return copyout(a2, a3, a4); /*0x174158*/
  }
  else
  {
    return 1; /*0x174160*/
  }
}
