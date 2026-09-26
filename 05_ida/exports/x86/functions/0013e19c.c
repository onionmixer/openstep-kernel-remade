/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13e19c. */
int __cdecl direnter(_WORD *a1, char *__src, int a3, _WORD *a4, unsigned int a5, int a6, unsigned int *a7)
{
  char *v7; // eax
  size_t v8; // edi
  int result; // eax
  unsigned int v10; // eax
  int v11; // eax
  __int16 v12; // si
  __int16 v13; // dx
  int v14; // edx
  __int16 v15; // ax
  __int16 v16; // ax
  int v17; // esi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // edi
  unsigned int v22; // eax
  __int16 v23; // ax
  int v24; // [esp+10h] [ebp-18h] BYREF
  int v25[3]; // [esp+14h] [ebp-14h] BYREF
  int v26; // [esp+20h] [ebp-8h]

  v7 = __src; /*0x13e1a5*/
  v8 = 0; /*0x13e1a8*/
  if ( *__src ) /*0x13e1aa*/
  {
    while ( *v7 != 47 ) /*0x13e1b3*/
    {
      ++v7; /*0x13e1b9*/
      ++v8; /*0x13e1ba*/
      if ( !*v7 ) /*0x13e1bb*/
        goto LABEL_4; /*0x13e1be*/
    }
    return 13; /*0x13e554*/
  }
  else
  {
LABEL_4:
    if ( !v8 ) /*0x13e1c2*/
      panic(aDirenter); /*0x13e1c9*/
    if ( *__src == 46 && (v8 == 1 || v8 == 2 && __src[1] == 46) ) /*0x13e1e7*/
    {
      if ( a3 == 2 ) /*0x13e1ed*/
        return 66; /*0x13e1ef*/
      if ( !a7 ) /*0x13e200*/
        return 17; /*0x13e200*/
      result = dirlook((unsigned int)a1, __src, a7); /*0x13e20e*/
      if ( !result ) /*0x13e217*/
        return 17; /*0x13e21d*/
      return result; /*0x13e1f4*/
    }
    v25[0] = 0; /*0x13e228*/
    v26 = 0; /*0x13e22f*/
    if ( a3 ) /*0x13e23a*/
    {
      while ( 1 ) /*0x13e253*/
      {
        v10 = a5; /*0x13e253*/
        if ( (*(_BYTE *)(a5 + 68) & 1) == 0 ) /*0x13e25a*/
          break; /*0x13e25a*/
        *(_BYTE *)(a5 + 68) |= 0x10u; /*0x13e244*/
        sleep(v10); /*0x13e24b*/
      }
      v11 = a5; /*0x13e25c*/
      v12 = *(_WORD *)(a5 + 68) | 1; /*0x13e263*/
      *(_WORD *)(a5 + 68) = v12; /*0x13e267*/
      v13 = *(_WORD *)(v11 + 102); /*0x13e26b*/
      if ( !v13 ) /*0x13e272*/
      {
        *(_WORD *)(v11 + 68) = v12 & 0xFFFE; /*0x13e279*/
        if ( (v12 & 0x10) != 0 ) /*0x13e283*/
        {
          *(_WORD *)(v11 + 68) = v12 & 0xFFEE; /*0x13e28a*/
          wakeup(v11); /*0x13e28f*/
        }
        return 2; /*0x13e299*/
      }
      if ( v13 == 0x7FFF ) /*0x13e2a5*/
      {
        *(_WORD *)(v11 + 68) = v12 & 0xFFFE; /*0x13e2ac*/
        if ( (v12 & 0x10) != 0 ) /*0x13e2b6*/
        {
          *(_WORD *)(v11 + 68) = v12 & 0xFFEE; /*0x13e2bd*/
          wakeup(v11); /*0x13e2c2*/
        }
        return 31; /*0x13e2cc*/
      }
      *(_WORD *)(v11 + 102) = v13 + 1; /*0x13e2d6*/
      *(_BYTE *)(v11 + 68) |= 0x40u; /*0x13e2da*/
      iupdat(v11, 1); /*0x13e2e1*/
      v14 = a5; /*0x13e2e6*/
      v15 = *(_WORD *)(a5 + 68); /*0x13e2e9*/
      *(_WORD *)(a5 + 68) = v15 & 0xFFFE; /*0x13e2f2*/
      if ( (v15 & 0x10) != 0 ) /*0x13e2fb*/
      {
        LOBYTE(v15) = v15 & 0xEE; /*0x13e2fd*/
        *(_WORD *)(v14 + 68) = v15; /*0x13e2ff*/
        wakeup(v14); /*0x13e304*/
      }
    }
    while ( 1 ) /*0x13e327*/
    {
      v16 = a1[34]; /*0x13e327*/
      if ( (v16 & 1) == 0 ) /*0x13e32d*/
        break; /*0x13e32d*/
      LOBYTE(v16) = v16 | 0x10; /*0x13e310*/
      a1[34] = v16; /*0x13e315*/
      sleep((unsigned int)a1); /*0x13e31c*/
    }
    *((_BYTE *)a1 + 68) |= 1u; /*0x13e332*/
    if ( (a1[50] & 0xF000) == 0x4000 ) /*0x13e342*/
    {
      if ( a1[51] ) /*0x13e353*/
      {
        v17 = iaccess(a1, 64); /*0x13e36f*/
        if ( !v17 /*0x13e3c4*/
          && (a3 != 2
           || (*(_WORD *)(a5 + 100) & 0xF000) != 0x4000
           || a4 == a1
           || (v17 = iaccess(a5, 128)) == 0 && (v17 = sub_13F66C(a5, (unsigned int)a1)) == 0) )
        {
          v17 = sub_13E5C8((int)a1, __src, v8, (int)v25, (int)&v24); /*0x13e3e3*/
          if ( !v17 ) /*0x13e3ea*/
          {
            if ( v24 ) /*0x13e3f5*/
            {
              if ( a3 == 1 ) /*0x13e3ff*/
              {
                iput(v24); /*0x13e47d*/
                v17 = 17; /*0x13e482*/
              }
              else if ( a3 ) /*0x13e401*/
              {
                if ( a3 == 2 ) /*0x13e407*/
                {
                  v17 = sub_13E838((int)a4, a5, (int)a1, __src, v8, v24, (int)v25); /*0x13e44f*/
                  iput(v24); /*0x13e455*/
                  if ( !*(_WORD *)(v24 + 102) ) /*0x13e460*/
                    vnode_uncache(v24 + 12); /*0x13e46f*/
                }
              }
              else if ( a7 ) /*0x13e414*/
              {
                *a7 = v24; /*0x13e419*/
                v17 = 17; /*0x13e41b*/
              }
              else
              {
                iput(v24); /*0x13e429*/
              }
            }
            else
            {
              v17 = iaccess(a1, 128); /*0x13e49a*/
              if ( !v17 && (a3 || (v17 = sub_13EF04(a1, &a5, a6)) == 0) ) /*0x13e4c2*/
              {
                v17 = diraddentry((int)a1, __src, v8, (int)v25, a5, (int)a4); /*0x13e4e2*/
                if ( v17 ) /*0x13e4e9*/
                {
                  if ( !a3 ) /*0x13e4ef*/
                  {
                    if ( (*(_WORD *)(a5 + 100) & 0xF000) == 0x4000 ) /*0x13e500*/
                      --a1[51]; /*0x13e502*/
                    v18 = a5; /*0x13e506*/
                    *(_WORD *)(a5 + 102) = 0; /*0x13e509*/
                    *(_BYTE *)(v18 + 68) |= 0x40u; /*0x13e50f*/
                    irele(v18); /*0x13e514*/
                    a5 = 0; /*0x13e519*/
                  }
                }
                else if ( a7 ) /*0x13e528*/
                {
                  while ( 1 ) /*0x13e53b*/
                  {
                    v19 = a5; /*0x13e53b*/
                    if ( (*(_BYTE *)(a5 + 68) & 1) == 0 ) /*0x13e542*/
                      break; /*0x13e542*/
                    *(_BYTE *)(a5 + 68) |= 0x10u; /*0x13e52c*/
                    sleep(v19); /*0x13e533*/
                  }
                  v20 = a5; /*0x13e544*/
                  *(_BYTE *)(a5 + 68) |= 1u; /*0x13e547*/
                  *a7 = v20; /*0x13e54e*/
                }
                else if ( !a3 ) /*0x13e560*/
                {
                  irele(a5); /*0x13e566*/
                }
              }
            }
          }
        }
      }
      else
      {
        v17 = 2; /*0x13e35a*/
      }
    }
    else
    {
      v17 = 20; /*0x13e344*/
    }
    v21 = v26; /*0x13e56e*/
    if ( v26 ) /*0x13e573*/
    {
      byte_swap_dir_block_out(v26); /*0x13e576*/
      brelse(v21); /*0x13e57c*/
    }
    if ( v17 && a3 ) /*0x13e58c*/
    {
      v22 = a5; /*0x13e58e*/
      --*(_WORD *)(a5 + 102); /*0x13e591*/
      *(_BYTE *)(v22 + 68) |= 0x40u; /*0x13e595*/
    }
    v23 = a1[34]; /*0x13e59c*/
    a1[34] = v23 & 0xFFFE; /*0x13e5a5*/
    if ( (v23 & 0x10) != 0 ) /*0x13e5ab*/
    {
      LOBYTE(v23) = v23 & 0xEE; /*0x13e5ad*/
      a1[34] = v23; /*0x13e5af*/
      wakeup((int)a1); /*0x13e5b4*/
    }
    return v17; /*0x13e5b9*/
  }
}
