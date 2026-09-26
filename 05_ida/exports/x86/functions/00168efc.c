/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168efc. */
int __cdecl thread_swapin(_DWORD *a1)
{
  int result; // eax

  result = a1[19]; /*0x168f03*/
  if ( (result & 0x300) == 0x100 ) /*0x168f14*/
  {
    BYTE1(result) = BYTE1(result) & 0xFC | 2; /*0x168f23*/
    a1[19] = result; /*0x168f26*/
    do /*0x168f45*/
    {
      while ( swapper_lock_data ) /*0x168f33*/
        ; /*0x168f31*/
    }
    while ( _InterlockedExchange(&swapper_lock_data, 1) == 1 ); /*0x168f45*/
    *a1 = &swapin_queue; /*0x168f47*/
    a1[1] = dword_1F6D94; /*0x168f53*/
    *(_DWORD *)a1[1] = a1; /*0x168f59*/
    dword_1F6D94 = (int)a1; /*0x168f5b*/
    _InterlockedExchange(&swapper_lock_data, 0); /*0x168f63*/
    return thread_wakeup_prim((int)&swapin_queue, 0, 0); /*0x168f72*/
  }
  else if ( (result & 0x300) != 0x200 ) /*0x168f1c*/
  {
    panic(aThreadSwapin); /*0x168f81*/
  }
  return result; /*0x168f86*/
}
