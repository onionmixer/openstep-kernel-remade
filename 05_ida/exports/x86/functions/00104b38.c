/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104b38. */
void __cdecl expand_fdlist(int a1, int a2)
{
  size_t v2; // esi
  size_t v3; // [esp+Ch] [ebp-Ch]
  void *v4; // [esp+10h] [ebp-8h]
  void *v5; // [esp+14h] [ebp-4h]

  if ( *(_DWORD *)(a1 + 348) <= a2 ) /*0x104b4d*/
  {
    v3 = a2 + 1; /*0x104b56*/
    v5 = (void *)kalloc(4 * (a2 + 1)); /*0x104b66*/
    v4 = (void *)kalloc(a2 + 1); /*0x104b72*/
    if ( a2 >= *(_DWORD *)(a1 + 348) ) /*0x104b80*/
    {
      v2 = *(_DWORD *)(a1 + 348); /*0x104ba0*/
      bzero(v5, 4 * (a2 + 1)); /*0x104ba7*/
      bzero(v4, v3); /*0x104bb4*/
      if ( v2 ) /*0x104bbe*/
      {
        bcopy(*(const void **)(a1 + 336), v5, 4 * v2); /*0x104bd3*/
        bcopy(*(const void **)(a1 + 340), v4, v2); /*0x104be4*/
        kfree(*(_DWORD *)(a1 + 336), 4 * v2); /*0x104bf1*/
        kfree(*(_DWORD *)(a1 + 340), v2); /*0x104c01*/
      }
      *(_DWORD *)(a1 + 336) = v5; /*0x104c09*/
      *(_DWORD *)(a1 + 340) = v4; /*0x104c12*/
      *(_DWORD *)(a1 + 348) = v3; /*0x104c1b*/
    }
    else
    {
      kfree((int)v5, 4 * (a2 + 1)); /*0x104b87*/
      kfree((int)v4, v3); /*0x104b94*/
    }
  }
}
