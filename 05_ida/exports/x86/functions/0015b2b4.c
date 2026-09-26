/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b2b4. */
int __cdecl swapinStack(int a1)
{
  _DWORD *v1; // esi
  _DWORD *v2; // eax
  int v3; // ebx
  int v4; // esi
  int *v5; // ecx
  int v6; // edx
  int v8; // [esp+Ch] [ebp-4h]

  v1 = (_DWORD *)(~page_mask & a1); /*0x15b2cc*/
  --dword_1F63BC; /*0x15b2d1*/
  vm_map_pageable(kernel_map, v1, ~page_mask & ((unsigned int)v1 + dword_1E5BA0 + page_mask), 0); /*0x15b2ee*/
  lock_write((int)&stack_queue_lock); /*0x15b2f8*/
  *(_DWORD *)(a1 - 12 + 8) = 2; /*0x15b2fd*/
  if ( *v1 == -17958194 ) /*0x15b30d*/
  {
    *v1 = 0; /*0x15b30f*/
    --dword_1F63C0; /*0x15b315*/
    v2 = v1; /*0x15b31b*/
    v3 = 0; /*0x15b31d*/
    if ( dword_1E5BA4 > 0 ) /*0x15b327*/
    {
      v4 = dword_1E5BA0; /*0x15b329*/
      v8 = dword_1E5BA4; /*0x15b32f*/
      v5 = v2 + 1; /*0x15b332*/
      do /*0x15b37f*/
      {
        if ( !v5[1] ) /*0x15b338*/
        {
          v5[1] = v5[1]; /*0x15b341*/
          v6 = dword_1E5B9C; /*0x15b344*/
          if ( (int *)dword_1E5B9C == &dword_1E5B98 ) /*0x15b350*/
            dword_1E5B98 = (int)v2; /*0x15b352*/
          else
            *(_DWORD *)dword_1E5B9C = v2; /*0x15b35c*/
          *v5 = v6; /*0x15b35e*/
          *v2 = &dword_1E5B98; /*0x15b360*/
          dword_1E5B9C = (int)v2; /*0x15b366*/
          ++dword_1DED68; /*0x15b36b*/
          ++dword_1F63B8; /*0x15b371*/
        }
        v5 = (int *)((char *)v5 + v4); /*0x15b377*/
        v2 = (_DWORD *)((char *)v2 + v4); /*0x15b379*/
        ++v3; /*0x15b37b*/
      }
      while ( v8 > v3 ); /*0x15b37f*/
    }
  }
  return lock_done(&stack_queue_lock); /*0x15b38e*/
}
