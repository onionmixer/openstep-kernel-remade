/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1209ec. */
int __cdecl nb_alloc(int a1)
{
  unsigned int *v1; // eax
  unsigned int *v2; // ebx
  int result; // eax

  v1 = (unsigned int *)kalloc(a1 + 4); /*0x1209f9*/
  v2 = v1; /*0x1209fe*/
  if ( v1 ) /*0x120a05*/
  {
    *v1 = a1 + 4; /*0x120a07*/
    result = nb_alloc_wrapper(v1 + 1, a1, sub_120B84, v1); /*0x120a14*/
    if ( result ) /*0x120a1e*/
      return result; /*0x120a1e*/
    kfree((int)v2, *v2); /*0x120a24*/
  }
  return 0; /*0x120a2e*/
}
