/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1078dc. */
void *alloc_posix_proc()
{
  void *result; // eax

  result = (void *)kalloc(0x20u); /*0x1078e3*/
  qmemcpy(result, &unk_1D10BC, 0x20u); /*0x1078f5*/
  return result; /*0x1078fa*/
}
