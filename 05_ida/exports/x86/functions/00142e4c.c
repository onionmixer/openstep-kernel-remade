/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142e4c. */
vm_size_t bufstats()
{
  vm_size_t result; // eax
  void *v1; // esp
  unsigned int v2; // ebx
  vm_size_t v3; // ecx
  int v4; // esi
  vm_size_t v5; // ebx
  vm_size_t v6; // ebx
  vm_size_t v7; // ecx
  int v8; // [esp+0h] [ebp-20h] BYREF
  int v9; // [esp+Ch] [ebp-14h]
  int *v10; // [esp+10h] [ebp-10h]
  int *v11; // [esp+14h] [ebp-Ch]
  int *v12; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  result = 4 * (0x2000 / page_size) + 4; /*0x142e62*/
  v1 = alloca(result); /*0x142e69*/
  v11 = &v8; /*0x142e6b*/
  v12 = &bfreelist; /*0x142e6e*/
  for ( i = 0; v12 < (int *)&buf; ++i )
  {
    v9 = 0; /*0x142e8c*/
    v2 = 0; /*0x142e93*/
    v3 = page_size; /*0x142e95*/
    do /*0x142ec3*/
      v11[v2++] = 0; /*0x142eb3*/
    while ( v2 <= 0x2000 / v3 ); /*0x142ec3*/
    v4 = splbio(); /*0x142eca*/
    v10 = (int *)v12[3]; /*0x142ed2*/
    if ( v10 != v12 ) /*0x142eda*/
    {
      v5 = page_size; /*0x142edc*/
      do /*0x142f05*/
      {
        ++v11[v10[6] / v5]; /*0x142ef1*/
        ++v9; /*0x142ef4*/
        v10 = (int *)v10[3]; /*0x142efd*/
      }
      while ( v10 != v12 ); /*0x142f05*/
    }
    splx(v4); /*0x142f08*/
    printf("%s: total-%d", (&off_1DE120)[i], v9);
    v6 = 0; /*0x142f26*/
    v7 = page_size; /*0x142f2b*/
    do /*0x142f71*/
    {
      if ( v11[v6] ) /*0x142f47*/
        printf(", %d-%d", v7 * v6, v11[v6]); /*0x142f5a*/
      ++v6; /*0x142f62*/
      v7 = page_size; /*0x142f63*/
    }
    while ( v6 <= 0x2000 / page_size ); /*0x142f71*/
    result = printf("\n"); /*0x142f78*/
    v12 += 17; /*0x142f80*/
  }
  return result; /*0x142f97*/
}
