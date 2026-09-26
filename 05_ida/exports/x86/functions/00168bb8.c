/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168bb8. */
int __cdecl host_stack_usage(int a1, _DWORD *a2, _DWORD *a3, int *a4, int *a5, int *a6, _DWORD *a7)
{
  int v8; // eax
  int v9; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h] BYREF

  if ( !a1 ) /*0x168bcb*/
    return 22; /*0x168bcd*/
  do /*0x168bed*/
  {
    while ( stack_usage_lock ) /*0x168bdb*/
      ; /*0x168bd9*/
  }
  while ( _InterlockedExchange(&stack_usage_lock, 1) == 1 ); /*0x168bed*/
  v9 = stack_max_usage; /*0x168bf5*/
  _InterlockedExchange(&stack_usage_lock, 0); /*0x168bfa*/
  stack_statistics(&v10, (unsigned int *)&v9); /*0x168c08*/
  *a2 = 0; /*0x168c10*/
  *a3 = v10; /*0x168c19*/
  v8 = ~page_mask & (page_mask + 4084 * v10); /*0x168c33*/
  *a4 = v8; /*0x168c35*/
  *a5 = v8; /*0x168c3a*/
  *a6 = v9; /*0x168c42*/
  *a7 = 0; /*0x168c47*/
  return 0; /*0x168c52*/
}
