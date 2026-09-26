/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1916e0. */
int __cdecl sub_1916E0(int a1, int a2)
{
  unsigned int v2; // ebx
  int v4; // esi
  unsigned int v5; // ecx
  volatile __int32 *v6; // edx
  _DWORD *v7; // eax
  _BYTE *v8; // edx
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // edi
  _DWORD *v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]

  v2 = pg_desc_tbl + 20 * ((unsigned int)(a1 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x191707*/
  if ( a2 == (unsigned __int8)(a2 & *(_BYTE *)(v2 + 16)) ) /*0x191714*/
    return 1; /*0x191716*/
  v12 = (_DWORD *)(pg_desc_tbl + 20 * ((unsigned int)(a1 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1))); /*0x191720*/
  v13 = splvm(); /*0x191728*/
  v4 = *(_DWORD *)(v2 + 4); /*0x19172b*/
  if ( v4 ) /*0x191730*/
  {
    while ( 1 ) /*0x19173b*/
    {
      v5 = v12[2]; /*0x19173b*/
      v6 = (volatile __int32 *)(v4 + 12); /*0x19173e*/
      do /*0x191756*/
      {
        while ( *v6 ) /*0x191744*/
          ; /*0x191746*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x191756*/
      v7 = (_DWORD *)(*(_DWORD *)v4 + 4 * (v5 >> 22)); /*0x191760*/
      if ( (*(_BYTE *)v7 & 1) != 0 ) /*0x191765*/
      {
        v8 = (_BYTE *)(((v5 >> 10) & 0xFFC) + (*v7 & 0xFFFFF000)); /*0x191779*/
        if ( v8 ) /*0x19177b*/
        {
          v9 = ptes_per_vm_page; /*0x19177d*/
          while ( 1 ) /*0x19179d*/
          {
            v10 = v9--; /*0x19179d*/
            if ( v10 <= 0 ) /*0x1917a2*/
              break; /*0x1917a2*/
            if ( (*v8 & 0x40) != 0 ) /*0x19178b*/
              *(_BYTE *)(v2 + 16) |= 1u; /*0x19178d*/
            if ( (*v8 & 0x20) != 0 ) /*0x191794*/
              *(_BYTE *)(v2 + 16) |= 2u; /*0x191796*/
            v8 += 4; /*0x19179a*/
          }
          if ( a2 == (unsigned __int8)(a2 & *(_BYTE *)(v2 + 16)) ) /*0x1917ae*/
            break; /*0x1917ae*/
        }
      }
      _InterlockedExchange((volatile __int32 *)(v4 + 12), 0); /*0x1917b2*/
      v11 = (_DWORD *)*v12; /*0x1917b8*/
      v12 = v11; /*0x1917ba*/
      if ( v11 ) /*0x1917bf*/
      {
        v4 = v11[1]; /*0x1917c1*/
        if ( v4 ) /*0x1917c6*/
          continue; /*0x1917c6*/
      }
      goto LABEL_19; /*0x1917c6*/
    }
    _InterlockedExchange((volatile __int32 *)(v4 + 12), 0); /*0x1917de*/
    splx(v13); /*0x1917e5*/
    return 1; /*0x1917ea*/
  }
  else
  {
LABEL_19:
    splx(v13); /*0x1917cc*/
    return 0; /*0x1917d5*/
  }
}
