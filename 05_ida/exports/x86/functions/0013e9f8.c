/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13e9f8. */
int __cdecl sub_13E9F8(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v3; // ebx
  __int16 v4; // ax
  __int16 v5; // ax
  int *v6; // edi
  char v7; // al
  __int16 v8; // ax
  __int16 v9; // ax
  __int16 v10; // ax
  __int16 v11; // ax
  __int16 v12; // ax
  __int16 v13; // ax
  __int16 v15; // ax
  int v16; // [esp+10h] [ebp-4h] BYREF

  v3 = 0; /*0x13ea04*/
  while ( 1 ) /*0x13ea19*/
  {
    v4 = *(_WORD *)(a1 + 68); /*0x13ea19*/
    if ( (v4 & 1) == 0 ) /*0x13ea1f*/
      break; /*0x13ea1f*/
    LOBYTE(v4) = v4 | 0x10; /*0x13ea08*/
    *(_WORD *)(a1 + 68) = v4; /*0x13ea0a*/
    sleep(a1); /*0x13ea11*/
  }
  v5 = *(_WORD *)(a1 + 68); /*0x13ea21*/
  LOBYTE(v5) = v5 | 1; /*0x13ea25*/
  *(_WORD *)(a1 + 68) = v5; /*0x13ea27*/
  if ( !*(_WORD *)(a1 + 102) || *(_DWORD *)(a1 + 108) <= 0x17u ) /*0x13ea36*/
  {
    *(_WORD *)(a1 + 68) = v5 & 0xFFFE; /*0x13ea3d*/
    if ( (v5 & 0x10) != 0 ) /*0x13ea43*/
    {
      LOBYTE(v5) = v5 & 0xEE; /*0x13ea49*/
      *(_WORD *)(a1 + 68) = v5; /*0x13ea4b*/
      wakeup(a1); /*0x13ea50*/
    }
    return 0; /*0x13ec10*/
  }
  v6 = (int *)blkatoff(a1, 0, &v16); /*0x13ea68*/
  if ( v6 ) /*0x13ea6f*/
  {
    if ( *(_DWORD *)(v16 + 12) != *(_DWORD *)(a3 + 72) ) /*0x13ea8f*/
    {
      if ( *(_WORD *)(v16 + 18) == 2 && *(_WORD *)(v16 + 20) == 11822 ) /*0x13eaa2*/
      {
        ++*(_WORD *)(a3 + 102); /*0x13eac3*/
        *(_BYTE *)(a3 + 68) |= 0x40u; /*0x13eac7*/
        iupdat(a3, 1); /*0x13eace*/
        dnlc_remove(a1 + 12, asc_1DDE54); /*0x13eadc*/
        *(_DWORD *)(v16 + 12) = *(_DWORD *)(a3 + 72); /*0x13eaea*/
        dnlc_enter(a1 + 12, asc_1DDE57, a3 + 12, nullptr); /*0x13eafc*/
        byte_swap_dir_block_out(v6); /*0x13eb05*/
        bwrite(v6); /*0x13eb0b*/
        v6 = nullptr; /*0x13eb10*/
        v7 = *(_BYTE *)(dword_1E875C + 104); /*0x13eb1a*/
        if ( !v7 ) /*0x13eb1f*/
        {
          v8 = *(_WORD *)(a1 + 68); /*0x13eb2c*/
          *(_WORD *)(a1 + 68) = v8 & 0xFFFE; /*0x13eb35*/
          if ( (v8 & 0x10) != 0 ) /*0x13eb3b*/
          {
            LOBYTE(v8) = v8 & 0xEE; /*0x13eb3d*/
            *(_WORD *)(a1 + 68) = v8; /*0x13eb3f*/
            wakeup(a1); /*0x13eb44*/
          }
          if ( a2 ) /*0x13eb50*/
          {
            v9 = *(_WORD *)(a3 + 68); /*0x13eb59*/
            *(_WORD *)(a3 + 68) = v9 & 0xFFFE; /*0x13eb62*/
            if ( (v9 & 0x10) != 0 ) /*0x13eb68*/
            {
              LOBYTE(v9) = v9 & 0xEE; /*0x13eb6a*/
              *(_WORD *)(a3 + 68) = v9; /*0x13eb6c*/
              wakeup(a3); /*0x13eb71*/
            }
            while ( 1 ) /*0x13eb93*/
            {
              v10 = *(_WORD *)(a2 + 68); /*0x13eb93*/
              if ( (v10 & 1) == 0 ) /*0x13eb99*/
                break; /*0x13eb99*/
              LOBYTE(v10) = v10 | 0x10; /*0x13eb7c*/
              *(_WORD *)(a2 + 68) = v10; /*0x13eb81*/
              sleep(a2); /*0x13eb88*/
            }
            *(_BYTE *)(a2 + 68) |= 1u; /*0x13eb9e*/
            v11 = *(_WORD *)(a2 + 102); /*0x13eba2*/
            if ( v11 ) /*0x13eba9*/
            {
              *(_WORD *)(a2 + 102) = v11 - 1; /*0x13ebad*/
              *(_BYTE *)(a2 + 68) |= 0x40u; /*0x13ebb1*/
              iupdat(a2, 1); /*0x13ebb8*/
            }
            v12 = *(_WORD *)(a2 + 68); /*0x13ebc3*/
            *(_WORD *)(a2 + 68) = v12 & 0xFFFE; /*0x13ebcc*/
            if ( (v12 & 0x10) != 0 ) /*0x13ebd2*/
            {
              LOBYTE(v12) = v12 & 0xEE; /*0x13ebd4*/
              *(_WORD *)(a2 + 68) = v12; /*0x13ebd6*/
              wakeup(a2); /*0x13ebdb*/
            }
            while ( 1 ) /*0x13ebff*/
            {
              v13 = *(_WORD *)(a3 + 68); /*0x13ebff*/
              if ( (v13 & 1) == 0 ) /*0x13ec05*/
                break; /*0x13ec05*/
              LOBYTE(v13) = v13 | 0x10; /*0x13ebe8*/
              *(_WORD *)(a3 + 68) = v13; /*0x13ebed*/
              sleep(a3); /*0x13ebf4*/
            }
            *(_BYTE *)(a3 + 68) |= 1u; /*0x13ec0a*/
          }
          return 0; /*0x13ec0a*/
        }
        v3 = v7; /*0x13eb21*/
      }
      else
      {
        sub_13F5AC(a1, aMangledEntry, 0); /*0x13eaac*/
        v3 = 22; /*0x13eab1*/
      }
    }
  }
  else
  {
    v3 = *(char *)(dword_1E875C + 104); /*0x13ea76*/
  }
  if ( v6 ) /*0x13ec16*/
  {
    byte_swap_dir_block_out(v6); /*0x13ec19*/
    brelse((int)v6); /*0x13ec1f*/
  }
  v15 = *(_WORD *)(a1 + 68); /*0x13ec27*/
  *(_WORD *)(a1 + 68) = v15 & 0xFFFE; /*0x13ec30*/
  if ( (v15 & 0x10) != 0 ) /*0x13ec36*/
  {
    LOBYTE(v15) = v15 & 0xEE; /*0x13ec38*/
    *(_WORD *)(a1 + 68) = v15; /*0x13ec3a*/
    wakeup(a1); /*0x13ec3f*/
  }
  return v3; /*0x13ec49*/
}
