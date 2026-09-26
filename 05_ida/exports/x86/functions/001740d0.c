/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1740d0. */
int __cdecl copyinmap(int a1, void *a2, void *a3, size_t a4)
{
  if ( *(_DWORD *)(a1 + 36) == kernel_pmap ) /*0x1740e9*/
  {
    bcopy(a2, a3, a4); /*0x1740ee*/
    return 0; /*0x1740f3*/
  }
  else if ( *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12) == a1 ) /*0x174103*/
  {
    return copyin(a2, a3, a4); /*0x174108*/
  }
  else
  {
    return 1; /*0x174110*/
  }
}
