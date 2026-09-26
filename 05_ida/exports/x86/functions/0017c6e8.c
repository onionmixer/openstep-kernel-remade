/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c6e8. */
int __cdecl vm_statistics(int a1, int *a2)
{
  if ( !a1 ) /*0x17c6f1*/
    return 4; /*0x17c744*/
  vm_stat = page_size; /*0x17c6f9*/
  dword_1F64F4 = vm_page_free_count; /*0x17c705*/
  dword_1F64F8 = vm_page_active_count; /*0x17c711*/
  dword_1F64FC = vm_page_inactive_count; /*0x17c71d*/
  dword_1F6500 = vm_page_wire_count; /*0x17c729*/
  qmemcpy(a2, &vm_stat, 0x34u); /*0x17c73d*/
  return 0; /*0x17c74c*/
}
