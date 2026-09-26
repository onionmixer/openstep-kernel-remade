/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15e2ac. */
void __cdecl unmap_vnode(_DWORD *a1)
{
  int v1; // ebx
  __int16 v2; // dx
  __int16 v3; // ax
  int v4; // esi
  volatile __int32 *v5; // edx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v1 = *a1; /*0x15e2b8*/
  if ( (*(_BYTE *)(*a1 + 56) & 0x10) != 0 ) /*0x15e2be*/
  {
    v2 = *(_WORD *)(v1 + 4); /*0x15e2c4*/
    *(_WORD *)(v1 + 4) = v2 - 1; /*0x15e2cc*/
    if ( (__int16)(v2 - 1) <= 0 ) /*0x15e2d7*/
    {
      *(_WORD *)(v1 + 4) = v2; /*0x15e2dd*/
      (*(void (__cdecl **)(_DWORD *, int *))(a1[7] + 124))(a1, &v6); /*0x15e2ec*/
      v3 = *(_WORD *)(v1 + 4); /*0x15e2ee*/
      *(_WORD *)(v1 + 4) = v3 - 1; /*0x15e2f6*/
      if ( v6 ) /*0x15e301*/
      {
        v4 = *(_DWORD *)(v1 + 36); /*0x15e310*/
        if ( close_flush || (*(_BYTE *)(v1 + 56) & 4) != 0 ) /*0x15e320*/
        {
          *(_WORD *)(v1 + 4) = v3; /*0x15e322*/
          vmp_get(v1); /*0x15e327*/
          vmp_push(v1); /*0x15e32d*/
        }
        v5 = (volatile __int32 *)(v4 + 16); /*0x15e335*/
        do /*0x15e34a*/
        {
          while ( *v5 ) /*0x15e338*/
            ; /*0x15e33a*/
        }
        while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15e34a*/
        vm_object_deactivate_pages(v4); /*0x15e34d*/
        _InterlockedExchange((volatile __int32 *)(v4 + 16), 0); /*0x15e357*/
        if ( close_flush || (*(_BYTE *)(v1 + 56) & 4) != 0 ) /*0x15e367*/
        {
          vmp_put(v1); /*0x15e36a*/
          --*(_WORD *)(v1 + 4); /*0x15e36f*/
        }
      }
      else
      {
        mfs_memfree(v1, 0); /*0x15e306*/
      }
    }
  }
}
