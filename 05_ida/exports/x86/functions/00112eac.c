/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112eac. */
int __cdecl q_to_b(int a1, char *a2, int a3)
{
  int v3; // edi
  signed __int32 v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v3 = a3; /*0x112eb8*/
  if ( a3 <= 0 ) /*0x112ebd*/
    return 0; /*0x112ebf*/
  v10 = spltty(); /*0x112ecd*/
  if ( *(int *)a1 > 0 ) /*0x112ed3*/
  {
    v9 = a2; /*0x112eff*/
    while ( 1 ) /*0x112f11*/
    {
      v5 = 64 - (*(_DWORD *)(a1 + 4) & 0x3F); /*0x112f11*/
      if ( v5 > v3 ) /*0x112f15*/
        v5 = v3; /*0x112f17*/
      if ( v5 > *(_DWORD *)a1 ) /*0x112f1d*/
        v5 = *(_DWORD *)a1; /*0x112f1f*/
      bcopy(*(const void **)(a1 + 4), a2, v5); /*0x112f27*/
      *(_DWORD *)(a1 + 4) += v5; /*0x112f2c*/
      v6 = *(_DWORD *)a1 - v5; /*0x112f31*/
      *(_DWORD *)a1 = v6; /*0x112f33*/
      v3 -= v5; /*0x112f35*/
      a2 += v5; /*0x112f37*/
      if ( v6 <= 0 ) /*0x112f3f*/
        break; /*0x112f3f*/
      v8 = *(_DWORD *)(a1 + 4); /*0x112f88*/
      if ( (v8 & 0x3F) == 0 ) /*0x112f8d*/
      {
        *(_DWORD *)(a1 + 4) = *(_DWORD *)(v8 - 64) + 12; /*0x112f95*/
        *(_DWORD *)(v8 - 64) = cfreelist; /*0x112f9e*/
        cfreelist = v8 - 64; /*0x112fa4*/
        cfreecount += 52; /*0x112fa9*/
        if ( cwaiting ) /*0x112fb7*/
        {
          wakeup((int)&cwaiting); /*0x112fbe*/
          cwaiting = 0; /*0x112fc3*/
        }
      }
      if ( !v3 ) /*0x112fcf*/
        goto LABEL_17; /*0x112fcf*/
    }
    v7 = *(_DWORD *)(a1 + 4) - 1; /*0x112f44*/
    LOBYTE(v7) = v7 & 0xC0; /*0x112f45*/
    *(_DWORD *)(a1 + 8) = 0; /*0x112f47*/
    *(_DWORD *)(a1 + 4) = 0; /*0x112f4e*/
    *(_DWORD *)v7 = cfreelist; /*0x112f5b*/
    cfreelist = v7; /*0x112f5d*/
    cfreecount += 52; /*0x112f62*/
    if ( cwaiting ) /*0x112f70*/
    {
      wakeup((int)&cwaiting); /*0x112f77*/
      cwaiting = 0; /*0x112f7c*/
    }
LABEL_17:
    splx(v10); /*0x112fd5*/
    return a2 - v9; /*0x112fe1*/
  }
  else
  {
    *(_DWORD *)a1 = 0; /*0x112ed5*/
    *(_DWORD *)(a1 + 8) = 0; /*0x112edb*/
    *(_DWORD *)(a1 + 4) = 0; /*0x112ee2*/
    splx(v10); /*0x112eed*/
    return 0; /*0x112ef2*/
  }
}
