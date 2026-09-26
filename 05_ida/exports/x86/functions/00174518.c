/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174518. */
unsigned int __cdecl kmem_alloc_wait(_DWORD *a1, int a2)
{
  unsigned int v2; // edi
  int v3; // esi
  unsigned int v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = ~page_mask & (page_mask + a2); /*0x174532*/
  do /*0x1745a3*/
  {
    lock_write((int)a1); /*0x174535*/
    ++a1[19]; /*0x17453a*/
    lock_set_recursive((int)a1); /*0x174541*/
    v5 = a1[5]; /*0x174549*/
    v3 = vm_map_find((int)a1, 0, 0, &v5, v2, 1); /*0x17455d*/
    lock_clear_recursive((int)a1); /*0x174560*/
    if ( v3 ) /*0x17456a*/
    {
      if ( a1[6] - a1[5] < v2 ) /*0x174574*/
      {
        lock_done((int)a1); /*0x174577*/
        return 0; /*0x17457e*/
      }
      assert_wait((int)a1, 1); /*0x174583*/
      lock_done((int)a1); /*0x174589*/
      thread_block(); /*0x17458e*/
    }
    else
    {
      lock_done((int)a1); /*0x174599*/
    }
  }
  while ( v3 ); /*0x1745a3*/
  return v5; /*0x1745ab*/
}
