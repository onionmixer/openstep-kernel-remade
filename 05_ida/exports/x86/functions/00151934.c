/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151934. */
int __cdecl ipc_table_fill(int a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // ebx
  vm_size_t v5; // esi
  int result; // eax
  vm_size_t i; // edi
  unsigned int j; // esi
  unsigned int v9; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]

  v10 = a3 * a4; /*0x151944*/
  v4 = 0; /*0x151947*/
  v9 = 1; /*0x151949*/
  if ( a2 ) /*0x151953*/
  {
    v5 = page_size; /*0x151955*/
    do /*0x15197e*/
    {
      if ( v9 >= v5 ) /*0x15195f*/
        break; /*0x15195f*/
      if ( v9 >= v10 ) /*0x151967*/
      {
        result = v9 / a4; /*0x15196e*/
        *(_DWORD *)(a1 + 4 * v4++) = v9 / a4; /*0x151974*/
      }
      v9 *= 2; /*0x151978*/
    }
    while ( a2 > v4 ); /*0x15197e*/
  }
  for ( i = page_size; a2 > v4; i *= 2 ) /*0x151989*/
  {
    for ( j = 0; j <= 0xE; ++j ) /*0x15198c*/
    {
      if ( a2 <= v4 ) /*0x151993*/
        break; /*0x151993*/
      if ( v9 >= v10 ) /*0x15199b*/
      {
        result = v9 / a4; /*0x1519a2*/
        *(_DWORD *)(a1 + 4 * v4++) = v9 / a4; /*0x1519a8*/
      }
      v9 += i; /*0x1519ad*/
    }
  }
  return result; /*0x1519bf*/
}
