/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1749c4. */
int __cdecl vm_map_lookup_entry(int a1, unsigned int a2, _DWORD *a3)
{
  volatile __int32 *v3; // edx
  _DWORD *v4; // ecx
  _DWORD *v5; // eax
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // edx

  v3 = (volatile __int32 *)(a1 + 60); /*0x1749d3*/
  do /*0x1749ea*/
  {
    while ( *v3 ) /*0x1749d8*/
      ; /*0x1749da*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1749ea*/
  v4 = *(_DWORD **)(a1 + 56); /*0x1749ec*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1749f1*/
  v5 = (_DWORD *)(a1 + 12); /*0x1749f4*/
  if ( v4 == (_DWORD *)(a1 + 12) ) /*0x1749f9*/
    v4 = *(_DWORD **)(a1 + 16); /*0x1749fb*/
  if ( v4[2] > a2 ) /*0x174a01*/
  {
    v5 = (_DWORD *)v4[1]; /*0x174a18*/
    v4 = *(_DWORD **)(a1 + 16); /*0x174a1b*/
LABEL_18:
    while ( v4 != v5 ) /*0x174a59*/
    {
      if ( v4[3] > a2 ) /*0x174a23*/
      {
        if ( v4[2] > a2 ) /*0x174a28*/
          goto LABEL_19; /*0x174a28*/
        *a3 = v4; /*0x174a2a*/
        v7 = (volatile __int32 *)(a1 + 60); /*0x174a2c*/
        do /*0x174a42*/
        {
          while ( *v7 ) /*0x174a30*/
            ; /*0x174a32*/
        }
        while ( _InterlockedExchange(v7, 1) == 1 ); /*0x174a42*/
        *(_DWORD *)(a1 + 56) = v4; /*0x174a44*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174a49*/
        return 1; /*0x174a51*/
      }
      v4 = (_DWORD *)v4[1]; /*0x174a54*/
    }
    goto LABEL_19; /*0x174a59*/
  }
  if ( v4 == v5 ) /*0x174a05*/
  {
LABEL_19:
    *a3 = *v4; /*0x174a5b*/
    v8 = (volatile __int32 *)(a1 + 60); /*0x174a5f*/
    do /*0x174a76*/
    {
      while ( *v8 ) /*0x174a64*/
        ; /*0x174a66*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x174a76*/
    *(_DWORD *)(a1 + 56) = *a3; /*0x174a7a*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174a7f*/
    return 0; /*0x174a82*/
  }
  if ( v4[3] <= a2 ) /*0x174a0a*/
    goto LABEL_18; /*0x174a0a*/
  *a3 = v4; /*0x174a0c*/
  return 1; /*0x174a87*/
}
