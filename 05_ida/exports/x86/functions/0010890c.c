/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10890c. */
int __cdecl setrlimit(int a1, const rlimit *a2)
{
  int result; // eax
  _DWORD *v3; // ebx
  _DWORD *v4; // edi
  int v5; // edx
  int v6; // ecx
  vm_address_t address; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x10891b*/
  if ( *v3 <= 5u )
  {
    v4 = (_DWORD *)(active_u + 8 * *v3 + 612); /*0x108936*/
    result = copyin(v3[1], &v8, 8); /*0x108947*/
    *(_BYTE *)(dword_1E875C + 104) = result; /*0x108952*/
    if ( !*(_BYTE *)(dword_1E875C + 104) )
    {
      if ( (v5 = v4[1], v8 <= v5) && v9 <= v5 || (result = suser()) != 0 )
      {
        if ( *v3 == 3
          && (v8 <= *v4
            ? (result = vm_deallocate(
                          *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
                          ~page_mask & (*(_DWORD *)(*(_DWORD *)active_u + 132) - *v4),
                          (~page_mask & (page_mask + *v4)) - (~page_mask & (v8 + page_mask))))
            : (address = ~page_mask & (*(_DWORD *)(*(_DWORD *)active_u + 132) - v8),
               result = vm_allocate(
                          *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12),
                          &address,
                          (~page_mask & (page_mask + v8)) - (~page_mask & (*v4 + page_mask)),
                          0)),
              result) )
        {
          *(_BYTE *)(dword_1E875C + 104) = 22; /*0x108a2a*/
        }
        else
        {
          v6 = v9; /*0x108a33*/
          *v4 = v8; /*0x108a36*/
          v4[1] = v6; /*0x108a38*/
        }
      }
    }
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x108925*/
  }
  return result; /*0x108a3e*/
}
