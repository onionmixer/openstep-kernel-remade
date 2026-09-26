/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ab9c. */
vm_size_t initKernelStacks()
{
  vm_size_t result; // eax

  dword_1E5B9C = (int)&dword_1E5B98; /*0x15ab9f*/
  dword_1E5B98 = (int)&dword_1E5B98; /*0x15aba9*/
  lock_init(&stack_queue_lock, 1); /*0x15abba*/
  dword_1E5BA0 = 4096; /*0x15abbf*/
  result = (page_size + 4095) >> 12; /*0x15abd3*/
  dword_1E5BA4 = result; /*0x15abd6*/
  return result; /*0x15abdd*/
}
